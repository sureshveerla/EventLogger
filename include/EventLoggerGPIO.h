#ifndef EVENTLOGGERGPIO_H
#define EVENTLOGGERGPIO_H

#include <QObject>
#include <QMap>
#include <QPair>
#include <QString>
#include <QSettings>
#include <QTimer>
#include <QSerialPort>
#include <QProcess>
#include <QByteArray>

extern "C"
{
#include <gpiod.h>
}

// ============================================================================
// EventLoggerGPIO
// ============================================================================
//
// Drives 3 status LEDs for the ELU:
//
//   GPS_Fix     -> physical GPIO line (libgpiod)   -> gpiochip2 / offset 40
//   VCOM_Ping   -> physical GPIO line (libgpiod)   -> gpiochip1 / offset 2
//   GSM_Status  -> NOT a SoM GPIO line. It is driven remotely through the
//                  LARA modem's own GPIO16, over AT+UGPIOC on /dev/ttyS1.
//
// LED semantics (per requirement):
//
//   GPS_Fix    : Fix available      -> STABLE ON
//                No fix / no data   -> BLINK
//
//   VCOM_Ping  : VC_IP reachable    -> BLINK
//                VC_IP unreachable  -> STABLE ON
//
//   GSM_Status : SIM + Network + Signal all OK -> STABLE   (AT+UGPIOC=16,0,0)
//                Any of them failing            -> BLINK   (AT+UGPIOC=16,0,1)
//
//                IMPORTANT hardware note: on this board, commanding the LARA
//                GPIO16 HIGH (AT+UGPIOC=16,0,1) makes the LED blink BY ITSELF
//                at the hardware level - it is NOT toggled by software here.
//                Commanding it LOW (AT+UGPIOC=16,0,0) is what gives a stable
//                LED. So for GSM we send the command ONCE per state change;
//                there is no GSM blink QTimer.
//
// GPS is read directly on /dev/ttyS0 (NMEA GGA sentences) inside this class.
//
// ============================================================================

class EventLoggerGPIO : public QObject
{
    Q_OBJECT

public:
    explicit EventLoggerGPIO(
        QSettings *pcCfgSettings,
        QObject *pcParent = nullptr);

    ~EventLoggerGPIO() override;

    bool Init();

    // Generic line access (used for GPS_Fix / VCOM_Ping only)
    bool RequestLine(
        const QString &strLogicalName,
        bool bInitialValue);

    bool WriteLine(
        const QString &strLogicalName,
        bool bValue);

    bool SetLine(
        const QString &strLogicalName,
        bool bValue);

    void ReleaseAll();

    // ------------------------------------------------------------------
    // GPS (kept public: still callable externally if some other module
    // wants to force a status, but normally driven internally now from
    // the /dev/ttyS0 NMEA parser)
    // ------------------------------------------------------------------
    void SetGPSFixStatus(bool fixed);

    void UpdateGPSStatus(
        bool uartOk,
        int fixQuality,
        int satellites);

    // ------------------------------------------------------------------
    // VC Ping
    // ------------------------------------------------------------------
    void SetVCOMPingStatus(bool reachable);

    // ------------------------------------------------------------------
    // GSM
    // ------------------------------------------------------------------
    void SetGSMStatus(bool ok);

    // ------------------------------------------------------------------
    // Bring-up / wiring diagnostic helper.
    //
    // Cycles every gpiod-backed LED (GPS_Fix, VCOM_Ping) ON for
    // uiOnMs then OFF, logging the LOGICAL value requested and the
    // RAW physical line level read back via gpiod_line_get_value().
    //
    // Use this once during hardware bring-up to confirm the ActiveLow
    // flag in the [GPIO] config section matches how each LED is wired.
    // If the LED does not light when this logs "logical ON", flip
    // <Name>_ActiveLow in the ini file.
    // ------------------------------------------------------------------
    void RunLedSelfTest(int uiOnMs = 500);

private:
    struct GpioLine
    {
        QString strSodimmLabel;
        QString strChipPath;
        unsigned int uiLineOffset = 0;
        bool bActiveLow = false;

        gpiod_chip *pChip = nullptr;
        gpiod_line *pLine = nullptr;
    };

    static const QMap<QString, QPair<QString, unsigned int>> s_kSodimmMap;

    QSettings *m_pcCfgSettings = nullptr;

    QMap<QString, GpioLine> m_ocLines;

    // Reads back the actual physical level of a requested line and logs
    // a warning if it does not match what was just written (accounting
    // for ActiveLow). Called from SetLine()/WriteLine().
    void LogLineState(
        const QString &strLogicalName,
        bool bRequestedLogicalValue);

    // ------------------------------------------------------------------
    // GPS
    // ------------------------------------------------------------------
    QSerialPort *m_pGPSSerial = nullptr;
    QByteArray m_ocGPSRxBuffer;

    QTimer m_GPSBlinkTimer;
    QTimer m_GPSWatchdogTimer;

    bool m_bGPSFix = false;
    bool m_bGPSLedState = false;

    bool m_bGPSUartOk = false;
    int m_iGPSFixQuality = 0;
    int m_iGPSSatellites = 0;

    void StartGPSMonitoring();
    bool OpenGPSUART();

    bool ParseGGA(
        const QString &strSentence,
        int &iFixQuality,
        int &iSatellites) const;

    void StartGPSBlink();
    void StopGPSBlink(bool bFinalState);

private slots:
    void onGPSReadyRead();
    void onGPSBlinkTimeout();
    void onGPSWatchdogTimeout();

    // --------------------------------------------------------------------
    // GSM
    // --------------------------------------------------------------------
private:
    QSerialPort *m_pGSMSerial = nullptr;

    QTimer m_GSMCheckTimer;

    bool m_bGSMUartOk = false;
    bool m_bGSMSimOk = false;
    bool m_bGSMNetworkOk = false;
    bool m_bGSMSignalOk = false;
    bool m_bGSMOverallOk = false;

    bool m_bGSMLedCommandedOn = false; // true == last command sent was "stable" (LOW)

    int m_iGSMRSSI = -1;
    int m_iGSMBER = -1;

    void StartGSMMonitoring();
    bool OpenGSMUART();

    bool SendGSMCommand(
        const QByteArray &command,
        QByteArray &response,
        int timeoutMs);

    bool CheckGSMUART();
    bool CheckGSMSIM();
    bool CheckGSMNetwork();
    bool CheckGSMsignal();

    void EvaluateGSMStatus();

    // Sends the AT+UGPIOC command ONCE for the requested state.
    // bStable = true  -> AT+UGPIOC=16,0,0 (LOW  -> hardware stable)
    // bStable = false -> AT+UGPIOC=16,0,1 (HIGH -> hardware auto-blinks)
    void CommandGSMLed(bool bStable);

private slots:
    void onGSMCheckTimeout();

    // --------------------------------------------------------------------
    // VC Ping
    // --------------------------------------------------------------------
private:
    QString m_strVCIP;

    QProcess *m_pPingProcess = nullptr;

    QTimer m_VCPingTimer;
    QTimer m_VCBlinkTimer;

    bool m_bVCReachable = false;
    bool m_bVCLedState = false;

    void StartVCPingMonitoring();

    void StartVCBlink();
    void StopVCBlink(bool bFinalState);

private slots:
    void onVCPingTimeout();
    void onPingFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void onPingError(QProcess::ProcessError error);
    void onVCBlinkTimeout();
};

#endif // EVENTLOGGERGPIO_H