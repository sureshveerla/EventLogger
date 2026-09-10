#ifndef NMSUDPSERVER_H
#define NMSUDPSERVER_H

#include <QObject>
#include "nmsQtInc.h"
#include "nmsStructs.h"
#include "kavachpkthandler.h"
#include "EventLoggerKMS.h"      // ICD §D — KMS gateway

class nmsUDPServer : public QObject
{
    Q_OBJECT
public:

    explicit nmsUDPServer(QString strCfgFilePath,
                          QObject *pcParent = nullptr);
    virtual ~nmsUDPServer();

    KavachPktHandler *m_pcKavachPktHndlr;

    // ── KMS gateway (ICD §D) ─────────────────────────────────
    EventLoggerKMS   *m_pcKMS;        // created in InitKMS()
    QUdpSocket       *m_pcKMSSocket;  // bound to port 4447

    bool SendPacketViaGSM(const QByteArray &datagram);

signals:

    void SigNewFaultPacket(QHostAddress senderIP, quint16 senderPort, QByteArray datagram);
    void SigStationDisConnected(QString strSenderIP,bool bstatus);
    void SigConnected(QString strSenderIP, bool bstatus);

private slots:

    void SlotOnReadyRead(QUdpSocket *pcsocket);
    void StationConnStatus();
    void SlotKMSSendToVC(QByteArray packet, QHostAddress vcAddr, quint16 vcPort);

public slots:
    void SlotUpdateGPSTime(const QDateTime &gpsTime);

    void SendSNTPResponse(QUdpSocket *socket,
                          const QHostAddress &clientAddr,
                          quint16 clientPort,
                          const QByteArray &request); //SNTP

    QDateTime GetGPSTime();



public slots:

    void SlotSendAckEventLoggertoKavach(QHostAddress senderIP, quint16 senderPort,stNMStoKavach *pstAck);


private:

    QUdpSocket *m_pcSocket,
        *m_pcClntSock;

    QList<QHostAddress> m_ocaddressList;
    QList<QUdpSocket *> m_lstSockets;
    QStringList    m_strlstIPAddr,m_strlstPort;
    QString      m_strIPAddr,m_strPort;

    QQueue<QByteArray> m_datagramQueue;
    QMutex m_queueMutex;

    QMap<QString, QDateTime> m_lastPacketTime;

    QString m_strSenderIP, m_strCfgFilPath;

    quint16 m_usSenderPort ;

    QDateTime m_gpsDateTime;  //SNTP

    QString m_strGSMRelayIP;
    quint16 m_usGSMRelayPort = 0;

    void Init();
    void InitKMS(); // ICD §D — bind port 4447, create EventLoggerKMS, wire signals
};

#endif // NMSUDPSERVER_H