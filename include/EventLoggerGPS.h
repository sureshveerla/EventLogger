#ifndef EVENTLOGGERGPS_H
#define EVENTLOGGERGPS_H

#include <QObject>
#include <QSerialPort>
#include <QDateTime>


class EventLogger : public QObject
{
    Q_OBJECT

public:
    explicit EventLogger(QObject *parent = nullptr);

signals:

    void gpsUTCReady(const QDateTime &utcTime);

    void gpsPositionReady(
        double latitude,
        double longitude,
        bool valid
        );

    void gpsSpeedReady(qint32 speedMMps);

    void gpsFixStatusReady(quint8 fixStatus);

private slots:

    void readGPSData();

private:

    void processRMC(const QByteArray &line);

    void processGGA(const QByteArray &line);

private:

    QSerialPort *m_serial;

    QByteArray m_buffer;
};

#endif // EVENTLOGGERGPS_H