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
    m_gpioChip(nullptr),
    m_vcLed(nullptr),
    m_eventLed(nullptr),
    m_faultLed(nullptr),
    m_eventLedTimer(nullptr),
    m_faultLedTimer(nullptr),
    m_vcOK(false),
    m_gpsOK(false),
    m_gsmOK(false),
    m_faultLedState(false)
{
    qDebug() << "======================================";
    qDebug() << "EventLogger Status LED Initialization";
    qDebug() << "======================================";

    qDebug() << "[LED] Constructor entered";
    qDebug() << "[LED] Thread =" << QThread::currentThread();

    // ---------------------------------------------------------
    // GPIO
    // ---------------------------------------------------------

    if (!initializeGPIO())
    {
        qWarning() << "[LED] GPIO initialization FAILED";
        return;
    }

    qDebug() << "[LED] GPIO initialization completed";


    // ---------------------------------------------------------
    // Event LED timer
    // ---------------------------------------------------------

    m_eventLedTimer = new QTimer(this);
    m_eventLedTimer->setSingleShot(true);
    m_eventLedTimer->setInterval(1000);

    connect(m_eventLedTimer,
            &QTimer::timeout,
            this,
            &EventLoggerStatusLED::EventLedTimeout);

    qDebug() << "[LED] EVENT TIMER CREATED";


    // ---------------------------------------------------------
    // Fault LED timer
    // ---------------------------------------------------------

    m_faultLedTimer = new QTimer(this);
    m_faultLedTimer->setSingleShot(false);
    m_faultLedTimer->setInterval(500);

    connect(m_faultLedTimer,
            &QTimer::timeout,
            this,
            &EventLoggerStatusLED::FaultLedTimeout);

    qDebug() << "[LED] FAULT TIMER CREATED";


    // ---------------------------------------------------------
    // Initial state
    // ---------------------------------------------------------

    m_vcOK = false;
    m_gpsOK = false;
    m_gsmOK = false;

    m_faultLedState = false;

    setGPIO(m_vcLed, false);
    setGPIO(m_eventLed, false);
    setGPIO(m_faultLed, false);


    qDebug() << "[LED] GPIO initial states set";


    // ---------------------------------------------------------
    // IMPORTANT
    //
    // Do NOT start the timer here.
    // Start it after the Qt event loop begins.
    // ---------------------------------------------------------

    qDebug() << "[LED] Constructor completed";

    qDebug() << "[LED] VC IP LED     : SODIMM_208";
    qDebug() << "[LED] Event Logging : SODIMM_210";
    qDebug() << "[LED] Fault LED     : SODIMM_212";
}


// ============================================================
// Destructor
// ============================================================

EventLoggerStatusLED::~EventLoggerStatusLED()
{
    qDebug() << "[LED] EventLoggerStatusLED destructor called";


    // ---------------------------------------------------------
    // Stop timers
    // ---------------------------------------------------------

    if (m_eventLedTimer)
    {
        m_eventLedTimer->stop();
    }

    if (m_faultLedTimer)
    {
        qDebug() << "[LED] Fault timer active at destruction ="
                 << m_faultLedTimer->isActive();

        m_faultLedTimer->stop();
    }


    // ---------------------------------------------------------
    // Turn OFF and release VC LED
    // ---------------------------------------------------------

    if (m_vcLed)
    {
        gpiod_line_set_value(m_vcLed, 0);

        gpiod_line_release(m_vcLed);

        m_vcLed = nullptr;
    }


    // ---------------------------------------------------------
    // Turn OFF and release Event LED
    // ---------------------------------------------------------

    if (m_eventLed)
    {
        gpiod_line_set_value(m_eventLed, 0);

        gpiod_line_release(m_eventLed);

        m_eventLed = nullptr;
    }


    // ---------------------------------------------------------
    // Turn OFF and release Fault LED
    // ---------------------------------------------------------

    if (m_faultLed)
    {
        gpiod_line_set_value(m_faultLed, 0);

        gpiod_line_release(m_faultLed);

        m_faultLed = nullptr;
    }


    // ---------------------------------------------------------
    // Close GPIO chip
    // ---------------------------------------------------------

    if (m_gpioChip)
    {
        gpiod_chip_close(m_gpioChip);

        m_gpioChip = nullptr;
    }
}


void EventLoggerStatusLED::Start()
{
    qDebug() << "======================================";
    qDebug() << "[LED] Start() called";
    qDebug() << "[LED] Thread =" << QThread::currentThread();
    qDebug() << "[LED] Event dispatcher ="
             << QThread::currentThread()->eventDispatcher();
    qDebug() << "======================================";

    // Initial condition:
    //
    // VC  = false
    // GPS = false
    // GSM = false
    //
    // Therefore Fault LED must blink.

    updateFaultLED();

    qDebug() << "[LED] Start() completed";
}

// ============================================================
// GPIO INITIALIZATION
//
// SODIMM_208 -> gpiochip1 line 2
// SODIMM_210 -> gpiochip1 line 3
// SODIMM_212 -> gpiochip1 line 4
// ============================================================

bool EventLoggerStatusLED::initializeGPIO()
{
    qDebug() << "[LED] Opening /dev/gpiochip1";


    // ---------------------------------------------------------
    // Open GPIO chip
    // ---------------------------------------------------------

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


    // ---------------------------------------------------------
    // VC IP LED
    //
    // SODIMM_208
    // gpiochip1 line 2
    // ---------------------------------------------------------

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


    // ---------------------------------------------------------
    // Event Logging LED
    //
    // SODIMM_210
    // gpiochip1 line 3
    // ---------------------------------------------------------

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


    // ---------------------------------------------------------
    // Fault LED
    //
    // SODIMM_212
    // gpiochip1 line 4
    // ---------------------------------------------------------

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
// true  -> VC IP reachable -> LED ON
// false -> VC IP unreachable -> LED OFF
// ============================================================

void EventLoggerStatusLED::SetVCIPStatus(
    bool status)
{
    m_vcOK = status;


    setGPIO(
        m_vcLed,
        status);


    qDebug()
        << "[LED] VC IP:"
        << (status ? "ON" : "OFF");


    updateFaultLED();
}


// ============================================================
// GPS STATUS
//
// 0x03 = valid GPS fix
// Anything else = GPS fault
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
// LED remains ON for 1 second.
// ============================================================

void EventLoggerStatusLED::EventDataReceived()
{
    if (!m_eventLed)
    {
        qWarning()
        << "[LED] EventDataReceived(): Event LED NULL";

        return;
    }


    // ---------------------------------------------------------
    // Turn Event LED ON
    // ---------------------------------------------------------

    setGPIO(
        m_eventLed,
        true);


    // ---------------------------------------------------------
    // Restart 1-second timer
    //
    // Every new packet restarts the timer.
    // Therefore LED stays ON while data continues arriving.
    // ---------------------------------------------------------

    if (m_eventLedTimer)
    {
        m_eventLedTimer->start();
    }


    qDebug()
        << "[LED] Event Logging -> DATA RECEIVED";
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


    // ---------------------------------------------------------
    // FAULT
    // ---------------------------------------------------------

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


    // ---------------------------------------------------------
    // NO FAULT
    // ---------------------------------------------------------

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