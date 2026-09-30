#include "EventLoggerStatusLED.h"

#include <QDebug>
#include <QThread>
#include <QCoreApplication>
#include <QTimer>


// ============================================================
// Constructor
// ============================================================

EventLoggerStatusLED::EventLoggerStatusLED(QObject *parent)
    : QObject(parent),

    // --------------------------------------------------------
    // GPIO CHIP 1
    // --------------------------------------------------------

    m_gpioChip(nullptr),
    m_vcLed(nullptr),
    m_eventLed(nullptr),
    m_faultLed(nullptr),

    // --------------------------------------------------------
    // GPS GPIO CHIP
    // --------------------------------------------------------

    m_gpsGpioChip(nullptr),
    m_gpsLed(nullptr),

    // --------------------------------------------------------
    // TIMERS
    // --------------------------------------------------------

    m_eventLedTimer(nullptr),
    m_faultLedTimer(nullptr),
    m_gpsLedTimer(nullptr),

    // --------------------------------------------------------
    // HEALTH STATUS
    // --------------------------------------------------------

    m_vcOK(false),
    m_gpsOK(false),
    m_gsmOK(false),

    // --------------------------------------------------------
    // LED STATES
    // --------------------------------------------------------

    m_vcLedState(false),
    m_faultLedState(false),
    m_gpsLedState(false)
{
    qDebug() << "======================================";
    qDebug() << "EventLogger Status LED Initialization";
    qDebug() << "======================================";

    qDebug() << "[LED] Constructor entered";
    qDebug() << "[LED] Thread =" << QThread::currentThread();


    // =========================================================
    // GPIO CHIP 1
    // =========================================================

    if (!initializeGPIO())
    {
        qWarning() << "[LED] GPIO initialization FAILED";
        return;
    }

    qDebug() << "[LED] GPIO initialization completed";


    // =========================================================
    // GPS GPIO
    // =========================================================

    if (!initializeGPSGPIO())
    {
        qWarning() << "[GPS LED] GPS GPIO initialization FAILED";
    }
    else
    {
        qDebug() << "[GPS LED] GPS GPIO initialization completed";
    }

    m_vcLedTimer = new QTimer(this);

    m_vcLedTimer->setSingleShot(false);

    m_vcLedTimer->setInterval(500);

    connect(m_vcLedTimer,
            &QTimer::timeout,
            this,
            &EventLoggerStatusLED::VCIPLedTimeout);

    qDebug() << "[LED] VC IP TIMER CREATED";


    // =========================================================
    // EVENT LED TIMER
    // =========================================================

    m_eventLedTimer = new QTimer(this);

    m_eventLedTimer->setSingleShot(true);

    // Event LED remains ON for 1 second
    // after the last valid EventLogger/Kavach packet.
    m_eventLedTimer->setInterval(2000);

    connect(m_eventLedTimer,
            &QTimer::timeout,
            this,
            &EventLoggerStatusLED::EventLedTimeout);

    qDebug() << "[LED] EVENT TIMER CREATED";


    // =========================================================
    // FAULT LED TIMER
    // =========================================================

    m_faultLedTimer = new QTimer(this);

    m_faultLedTimer->setSingleShot(false);

    // Fault LED blink interval = 500 ms
    m_faultLedTimer->setInterval(500);

    connect(m_faultLedTimer,
            &QTimer::timeout,
            this,
            &EventLoggerStatusLED::FaultLedTimeout);

    qDebug() << "[LED] FAULT TIMER CREATED";


    // =========================================================
    // GPS LED TIMER
    // =========================================================

    m_gpsLedTimer = new QTimer(this);

    m_gpsLedTimer->setSingleShot(false);

    // GPS LED blink interval = 500 ms
    m_gpsLedTimer->setInterval(500);

    connect(m_gpsLedTimer,
            &QTimer::timeout,
            this,
            &EventLoggerStatusLED::GPSLedTimeout);

    qDebug() << "[GPS LED] GPS TIMER CREATED";


    // =========================================================
    // INITIAL HEALTH STATUS
    // =========================================================

    m_vcOK = false;
    m_gpsOK = false;
    m_gsmOK = false;


    // =========================================================
    // INITIAL LED STATES
    // =========================================================

    m_faultLedState = false;
    m_gpsLedState = false;


    // VC LED OFF
    setGPIO(m_vcLed, false);

    // Event LED OFF
    setGPIO(m_eventLed, false);

    // Fault LED OFF initially
    setGPIO(m_faultLed, false);

    // GPS LED OFF initially
    setGPIO(m_gpsLed, false);


    qDebug() << "[LED] GPIO initial states set";


    // =========================================================
    // IMPORTANT
    //
    // Do NOT start timers here.
    //
    // Timers must run after the Qt event loop starts.
    // =========================================================

    qDebug() << "[LED] Constructor completed";

    qDebug() << "[LED] VC IP LED     : SODIMM_208";
    qDebug() << "[LED] Event Logging : SODIMM_210";
    qDebug() << "[LED] Fault LED     : SODIMM_212";
    qDebug() << "[LED] GPS LED       : gpiochip2 line 40";
}


// ============================================================
// Destructor
// ============================================================

EventLoggerStatusLED::~EventLoggerStatusLED()
{
    qDebug() << "[LED] EventLoggerStatusLED destructor called";


    // =========================================================
    // STOP TIMERS
    // =========================================================

    if (m_eventLedTimer)
    {
        m_eventLedTimer->stop();
    }


    if (m_faultLedTimer)
    {
        qDebug()
        << "[LED] Fault timer active at destruction ="
        << m_faultLedTimer->isActive();

        m_faultLedTimer->stop();
    }


    if (m_gpsLedTimer)
    {
        qDebug()
        << "[GPS LED] GPS timer active at destruction ="
        << m_gpsLedTimer->isActive();

        m_gpsLedTimer->stop();
    }


    // =========================================================
    // RELEASE VC LED
    // =========================================================

    if (m_vcLed)
    {
        gpiod_line_set_value(m_vcLed, 0);

        gpiod_line_release(m_vcLed);

        m_vcLed = nullptr;
    }


    // =========================================================
    // RELEASE EVENT LED
    // =========================================================

    if (m_eventLed)
    {
        gpiod_line_set_value(m_eventLed, 0);

        gpiod_line_release(m_eventLed);

        m_eventLed = nullptr;
    }


    // =========================================================
    // RELEASE FAULT LED
    // =========================================================

    if (m_faultLed)
    {
        gpiod_line_set_value(m_faultLed, 0);

        gpiod_line_release(m_faultLed);

        m_faultLed = nullptr;
    }


    // =========================================================
    // CLOSE GPIO CHIP 1
    // =========================================================

    if (m_gpioChip)
    {
        gpiod_chip_close(m_gpioChip);

        m_gpioChip = nullptr;
    }


    // =========================================================
    // RELEASE GPS LED
    // =========================================================

    if (m_gpsLed)
    {
        gpiod_line_set_value(m_gpsLed, 0);

        gpiod_line_release(m_gpsLed);

        m_gpsLed = nullptr;
    }


    // =========================================================
    // CLOSE GPS GPIO CHIP
    // =========================================================

    if (m_gpsGpioChip)
    {
        gpiod_chip_close(m_gpsGpioChip);

        m_gpsGpioChip = nullptr;
    }


    qDebug() << "[LED] GPIO cleanup completed";
}


// ============================================================
// START
// ============================================================

void EventLoggerStatusLED::Start()
{
    qDebug() << "======================================";
    qDebug() << "[LED] Start() called";
    qDebug() << "[LED] Thread =" << QThread::currentThread();
    qDebug() << "[LED] Event dispatcher ="
             << QThread::currentThread()->eventDispatcher();
    qDebug() << "======================================";


    // ---------------------------------------------------------
    // Initial condition:
    //
    // VC  = false
    // GPS = false
    // GSM = false
    //
    // Therefore Fault LED must blink.
    // ---------------------------------------------------------

    updateFaultLED();


    qDebug() << "[LED] Start() completed";
}


// ============================================================
// GPIO INITIALIZATION
//
// GPIO CHIP 1
//
// SODIMM_208 -> gpiochip1 line 2 -> VC LED
// SODIMM_210 -> gpiochip1 line 3 -> Event LED
// SODIMM_212 -> gpiochip1 line 4 -> Fault LED
// ============================================================

bool EventLoggerStatusLED::initializeGPIO()
{
    qDebug() << "[LED] Opening /dev/gpiochip1";


    // =========================================================
    // OPEN GPIO CHIP
    // =========================================================

    m_gpioChip =
        gpiod_chip_open("/dev/gpiochip1");

    if (!m_gpioChip)
    {
        qWarning()
        << "[LED] Cannot open /dev/gpiochip1";

        return false;
    }

    qDebug()
        << "[LED] gpiochip1 opened successfully";


    // =========================================================
    // VC IP LED
    //
    // SODIMM_208
    // gpiochip1 line 2
    // =========================================================

    qDebug()
        << "[LED] Getting SODIMM_208";


    m_vcLed =
        gpiod_chip_get_line(
            m_gpioChip,
            2);


    if (!m_vcLed)
    {
        qWarning()
        << "[LED] Cannot get SODIMM_208";

        return false;
    }


    if (gpiod_line_request_output(
            m_vcLed,
            "EventLogger-VC-IP-LED",
            0) < 0)
    {
        qWarning()
        << "[LED] Cannot request SODIMM_208";

        return false;
    }


    qDebug()
        << "[LED] SODIMM_208 requested successfully";


    // =========================================================
    // EVENT LOGGING LED
    //
    // SODIMM_210
    // gpiochip1 line 3
    // =========================================================

    qDebug()
        << "[LED] Getting SODIMM_210";


    m_eventLed =
        gpiod_chip_get_line(
            m_gpioChip,
            3);


    if (!m_eventLed)
    {
        qWarning()
        << "[LED] Cannot get SODIMM_210";

        return false;
    }


    if (gpiod_line_request_output(
            m_eventLed,
            "EventLogger-Event-LED",
            0) < 0)
    {
        qWarning()
        << "[LED] Cannot request SODIMM_210";

        return false;
    }


    qDebug()
        << "[LED] SODIMM_210 requested successfully";


    // =========================================================
    // FAULT LED
    //
    // SODIMM_212
    // gpiochip1 line 4
    // =========================================================

    qDebug()
        << "[LED] Getting SODIMM_212";


    m_faultLed =
        gpiod_chip_get_line(
            m_gpioChip,
            4);


    if (!m_faultLed)
    {
        qWarning()
        << "[LED] Cannot get SODIMM_212";

        return false;
    }


    if (gpiod_line_request_output(
            m_faultLed,
            "EventLogger-Fault-LED",
            0) < 0)
    {
        qWarning()
        << "[LED] Cannot request SODIMM_212";

        return false;
    }


    qDebug()
        << "[LED] SODIMM_212 requested successfully";


    qDebug()
        << "[LED] All GPIOs initialized successfully";


    return true;
}


// ============================================================
// GPS GPIO INITIALIZATION
//
// ACTUAL GPS LED
//
// /dev/gpiochip2
// line 40
//
// This is kept separate from gpiochip1 because the physical
// GPS LED is actually controlled by gpiochip2 line 40.
// ============================================================

bool EventLoggerStatusLED::initializeGPSGPIO()
{
    qDebug()
    << "[GPS LED] Opening /dev/gpiochip2";


    // =========================================================
    // OPEN GPIO CHIP 2
    // =========================================================

    m_gpsGpioChip =
        gpiod_chip_open("/dev/gpiochip2");

    if (!m_gpsGpioChip)
    {
        qWarning()
        << "[GPS LED] Cannot open /dev/gpiochip2";

        return false;
    }


    qDebug()
        << "[GPS LED] gpiochip2 opened successfully";


    // =========================================================
    // GET GPS LED
    //
    // gpiochip2 line 40
    // =========================================================

    m_gpsLed =
        gpiod_chip_get_line(
            m_gpsGpioChip,
            40);


    if (!m_gpsLed)
    {
        qWarning()
        << "[GPS LED] Cannot get gpiochip2 line 40";

        gpiod_chip_close(m_gpsGpioChip);

        m_gpsGpioChip = nullptr;

        return false;
    }


    // =========================================================
    // REQUEST GPS LED AS OUTPUT
    // =========================================================

    if (gpiod_line_request_output(
            m_gpsLed,
            "EventLogger-GPS-LED",
            0) < 0)
    {
        qWarning()
        << "[GPS LED] Cannot request gpiochip2 line 40";

        m_gpsLed = nullptr;

        gpiod_chip_close(m_gpsGpioChip);

        m_gpsGpioChip = nullptr;

        return false;
    }


    qDebug()
        << "[GPS LED] gpiochip2 line 40 requested successfully";


    return true;
}


// ============================================================
// GPIO SET
// ============================================================

void EventLoggerStatusLED::setGPIO(
    gpiod_line *line,
    bool state)
{
    if (!line)
    {
        qWarning()
        << "[LED] setGPIO(): NULL GPIO line";

        return;
    }


    const int value =
        state ? 1 : 0;


    const int ret =
        gpiod_line_set_value(
            line,
            value);


    if (ret < 0)
    {
        qWarning()
        << "[LED] gpiod_line_set_value() FAILED"
        << "state ="
        << state;
    }
}


// ============================================================
// VC IP STATUS
//
// VC reachable
//      -> LED continuously ON
//
// VC unreachable
//      -> LED BLINK every 500 ms
// ============================================================

void EventLoggerStatusLED::SetVCIPStatus(bool status)
{
    m_vcOK = status;


    // =========================================================
    // VC REACHABLE
    // =========================================================

    if (status)
    {
        // Stop blinking
        if (m_vcLedTimer)
        {
            m_vcLedTimer->stop();
        }


        // Reset state
        m_vcLedState = true;


        // LED continuously ON
        setGPIO(
            m_vcLed,
            true);


        qDebug()
            << "[LED] VC IP: REACHABLE -> LED ON";
    }


    // =========================================================
    // VC UNREACHABLE
    // =========================================================

    else
    {
        // Start blinking if not already running
        if (m_vcLedTimer &&
            !m_vcLedTimer->isActive())
        {
            // Start from OFF
            m_vcLedState = false;

            setGPIO(
                m_vcLed,
                false);


            m_vcLedTimer->start();


            qWarning()
                << "[LED] VC IP: UNREACHABLE -> LED BLINKING";
        }
    }


    // Update Fault LED
    updateFaultLED();
}


// ============================================================
// GPS STATUS
//
// 0x03 = VALID GPS FIX
//
// 0x00 = NO FIX
// 0x01 = ESTIMATED / DEAD RECKONING
//
// GPS LED:
//
// 0x03
//     GPS LED continuously ON
//
// Anything else
//     GPS LED BLINKS every 500 ms
//
// Fault LED:
//
// 0x03
//     GPS healthy
//
// Anything else
//     GPS fault
// ============================================================

void EventLoggerStatusLED::SetGPSStatus(
    quint8 status)
{
    m_gpsOK =
        (status == 0x03);


    qDebug()
        << "[LED] GPS:"
        << (m_gpsOK ? "OK" : "FAULT")
        << "Status ="
        << QString("0x%1")
               .arg(
                   status,
                   2,
                   16,
                   QChar('0'))
               .toUpper();


    // =========================================================
    // VALID GPS FIX
    //
    // GPS LED = continuously ON
    // =========================================================

    if (m_gpsOK)
    {
        if (m_gpsLedTimer)
        {
            m_gpsLedTimer->stop();
        }


        m_gpsLedState = true;


        setGPIO(
            m_gpsLed,
            true);


        qDebug()
            << "[GPS LED] VALID FIX -> ON";
    }


    // =========================================================
    // NO FIX / ESTIMATED
    //
    // GPS LED = BLINK
    // =========================================================

    else
    {
        // Start from OFF
        if (!m_gpsLedTimer ||
            !m_gpsLedTimer->isActive())
        {
            m_gpsLedState = false;

            setGPIO(
                m_gpsLed,
                false);
        }


        if (m_gpsLedTimer &&
            !m_gpsLedTimer->isActive())
        {
            m_gpsLedTimer->start();

            qDebug()
                << "[GPS LED] NO VALID FIX -> BLINK STARTED";
        }
    }


    // =========================================================
    // UPDATE FAULT LED
    // =========================================================

    updateFaultLED();
}


// ============================================================
// GSM STATUS
//
// true  -> GSM healthy
// false -> GSM fault
// ============================================================

void EventLoggerStatusLED::SetGSMStatus(
    bool status)
{
    m_gsmOK = status;


    qDebug()
        << "[LED] GSM:"
        << (status ? "OK" : "FAULT");


    updateFaultLED();
}

// ============================================================
// EVENT DATA RECEIVED
//
// Any valid EventLogger/Kavach packet received:
//
//     Event LED = ON
//
// LED remains ON for 1 second after the latest packet.
//
// Every new packet restarts the timer.
// ============================================================

void EventLoggerStatusLED::EventDataReceived()
{
    if (!m_eventLed)
    {
        qWarning()
        << "[LED] EventDataReceived(): Event LED NULL";

        return;
    }


    // =========================================================
    // TURN EVENT LED ON
    // =========================================================

    setGPIO(
        m_eventLed,
        true);


    // =========================================================
    // RESTART 1-SECOND TIMER
    //
    // Every new packet restarts the timer.
    //
    // Therefore LED stays ON while data continues arriving.
    // =========================================================

    if (m_eventLedTimer)
    {
        m_eventLedTimer->start();
    }


    qDebug()
        << "[LED] Event Logging -> DATA RECEIVED";
}

// ============================================================
// VC IP LED TIMER
//
// Every 500 ms:
//
//      OFF -> ON
//      ON  -> OFF
//
// Used only when VC is unreachable.
// ============================================================

void EventLoggerStatusLED::VCIPLedTimeout()
{
    // Safety check
    if (m_vcOK)
    {
        if (m_vcLedTimer)
        {
            m_vcLedTimer->stop();
        }

        m_vcLedState = true;

        setGPIO(
            m_vcLed,
            true);

        return;
    }


    // Toggle LED
    m_vcLedState =
        !m_vcLedState;


    qDebug()
        << "[VC LED] TIMER TIMEOUT"
        << "State ="
        << m_vcLedState;


    setGPIO(
        m_vcLed,
        m_vcLedState);
}


// ============================================================
// EVENT LED TIMEOUT
// ============================================================

void EventLoggerStatusLED::EventLedTimeout()
{
    qDebug()
    << "[LED] Event Logging -> OFF";


    setGPIO(
        m_eventLed,
        false);
}


// ============================================================
// FAULT LED LOGIC
//
// VC healthy + GPS healthy + GSM healthy
//              -> Fault LED OFF
//
// Any one unhealthy
//              -> Fault LED BLINK
//
// Blink interval = 500 ms
// ============================================================

void EventLoggerStatusLED::updateFaultLED()
{
    const bool fault =
        !m_vcOK ||
        !m_gpsOK ||
        !m_gsmOK;


    qDebug()
        << "[FAULT LED]"
        << "VC ="
        << m_vcOK
        << "GPS ="
        << m_gpsOK
        << "GSM ="
        << m_gsmOK
        << "FAULT ="
        << fault;


    // =========================================================
    // FAULT
    // =========================================================

    if (fault)
    {
        if (m_faultLedTimer &&
            !m_faultLedTimer->isActive())
        {
            qDebug()
            << "[FAULT LED] Starting blink timer";


            m_faultLedState = false;


            setGPIO(
                m_faultLed,
                false);


            m_faultLedTimer->start();


            qDebug()
                << "[FAULT LED] Timer active ="
                << m_faultLedTimer->isActive()
                << "interval ="
                << m_faultLedTimer->interval();
        }
    }


    // =========================================================
    // NO FAULT
    // =========================================================

    else
    {
        qDebug()
        << "[FAULT LED] All healthy - LED OFF";


        if (m_faultLedTimer)
        {
            m_faultLedTimer->stop();
        }


        m_faultLedState = false;


        setGPIO(
            m_faultLed,
            false);
    }
}


// ============================================================
// FAULT LED TIMER
//
// Every 500 ms:
//
//     OFF -> ON
//     ON  -> OFF
// ============================================================

void EventLoggerStatusLED::FaultLedTimeout()
{
    qDebug()
    << "[FAULT LED] TIMER TIMEOUT";


    m_faultLedState =
        !m_faultLedState;


    qDebug()
        << "[FAULT LED] State ="
        << m_faultLedState;


    setGPIO(
        m_faultLed,
        m_faultLedState);
}


// ============================================================
// GPS LED TIMER
//
// Every 500 ms:
//
//     OFF -> ON
//     ON  -> OFF
//
// This timer is active only when GPS does not have
// a valid fix (status != 0x03).
// ============================================================

void EventLoggerStatusLED::GPSLedTimeout()
{
    qDebug()
    << "[GPS LED] TIMER TIMEOUT";


    m_gpsLedState =
        !m_gpsLedState;


    qDebug()
        << "[GPS LED] State ="
        << m_gpsLedState;


    setGPIO(
        m_gpsLed,
        m_gpsLedState);
}