#ifndef EVENTLOGGERGPS_H
#define EVENTLOGGERGPS_H

#include <QObject>
#include <QSerialPort>
#include <QByteArray>
#include <QDateTime>


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

    // ============================================================
    // GPS Fix Status
    //
    // 0x00 = NO FIX
    // 0x01 = ESTIMATED / DEAD RECKONING
    // 0x03 = VALID FIX
    // ============================================================

    void gpsFixStatusReady(quint8 fixStatus);


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


    // ============================================================
    // GPS UART
    // ============================================================

    QSerialPort *m_serial;

    QByteArray m_buffer;
};

#endif // EVENTLOGGERGPS_H