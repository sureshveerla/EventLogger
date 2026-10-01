#ifndef EVENTLOGGERGPS_H
#define EVENTLOGGERGPS_H

#include <QObject>
#include <QByteArray>
#include <QDateTime>
#include <QElapsedTimer>
#include <QSerialPort>
#include <QSocketNotifier>
#include <QTimer>

class EventLogger : public QObject
{
    Q_OBJECT

public:
    explicit EventLogger(QObject *parent = nullptr);
    ~EventLogger();

signals:
    void gpsTOWReady(quint32 iTOW);
    void gpsPPSStatusReady(bool valid);
    void gpsUTCReady(const QDateTime &utcTime);
    void gpsPositionReady(double latitude, double longitude, bool valid);
    void gpsSpeedReady(qint32 speedMMps);
    void gpsFixStatus(int status);
    void gpsFixStatusReady(quint8 status);

private slots:
    void readGPSData();
    void handlePPSEvent();
    void checkPPSTimeout();

private:
    bool initPPS();

    void processUBX(const QByteArray &packet);
    void processRMC(const QByteArray &line);
    void processGGA(const QByteArray &line);

private:
    // GPS UART
    QSerialPort *m_serial = nullptr;
    QByteArray m_buffer;

    // PPS
    int m_ppsGpioNumber = -1;
    int m_ppsFd = -1;

    QSocketNotifier *m_ppsNotifier = nullptr;
    QTimer *m_ppsTimeoutTimer = nullptr;
    QElapsedTimer m_ppsTimer;

    bool m_bHavePpsPulse = false;
    qint64 m_lastPpsTimeNs = 0;
    int m_ppsValidPulseCount = 0;
    bool m_bPPSValid = false;

    // These should retain your existing configured values if your
    // original header already initializes them elsewhere.
    int m_ppsPulseCountRequired = 3;
    int m_ppsPeriodNominalMs = 1000;
    int m_ppsPeriodToleranceMs = 100;

    // ------------------------------------------------------------
    // GNSS state
    // ------------------------------------------------------------
    bool m_gpsFixAvailable = false;
    int m_gpsFixQuality = 0;
    int m_gpsSatellites = 0;
    double m_gpsHdop = 0.0;

    // Filtered status used by the 0xA2 heartbeat.
    // 1 = GNSS healthy
    // 0 = GNSS fault/no valid GNSS
    quint8 m_gpsfixstatus = 0;

    int m_gpsBadCount = 0;
    int m_gpsGoodCount = 0;

    static constexpr int GPS_BAD_CONFIRM_COUNT = 3;
    static constexpr int GPS_GOOD_CONFIRM_COUNT = 3;
};

#endif // EVENTLOGGERGPS_H
