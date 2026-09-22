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
    void SetVCIPStatus(bool status);
    void SetGPSStatus(quint8 status);
    void SetGSMStatus(bool status);
    void EventDataReceived();

private slots:
    void EventLedTimeout();
    void FaultLedTimeout();

private:
    bool initializeGPIO();
    void setGPIO(gpiod_line *line, bool state);
    void updateFaultLED();

private:
    gpiod_chip *m_gpioChip;

    gpiod_line *m_vcLed;
    gpiod_line *m_eventLed;
    gpiod_line *m_faultLed;

    QTimer *m_eventLedTimer;
    QTimer *m_faultLedTimer;

    bool m_vcOK;
    bool m_gpsOK;
    bool m_gsmOK;

    bool m_faultLedState;
};

#endif