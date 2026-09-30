#ifndef EVENTLOGGERGPS_H
#define EVENTLOGGERGPS_H

#include <QObject>
#include <QSerialPort>
#include <QByteArray>
#include <QDateTime>
#include <QElapsedTimer>
#include <QTimer>
#include <QSocketNotifier>


class EventLogger : public QObject
{
    Q_OBJECT

public:

    explicit EventLogger(QObject *parent = nullptr);

    ~EventLogger();


signals:

    // ============================================================
    // GPS signals
    // ============================================================

    void gpsUTCReady(const QDateTime &utcTime);

    void gpsPositionReady(double latitude,
                          double longitude,
                          bool valid);

    void gpsSpeedReady(qint32 speedMMps);

    void gpsTOWReady(quint32 tow);

    void gpsPPSStatusReady(bool valid);

    // ============================================================
    // GPS Fix Status
    //
    // 0x00 = NO FIX
    // 0x01 = ESTIMATED / DEAD RECKONING
    // 0x03 = VALID FIX
    // ============================================================

    void gpsFixStatusReady(quint8 fixStatus);

    void gpsFixStatus(quint8 fixStatus);

private slots:

    // ============================================================
    // GPS UART
    // ============================================================

    void readGPSData();


private:

    // ============================================================
    // GPS processing
    // ============================================================

    void processRMC(const QByteArray &line);

    void processGGA(const QByteArray &line);

    void processUBX(const QByteArray &packet);

    // ============================================================
    // PPS
    // ============================================================

    bool initPPS();

    void handlePPSEvent();

    void checkPPSTimeout();


    // ============================================================
    // GPS UART
    // ============================================================

    QSerialPort *m_serial;

    QByteArray m_buffer;

    // ============================================================
    // PPS GPIO
    // ============================================================

    // sysfs GPIO number of the PPS line (/sys/class/gpio/gpio17)
    // same value as PpsGpioLine=17 in the AT03 GNSS/PPS test config
    const int m_ppsGpioNumber = 17;

    int m_ppsFd = -1;

    QSocketNotifier *m_ppsNotifier = nullptr;

    QTimer *m_ppsTimeoutTimer = nullptr;

    QElapsedTimer m_ppsTimer;

    qint64 m_lastPpsTimeNs = 0;

    bool m_bHavePpsPulse = false;

    int m_ppsValidPulseCount = 0;

    bool m_bPPSValid = false;

    // PPS configuration
    const int m_ppsPulseCountRequired = 5;
    const int m_ppsPeriodNominalMs = 1000;
    const int m_ppsPeriodToleranceMs = 50;
};

#endif // EVENTLOGGERGPS_H