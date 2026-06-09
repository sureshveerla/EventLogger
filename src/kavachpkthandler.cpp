#include "kavachpkthandler.h"
#include "nmsStructs.h"
KavachPktHandler::KavachPktHandler(QObject *pcParent)
    : QThread(pcParent),
    m_running(true)
{

}

KavachPktHandler::~KavachPktHandler()
{
    QMutexLocker locker(&m_mutex);
    m_running = false;
    m_condition.wakeAll();
    locker.unlock();
    wait();
}

void KavachPktHandler::enqueuePacket(QHostAddress senderIP, quint16 senderPort, QByteArray datagram)
{
    QMutexLocker locker(&m_mutex);
    m_queueIP.enqueue(senderIP);
    m_queuePort.enqueue(senderPort);
    m_queueData.enqueue(datagram);

    m_condition.wakeOne();
}

void KavachPktHandler::run()
{
    while (true)
    {
        QMutexLocker locker(&m_mutex);
        while (m_queueData.isEmpty() && m_running)
        {
            bool btimedOut = !m_condition.wait(&m_mutex, 10000);
            if (btimedOut)
            {
                qDebug() << "[Thread] Timeout: No data received in 3 seconds.";
            }
            // else
            // {
            //   locker.unlock();
            emit SigStationConnStatus();
            //   locker.relock();
            // }
        }
        if (!m_running && m_queueData.isEmpty())
        {
            break;
        }

        if(!m_queueData.isEmpty() && m_running)
        {
            QHostAddress senderIP = m_queueIP.dequeue();
            quint16 senderPort = m_queuePort.dequeue();
            QByteArray data = m_queueData.dequeue();

            if (data.size() < 4)
            {
                emit logToDB("Invalid packet (too short) from: " + senderIP.toString());
                continue;
            }

            // QByteArray payload = data.mid(2/* data.size() - 6*/);
            QByteArray crcBytes = data.right(4);
            // quint16 crclength = data.size() -4;
            // QByteArray payload = data.mid(2);
            int startIndex = 2;
            int length = data.size() - startIndex - 4;

            if (length <= 0 || (startIndex + length) > data.size())
            {
                qWarning() << "Invalid payload length from:" << senderIP.toString()
                << "Size:" << data.size();
                continue;
            }
            QByteArray payload = data.mid(startIndex, length);

            // quint32 receivedCRC;
            // QDataStream stream(crcBytes);
            // stream.setByteOrder(QDataStream::BigEndian);
            // stream >> receivedCRC;

            // uint32_t uiRecvCRC;
            // memcpy(&uiRecvCRC,crcBytes.constData(),sizeof(uiRecvCRC));

            uint32_t receivedCRC = static_cast<uint8_t>(crcBytes[0]) << 24|
                                   (static_cast<uint8_t>(crcBytes[1]) << 16) |
                                   (static_cast<uint8_t>(crcBytes[2]) << 8) |
                                   (static_cast<uint8_t>(crcBytes[3]));

            // crc32 crcChecker;

            // quint32 calculatedCRC = crcChecker.get(payload.constData(), payload.size());

            uint32_t calculatedCRC = CalculateCRC32(payload.size(),
                                                    reinterpret_cast<const uint8_t*>(payload.constData()));
            uint32_t crc = qToBigEndian(calculatedCRC);

            if (receivedCRC != crc)
            {
                qDebug() << "CRC Mismatched :" << "receivedCRC "  << receivedCRC << "calculatedCRC " << calculatedCRC
                         << crc << payload.size();
                continue;
            }
            else
            {
                qDebug() << "CRC Matched:" << "receivedCRC "  << receivedCRC << "calculatedCRC " << calculatedCRC << crc;


                emit SigNewFaultPacket(senderIP,senderPort,data);
            }
        }
        else
        {
            bool btimedOut = !m_condition.wait(&m_mutex, 60000);
            if (btimedOut)
            {
                qDebug() << "[Thread] Timeout while idle.";
            }
        }
        //usleep(500);
    }
}

uint32_t KavachPktHandler::crc32(const uint8_t *data, size_t len)
{
    uint32_t crc = 0xFFFFFFFF;

    for (size_t i = 0; i < len; i++)
    {
        crc ^= data[i];

        for (int j = 0; j < 8; j++)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0xEDB88320;
            else
                crc >>= 1;
        }
    }
    return crc ^ 0xFFFFFFFF;
}

