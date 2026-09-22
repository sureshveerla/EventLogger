#include "EventLoggerGPS.h"

#include <QDebug>
#include <QDateTime>
#include <QTimeZone>
#include <QtMath>


// ============================================================================
// Constructor
// ============================================================================

EventLogger::EventLogger(QObject *parent)
    : QObject(parent),
    m_serial(nullptr)
{
    // ============================================================
    // GPS UART
    // ============================================================

    m_serial = new QSerialPort(this);

    m_serial->setPortName("/dev/ttyS0");

    m_serial->setBaudRate(QSerialPort::Baud9600);

    m_serial->setDataBits(QSerialPort::Data8);

    m_serial->setParity(QSerialPort::NoParity);

    m_serial->setStopBits(QSerialPort::OneStop);

    m_serial->setFlowControl(QSerialPort::NoFlowControl);


    // ============================================================
    // Open GPS UART
    // ============================================================

    if (!m_serial->open(QIODevice::ReadOnly))
    {
        qDebug()
        << "UART GPS not connected:"
        << m_serial->errorString();

        m_serial->deleteLater();

        m_serial = nullptr;

        return;
    }


    qDebug()
        << "==============================================";

    qDebug()
        << "UART GPS connected successfully";

    qDebug()
        << "Device :"
        << m_serial->portName();

    qDebug()
        << "Baud   :"
        << m_serial->baudRate();

    qDebug()
        << "==============================================";


    // ============================================================
    // GPS Ready Read
    // ============================================================

    connect(m_serial,
            &QSerialPort::readyRead,
            this,
            &EventLogger::readGPSData,
            Qt::QueuedConnection);
}


// ============================================================================
// Destructor
// ============================================================================

EventLogger::~EventLogger()
{
    // ============================================================
    // Close GPS UART
    // ============================================================

    if (m_serial)
    {
        if (m_serial->isOpen())
        {
            m_serial->close();
        }
    }
}


// ============================================================================
// Read GPS Data
// ============================================================================

void EventLogger::readGPSData()
{
    if (!m_serial)
        return;


    // ============================================================
    // Read available UART data
    // ============================================================

    QByteArray raw =
        m_serial->readAll();


    if (raw.isEmpty())
        return;


    m_buffer.append(raw);


    // ============================================================
    // Process complete NMEA lines
    // ============================================================

    while (m_buffer.contains('\n'))
    {
        int index =
            m_buffer.indexOf('\n');


        QByteArray line =
            m_buffer.left(index);


        // --------------------------------------------------------
        // Remove processed line including '\n'
        // --------------------------------------------------------

        m_buffer.remove(
            0,
            index + 1);


        // --------------------------------------------------------
        // Remove \r, spaces, etc.
        // --------------------------------------------------------

        line =
            line.trimmed();


        if (line.isEmpty())
            continue;


        // ========================================================
        // DEBUG - Print every NMEA sentence
        // ========================================================

        qDebug()
            << "[GPS RX]"
            << line;


        // ========================================================
        // RMC
        // ========================================================

        if (line.startsWith("$GPRMC") ||
            line.startsWith("$GNRMC"))
        {
            processRMC(line);
        }


        // ========================================================
        // GGA
        // ========================================================

        else if (line.startsWith("$GPGGA") ||
                 line.startsWith("$GNGGA"))
        {
            processGGA(line);
        }
    }
}


// ============================================================================
// Process RMC
//
// RMC format:
//
// $GNRMC,
//       [1] UTC Time
//       [2] Status A/V
//       [3] Latitude
//       [4] N/S
//       [5] Longitude
//       [6] E/W
//       [7] Speed in knots
//       [8] Course
//       [9] Date DDMMYY
//       ...
//
// ============================================================================

void EventLogger::processRMC(
    const QByteArray &line)
{
    QList<QByteArray> fields =
        line.split(',');


    // ============================================================
    // We need at least field[2] for A/V status
    // ============================================================

    if (fields.size() <= 2)
    {
        qDebug()
        << "[RMC] ERROR: Not enough fields";

        return;
    }


    // ============================================================
    // RMC Status
    // ============================================================

    QByteArray status =
        fields[2].trimmed();


    if (status == "A")
    {
        qDebug()
        << "[GPS] RMC: FIX";
    }
    else if (status == "V")
    {
        qDebug()
        << "[GPS] RMC: NO FIX";
    }
    else
    {
        qDebug()
        << "Unknown RMC status:"
        << status;
    }


    // ============================================================
    // If RMC does not have enough fields, stop here
    // ============================================================

    if (fields.size() <= 9)
    {
        qDebug()
        << "[RMC] WARNING: Not enough fields for"
        << "time/date/position";

        return;
    }


    // ============================================================
    // UTC Time
    // ============================================================

    QByteArray rawTime =
        fields[1].trimmed();


    // ============================================================
    // Date
    // ============================================================

    QByteArray rawDate =
        fields[9].trimmed();


    // ============================================================
    // Parse UTC Date + Time
    // ============================================================

    if (rawDate.length() == 6 &&
        rawTime.length() >= 6)
    {
        int day =
            rawDate.mid(0, 2).toInt();

        int month =
            rawDate.mid(2, 2).toInt();

        int year =
            2000 +
            rawDate.mid(4, 2).toInt();


        int hour =
            rawTime.mid(0, 2).toInt();

        int minute =
            rawTime.mid(2, 2).toInt();

        int second =
            rawTime.mid(4, 2).toInt();


        QDate date(
            year,
            month,
            day);


        QTime time(
            hour,
            minute,
            second);


        if (date.isValid() &&
            time.isValid())
        {
            QDateTime utcTime(
                date,
                time,
                QTimeZone::utc());


            QTimeZone istZone(
                "Asia/Kolkata");


            QDateTime istTime =
                utcTime.toTimeZone(
                    istZone);


            QString formattedUTC =
                utcTime.toString(
                    "yyyy-MM-dd HH:mm:ss");


            QString formattedIST =
                istTime.toString(
                    "yyyy-MM-dd HH:mm:ss");


            qDebug()
                << "GPS UTC:"
                << formattedUTC;

            qDebug()
                << "GPS IST:"
                << formattedIST;


            emit gpsUTCReady(
                utcTime);
        }
        else
        {
            qDebug()
            << "[RMC] ERROR: Invalid date/time";
        }
    }
    else
    {
        qDebug()
        << "[RMC] WARNING: Invalid date/time fields";
    }


    // ============================================================
    // Latitude / Longitude
    //
    // Only calculate valid position when RMC status = A
    // ============================================================

    if (status == "A" &&
        fields.size() > 6)
    {
        QByteArray latString =
            fields[3].trimmed();

        QByteArray latDirection =
            fields[4].trimmed();


        QByteArray lonString =
            fields[5].trimmed();

        QByteArray lonDirection =
            fields[6].trimmed();


        if (!latString.isEmpty() &&
            !latDirection.isEmpty() &&
            !lonString.isEmpty() &&
            !lonDirection.isEmpty())
        {
            bool latOK = false;

            bool lonOK = false;


            double rawLat =
                latString.toDouble(
                    &latOK);


            double rawLon =
                lonString.toDouble(
                    &lonOK);


            if (latOK && lonOK)
            {
                // ------------------------------------------------
                // Latitude
                //
                // NMEA format:
                // DDMM.MMMM
                // ------------------------------------------------

                int latDeg =
                    static_cast<int>(
                        rawLat / 100.0);


                double latMin =
                    rawLat -
                    (latDeg * 100.0);


                double dLat =
                    latDeg +
                    (latMin / 60.0);


                if (latDirection == "S")
                    dLat = -dLat;


                // ------------------------------------------------
                // Longitude
                //
                // DDDMM.MMMM
                // ------------------------------------------------

                int lonDeg =
                    static_cast<int>(
                        rawLon / 100.0);


                double lonMin =
                    rawLon -
                    (lonDeg * 100.0);


                double dLon =
                    lonDeg +
                    (lonMin / 60.0);


                if (lonDirection == "W")
                    dLon = -dLon;


                qDebug()
                    << "GPS Latitude :"
                    << dLat;


                qDebug()
                    << "GPS Longitude:"
                    << dLon;


                emit gpsPositionReady(
                    dLat,
                    dLon,
                    true);
            }
            else
            {
                qDebug()
                << "[RMC] ERROR: Invalid Lat/Lon";
            }
        }
        else
        {
            qDebug()
            << "[RMC] WARNING: Lat/Lon fields empty";
        }
    }
    else if (status == "V")
    {
        // --------------------------------------------------------
        // No valid RMC position
        // --------------------------------------------------------

        emit gpsPositionReady(
            0.0,
            0.0,
            false);
    }


    // ============================================================
    // Ground Speed
    //
    // RMC field[7] = speed over ground in knots
    //
    // 1 knot = 514.4444 mm/s
    // ============================================================

    if (status == "A" &&
        fields.size() > 7 &&
        !fields[7].trimmed().isEmpty())
    {
        bool speedOK = false;


        double speedKnots =
            fields[7]
                .trimmed()
                .toDouble(
                    &speedOK);


        if (speedOK)
        {
            qint32 speedMMps =
                static_cast<qint32>(
                    qRound(
                        speedKnots *
                        514.4444));


            qDebug()
                << "GPS Speed:"
                << speedKnots
                << "knots ="
                << speedMMps
                << "mm/s";


            emit gpsSpeedReady(
                speedMMps);
        }
        else
        {
            qDebug()
            << "[RMC] ERROR: Invalid speed";
        }
    }
}


// ============================================================================
// Process GGA
//
// GGA format:
//
// $GNGGA,
//       [1] UTC Time
//       [2] Latitude
//       [3] N/S
//       [4] Longitude
//       [5] E/W
//       [6] Fix Quality
//       [7] Number of Satellites
//       [8] HDOP
//       ...
//
// Fix Quality:
//
// 0 = Invalid / No Fix
// 1 = GPS Fix
// 2 = DGPS Fix
// 3 = PPS Fix
// 4 = RTK Fixed
// 5 = RTK Float
// 6 = Estimated / Dead Reckoning
//
// ============================================================================

void EventLogger::processGGA(
    const QByteArray &line)
{
    QList<QByteArray> fields =
        line.split(',');


    // ============================================================
    // Need field[6] = Fix Quality
    // ============================================================

    if (fields.size() <= 6)
    {
        qDebug()
        << "[GGA] ERROR: Not enough fields";

        // --------------------------------------------------------
        // No valid GGA
        //
        // GPS status = NO FIX
        // --------------------------------------------------------

        emit gpsFixStatusReady(0x00);

        return;
    }


    // ============================================================
    // Fix Quality
    // ============================================================

    bool ok = false;


    int fixQuality =
        fields[6]
            .trimmed()
            .toInt(&ok);


    // ============================================================
    // Invalid / empty Fix Quality
    // ============================================================

    if (!ok)
    {
        qDebug()
        << "[GPS] INVALID FIX QUALITY";

        emit gpsFixStatusReady(0x00);

        return;
    }


    // ============================================================
    // Number of Satellites
    //
    // GGA field[7]
    // ============================================================

    int satellites = 0;


    if (fields.size() > 7)
    {
        satellites =
            fields[7]
                .trimmed()
                .toInt();
    }


    // ============================================================
    // HDOP
    //
    // GGA field[8]
    // ============================================================

    double hdop = 0.0;


    if (fields.size() > 8)
    {
        hdop =
            fields[8]
                .trimmed()
                .toDouble();
    }


    // ============================================================
    // GPS FIX DECISION
    //
    // FIX:
    //     Fix Quality 1..5
    //     AND satellites > 0
    //
    // NO FIX:
    //     Fix Quality 0
    //     OR 6
    //     OR satellites == 0
    //
    // IMPORTANT:
    //     This class ONLY reports GPS status.
    //
    //     EventLoggerStatusLED controls SODIMM_212.
    // ============================================================

    bool gpsFixAvailable =
        (fixQuality >= 1 &&
         fixQuality <= 5 &&
         satellites > 0);


    if (gpsFixAvailable)
    {
        qDebug()
        << "[GPS] FIX AVAILABLE"
        << "| Quality:"
        << fixQuality
        << "| Satellites:"
        << satellites
        << "| HDOP:"
        << hdop;
    }
    else
    {
        qDebug()
        << "[GPS] NO FIX"
        << "| Quality:"
        << fixQuality
        << "| Satellites:"
        << satellites
        << "| HDOP:"
        << hdop;
    }


    // ============================================================
    // Existing ICD Fix Status
    // ============================================================

    quint8 icdFixStatus =
        0x00;


    // ------------------------------------------------------------
    // No Fix
    // ------------------------------------------------------------

    if (fixQuality == 0)
    {
        icdFixStatus =
            0x00;


        qDebug()
            << "[GPS] NO FIX | SAT:"
            << satellites
            << "| HDOP:"
            << hdop;
    }


    // ------------------------------------------------------------
    // Estimated / Dead Reckoning
    // ------------------------------------------------------------

    else if (fixQuality == 6)
    {
        icdFixStatus =
            0x01;


        qDebug()
            << "[GPS] ESTIMATED | SAT:"
            << satellites
            << "| HDOP:"
            << hdop;
    }


    // ------------------------------------------------------------
    // Valid Fix
    //
    // 1 = GPS Fix
    // 2 = DGPS Fix
    // 3 = PPS Fix
    // 4 = RTK Fixed
    // 5 = RTK Float
    // ------------------------------------------------------------

    else if (fixQuality >= 1 &&
             fixQuality <= 5)
    {
        // Keep the existing ICD behavior:
        // 1..5 = 0x03

        icdFixStatus =
            0x03;


        qDebug()
            << "[GPS] FIX | SAT:"
            << satellites
            << "| HDOP:"
            << hdop;
    }


    // ------------------------------------------------------------
    // Unknown Fix Quality
    // ------------------------------------------------------------

    else
    {
        icdFixStatus =
            0x00;


        qDebug()
            << "[GPS] UNKNOWN | QUALITY:"
            << fixQuality
            << "| SAT:"
            << satellites
            << "| HDOP:"
            << hdop;
    }


    // ============================================================
    // Send ICD GPS Fix Status
    // ============================================================

    emit gpsFixStatusReady(
        icdFixStatus);
}