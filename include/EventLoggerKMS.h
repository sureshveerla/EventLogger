/*******************************************************************************
 * File    : EventLoggerKMS.h
 * Purpose : Key Management System (KMS) Communication — ELU Side
 *
 * ICD Reference: Section D — Key Management System (KMS) Communication; Port 4447
 *
 * ARCHITECTURE:
 *   The ELU acts purely as a transparent gateway.
 *   - KMS packets from the Vital Controller (VC) are forwarded to KMS via GSM/GPRS.
 *   - KMS packets received from KMS are forwarded to the Vital Controller via UDP.
 *   - OTP received via SMS is encapsulated in a 0x96 packet and sent to VC via UDP.
 *   - Communication failures are reported to VC via 0x97 packet.
 *
 * CHANNEL CONFIG (from ICD §D.5–D.6):
 *   ELU-A: 192.168.10.10  port 4447  (Primary / default active)
 *   ELU-B: 192.168.10.11  port 4447  (Standby)
 *
 * PACKET FLOW (ICD §D.7):
 *   VC → ELU (UDP 4447) → KMS (GSM/GPRS):
 *     0x90 Identification  (raw, transparent)
 *     0x92 Auth Key Req    (raw, transparent)
 *     0x94 Auth Query      (raw, transparent)
 *
 *   KMS (GSM/GPRS) → ELU → VC (UDP 4447):
 *     0x91 ID Ack          (raw, transparent, within 2000ms)
 *     0x93 Auth Key        (raw, transparent, within 2000ms)
 *     0x95 Auth Key Status (raw, transparent, within 2000ms)
 *     0x96 OTP (built by ELU from SMS)
 *     0x97 Comm Failure (built by ELU on failure)
 *
 * RETRY (ICD §D.10):
 *   ELU performs max 3 UDP/SMS-level retries per message.
 *   Retries do NOT constitute KMS protocol retries (those are VC's job).
 *
 * Author  : SaNa Software
 * Date    : 2026
 ******************************************************************************/

#ifndef EVENTLOGGERKMS_H
#define EVENTLOGGERKMS_H

#include <QObject>
#include <QByteArray>
#include <QUdpSocket>
#include <QHostAddress>
#include <QSerialPort>
#include <QTimer>
#include <QDateTime>
#include <QtEndian>
#include "nmsQtInc.h"

extern "C" {
#include "crc32.h"
}

// ============================================================
//  ICD-defined KMS Packet SOF
// ============================================================
#define KMS_SOF1                    0xA5
#define KMS_SOF2                    0xC3

// ============================================================
//  ICD §D.7 — KMS Raw Message Types
// ============================================================
#define KMS_MSG_IDENTIFICATION          0x90   // VC → ELU → KMS
#define KMS_MSG_IDENTIFICATION_ACK      0x91   // KMS → ELU → VC
#define KMS_MSG_AUTH_KEY_REQ            0x92   // VC → ELU → KMS
#define KMS_MSG_AUTH_KEY                0x93   // KMS → ELU → VC
#define KMS_MSG_AUTH_QUERY              0x94   // VC → ELU → KMS
#define KMS_MSG_AUTH_KEY_STATUS         0x95   // KMS → ELU → VC
#define KMS_MSG_OTP                     0x96   // ELU → VC (built by ELU from SMS)
#define KMS_MSG_COMM_FAILURE            0x97   // ELU → VC (built by ELU on failure)

// ============================================================
//  ICD §D.8 — KAVACH Unit Types
// ============================================================
#define KMS_UNIT_STATIONARY             0x11
#define KMS_UNIT_ONBOARD                0x22
#define KMS_UNIT_TSRMS                  0x33

// ============================================================
//  ICD §D — SIM IDs
// ============================================================
#define KMS_SIM_PRIMARY                 0x01
#define KMS_SIM_SECONDARY               0x02

// ============================================================
//  ICD §D.8 — 0x91 Acknowledgement Status Codes
// ============================================================
#define KMS_ACK_OTP_SENT                0x01
#define KMS_ACK_ID_NOT_REGISTERED       0x02
#define KMS_ACK_MSG_DELIVERY_FAILED     0x03

// ============================================================
//  ICD §D.8 — 0x97 Failure Reason Codes
// ============================================================
#define KMS_FAIL_MODEM_GSM              0x11   // Modem/GSM failure
#define KMS_FAIL_SIM_REG                0x12   // SIM/Registration failure
#define KMS_FAIL_SIGNAL_THRESHOLD       0x13   // Signal below threshold
#define KMS_FAIL_GPRS_NETWORK           0x21   // GPRS/Network failure
#define KMS_FAIL_NO_KMS_RESPONSE        0x22   // No response from KMS (timeout)
#define KMS_FAIL_SMS_OTP                0x31   // SMS/OTP failure
#define KMS_FAIL_ELU_INTERNAL           0x41   // ELU internal error

// ============================================================
//  UDP Transport (ICD §D.1, §D.5)
// ============================================================
#define KMS_UDP_PORT                    4447

// ============================================================
//  CSQ Signal Thresholds
// ============================================================
#define KMS_CSQ_EXCELLENT               31
#define KMS_CSQ_GOOD_MIN                19
#define KMS_CSQ_OK_MIN                  14
#define KMS_CSQ_MARGINAL_MIN            9
#define KMS_CSQ_UNKNOWN                 99

// ============================================================
//  Signal Quality Enum
// ============================================================
enum class KMSSignalQuality {
    Excellent,
    Good,
    OK,
    Marginal,
    Unreachable,
    Unknown
};

// ============================================================
//  Channel Info
// ============================================================
struct KMSChannelConfig {
    QString      strLocalIP;      // ELU's own LAN IP on this channel
    QString      strVCIP;         // Vital Controller IP (VC side)
    quint16      usPort;          // UDP port ELU listens on for VC (4447)
    QString      strKMSServerIP;  // KMS Server IP  — RDSO confirmed SIM IP
    quint16      usKMSServerPort; // KMS Server Port — RDSO confirmed port
    quint8       ucSimID;         // SIM_PRIMARY or SIM_SECONDARY
    bool         bActive;         // true = active channel
};

// ============================================================
//  EventLoggerKMS Class
//
//  Implements ICD Section D — KMS gateway on the ELU side.
//  This class:
//   1. Receives raw KMS packets from VC (via UDP 4447) and forwards
//      them unchanged to KMS via GSM/GPRS modem.
//   2. Receives raw KMS packets from KMS (via GSM) and forwards them
//      unchanged to VC (via UDP 4447) within 2000ms.
//   3. Receives OTP via SMS, wraps it in a 0x96 packet, sends to VC.
//   4. Detects communication failures, builds 0x97, sends to VC.
//   5. Manages ELU-level UDP/SMS retries (max 3).
//   6. Reports signal strength; triggers 0x97 if below threshold.
// ============================================================
class EventLoggerKMS : public QObject
{
    Q_OBJECT

public:
    explicit EventLoggerKMS(QObject *parent = nullptr);
    ~EventLoggerKMS();

    // ── Initialization ────────────────────────────────────────
    // Call once after construction.
    // chanA / chanB: fill from Config.cfg
    // gsmPort: serial port connected to GSM modem (e.g. "/dev/ttyS2")
    bool Init(const KMSChannelConfig &chanA,
              const KMSChannelConfig &chanB,
              const QString          &gsmPort,
              qint32                  gsmBaud = 115200);

    // ── ELU Identity ─────────────────────────────────────────
    void SetKavachUnitInfo(quint8 ucUnitType, const quint8 ucUnitID[3]);

    // ── Public Packet Builders (for testing / external use) ──

    // Build ICD §D.8.3 — 0x96 OTP packet (for SMS-received OTP)
    QByteArray BuildOTPPacket(quint8        ucKavachUnitType,
                              const quint8  ucKavachUnitID[3],
                              quint8        ucSIMID,
                              const QString &strOTP);

    // Build ICD §D.8.8 — 0x97 KMS Communication Failure packet
    QByteArray BuildCommFailurePacket(quint8       ucKavachUnitType,
                                      const quint8 ucKavachUnitID[3],
                                      quint8       ucSIMID,
                                      quint8       ucFailureCode,
                                      quint8       ucRetryCount);

    // ── CRC Utilities ─────────────────────────────────────────
    static bool    ValidateCRC32(const QByteArray &packet, int crcStartOffset);
    static quint32 ComputeCRC32(const QByteArray &data, int startOffset, int length);

    // ── Signal Classification ─────────────────────────────────
    int              QueryCSQ();
    KMSSignalQuality ClassifyCSQ(int csq);

    // ── Status accessors for 0xA2 heartbeat ──────────────────
    // Return cached values — no AT command issued on call.
    int   GetLastCSQ()     const { return m_iLastCSQ; }
    bool  IsGSMRegistered()const { return m_bGSMRegistered; }
    // GSM status byte per ICD: 0=Not ready, 1=Registered, 2=Data active
    quint8 GetGSMStatus()  const { return m_ucGSMStatus; }
    static QString   SignalQualityString(KMSSignalQuality q);

    bool EnsureGPRSActive();

    QString SendATCommand(const QString &cmd, int timeoutMs = 2000);

    bool SendUDPViaGSM(const QByteArray &rawPacket,
                       const QString &destIP,
                       quint16 destPort);



signals:
    // Emitted when a packet is ready to be sent to VC via UDP
    void SigSendToVC(QByteArray packet, QHostAddress vcAddr, quint16 vcPort);

    // Emitted on channel changeover (ICD §D.11)
    void SigChannelChangeover(quint8 newSimID);

    // Emitted on CSQ update
    void SigCSQUpdated(int csqValue, KMSSignalQuality quality);

    // Emitted for logging / diagnostics
    void SigKMSPacketReceived(quint8 msgType, QByteArray packet);
    void SigKMSPacketSent(quint8 msgType, QByteArray packet);

public slots:
    // Called by UDP server when data arrives on port 4447 (from VC)
    void SlotHandleUDPFromVC(QByteArray datagram, QHostAddress senderIP, quint16 senderPort);

    // Periodic CSQ poll
    void SlotPollCSQ();

private slots:
    // Called when GSM serial has data (KMS response or SMS)
    void SlotHandleGSMData();

private:
    // ── GSM Modem ─────────────────────────────────────────────
    bool    InitGSMModem(const QString &portName, qint32 baudRate);

    // ── Packet Processing ─────────────────────────────────────
    // Validate SOF + CRC of an inbound KMS packet
    bool    IsValidKMSPacket(const QByteArray &packet);
    quint8  GetKMSMsgType(const QByteArray &packet);

    // Forward raw KMS packet from VC to KMS via GSM (transparent)
    void    ForwardToKMS(const QByteArray &rawPacket, quint8 msgType);

    // Forward raw KMS packet from KMS to VC via UDP (transparent, within 2000ms)
    void    ForwardToVC(const QByteArray &rawPacket);

    // Process OTP SMS and build+send 0x96 to VC
    void    ProcessOTPSms(const QString &smsText);

    // Build and send 0x97 failure packet to VC
    void    ReportFailureToVC(quint8 failureCode, quint8 retryCount);

    // Append 32-bit CCITT CRC to QByteArray (from crcStartOffset onwards)
    void    AppendCRC32(QByteArray &data, int crcStartOffset);

    // OTP extraction from SMS text
    bool    ExtractOTPFromSMS(const QString &smsText,
                           QString       &otpOut,
                           quint8        &simIDOut);

    bool IsModemReady() const
    {
        return m_bInitDone &&
               m_pGSMSerial != nullptr &&
               m_pGSMSerial->isOpen();
    }


    // In EventLoggerKMS.h private section:

    // ── Channel Management ────────────────────────────────────
    KMSChannelConfig &ActiveChannel();
    void SwitchChannel();

    void SlotReadLatestSMS();   // called after 0x91 to poll for new OTP SMS


    // ── Members ───────────────────────────────────────────────
    QSerialPort      *m_pGSMSerial;
    QUdpSocket       *m_pKmsUdpSocket = nullptr;
    QByteArray        m_gsmBuffer;
    QString          m_strCfgFilPath;


    QTimer           *m_pCSQTimer;

    // ELU identity (set from config)
    quint8  m_ucKavachUnitType;
    quint8  m_ucKavachUnitID[3];

    // Channel A = ELU-A (primary), Channel B = ELU-B (standby)
    KMSChannelConfig  m_chanA;
    KMSChannelConfig  m_chanB;
    bool              m_bUsingChanA;   // true = A active, false = B active

    // Last known VC address (from UDP sender field)
    QHostAddress      m_vcLastAddr;
    quint16           m_vcLastPort;

    bool              m_bInitDone;

    QTimer            *m_pOTPPollTimer;

    bool          m_bWaitingForOTP = false;
    QElapsedTimer m_otpWatchTimer;

    // ── Cached status — updated by SlotPollCSQ() ─────────────
    int               m_iLastCSQ     = -1;    // last AT+CSQ value (-1 = unknown)
    bool              m_bGSMRegistered = false; // true when AT+CREG says registered
    // 0=Not ready, 1=Registered (no data), 2=Data session active
    quint8            m_ucGSMStatus  = 0;

    int m_iCSQFailCount = 0;
    static constexpr int KMS_CSQ_FAIL_MAX = 3;
};

#endif // EVENTLOGGERKMS_H