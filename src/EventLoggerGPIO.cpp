#include "EventLoggerGPIO.h"

#include <QDebug>
#include <QRegularExpression>
#include <QElapsedTimer>
#include <QThread>


// ============================================================================
// GPIO MAP - GPS_Fix and VCOM_Ping only.
//
// GSM_Status is intentionally NOT in this map: it is not a SoM GPIO line.
// It is driven remotely on the LARA modem's own GPIO16 via AT+UGPIOC over
// /dev/ttyS1 (see CommandGSMLed()).
//
// GPS
// SODIMM_216 -> gpiochip2 -> offset 40  (Linux GPIO line 579)
//
// VC Ping
// SODIMM_208 -> gpiochip1 -> offset 2   (Linux GPIO line 517)
//
// ============================================================================

const QMap<QString, QPair<QString, unsigned int>>
    EventLoggerGPIO::s_kSodimmMap =
    {
        {
            "SODIMM_216",   // GPS_Fix
            {
                "/dev/gpiochip2",
                40
            }
        },

        {
            "SODIMM_208",   // VCOM_Ping
            {
                "/dev/gpiochip1",
                2
            }
        }
};


// ============================================================================
// Constructor
// ============================================================================

EventLoggerGPIO::EventLoggerGPIO(
    QSettings *pcCfgSettings,
    QObject *pcParent)
    : QObject(pcParent),
    m_pcCfgSettings(pcCfgSettings)
{
    qDebug()
    << "[GPIO] EventLoggerGPIO constructor";


    // ------------------------------------------------------------------------
    // GPS timers
    // ------------------------------------------------------------------------

    m_GPSBlinkTimer.setInterval(500);

    m_GPSWatchdogTimer.setInterval(3000);


    connect(&m_GPSBlinkTimer,
            &QTimer::timeout,
            this,
            &EventLoggerGPIO::onGPSBlinkTimeout);


    connect(&m_GPSWatchdogTimer,
            &QTimer::timeout,
            this,
            &EventLoggerGPIO::onGPSWatchdogTimeout);


    // ------------------------------------------------------------------------
    // GSM timer (health-check polling only - LED has no software timer,
    // see header comment / CommandGSMLed())
    // ------------------------------------------------------------------------

    m_GSMCheckTimer.setInterval(5000);


    connect(&m_GSMCheckTimer,
            &QTimer::timeout,
            this,
            &EventLoggerGPIO::onGSMCheckTimeout);


    // ------------------------------------------------------------------------
    // VC Ping timers
    // ------------------------------------------------------------------------

    m_VCPingTimer.setInterval(2000);

    m_VCBlinkTimer.setInterval(500);


    connect(&m_VCPingTimer,
            &QTimer::timeout,
            this,
            &EventLoggerGPIO::onVCPingTimeout);


    connect(&m_VCBlinkTimer,
            &QTimer::timeout,
            this,
            &EventLoggerGPIO::onVCBlinkTimeout);
}


// ============================================================================
// Destructor
// ============================================================================

EventLoggerGPIO::~EventLoggerGPIO()
{
    m_GPSBlinkTimer.stop();
    m_GPSWatchdogTimer.stop();

    m_GSMCheckTimer.stop();

    m_VCPingTimer.stop();
    m_VCBlinkTimer.stop();


    // ------------------------------------------------------------------------
    // Close GPS UART
    // ------------------------------------------------------------------------

    if (m_pGPSSerial)
    {
        if (m_pGPSSerial->isOpen())
        {
            m_pGPSSerial->close();
        }

        delete m_pGPSSerial;
        m_pGPSSerial = nullptr;
    }


    // ------------------------------------------------------------------------
    // Close GSM UART
    // ------------------------------------------------------------------------

    if (m_pGSMSerial)
    {
        if (m_pGSMSerial->isOpen())
        {
            m_pGSMSerial->close();
        }

        delete m_pGSMSerial;
        m_pGSMSerial = nullptr;
    }


    // ------------------------------------------------------------------------
    // Stop Ping process
    // ------------------------------------------------------------------------

    if (m_pPingProcess)
    {
        if (m_pPingProcess->state() !=
            QProcess::NotRunning)
        {
            m_pPingProcess->kill();
            m_pPingProcess->waitForFinished(500);
        }

        delete m_pPingProcess;
        m_pPingProcess = nullptr;
    }


    ReleaseAll();
}


// ============================================================================
// Init
// ============================================================================

bool EventLoggerGPIO::Init()
{
    if (!m_pcCfgSettings)
    {
        qCritical()
        << "[GPIO] No QSettings instance provided";

        return false;
    }


    qDebug()
        << "================================================";

    qDebug()
        << "[GPIO] Initializing GPIO";

    qDebug()
        << "================================================";


    // ------------------------------------------------------------------------
    // Read GPIO configuration
    //
    // NOTE: only entries whose SODIMM label resolves in s_kSodimmMap are
    // accepted, i.e. GPS_Fix and VCOM_Ping. A "GSM_Status_SODIMM" key, if
    // present in the ini from an older config, will now be skipped with a
    // warning - GSM LED no longer uses a SoM GPIO line at all.
    // ------------------------------------------------------------------------

    m_pcCfgSettings->beginGroup("GPIO");

    const QStringList lstKeys =
        m_pcCfgSettings->childKeys();


    for (const QString &strKey : lstKeys)
    {
        if (!strKey.endsWith("_SODIMM"))
        {
            continue;
        }


        const QString strLogicalName =
            strKey.left(
                strKey.length()
                - QString("_SODIMM").length());


        const QString strSodimm =
            m_pcCfgSettings
                ->value(strKey)
                .toString()
                .trimmed();


        const bool bActiveLow =
            m_pcCfgSettings
                ->value(
                    strLogicalName + "_ActiveLow",
                    false)
                .toBool();


        if (!s_kSodimmMap.contains(strSodimm))
        {
            qWarning()
            << "[GPIO]"
            << strLogicalName
            << "Unknown / unused SODIMM:"
            << strSodimm;

            continue;
        }


        GpioLine line;

        line.strSodimmLabel = strSodimm;
        line.strChipPath =
            s_kSodimmMap[strSodimm].first;

        line.uiLineOffset =
            s_kSodimmMap[strSodimm].second;

        line.bActiveLow =
            bActiveLow;


        m_ocLines.insert(
            strLogicalName,
            line);


        qInfo()
            << "[GPIO]"
            << strLogicalName
            << "->"
            << strSodimm
            << "("
            << line.strChipPath
            << "offset"
            << line.uiLineOffset
            << ")"
            << "ActiveLow:"
            << bActiveLow;
    }


    m_pcCfgSettings->endGroup();


    // ------------------------------------------------------------------------
    // Request ONLY the 2 physical GPIO lines. GSM LED is not requested
    // here - it goes through the modem UART instead.
    // ------------------------------------------------------------------------

    bool bGPS =
        RequestLine(
            "GPS_Fix",
            false);


    bool bVC =
        RequestLine(
            "VCOM_Ping",
            true);


    if (!bGPS)
    {
        qCritical()
        << "[GPIO] GPS_Fix line request FAILED - check chip path / offset / "
           "permissions (must be able to open /dev/gpiochip2)";
    }

    if (!bVC)
    {
        qCritical()
        << "[GPIO] VCOM_Ping line request FAILED - check chip path / offset / "
           "permissions (must be able to open /dev/gpiochip1)";
    }


    // ------------------------------------------------------------------------
    // Read VC IP
    // ------------------------------------------------------------------------

    m_strVCIP =
        m_pcCfgSettings
            ->value(
                "KMS/VC_IP",
                "")
            .toString()
            .trimmed();


    qDebug()
        << "[VC Ping] VC IP:"
        << m_strVCIP;


    // ------------------------------------------------------------------------
    // Initial LED states
    // ------------------------------------------------------------------------
    //
    // GPS:
    // No fix initially -> BLINK
    //
    // GSM:
    // Not checked yet -> BLINK (HIGH command; hardware auto-blinks)
    //
    // VC:
    // Not reachable initially -> STABLE ON
    //
    // ------------------------------------------------------------------------

    SetGPSFixStatus(false);

    SetGSMStatus(false);

    SetVCOMPingStatus(false);


    // ------------------------------------------------------------------------
    // Wiring / active-low bring-up self-test. Safe to leave enabled
    // permanently (it only runs once, at Init) or comment out once the
    // hardware wiring has been confirmed.
    // ------------------------------------------------------------------------

    RunLedSelfTest();


    // ------------------------------------------------------------------------
    // Start GPS monitoring (reads /dev/ttyS0 directly)
    // ------------------------------------------------------------------------

    StartGPSMonitoring();


    // ------------------------------------------------------------------------
    // Start GSM monitoring
    // ------------------------------------------------------------------------

    StartGSMMonitoring();


    // ------------------------------------------------------------------------
    // Start VC ping monitoring
    // ------------------------------------------------------------------------

    StartVCPingMonitoring();


    qDebug()
        << "[GPIO] GPIO initialization completed";


    return bGPS && bVC;
}


// ============================================================================
// Request GPIO line
// ============================================================================

bool EventLoggerGPIO::RequestLine(
    const QString &strLogicalName,
    bool bInitialValue)
{
    if (!m_ocLines.contains(strLogicalName))
    {
        qWarning()
        << "[GPIO] Line not configured:"
        << strLogicalName;

        return false;
    }


    GpioLine &line =
        m_ocLines[strLogicalName];


    // ------------------------------------------------------------------------
    // Open GPIO chip
    // ------------------------------------------------------------------------

    line.pChip =
        gpiod_chip_open(
            line.strChipPath
                .toLocal8Bit()
                .constData());


    if (!line.pChip)
    {
        qWarning()
        << "[GPIO] Cannot open:"
        << line.strChipPath;

        return false;
    }


    // ------------------------------------------------------------------------
    // Get GPIO line
    // ------------------------------------------------------------------------

    line.pLine =
        gpiod_chip_get_line(
            line.pChip,
            line.uiLineOffset);


    if (!line.pLine)
    {
        qWarning()
        << "[GPIO] Cannot get GPIO line:"
        << strLogicalName
        << "offset:"
        << line.uiLineOffset;

        gpiod_chip_close(line.pChip);

        line.pChip = nullptr;

        return false;
    }


    // ------------------------------------------------------------------------
    // GPIO request configuration
    // ------------------------------------------------------------------------

    struct gpiod_line_request_config config;

    config.consumer =
        "EventLoggerGPIO";

    config.request_type =
        GPIOD_LINE_REQUEST_DIRECTION_OUTPUT;

    config.flags =
        line.bActiveLow
            ? GPIOD_LINE_REQUEST_FLAG_ACTIVE_LOW
            : 0;


    // ------------------------------------------------------------------------
    // Request line
    // ------------------------------------------------------------------------

    if (gpiod_line_request(
            line.pLine,
            &config,
            bInitialValue ? 1 : 0) < 0)
    {
        qWarning()
        << "[GPIO] Failed to request:"
        << strLogicalName;

        gpiod_chip_close(line.pChip);

        line.pChip = nullptr;
        line.pLine = nullptr;

        return false;
    }


    qDebug()
        << "[GPIO] Requested:"
        << strLogicalName
        << "chip:"
        << line.strChipPath
        << "offset:"
        << line.uiLineOffset
        << "ActiveLow:"
        << line.bActiveLow
        << "initial (logical):"
        << bInitialValue;


    LogLineState(
        strLogicalName,
        bInitialValue);


    return true;
}


// ============================================================================
// Write GPIO
// ============================================================================

bool EventLoggerGPIO::WriteLine(
    const QString &strLogicalName,
    bool bValue)
{
    if (!m_ocLines.contains(strLogicalName))
    {
        qWarning()
        << "[GPIO] GPIO not found:"
        << strLogicalName;

        return false;
    }


    GpioLine &line =
        m_ocLines[strLogicalName];


    if (!line.pLine)
    {
        qWarning()
        << "[GPIO] Invalid GPIO line:"
        << strLogicalName;

        return false;
    }


    const int ret =
        gpiod_line_set_value(
            line.pLine,
            bValue ? 1 : 0);


    if (ret < 0)
    {
        qWarning()
        << "[GPIO] Failed to write:"
        << strLogicalName
        << "value:"
        << bValue;

        return false;
    }


    LogLineState(
        strLogicalName,
        bValue);


    return true;
}


// ============================================================================
// Set GPIO
// ============================================================================

bool EventLoggerGPIO::SetLine(
    const QString &strLogicalName,
    bool bValue)
{
    return WriteLine(
        strLogicalName,
        bValue);
}


// ============================================================================
// LogLineState
// ============================================================================
//
// Reads back the RAW physical level libgpiod is currently driving (as
// reported by the kernel, i.e. gpiod_line_get_value() already accounts
// for the ACTIVE_LOW flag applied at request time) and cross-checks it
// against what we asked for. If they don't match, something upstream of
// libgpiod (wiring, buffer/driver stage, wrong ActiveLow flag for THIS
// board revision) is inverted or broken - which is exactly the class of
// bug behind "code says line is fine but the LED never lights".
// ============================================================================

void EventLoggerGPIO::LogLineState(
    const QString &strLogicalName,
    bool bRequestedLogicalValue)
{
    if (!m_ocLines.contains(strLogicalName))
    {
        return;
    }


    const GpioLine &line =
        m_ocLines[strLogicalName];


    if (!line.pLine)
    {
        return;
    }


    const int iRawValue =
        gpiod_line_get_value(
            line.pLine);


    if (iRawValue < 0)
    {
        qWarning()
        << "[GPIO]"
        << strLogicalName
        << "gpiod_line_get_value() failed - cannot verify wiring";

        return;
    }


    const bool bReadBackLogical =
        (iRawValue != 0);


    if (bReadBackLogical != bRequestedLogicalValue)
    {
        qWarning()
        << "[GPIO]"
        << strLogicalName
        << "MISMATCH - requested logical:"
        << bRequestedLogicalValue
        << "read back logical:"
        << bReadBackLogical
        << "(ActiveLow="
        << line.bActiveLow
        << "). Check wiring / <Name>_ActiveLow in the ini.";
    }
    else
    {
        qDebug()
        << "[GPIO]"
        << strLogicalName
        << "logical:"
        << bRequestedLogicalValue
        << "confirmed by readback (ActiveLow="
        << line.bActiveLow
        << ")";
    }
}


// ============================================================================
// RunLedSelfTest
// ============================================================================
//
// Bring-up helper: forces GPS_Fix and VCOM_Ping ON, waits, then OFF,
// logging logical vs. readback state at each step via LogLineState()
// (called internally by SetLine/WriteLine). Watch the physical LEDs
// during this window and compare against the log:
//
//   - LED lights while log says "logical: true"  -> wiring/ActiveLow OK
//   - LED does NOT light while log says "logical: true"
//         -> flip <Name>_ActiveLow in the [GPIO] ini section
//   - readback MISMATCH warning printed
//         -> libgpiod/kernel-level problem (permissions, wrong offset,
//            line already claimed by another process/driver), not a
//            polarity issue
//
// This call blocks briefly (QThread::msleep) since it is only meant to
// run once during Init(), before the event loop has real-time work to
// do. Do not call this after Init() from a time-critical context.
// ============================================================================

void EventLoggerGPIO::RunLedSelfTest(int uiOnMs)
{
    qDebug()
    << "[GPIO] ==== LED self-test: ON ====";

    SetLine("GPS_Fix", true);
    SetLine("VCOM_Ping", true);

    QThread::msleep(
        static_cast<unsigned long>(uiOnMs));

    qDebug()
        << "[GPIO] ==== LED self-test: OFF ====";

    SetLine("GPS_Fix", false);
    SetLine("VCOM_Ping", false);
}


// ============================================================================
// Release GPIOs
// ============================================================================

void EventLoggerGPIO::ReleaseAll()
{
    for (auto it = m_ocLines.begin();
         it != m_ocLines.end();
         ++it)
    {
        GpioLine &line =
            it.value();


        if (line.pLine)
        {
            gpiod_line_release(
                line.pLine);

            line.pLine = nullptr;
        }


        if (line.pChip)
        {
            gpiod_chip_close(
                line.pChip);

            line.pChip = nullptr;
        }
    }


    m_ocLines.clear();
}


// ###########################################################################
// GPS
// ###########################################################################


// ============================================================================
// SetGPSFixStatus
// ============================================================================
//
// Fix available    -> STABLE ON
// No fix           -> BLINK
// ============================================================================

void EventLoggerGPIO::SetGPSFixStatus(
    bool fixed)
{
    if (fixed)
    {
        m_bGPSFix = true;

        StopGPSBlink(true);

        qDebug()
            << "[GPIO] GPS FIX -> STABLE ON";
    }
    else
    {
        m_bGPSFix = false;

        StartGPSBlink();

        qDebug()
            << "[GPIO] GPS NO FIX -> BLINK";
    }
}


// ============================================================================
// UpdateGPSStatus
// ============================================================================
//
// uartOk       -> GPS UART/data is working
// fixQuality   -> GGA field[6]
// satellites   -> GGA field[7]
//
// ============================================================================

void EventLoggerGPIO::UpdateGPSStatus(
    bool uartOk,
    int fixQuality,
    int satellites)
{
    m_bGPSUartOk =
        uartOk;

    m_iGPSFixQuality =
        fixQuality;

    m_iGPSSatellites =
        satellites;


    // ------------------------------------------------------------------------
    // GPS fix decision
    //
    // Fix Quality:
    //
    // 0       = No fix
    // 1..5    = Valid positioning fix
    // 6       = Estimated / Dead Reckoning
    //
    // ------------------------------------------------------------------------

    m_bGPSFix =
        m_bGPSUartOk
        &&
        (m_iGPSFixQuality >= 1)
        &&
        (m_iGPSFixQuality <= 5)
        &&
        (m_iGPSSatellites > 0);


    qDebug()
        << "[GPS STATUS]"
        << "UART:"
        << m_bGPSUartOk
        << "FixQuality:"
        << m_iGPSFixQuality
        << "Satellites:"
        << m_iGPSSatellites
        << "FIX:"
        << m_bGPSFix;


    // ------------------------------------------------------------------------
    // GPS watchdog - every valid GGA sentence restarts this. If no GGA is
    // seen for 3 seconds, GPS is considered faulty (handled in
    // onGPSWatchdogTimeout()).
    // ------------------------------------------------------------------------

    m_GPSWatchdogTimer.start();


    SetGPSFixStatus(
        m_bGPSFix);
}


// ============================================================================
// StartGPSMonitoring
// ============================================================================
//
// Opens /dev/ttyS0 and starts listening for NMEA GGA sentences directly,
// replacing the previous design where an external EventLoggerGPS class
// pushed status in via UpdateGPSStatus().
// ============================================================================

void EventLoggerGPIO::StartGPSMonitoring()
{
    if (!m_pGPSSerial)
    {
        m_pGPSSerial =
            new QSerialPort(this);


        m_pGPSSerial->setPortName(
            "/dev/ttyS0");

        const int iBaud =
            m_pcCfgSettings
                ->value(
                    "GPS/BaudRate",
                    9600)
                .toInt();

        m_pGPSSerial->setBaudRate(
            iBaud);

        m_pGPSSerial->setDataBits(
            QSerialPort::Data8);

        m_pGPSSerial->setParity(
            QSerialPort::NoParity);

        m_pGPSSerial->setStopBits(
            QSerialPort::OneStop);

        m_pGPSSerial->setFlowControl(
            QSerialPort::NoFlowControl);


        connect(m_pGPSSerial,
                &QSerialPort::readyRead,
                this,
                &EventLoggerGPIO::onGPSReadyRead);
    }


    if (!OpenGPSUART())
    {
        qWarning()
        << "[GPS] UART open failed";

        m_bGPSUartOk = false;

        SetGPSFixStatus(false);
    }


    // ------------------------------------------------------------------------
    // Start the "no data" watchdog. If nothing arrives within 3s of
    // starting, onGPSWatchdogTimeout() will mark GPS as faulty.
    // ------------------------------------------------------------------------

    m_GPSWatchdogTimer.start();


    qDebug()
        << "[GPS] Monitoring started"
        << "UART:"
        << "/dev/ttyS0"
        << "Baud:"
        << m_pGPSSerial->baudRate();
}


// ============================================================================
// OpenGPSUART
// ============================================================================

bool EventLoggerGPIO::OpenGPSUART()
{
    if (!m_pGPSSerial)
        return false;


    if (m_pGPSSerial->isOpen())
        return true;


    if (!m_pGPSSerial->open(
            QIODevice::ReadOnly))
    {
        qWarning()
        << "[GPS] Cannot open /dev/ttyS0:"
        << m_pGPSSerial->errorString();

        return false;
    }


    qDebug()
        << "[GPS] UART opened successfully:"
        << "/dev/ttyS0";


    return true;
}


// ============================================================================
// onGPSReadyRead
// ============================================================================
//
// Accumulates raw bytes into a line buffer, splits on CR/LF, and hands
// each complete NMEA sentence to ParseGGA(). Only $..GGA sentences are
// acted on; everything else (RMC, GSA, GSV, ...) is ignored.
// ============================================================================

void EventLoggerGPIO::onGPSReadyRead()
{
    if (!m_pGPSSerial)
        return;


    m_ocGPSRxBuffer.append(
        m_pGPSSerial->readAll());


    int iNewlineIndex = -1;


    while ((iNewlineIndex =
            m_ocGPSRxBuffer.indexOf('\n')) != -1)
    {
        QByteArray line =
            m_ocGPSRxBuffer
                .left(iNewlineIndex)
                .trimmed();


        m_ocGPSRxBuffer.remove(
            0,
            iNewlineIndex + 1);


        if (line.isEmpty())
        {
            continue;
        }


        const QString strSentence =
            QString::fromLatin1(line);


        if (!strSentence.contains("GGA"))
        {
            continue;
        }


        int iFixQuality = 0;
        int iSatellites = 0;


        if (ParseGGA(
                strSentence,
                iFixQuality,
                iSatellites))
        {
            UpdateGPSStatus(
                true,
                iFixQuality,
                iSatellites);
        }
        else
        {
            qWarning()
            << "[GPS] Failed to parse GGA sentence:"
            << strSentence;
        }
    }


    // ------------------------------------------------------------------------
    // Prevent unbounded growth if garbage data with no newlines arrives.
    // ------------------------------------------------------------------------

    if (m_ocGPSRxBuffer.size() > 4096)
    {
        qWarning()
        << "[GPS] RX buffer overflow, discarding";

        m_ocGPSRxBuffer.clear();
    }
}


// ============================================================================
// ParseGGA
// ============================================================================
//
// $GPGGA,time,lat,N,lon,E,fixQuality,numSat,HDOP,alt,M,geoid,M,age,id*CS
//   [0]   [1]  [2] [3][4][5]  [6]      [7]   ...
//
// Returns true and fills iFixQuality / iSatellites if the sentence has
// enough comma-separated fields to be a valid GGA sentence. Does not
// verify the NMEA checksum - the GPS watchdog timer (3s) is the safety
// net for corrupted/missing data.
// ============================================================================

bool EventLoggerGPIO::ParseGGA(
    const QString &strSentence,
    int &iFixQuality,
    int &iSatellites) const
{
    if (!strSentence.startsWith('$'))
    {
        return false;
    }


    // Strip checksum suffix ("*XX") if present, it's irrelevant to the
    // field split below.
    QString strClean = strSentence;

    const int iStarIndex =
        strClean.indexOf('*');

    if (iStarIndex != -1)
    {
        strClean =
            strClean.left(iStarIndex);
    }


    const QStringList lstFields =
        strClean.split(',');


    // Need at least fields[0..7]
    if (lstFields.size() < 8)
    {
        return false;
    }


    if (!lstFields.at(0).contains("GGA"))
    {
        return false;
    }


    bool bFixOk = false;
    bool bSatOk = false;


    iFixQuality =
        lstFields.at(6).toInt(&bFixOk);

    iSatellites =
        lstFields.at(7).toInt(&bSatOk);


    // Empty fields (e.g. "0" fix with no satellites) still parse to 0/0,
    // which is a valid "no fix" reading - only a genuine non-numeric
    // field is treated as a parse failure.
    if (!bFixOk)
    {
        iFixQuality = 0;
    }

    if (!bSatOk)
    {
        iSatellites = 0;
    }


    return true;
}


// ============================================================================
// Start GPS blink
// ============================================================================

void EventLoggerGPIO::StartGPSBlink()
{
    if (!m_GPSBlinkTimer.isActive())
    {
        m_bGPSLedState = false;

        SetLine(
            "GPS_Fix",
            false);

        m_GPSBlinkTimer.start();
    }
}


// ============================================================================
// Stop GPS blink
// ============================================================================

void EventLoggerGPIO::StopGPSBlink(
    bool bFinalState)
{
    m_GPSBlinkTimer.stop();

    m_bGPSLedState =
        bFinalState;

    SetLine(
        "GPS_Fix",
        bFinalState);
}


// ============================================================================
// GPS blink timer
// ============================================================================

void EventLoggerGPIO::onGPSBlinkTimeout()
{
    m_bGPSLedState =
        !m_bGPSLedState;


    SetLine(
        "GPS_Fix",
        m_bGPSLedState);


    qDebug()
        << "[GPIO] GPS LED:"
        << (m_bGPSLedState
                ? "ON"
                : "OFF");
}


// ============================================================================
// GPS watchdog
// ============================================================================

void EventLoggerGPIO::onGPSWatchdogTimeout()
{
    /*
     * No GPS GGA data received for 3 seconds.
     *
     * Therefore consider GPS UART/data unavailable.
     */

    m_bGPSUartOk = false;

    m_bGPSFix = false;


    qWarning()
        << "[GPS] No GPS data received for 3 seconds";


    SetGPSFixStatus(false);
}


// ###########################################################################
// GSM
// ###########################################################################


// ============================================================================
// Start GSM monitoring
// ============================================================================

void EventLoggerGPIO::StartGSMMonitoring()
{
    if (!m_pGSMSerial)
    {
        m_pGSMSerial =
            new QSerialPort(this);


        // --------------------------------------------------------------------
        // GSM UART
        // --------------------------------------------------------------------

        m_pGSMSerial->setPortName(
            "/dev/ttyS1");

        m_pGSMSerial->setBaudRate(
            QSerialPort::Baud115200);

        m_pGSMSerial->setDataBits(
            QSerialPort::Data8);

        m_pGSMSerial->setParity(
            QSerialPort::NoParity);

        m_pGSMSerial->setStopBits(
            QSerialPort::OneStop);

        m_pGSMSerial->setFlowControl(
            QSerialPort::NoFlowControl);
    }


    // ------------------------------------------------------------------------
    // Open UART
    // ------------------------------------------------------------------------

    if (!OpenGSMUART())
    {
        qWarning()
        << "[GSM] UART open failed";

        SetGSMStatus(false);
    }


    // ------------------------------------------------------------------------
    // First check immediately
    // ------------------------------------------------------------------------

    QTimer::singleShot(
        100,
        this,
        &EventLoggerGPIO::onGSMCheckTimeout);


    // ------------------------------------------------------------------------
    // Periodic GSM check
    // ------------------------------------------------------------------------

    m_GSMCheckTimer.start();


    qDebug()
        << "[GSM] Monitoring started"
        << "UART:"
        << "/dev/ttyS1"
        << "Baud:"
        << 115200;
}


// ============================================================================
// Open GSM UART
// ============================================================================

bool EventLoggerGPIO::OpenGSMUART()
{
    if (!m_pGSMSerial)
        return false;


    if (m_pGSMSerial->isOpen())
        return true;


    if (!m_pGSMSerial->open(
            QIODevice::ReadWrite))
    {
        qWarning()
        << "[GSM] Cannot open /dev/ttyS1:"
        << m_pGSMSerial->errorString();

        return false;
    }


    qDebug()
        << "[GSM] UART opened successfully:"
        << "/dev/ttyS1";


    return true;
}


// ============================================================================
// Send GSM AT command
// ============================================================================

bool EventLoggerGPIO::SendGSMCommand(
    const QByteArray &command,
    QByteArray &response,
    int timeoutMs)
{
    response.clear();


    if (!m_pGSMSerial)
        return false;


    // ------------------------------------------------------------------------
    // Make sure UART is open
    // ------------------------------------------------------------------------

    if (!m_pGSMSerial->isOpen())
    {
        if (!OpenGSMUART())
            return false;
    }


    // ------------------------------------------------------------------------
    // Clear old input
    // ------------------------------------------------------------------------

    m_pGSMSerial->clear(
        QSerialPort::Input);


    // ------------------------------------------------------------------------
    // Add CR
    // ------------------------------------------------------------------------

    QByteArray cmd =
        command;


    if (!cmd.endsWith('\r'))
        cmd.append('\r');


    qDebug()
        << "[GSM TX]"
        << command;


    // ------------------------------------------------------------------------
    // Write command
    // ------------------------------------------------------------------------

    const qint64 written =
        m_pGSMSerial->write(cmd);


    if (written != cmd.size())
    {
        qWarning()
        << "[GSM] UART write failed";

        return false;
    }


    if (!m_pGSMSerial
             ->waitForBytesWritten(timeoutMs))
    {
        qWarning()
        << "[GSM] UART write timeout";

        return false;
    }


    // ------------------------------------------------------------------------
    // Wait for response
    // ------------------------------------------------------------------------

    QElapsedTimer timer;

    timer.start();


    while (timer.elapsed() < timeoutMs)
    {
        if (m_pGSMSerial
                ->waitForReadyRead(100))
        {
            response.append(
                m_pGSMSerial
                    ->readAll());


            if (response.contains("OK")
                ||
                response.contains("ERROR"))
            {
                break;
            }
        }
    }


    // Read anything remaining
    response.append(
        m_pGSMSerial
            ->readAll());


    qDebug()
        << "[GSM RX]"
        << response;


    if (response.isEmpty())
    {
        return false;
    }


    return response.contains("OK");
}


// ============================================================================
// GSM UART check
// ============================================================================

bool EventLoggerGPIO::CheckGSMUART()
{
    QByteArray response;


    const bool ok =
        SendGSMCommand(
            "AT",
            response,
            1000);


    if (ok)
    {
        qDebug()
        << "[GSM] UART communication -> OK";
    }
    else
    {
        qWarning()
        << "[GSM] UART communication -> FAILED";
    }


    return ok;
}


// ============================================================================
// GSM SIM check
// ============================================================================

bool EventLoggerGPIO::CheckGSMSIM()
{
    QByteArray response;


    if (!SendGSMCommand(
            "AT+CPIN?",
            response,
            1500))
    {
        qWarning()
        << "[GSM] CPIN command failed";

        return false;
    }


    // ------------------------------------------------------------------------
    // SIM ready
    // ------------------------------------------------------------------------

    if (response.contains(
            "+CPIN: READY"))
    {
        qDebug()
        << "[GSM] SIM -> INSERTED / READY";

        return true;
    }


    // ------------------------------------------------------------------------
    // SIM not ready
    // ------------------------------------------------------------------------

    qWarning()
        << "[GSM] SIM -> NOT READY:"
        << response;


    return false;
}


// ============================================================================
// GSM network registration
// ============================================================================

bool EventLoggerGPIO::CheckGSMNetwork()
{
    bool registered = false;

    QByteArray response;


    // ------------------------------------------------------------------------
    // CREG - Circuit switched registration
    // ------------------------------------------------------------------------

    if (SendGSMCommand(
            "AT+CREG?",
            response,
            1500))
    {
        qDebug()
        << "[GSM] CREG:"
        << response;


        /*
         * Registered:
         *
         * +CREG: 0,1
         * +CREG: 0,5
         *
         * 1 = Home network
         * 5 = Roaming
         */

        if (response.contains(",1")
            ||
            response.contains(",5"))
        {
            registered = true;
        }
    }


    // ------------------------------------------------------------------------
    // CGREG - GPRS registration
    // ------------------------------------------------------------------------

    if (!registered)
    {
        response.clear();


        if (SendGSMCommand(
                "AT+CGREG?",
                response,
                1500))
        {
            qDebug()
            << "[GSM] CGREG:"
            << response;


            if (response.contains(",1")
                ||
                response.contains(",5"))
            {
                registered = true;
            }
        }
    }


    // ------------------------------------------------------------------------
    // CEREG - LTE/EPS registration
    // ------------------------------------------------------------------------

    if (!registered)
    {
        response.clear();


        if (SendGSMCommand(
                "AT+CEREG?",
                response,
                1500))
        {
            qDebug()
            << "[GSM] CEREG:"
            << response;


            if (response.contains(",1")
                ||
                response.contains(",5"))
            {
                registered = true;
            }
        }
    }


    qDebug()
        << "[GSM] Network registration:"
        << (registered
                ? "REGISTERED"
                : "NOT REGISTERED");


    return registered;
}


// ============================================================================
// GSM signal check
// ============================================================================

bool EventLoggerGPIO::CheckGSMsignal()
{
    QByteArray response;


    if (!SendGSMCommand(
            "AT+CSQ",
            response,
            1500))
    {
        qWarning()
        << "[GSM] CSQ command failed";

        return false;
    }


    // ------------------------------------------------------------------------
    // Expected:
    //
    // +CSQ: <rssi>,<ber>
    // ------------------------------------------------------------------------

    QRegularExpression regex(
        "\\+CSQ:\\s*(\\d+)\\s*,\\s*(\\d+)"
        );


    QRegularExpressionMatch match =
        regex.match(
            QString::fromLatin1(response));


    if (!match.hasMatch())
    {
        qWarning()
        << "[GSM] Invalid CSQ response:"
        << response;

        return false;
    }


    m_iGSMRSSI =
        match
            .captured(1)
            .toInt();


    m_iGSMBER =
        match
            .captured(2)
            .toInt();


    qDebug()
        << "[GSM] Signal RSSI:"
        << m_iGSMRSSI
        << "BER:"
        << m_iGSMBER;


    /*
     * CSQ RSSI:
     *
     * 0  = very poor
     * 1..31 = increasing signal
     * 99 = unknown
     *
     * Current threshold:
     *
     * RSSI >= 10 -> acceptable
     * RSSI < 10  -> LOW
     * RSSI 99    -> UNKNOWN
     */

    if (m_iGSMRSSI == 99)
    {
        qWarning()
        << "[GSM] Signal -> UNKNOWN";

        return false;
    }


    if (m_iGSMRSSI < 10)
    {
        qWarning()
        << "[GSM] Signal -> LOW"
        << "RSSI:"
        << m_iGSMRSSI;

        return false;
    }


    qDebug()
        << "[GSM] Signal -> OK";


    return true;
}


// ============================================================================
// GSM periodic health check
// ============================================================================

void EventLoggerGPIO::onGSMCheckTimeout()
{
    qDebug()
    << "";
    qDebug()
        << "================================================";
    qDebug()
        << "[GSM] MODEM HEALTH CHECK";
    qDebug()
        << "================================================";


    // ------------------------------------------------------------------------
    // 1. UART
    // ------------------------------------------------------------------------

    m_bGSMUartOk =
        CheckGSMUART();


    if (!m_bGSMUartOk)
    {
        qWarning()
        << "[GSM] CHECK FAILED: UART";

        m_bGSMSimOk = false;
        m_bGSMNetworkOk = false;
        m_bGSMSignalOk = false;

        EvaluateGSMStatus();

        return;
    }


    // ------------------------------------------------------------------------
    // 2. SIM
    // ------------------------------------------------------------------------

    m_bGSMSimOk =
        CheckGSMSIM();


    if (!m_bGSMSimOk)
    {
        qWarning()
        << "[GSM] CHECK FAILED: SIM";

        m_bGSMNetworkOk = false;
        m_bGSMSignalOk = false;

        EvaluateGSMStatus();

        return;
    }


    // ------------------------------------------------------------------------
    // 3. Network
    // ------------------------------------------------------------------------

    m_bGSMNetworkOk =
        CheckGSMNetwork();


    // ------------------------------------------------------------------------
    // 4. Signal
    // ------------------------------------------------------------------------

    m_bGSMSignalOk =
        CheckGSMsignal();


    // ------------------------------------------------------------------------
    // Evaluate final GSM state
    // ------------------------------------------------------------------------

    EvaluateGSMStatus();
}


// ============================================================================
// Evaluate GSM status
// ============================================================================

void EventLoggerGPIO::EvaluateGSMStatus()
{
    /*
     * GSM is considered healthy only when ALL are OK:
     *
     * UART
     * SIM
     * Network
     * Signal
     */

    m_bGSMOverallOk =
        m_bGSMUartOk
        &&
        m_bGSMSimOk
        &&
        m_bGSMNetworkOk
        &&
        m_bGSMSignalOk;


    qDebug()
        << "[GSM STATUS]"
        << "UART:"
        << m_bGSMUartOk
        << "SIM:"
        << m_bGSMSimOk
        << "NETWORK:"
        << m_bGSMNetworkOk
        << "SIGNAL:"
        << m_bGSMSignalOk
        << "OVERALL:"
        << m_bGSMOverallOk;


    SetGSMStatus(
        m_bGSMOverallOk);
}


// ============================================================================
// GSM status
// ============================================================================
//
// TRUE  (SIM + Network + Signal all OK)
//     -> LED STABLE   -> AT+UGPIOC=16,0,0 (LOW)
//
// FALSE (any check failed)
//     -> LED BLINKS BY ITSELF IN HARDWARE -> AT+UGPIOC=16,0,1 (HIGH)
//
// There is no software blink loop for this LED - one command per state
// change is all that's needed, because the modem's own GPIO16 output
// stage is what produces the blink when driven HIGH on this board.
// ============================================================================

void EventLoggerGPIO::SetGSMStatus(
    bool ok)
{
    CommandGSMLed(ok);


    qDebug()
        << "[GPIO] GSM:"
        << (ok ? "OK -> STABLE (LOW)" : "FAULT -> BLINK (HIGH)");
}


// ============================================================================
// CommandGSMLed
// ============================================================================
//
// Sends the AT+UGPIOC command exactly once per requested state, and only
// if the state actually changed (avoids hammering the UART every 5s
// health-check cycle when nothing changed).
// ============================================================================

void EventLoggerGPIO::CommandGSMLed(bool bStable)
{
    if (bStable == m_bGSMLedCommandedOn)
    {
        // Already in the requested state - nothing to send.
        return;
    }


    QByteArray response;

    if (bStable)
    {
        // LOW -> stable
        SendGSMCommand(
            "AT+UGPIOC=16,0,0",
            response,
            1000);

        qDebug()
            << "[GSM] GPIO16 -> LOW (stable)";
    }
    else
    {
        // HIGH -> hardware auto-blink
        SendGSMCommand(
            "AT+UGPIOC=16,0,1",
            response,
            1000);

        qDebug()
            << "[GSM] GPIO16 -> HIGH (hardware blink)";
    }


    m_bGSMLedCommandedOn = bStable;
}


// ###########################################################################
// VC PING
// ###########################################################################


// ============================================================================
// Start VC Ping monitoring
// ============================================================================

void EventLoggerGPIO::StartVCPingMonitoring()
{
    if (m_strVCIP.isEmpty())
    {
        qWarning()
        << "[VC Ping] VC_IP is empty";

        SetVCOMPingStatus(false);

        return;
    }


    // ------------------------------------------------------------------------
    // Create ping process
    // ------------------------------------------------------------------------

    if (!m_pPingProcess)
    {
        m_pPingProcess =
            new QProcess(this);


        connect(
            m_pPingProcess,
            QOverload<int,
                      QProcess::ExitStatus>::of(
                &QProcess::finished),
            this,
            &EventLoggerGPIO::onPingFinished);


        connect(
            m_pPingProcess,
            &QProcess::errorOccurred,
            this,
            &EventLoggerGPIO::onPingError);
    }


    // ------------------------------------------------------------------------
    // First ping immediately
    // ------------------------------------------------------------------------

    QTimer::singleShot(
        100,
        this,
        &EventLoggerGPIO::onVCPingTimeout);


    // ------------------------------------------------------------------------
    // Ping every 2 seconds
    // ------------------------------------------------------------------------

    m_VCPingTimer.start();


    qDebug()
        << "[VC Ping] Monitoring started"
        << "IP:"
        << m_strVCIP;
}


// ============================================================================
// VC Ping
// ============================================================================

void EventLoggerGPIO::onVCPingTimeout()
{
    if (m_strVCIP.isEmpty())
    {
        SetVCOMPingStatus(false);

        return;
    }


    if (!m_pPingProcess)
        return;


    // ------------------------------------------------------------------------
    // Don't start another ping while previous one is running
    // ------------------------------------------------------------------------

    if (m_pPingProcess->state()
        != QProcess::NotRunning)
    {
        return;
    }


    qDebug()
        << "[VC Ping] Checking:"
        << m_strVCIP;


    m_pPingProcess->start(
        "/usr/bin/ping",
        QStringList()
            << "-c"
            << "1"
            << "-W"
            << "1"
            << m_strVCIP);
}


// ============================================================================
// Ping finished
// ============================================================================

void EventLoggerGPIO::onPingFinished(
    int exitCode,
    QProcess::ExitStatus exitStatus)
{
    Q_UNUSED(exitStatus);


    QByteArray output;


    if (m_pPingProcess)
    {
        output =
            m_pPingProcess
                ->readAllStandardOutput();
    }


    const bool reachable =
        (exitCode == 0);


    m_bVCReachable =
        reachable;


    qDebug()
        << "[VC Ping]"
        << "IP:"
        << m_strVCIP
        << "ExitCode:"
        << exitCode
        << "Output:"
        << output
        << "Reachable:"
        << reachable;


    SetVCOMPingStatus(
        reachable);
}


// ============================================================================
// Ping error
// ============================================================================

void EventLoggerGPIO::onPingError(
    QProcess::ProcessError error)
{
    qWarning()
    << "[VC Ping] Process error:"
    << error;


    m_bVCReachable = false;


    SetVCOMPingStatus(false);
}


// ============================================================================
// SetVCOMPingStatus
// ============================================================================
//
// VC_IP reachable      -> BLINK
// VC_IP not reachable  -> STABLE ON
//
// ============================================================================

void EventLoggerGPIO::SetVCOMPingStatus(
    bool reachable)
{
    if (reachable)
    {
        StartVCBlink();

        qDebug()
            << "[GPIO] VCOM_Ping:"
            << "PING OK -> BLINK";
    }
    else
    {
        StopVCBlink(true);

        qDebug()
            << "[GPIO] VCOM_Ping:"
            << "PING FAIL -> STABLE ON";
    }
}


// ============================================================================
// Start VC blink
// ============================================================================

void EventLoggerGPIO::StartVCBlink()
{
    if (!m_VCBlinkTimer.isActive())
    {
        m_bVCLedState = false;

        SetLine(
            "VCOM_Ping",
            false);

        m_VCBlinkTimer.start();
    }
}


// ============================================================================
// Stop VC blink
// ============================================================================

void EventLoggerGPIO::StopVCBlink(
    bool bFinalState)
{
    m_VCBlinkTimer.stop();

    m_bVCLedState =
        bFinalState;

    SetLine(
        "VCOM_Ping",
        bFinalState);
}


// ============================================================================
// VC blink timer
// ============================================================================

void EventLoggerGPIO::onVCBlinkTimeout()
{
    /*
     * This function only toggles the LED.
     *
     * Actual VC reachability is determined
     * by the ping process.
     */

    m_bVCLedState =
        !m_bVCLedState;


    SetLine(
        "VCOM_Ping",
        m_bVCLedState);


    qDebug()
        << "[GPIO] VC LED:"
        << (m_bVCLedState
                ? "ON"
                : "OFF");
}