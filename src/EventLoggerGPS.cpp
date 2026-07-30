#include "EventLoggerGPS.h"
#include "qdatetime.h"
#include "qtimezone.h"
#include <QDebug>

EventLogger::EventLogger(QObject *parent)
    : QObject(parent), m_serial(nullptr)
{
    m_serial = new QSerialPort(this);

    // 🔁 Change from USB to UART
    m_serial->setPortName("/dev/ttyS0");

    // 🔁 Match stty: 38400 baud
    m_serial->setBaudRate(QSerialPort::Baud38400);

    // Same defaults as stty
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);

    if(!m_serial->open(QIODevice::ReadOnly))
    {
        qDebug() << "UART GPS not connected:" << m_serial->errorString();
        m_serial->deleteLater();
        m_serial = nullptr;
        return;
    }

    qDebug() << "UART GPS connected successfully on /dev/ttyS0";

    connect(m_serial, &QSerialPort::readyRead,
            this, &EventLogger::readGPSData,
            Qt::QueuedConnection);


}

void EventLogger::readGPSData()
{
    if (!m_serial) return;

    QByteArray raw = m_serial->readAll();
    m_buffer.append(raw);


    while (m_buffer.contains('\n'))
    {
        int index = m_buffer.indexOf('\n');
        QByteArray line = m_buffer.left(index).trimmed();
        m_buffer.remove(0, index + 1);


        if (line.startsWith("$GPRMC") || line.startsWith("$GNRMC"))
        {
            QList<QByteArray> fields = line.split(',');

            if (fields.size() > 9)
            {
                QByteArray status = fields[2];  // A or V

                if (status == "A")
                {
                    qDebug() << "✅ GPS FIX AVAILABLE";

                    QByteArray rawTime = fields[1]; // hhmmss
                    QByteArray rawDate = fields[9]; // DDMMYY

                    if (rawDate.length() == 6 && rawTime.length() >= 6)
                    {
                        int day    = rawDate.mid(0,2).toInt();
                        int month  = rawDate.mid(2,2).toInt();
                        int year   = 2000 + rawDate.mid(4,2).toInt();
                        int hour   = rawTime.mid(0,2).toInt();
                        int minute = rawTime.mid(2,2).toInt();
                        int second = rawTime.mid(4,2).toInt();

                        QDateTime utcTime = QDateTime(QDate(year, month, day),
                                                      QTime(hour, minute, second),
                                                      QTimeZone::utc());

                        QTimeZone istZone("Asia/Kolkata");
                        QDateTime istTime = utcTime.toTimeZone(istZone);
                        QString formattedIST = istTime.toString("yyyy-MM-dd HH:mm:ss");

                        qDebug() << "GPS UTC:" << utcTime.toString("yyyy-MM-dd HH:mm:ss")
                                 << "GPS IST:" << formattedIST;

                      //  emit gpsBufferReady(formattedIST.toUtf8());
                        emit gpsUTCReady(utcTime);

                        // ── Parse Lat/Lon for 0x28 message ─────────────
                        // $GPRMC: field[3]=lat(ddmm.mmmm), [4]=N/S,
                        //         field[5]=lon(dddmm.mmmm), [6]=E/W
                        if (fields.size() > 6)
                        {
                            // Latitude: ddmm.mmmm → decimal degrees
                            double rawLat = fields[3].toDouble();
                            int    latDeg = static_cast<int>(rawLat / 100);
                            double latMin = rawLat - latDeg * 100.0;
                            double dLat   = latDeg + latMin / 60.0;
                            if (fields[4] == "S") dLat = -dLat;

                            // Longitude: dddmm.mmmm → decimal degrees
                            double rawLon = fields[5].toDouble();
                            int    lonDeg = static_cast<int>(rawLon / 100);
                            double lonMin = rawLon - lonDeg * 100.0;
                            double dLon   = lonDeg + lonMin / 60.0;
                            if (fields[6] == "W") dLon = -dLon;

                            emit gpsPositionReady(dLat, dLon, true);
                        }
                    }
                }
                else
                {
                    qDebug() << "❌ No GPS Fix yet (waiting for satellites...)";
                    emit gpsPositionReady(0.0, 0.0, false);
                }
            }
        }
    }
}