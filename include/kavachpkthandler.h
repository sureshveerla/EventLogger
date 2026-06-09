#ifndef KAVACH_PKT_HANDLER_H
#define KAVACH_PKT_HANDLER_H

#include "nmsQtInc.h"
#include "QMutexLocker"
// #include "nmsCRC32.h"

extern "C" {
#include "crc32.h"
}


class KavachPktHandler : public QThread
{
    Q_OBJECT

public:
    explicit KavachPktHandler(QObject *pcParent = NULL);

    virtual ~KavachPktHandler();

    void run();

public slots:

    void enqueuePacket(QHostAddress senderIP, quint16 senderPort, QByteArray datagram);

signals:

    void logToDB(QString message);
    void updatePrompt(QString message);
    void sendAck(QHostAddress ip, quint16 port);
    void sendSMS(QString message);

    void SigNewFaultPacket(QHostAddress senderIP, quint16 senderPort,QByteArray datagram);
    void SigPreviousFaultInfo();

    void SigStationConnStatus();

private:

    QQueue<QHostAddress> m_queueIP;
    QQueue<quint16>      m_queuePort;
    QQueue<QByteArray>   m_queueData;


    bool m_running;
    QMutex m_mutex;
    QWaitCondition m_condition;

    static quint32 crc32(const uint8_t *data, size_t len);

};
#endif // KAVACH_PKT_HANDLER_H
