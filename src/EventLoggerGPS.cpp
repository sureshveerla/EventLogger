#include "EventLoggerGPS.h"

#include <QDebug>
#include <QDateTime>
#include <QTimeZone>
#include <QtMath>
#include <QFile>

#include <fcntl.h>
#include <unistd.h>


// ============================================================================
// Constructor
// ============================================================================

EventLogger::EventLogger(QObject *parent)
    : QObject(parent),
    m_serial(nullptr)
{
    // ============================================================
    // PPS (independent of GPS UART)
    // ============================================================

    if (!initPPS())
    {
        qWarning()
        << "[PPS] Initialization failed";
    }


    // ============================================================
    // GPS UART
    // ============================================================

    m_serial = new QSerialPort(this);

    m_serial->setPortName("/dev/ttyS0");

    m_serial->setBaudRate(QSerialPort::Baud9600);

    m_serial->setDataBits(QSerialPort::Data8);

    m_serial->setParity(QSerialPort::NoParity);

    m_serial->setStopBits(QSerialPort::OneStop);

    m_serial->setFlowControl(QSerialPort::NoFlowControl);


    // ============================================================
    // Open GPS UART
    // ============================================================

    if (!m_serial->open(QIODevice::ReadOnly))
    {
        qDebug()
        << "UART GPS not connected:"
        << m_serial->errorString();

        m_serial->deleteLater();

        m_serial = nullptr;

        return;
    }


    qDebug()
        << "==============================================";

    qDebug()
        << "UART GPS connected successfully";

    qDebug()
        << "Device :"
        << m_serial->portName();

    qDebug()
        << "Baud   :"
        << m_serial->baudRate();

    qDebug()
        << "==============================================";


    // ============================================================
    // GPS Ready Read
    // ============================================================

    connect(m_serial,
            &QSerialPort::readyRead,
            this,
            &EventLogger::readGPSData,
            Qt::QueuedConnection);

}


// ============================================================================
// Destructor
// ============================================================================

EventLogger::~EventLogger()
{
    // ============================================================
    // PPS cleanup
    // ============================================================

    if (m_ppsNotifier)
    {
        m_ppsNotifier->setEnabled(false);

        delete m_ppsNotifier;

        m_ppsNotifier = nullptr;
    }


    if (m_ppsTimeoutTimer)
    {
        m_ppsTimeoutTimer->stop();

        delete m_ppsTimeoutTimer;

        m_ppsTimeoutTimer = nullptr;
    }


    if (m_ppsFd >= 0)
    {
        ::close(m_ppsFd);

        m_ppsFd = -1;
    }


    // ============================================================
    // GPS UART
    // ============================================================

    if (m_serial)
    {
        if (m_serial->isOpen())
        {
            m_serial->close();
        }
    }
}


// ============================================================================
// Read GPS Data
// ============================================================================

void EventLogger::readGPSData()
{
    if (!m_serial)
        return;

    // ============================================================
    // Read available UART data
    // ============================================================

    QByteArray raw =
        m_serial->readAll();

    if (raw.isEmpty())
        return;

    m_buffer.append(raw);

    // ============================================================
    // Process both NMEA and UBX data
    // ============================================================

    while (!m_buffer.isEmpty())
    {
        // ========================================================
        // NMEA MESSAGE
        // ========================================================

        if (m_buffer.startsWith('$'))
        {
            int index =
                m_buffer.indexOf('\n');

            // Complete NMEA sentence not received yet
            if (index < 0)
                break;

            QByteArray line =
                m_buffer.left(index);

            // Remove processed line including '\n'
            m_buffer.remove(
                0,
                index + 1);

            // Remove \r, spaces, etc.
            line =
                line.trimmed();

            if (line.isEmpty())
                continue;

            // ====================================================
            // DEBUG
            // ====================================================

            qDebug()
                << "[GPS RX]"
                << line;

            // ====================================================
            // RMC
            // ====================================================

            if (line.startsWith("$GPRMC") ||
                line.startsWith("$GNRMC"))
            {
                processRMC(line);
            }

            // ====================================================
            // GGA
            // ====================================================

            else if (line.startsWith("$GPGGA") ||
                     line.startsWith("$GNGGA"))
            {
                processGGA(line);
            }

            continue;
        }

        // ========================================================
        // UBX MESSAGE
        // ========================================================

        if (m_buffer.size() >= 2 &&
            static_cast<quint8>(m_buffer.at(0)) == 0xB5 &&
            static_cast<quint8>(m_buffer.at(1)) == 0x62)
        {
            // Need at least:
            //
            // B5 62
            // CLASS
            // ID
            // LEN1
            // LEN2
            //
            if (m_buffer.size() < 6)
                break;

            quint16 payloadLength =
                static_cast<quint8>(m_buffer.at(4)) |
                (static_cast<quint8>(m_buffer.at(5)) << 8);

            // Complete UBX packet size:
            //
            // Sync       = 2
            // Class/ID   = 2
            // Length     = 2
            // Payload    = payloadLength
            // Checksum   = 2
            //
            int totalLength =
                8 + payloadLength;

            // Complete packet not received yet
            if (m_buffer.size() < totalLength)
                break;

            QByteArray ubxPacket =
                m_buffer.left(totalLength);

            // Remove processed UBX packet
            m_buffer.remove(
                0,
                totalLength);

            processUBX(ubxPacket);

            continue;
        }

        // ========================================================
        // UNKNOWN DATA
        //
        // Remove one byte until we find either:
        //
        // '$'       -> NMEA
        // B5 62     -> UBX
        // ========================================================

        m_buffer.remove(0, 1);
    }
}


void EventLogger::processUBX(const QByteArray &packet)
{
    if (packet.size() < 8)
        return;

    // ============================================================
    // Check UBX sync characters
    // ============================================================

    if (static_cast<quint8>(packet.at(0)) != 0xB5 ||
        static_cast<quint8>(packet.at(1)) != 0x62)
    {
        return;
    }

    quint8 msgClass =
        static_cast<quint8>(packet.at(2));

    quint8 msgId =
        static_cast<quint8>(packet.at(3));

    quint16 payloadLength =
        static_cast<quint8>(packet.at(4)) |
        (static_cast<quint8>(packet.at(5)) << 8);

    if (packet.size() !=
        (8 + payloadLength))
    {
        qWarning()
        << "[UBX] Invalid packet length";

        return;
    }

    // ============================================================
    // Check checksum
    //
    // Checksum is calculated over:
    //
    // CLASS
    // ID
    // LENGTH LSB
    // LENGTH MSB
    // PAYLOAD
    // ============================================================

    quint8 ckA = 0;
    quint8 ckB = 0;

    for (int i = 2;
         i < 6 + payloadLength;
         ++i)
    {
        ckA =
            static_cast<quint8>(
                ckA +
                static_cast<quint8>(packet.at(i)));

        ckB =
            static_cast<quint8>(
                ckB +
                ckA);
    }

    quint8 receivedCkA =
        static_cast<quint8>(
            packet.at(6 + payloadLength));

    quint8 receivedCkB =
        static_cast<quint8>(
            packet.at(7 + payloadLength));

    if (ckA != receivedCkA ||
        ckB != receivedCkB)
    {
        qWarning()
        << "[UBX] Checksum error";

        return;
    }

    // ============================================================
    // UBX-NAV-PVT
    //
    // CLASS = 0x01
    // ID    = 0x07
    // ============================================================

    if (msgClass == 0x01 &&
        msgId == 0x07)
    {
        if (payloadLength < 4)
            return;

        // ========================================================
        // iTOW
        //
        // Bytes 0..3 of NAV-PVT payload
        //
        // Little endian
        // ========================================================

        const quint8 b0 =
            static_cast<quint8>(packet.at(6));

        const quint8 b1 =
            static_cast<quint8>(packet.at(7));

        const quint8 b2 =
            static_cast<quint8>(packet.at(8));

        const quint8 b3 =
            static_cast<quint8>(packet.at(9));

        quint32 iTOW =
            static_cast<quint32>(b0) |
            (static_cast<quint32>(b1) << 8) |
            (static_cast<quint32>(b2) << 16) |
            (static_cast<quint32>(b3) << 24);

        qDebug()
            << "[GPS UBX-NAV-PVT]"
            << "iTOW ="
            << iTOW
            << "ms";

        // ========================================================
        // Send TOW to nmsMainWindow
        // ========================================================

        emit gpsTOWReady(iTOW);
    }
}

// ============================================================================
// PPS (sysfs GPIO edge, same method as AT03 GNSS/PPS test)
// ============================================================================

bool EventLogger::initPPS()
{
    if (m_ppsGpioNumber < 0)
    {
        qWarning()
        << "[PPS] GPIO number not set (m_ppsGpioNumber) - use the same value as AT03 PpsGpioLine";

        return false;
    }

    const QString gpioDir =
        QString("/sys/class/gpio/gpio%1").arg(m_ppsGpioNumber);

    const QString valuePath = gpioDir + "/value";
    const QString edgePath  = gpioDir + "/edge";
    const QString dirPath   = gpioDir + "/direction";


    // ============================================================
    // Export GPIO if not exported yet
    // ============================================================

    if (!QFile::exists(valuePath))
    {
        QFile exportFile("/sys/class/gpio/export");

        if (exportFile.open(QIODevice::WriteOnly))
        {
            exportFile.write(QByteArray::number(m_ppsGpioNumber));
            exportFile.close();
        }
    }

    if (!QFile::exists(valuePath))
    {
        qWarning()
        << "[PPS] Cannot open PPS GPIO value node:"
        << valuePath;

        return false;
    }


    // ============================================================
    // Direction = in, edge = rising
    // ============================================================

    QFile dirFile(dirPath);

    if (dirFile.exists() &&
        dirFile.open(QIODevice::WriteOnly))
    {
        dirFile.write("in");
        dirFile.close();
    }

    QFile edgeFile(edgePath);

    if (edgeFile.exists())
    {
        if (edgeFile.open(QIODevice::WriteOnly))
        {
            edgeFile.write("rising");
            edgeFile.close();
        }
        else
        {
            qWarning()
            << "[PPS] Cannot write edge file:"
            << edgePath;

            return false;
        }
    }


    // ============================================================
    // Open value node
    // ============================================================

    m_ppsFd =
        ::open(valuePath.toLocal8Bit().constData(),
               O_RDONLY | O_NONBLOCK);

    if (m_ppsFd < 0)
    {
        qWarning()
        << "[PPS] Cannot open PPS GPIO value node:"
        << valuePath;

        return false;
    }


    // Initial read - clears the pending state, otherwise the first
    // poll returns immediately
    char dummy[8];

    ssize_t ignored =
        ::read(m_ppsFd, dummy, sizeof(dummy));

    (void)ignored;


    // ============================================================
    // Start elapsed timer
    // ============================================================

    m_ppsTimer.start();

    m_bHavePpsPulse = false;
    m_ppsValidPulseCount = 0;


    // ============================================================
    // sysfs edge is reported as POLLPRI, which Qt maps to the
    // Exception notifier type
    // ============================================================

    m_ppsNotifier =
        new QSocketNotifier(
            m_ppsFd,
            QSocketNotifier::Exception,
            this);


    connect(
        m_ppsNotifier,
        &QSocketNotifier::activated,
        this,
        [this](int)
        {
            handlePPSEvent();
        });


    // ============================================================
    // PPS timeout timer
    // ============================================================

    m_ppsTimeoutTimer =
        new QTimer(this);

    m_ppsTimeoutTimer->setInterval(100);

    connect(
        m_ppsTimeoutTimer,
        &QTimer::timeout,
        this,
        &EventLogger::checkPPSTimeout);

    m_ppsTimeoutTimer->start();


    qDebug()
        << "[PPS] Monitoring"
        << valuePath
        << "| Required pulses:"
        << m_ppsPulseCountRequired
        << "| Nominal:"
        << m_ppsPeriodNominalMs
        << "ms"
        << "| Tolerance:"
        << m_ppsPeriodToleranceMs
        << "ms";


    return true;
}

void EventLogger::handlePPSEvent()
{
    if (m_ppsFd < 0)
        return;


    // ============================================================
    // Timestamp first (before any other work), then re-read the
    // value node - this clears the POLLPRI condition
    // ============================================================

    const qint64 currentTimeNs =
        m_ppsTimer.nsecsElapsed();

    char dummy[8];

    ::lseek(m_ppsFd, 0, SEEK_SET);

    ssize_t n =
        ::read(m_ppsFd, dummy, sizeof(dummy));

    if (n < 0)
    {
        qWarning()
        << "[PPS] Failed to read GPIO value";

        return;
    }


    // ============================================================
    // First PPS pulse
    // ============================================================

    if (!m_bHavePpsPulse)
    {
        m_bHavePpsPulse = true;

        m_lastPpsTimeNs =
            currentTimeNs;

        m_ppsValidPulseCount = 1;

        qDebug()
            << "[PPS] First pulse detected";

        return;
    }


    // ============================================================
    // Calculate PPS period
    // ============================================================

    const double periodMs =
        static_cast<double>(currentTimeNs - m_lastPpsTimeNs) / 1.0e6;

    m_lastPpsTimeNs =
        currentTimeNs;


    qDebug()
        << "[PPS] Pulse"
        << "Period:"
        << periodMs
        << "ms";


    // ============================================================
    // Check PPS period
    // ============================================================

    const int minPeriod =
        m_ppsPeriodNominalMs -
        m_ppsPeriodToleranceMs;

    const int maxPeriod =
        m_ppsPeriodNominalMs +
        m_ppsPeriodToleranceMs;


    if (periodMs >= minPeriod &&
        periodMs <= maxPeriod)
    {
        m_ppsValidPulseCount++;

        qDebug()
            << "[PPS] Valid pulse"
            << m_ppsValidPulseCount
            << "/"
            << m_ppsPulseCountRequired;


        if (m_ppsValidPulseCount >=
            m_ppsPulseCountRequired)
        {
            if (!m_bPPSValid)
            {
                m_bPPSValid = true;

                qDebug()
                    << "[PPS] VALID";
                emit gpsPPSStatusReady(true);
            }
        }
    }
    else
    {
        qWarning()
        << "[PPS] Invalid period:"
        << periodMs
        << "ms";

        // Restart validation sequence
        m_ppsValidPulseCount = 1;

        if (m_bPPSValid)
        {
            m_bPPSValid = false;
            emit gpsPPSStatusReady(false);
        }
    }
}

void EventLogger::checkPPSTimeout()
{
    if (!m_bHavePpsPulse)
        return;


    const qint64 elapsedSinceLastPpsMs =
        (m_ppsTimer.nsecsElapsed() - m_lastPpsTimeNs) / 1000000;


    const int timeoutMs =
        m_ppsPeriodNominalMs +
        m_ppsPeriodToleranceMs;


    if (elapsedSinceLastPpsMs >
        timeoutMs)
    {
        if (m_bPPSValid)
        {
            m_bPPSValid = false;

            qWarning()
                << "[PPS] TIMEOUT - PPS not detected";
            emit gpsPPSStatusReady(false);
        }

        m_ppsValidPulseCount = 0;
    }
}

// ============================================================================
// Process RMC
//
// RMC format:
//
// $GNRMC,
//       [1] UTC Time
//       [2] Status A/V
//       [3] Latitude
//       [4] N/S
//       [5] Longitude
//       [6] E/W
//       [7] Speed in knots
//       [8] Course
//       [9] Date DDMMYY
//       ...
//
// ============================================================================

void EventLogger::processRMC(
    const QByteArray &line)
{
    QList<QByteArray> fields =
        line.split(',');


    // ============================================================
    // We need at least field[2] for A/V status
    // ============================================================

    if (fields.size() <= 2)
    {
        qDebug()
        << "[RMC] ERROR: Not enough fields";

        return;
    }


    // ============================================================
    // RMC Status
    // ============================================================

    QByteArray status =
        fields[2].trimmed();


    if (status == "A")
    {
        qDebug()
        << "[GPS] RMC: FIX";
    }
    else if (status == "V")
    {
        qDebug()
        << "[GPS] RMC: NO FIX";
    }
    else
    {
        qDebug()
        << "Unknown RMC status:"
        << status;
    }


    // ============================================================
    // If RMC does not have enough fields, stop here
    // ============================================================

    if (fields.size() <= 9)
    {
        qDebug()
        << "[RMC] WARNING: Not enough fields for"
        << "time/date/position";

        return;
    }


    // ============================================================
    // UTC Time
    // ============================================================

    QByteArray rawTime =
        fields[1].trimmed();


    // ============================================================
    // Date
    // ============================================================

    QByteArray rawDate =
        fields[9].trimmed();


    // ============================================================
    // Parse UTC Date + Time
    // ============================================================

    if (rawDate.length() == 6 &&
        rawTime.length() >= 6)
    {
        int day =
            rawDate.mid(0, 2).toInt();

        int month =
            rawDate.mid(2, 2).toInt();

        int year =
            2000 +
            rawDate.mid(4, 2).toInt();

        int hour =
            rawTime.mid(0, 2).toInt();

        int minute =
            rawTime.mid(2, 2).toInt();

        int second =
            rawTime.mid(4, 2).toInt();

        // Get milliseconds from GPS time
        int millisecond = 0;

        int dotIndex = rawTime.indexOf('.');

        if (dotIndex >= 0)
        {
            QString fraction =
                rawTime.mid(dotIndex + 1);

            if (fraction.length() >= 3)
            {
                millisecond =
                    fraction.left(3).toInt();
            }
            else
            {
                millisecond =
                    fraction.leftJustified(3, '0').toInt();
            }
        }

        QDate date(
            year,
            month,
            day);

        QTime time(
            hour,
            minute,
            second,
            millisecond);

        if (date.isValid() &&
            time.isValid())
        {
            QDateTime utcTime(
                date,
                time,
                QTimeZone::utc());

            QTimeZone istZone(
                "Asia/Kolkata");

            QDateTime istTime =
                utcTime.toTimeZone(
                    istZone);

            QString formattedUTC =
                utcTime.toString(
                    "yyyy-MM-dd HH:mm:ss.zzz");

            QString formattedIST =
                istTime.toString(
                    "yyyy-MM-dd HH:mm:ss.zzz");

            qDebug()
                << "GPS UTC:"
                << formattedUTC;

            qDebug()
                << "GPS IST:"
                << formattedIST;

            emit gpsUTCReady(
                utcTime);
        }

        else
        {
            qDebug()
            << "[RMC] ERROR: Invalid date/time";
        }
    }
    else
    {
        qDebug()
        << "[RMC] WARNING: Invalid date/time fields";
    }


    // ============================================================
    // Latitude / Longitude
    //
    // Only calculate valid position when RMC status = A
    // ============================================================

    if (status == "A" &&
        fields.size() > 6)
    {
        QByteArray latString =
            fields[3].trimmed();

        QByteArray latDirection =
            fields[4].trimmed();


        QByteArray lonString =
            fields[5].trimmed();

        QByteArray lonDirection =
            fields[6].trimmed();


        if (!latString.isEmpty() &&
            !latDirection.isEmpty() &&
            !lonString.isEmpty() &&
            !lonDirection.isEmpty())
        {
            bool latOK = false;

            bool lonOK = false;


            double rawLat =
                latString.toDouble(
                    &latOK);


            double rawLon =
                lonString.toDouble(
                    &lonOK);


            if (latOK && lonOK)
            {
                // ------------------------------------------------
                // Latitude
                //
                // NMEA format:
                // DDMM.MMMM
                // ------------------------------------------------

                int latDeg =
                    static_cast<int>(
                        rawLat / 100.0);


                double latMin =
                    rawLat -
                    (latDeg * 100.0);


                double dLat =
                    latDeg +
                    (latMin / 60.0);


                if (latDirection == "S")
                    dLat = -dLat;


                // ------------------------------------------------
                // Longitude
                //
                // DDDMM.MMMM
                // ------------------------------------------------

                int lonDeg =
                    static_cast<int>(
                        rawLon / 100.0);


                double lonMin =
                    rawLon -
                    (lonDeg * 100.0);


                double dLon =
                    lonDeg +
                    (lonMin / 60.0);


                if (lonDirection == "W")
                    dLon = -dLon;


                qDebug()
                    << "GPS Latitude :"
                    << dLat;


                qDebug()
                    << "GPS Longitude:"
                    << dLon;


                emit gpsPositionReady(
                    dLat,
                    dLon,
                    true);
            }
            else
            {
                qDebug()
                << "[RMC] ERROR: Invalid Lat/Lon";
            }
        }
        else
        {
            qDebug()
            << "[RMC] WARNING: Lat/Lon fields empty";
        }
    }
    else if (status == "V")
    {
        // --------------------------------------------------------
        // No valid RMC position
        // --------------------------------------------------------

        emit gpsPositionReady(
            0.0,
            0.0,
            false);
    }


    // ============================================================
    // Ground Speed
    //
    // RMC field[7] = speed over ground in knots
    //
    // 1 knot = 514.4444 mm/s
    // ============================================================

    if (status == "A" &&
        fields.size() > 7 &&
        !fields[7].trimmed().isEmpty())
    {
        bool speedOK = false;


        double speedKnots =
            fields[7]
                .trimmed()
                .toDouble(
                    &speedOK);


        if (speedOK)
        {
            qint32 speedMMps =
                static_cast<qint32>(
                    qRound(
                        speedKnots *
                        514.4444));


            qDebug()
                << "GPS Speed:"
                << speedKnots
                << "knots ="
                << speedMMps
                << "mm/s";


            emit gpsSpeedReady(
                speedMMps);
        }
        else
        {
            qDebug()
            << "[RMC] ERROR: Invalid speed";
        }
    }
}


// ============================================================================
// Process GGA
//
// GGA format:
//
// $GNGGA,
//       [1] UTC Time
//       [2] Latitude
//       [3] N/S
//       [4] Longitude
//       [5] E/W
//       [6] Fix Quality
//       [7] Number of Satellites
//       [8] HDOP
//       ...
//
// Fix Quality:
//
// 0 = Invalid / No Fix
// 1 = GPS Fix
// 2 = DGPS Fix
// 3 = PPS Fix
// 4 = RTK Fixed
// 5 = RTK Float
// 6 = Estimated / Dead Reckoning
//
// ============================================================================

void EventLogger::processGGA(
    const QByteArray &line)
{
    QList<QByteArray> fields =
        line.split(',');


    // ============================================================
    // Need field[6] = Fix Quality
    // ============================================================

    if (fields.size() <= 6)
    {
        qDebug()
        << "[GGA] ERROR: Not enough fields";

        // --------------------------------------------------------
        // No valid GGA
        //
        // GPS status = NO FIX
        // --------------------------------------------------------

        emit gpsFixStatusReady(0x00);

        return;
    }


    // ============================================================
    // Fix Quality
    // ============================================================

    bool ok = false;


    int fixQuality =
        fields[6]
            .trimmed()
            .toInt(&ok);


    // ============================================================
    // Invalid / empty Fix Quality
    // ============================================================

    if (!ok)
    {
        qDebug()
        << "[GPS] INVALID FIX QUALITY";

        emit gpsFixStatusReady(0x00);

        return;
    }


    // ============================================================
    // Number of Satellites
    //
    // GGA field[7]
    // ============================================================

    int satellites = 0;


    if (fields.size() > 7)
    {
        satellites =
            fields[7]
                .trimmed()
                .toInt();
    }


    // ============================================================
    // HDOP
    //
    // GGA field[8]
    // ============================================================

    double hdop = 0.0;


    if (fields.size() > 8)
    {
        hdop =
            fields[8]
                .trimmed()
                .toDouble();
    }


    // ============================================================
    // Store latest GPS parameters
    // ============================================================

    m_gpsFixQuality = fixQuality;
    m_gpsSatellites = satellites;
    m_gpsHdop = hdop;


    // ============================================================
    // GPS FIX DECISION
    //
    // Valid fix:
    //     Fix Quality 1..5
    //     AND satellites > 0
    //
    // No valid fix:
    //     anything else
    // ============================================================

    const bool gpsFixAvailable =
        (fixQuality >= 1 &&
         fixQuality <= 5 &&
         satellites > 0);

    m_gpsFixAvailable = gpsFixAvailable;


    // ============================================================
    // GPS HEALTH FILTER
    //
    // We receive GGA messages more frequently than the 0xA2
    // heartbeat. Therefore do NOT immediately toggle the
    // healthiness status on every GGA message.
    //
    // Three consecutive bad GGA messages -> GPS FAULT
    // Three consecutive good GGA messages -> GPS HEALTHY
    //
    // This filters the transient 2-3 message toggling seen
    // during antenna removal/recovery.
    // ============================================================

    if (!gpsFixAvailable)
    {
        ++m_gpsBadCount;
        m_gpsGoodCount = 0;

        if (m_gpsBadCount >= GPS_BAD_CONFIRM_COUNT)
        {
            m_gpsBadCount = GPS_BAD_CONFIRM_COUNT;
            m_gpsfixstatus = 0;
        }
    }
    else
    {
        ++m_gpsGoodCount;
        m_gpsBadCount = 0;

        if (m_gpsGoodCount >= GPS_GOOD_CONFIRM_COUNT)
        {
            m_gpsGoodCount = GPS_GOOD_CONFIRM_COUNT;
            m_gpsfixstatus = 1;
        }
    }


    // ============================================================
    // Debug
    // ============================================================

    qDebug()
        << "[GPS HEALTH]"
        << "FixQuality =" << fixQuality
        << "| Satellites =" << satellites
        << "| HDOP =" << hdop
        << "| BadCount =" << m_gpsBadCount
        << "| GoodCount =" << m_gpsGoodCount
        << "| Status =" << m_gpsfixstatus;


    // Existing GPS FIX indication is still emitted.
    // This remains the raw/current fix indication and is NOT
    // used directly as the filtered 0xA2 health status.
    emit gpsFixStatus(gpsFixAvailable ? 1 : 0);


    // ============================================================
    // Existing ICD Fix Status
    // ============================================================

    quint8 icdFixStatus =
        0x00;


    // ------------------------------------------------------------
    // No Fix
    // ------------------------------------------------------------

    if (fixQuality == 0)
    {
        icdFixStatus =
            0x00;


        qDebug()
            << "[GPS] NO FIX | SAT:"
            << satellites
            << "| HDOP:"
            << hdop;
    }


    // ------------------------------------------------------------
    // Estimated / Dead Reckoning
    // ------------------------------------------------------------

    else if (fixQuality == 6)
    {
        icdFixStatus =
            0x01;


        qDebug()
            << "[GPS] ESTIMATED | SAT:"
            << satellites
            << "| HDOP:"
            << hdop;
    }


    // ------------------------------------------------------------
    // Valid Fix
    //
    // 1 = GPS Fix
    // 2 = DGPS Fix
    // 3 = PPS Fix
    // 4 = RTK Fixed
    // 5 = RTK Float
    // ------------------------------------------------------------

    else if (fixQuality >= 1 &&
             fixQuality <= 5)
    {
        // Keep the existing ICD behavior:
        // 1..5 = 0x03

        icdFixStatus =
            0x03;


        qDebug()
            << "[GPS] FIX | SAT:"
            << satellites
            << "| HDOP:"
            << hdop;
    }


    // ------------------------------------------------------------
    // Unknown Fix Quality
    // ------------------------------------------------------------

    else
    {
        icdFixStatus =
            0x00;


        qDebug()
            << "[GPS] UNKNOWN | QUALITY:"
            << fixQuality
            << "| SAT:"
            << satellites
            << "| HDOP:"
            << hdop;
    }



    // ============================================================
    // Send ICD GPS Fix Status
    // ============================================================

    emit gpsFixStatusReady(
        icdFixStatus);
}