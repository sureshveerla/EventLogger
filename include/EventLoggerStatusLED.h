#ifndef EVENTLOGGERSTATUSLED_H
#define EVENTLOGGERSTATUSLED_H

#include <QObject>
#include <QTimer>
#include <QThread>

#include <gpiod.h>

class EventLoggerStatusLED : public QObject
{
    Q_OBJECT

public:
    explicit EventLoggerStatusLED(QObject *parent = nullptr);
    ~EventLoggerStatusLED();

public slots:

    void Start();

    // VC IP status
    void SetVCIPStatus(bool status);

    // GPS status
    void SetGPSStatus(quint8 status);

    // GSM status
    void SetGSMStatus(bool status);


    // Event data received
    void EventDataReceived();

private slots:

    void VCIPLedTimeout();
    void EventLedTimeout();
    void FaultLedTimeout();
    void GPSLedTimeout();

private:

    bool initializeGPIO();
    bool initializeGPSGPIO();

    void setGPIO(gpiod_line *line, bool state);
    void updateFaultLED();

private:

    // =========================================================
    // GPIO CHIP 1
    // =========================================================

    gpiod_chip *m_gpioChip;

    // SODIMM_208 -> gpiochip1 line 2
    gpiod_line *m_vcLed;

    // SODIMM_210 -> gpiochip1 line 3
    gpiod_line *m_eventLed;

    // SODIMM_212 -> gpiochip1 line 4
    gpiod_line *m_faultLed;


    // =========================================================
    // GPS LED
    // =========================================================

    // gpiochip2 line 40
    gpiod_chip *m_gpsGpioChip;
    gpiod_line *m_gpsLed;


    // =========================================================
    // TIMERS
    // =========================================================

    // VC LED blink timer
    QTimer *m_vcLedTimer;

    // Event LED timer
    QTimer *m_eventLedTimer;

    // Fault LED blink timer
    QTimer *m_faultLedTimer;

    // GPS LED blink timer
    QTimer *m_gpsLedTimer;


    // =========================================================
    // STATUS
    // =========================================================

    bool m_vcOK;
    bool m_gpsOK;
    bool m_gsmOK;


    // =========================================================
    // LED STATES
    // =========================================================

    bool m_vcLedState;
    bool m_faultLedState;
    bool m_gpsLedState;
};

#endif