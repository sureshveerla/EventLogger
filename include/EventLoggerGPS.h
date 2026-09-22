#ifndef EVENTLOGGERGPS_H
#define EVENTLOGGERGPS_H

#include <QObject>
#include <QSerialPort>
#include <QByteArray>
#include <QDateTime>
#include <QTimer>

#include <gpiod.h>


class EventLogger : public QObject
{
    Q_OBJECT

public:

    explicit EventLogger(QObject *parent = nullptr);

    ~EventLogger();


signals:

    // ============================================================
    // Existing GPS signals
    // ============================================================

    void gpsUTCReady(const QDateTime &utcTime);

    void gpsPositionReady(double latitude,
                          double longitude,
                          bool valid);

    void gpsSpeedReady(qint32 speedMMps);

    void gpsFixStatusReady(quint8 fixStatus);


private slots:

    // ============================================================
    // GPS UART
    // ============================================================

    void readGPSData();


    // ============================================================
    // GPS LED
    // ============================================================

    void toggleGPSLed();


private:

    // ============================================================
    // GPS processing
    // ============================================================

    void processRMC(const QByteArray &line);

    void processGGA(const QByteArray &line);


    // ============================================================
    // GPS UART
    // ============================================================

    QSerialPort *m_serial;

    QByteArray m_buffer;


    // ============================================================
    // GPS LED
    //
    // SODIMM_212
    // gpiochip2
    // offset 4
    //
    // HIGH = stable ON
    // LOW/HIGH toggle = blink
    // ============================================================

    gpiod_chip *m_gpsGpioChip;

    gpiod_line *m_gpsGpioLine;

    QTimer *m_gpsLedTimer;

    bool m_gpsLedState;


    // ============================================================
    // GPS LED functions
    // ============================================================

    bool initGPSLedGPIO();

    void setGPSLed(bool state);
};

#endif // EVENTLOGGERGPS_H