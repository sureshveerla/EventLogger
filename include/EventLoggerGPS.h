#ifndef EVENTLOGGERGPS_H
#define EVENTLOGGERGPS_H

#include <QObject>
#include <QSerialPort>
#include <QByteArray>
#include <QDateTime>      // ← ADD THIS LINE

class EventLogger : public QObject
{
    Q_OBJECT

public:
    explicit EventLogger(QObject *parent = nullptr);

signals:
   // void gpsBufferReady(QByteArray buffer);
    void gpsUTCReady(QDateTime utcTime);

    // Emitted when a valid $GPRMC fix is parsed.
    // lat/lon in decimal degrees.  bValid = false when sentence status is 'V'.
    void gpsPositionReady(double dLat, double dLon, bool bValid);

private slots:
    void readGPSData();

private:
    QSerialPort *m_serial;
    QByteArray m_buffer;
};

#endif