
#ifndef _NMS_STRUCTS_H_
#define _NMS_STRUCTS_H_

#include "nmsQtInc.h"
#include "nmsEnum.h"
#define _LITTLE_ENDIAN_BYTE_ORDER_    0x00
#define _BIG_ENDIAN_BYTE_ORDER_       0x01

#define _BYTE_ORDER_                  _BIG_ENDIAN_BYTE_ORDER_

//#pragma pack(push,1)  // Ensure no padding between members
typedef struct stkavachtonms {

    quint16  usStartFrame;     // 0xA5, 0xC3
    quint8   ucMsgType;             // e.g., 0xFC
    quint16  usmsgLength;

    quint8  ucDay;
    quint8  ucMonth;
    quint8  ucYear;

    quint8  ucHour;
    quint8  ucMinute;
    quint8  ucSecond;

    quint8   ucKavachType;
    quint8   ucKavachSubsysID[3];      // 3-byte ID (hex representation)

    quint8   ucTotalFaultsCode;
    quint16  usFaultCodes[10];

    quint32  uiCRC;

}__attribute((packed)) stKavachtoNMS;
// #pragma pack(pop)

Q_DECLARE_METATYPE(stKavachtoNMS);

typedef struct stfaultentry
{
    quint8  ucModuleID;
    quint8  ucFaultType;
    quint16 usFaultCode;
} __attribute__((packed)) stFaultEntry;

Q_DECLARE_METATYPE(stFaultEntry)

typedef struct ststationfaults {

    quint16  usStartFrame;     // 0xAAAA, 0xC3
    quint8   ucMsgType;             // e.g., 0x19
    quint16  usmsgLength;
    quint16 usMsgSeq;
    quint8  ucKavachSubsysID[3];
    quint16 usNMSID;
    quint8  ucVersion;
    quint8  ucDate[3];        // dd mm yy
    quint8  ucTime[3];        // hh mm ss

    quint8   ucKavachType;
    quint8   ucTotalFaultsCode;

    stFaultEntry stFaults[10];
    quint32  uiCRC;

}__attribute((packed)) stStationFaults;

Q_DECLARE_METATYPE(stStationFaults);


typedef struct stnmstokavach {

    quint16  usStartFrame;     // 0xA5, 0xC3
    quint8   ucMsgType;             // e.g., 0xFC
    quint16  usmsgLength;
    quint16  usMsgSeq;
    quint16  usNMSSystemID;
    quint8   ucKavachSubsysID[3];      // 3-byte ID (hex representation)
    quint8   ucKavachType;
    quint32  uiCRC;

}__attribute((packed)) stNMStoKavach;

Q_DECLARE_METATYPE(stNMStoKavach);

typedef struct staccessrequestpkt {
    quint16 usStartFrame;     // 0xAAAA
    quint8  ucMsgType;        // 0x11
    quint16 usMsgLength;
    quint16 usMsgSeq;
    quint16 usStatKavachID;
    quint16 usNMSID;
    quint8  ucVersion;
    quint8  ucDate[3];        // dd mm yy
    quint8  ucTime[3];        // hh mm ss
    quint8  ucRadioType;      // 0xF1
    quint8  ucSOF1;           // 0xA5
    quint8  ucSOF2;           // 0xC3
    quint32 uiCRC;
} __attribute__((packed)) stAccessRequestPkt;
Q_DECLARE_METATYPE(stAccessRequestPkt);

typedef struct stpacketheader {
    quint16 usStartFrame;     // 0xAAAA
    quint8  ucMsgType;        // 0x15,0x16,0x11
    quint16 usMsgLength;
    quint16 usMsgSeq;
    quint16 usStatKavachID;
    quint16 usNMSID;
    quint8  ucVersion;
    quint8  ucDate[3];        // dd mm yy
    quint8  ucTime[3];        // hh mm ss
} __attribute__((packed)) stPacketHeader;
Q_DECLARE_METATYPE(stPacketHeader);

typedef struct stfieldeventdata {
    quint16 usStartFrame;     // 0xAAAA
    quint8  ucMsgType;        // 0x15,0x16,0x11
    quint16 usMsgLength;
    quint16 usMsgSeq;
    quint16 usStatKavachID;
    quint16 usNMSID;
    quint8  ucVersion;
    quint8  ucDate[3];        // dd mm yy
    quint8  ucTime[3];        // hh mm ss
    quint8  ucEvntCnt;
    quint16 usRelayAddr;
    quint8  ucRelayStatus;
    quint32 uiCRC;
} __attribute__((packed)) stFieldEventData;
Q_DECLARE_METATYPE(stFieldEventData);

typedef struct ststationrssimsg {
    quint16 usStartFrame;     // 0xAAAA
    quint8  ucMsgType;        // 0x21
    quint16 usMsgLength;
    quint16 usMsgSeq;
    quint16 usStatKavachID;
    quint16 usNMSID;
    quint8  ucVersion;
    quint8  ucDate[3];        // dd mm yy
    quint8  ucTime[3];        // hh mm ss
    quint8  ucLocoKavachID[3];
    quint8  ucOnBrdRadio1RSSISamCnt;
    quint16 usRefRFIDTag;
    quint8  ucAbsloc[3];
    quint16 usRSSIValue;
    quint8  ucOnBrdRadio2RSSISamCnt;
    quint16 usRefRFIDTag2;
    quint8  ucAbsloc2[3];
    quint16 usRSSIValue2;
    quint32 uiCRC;
} __attribute__((packed)) stStationRSSIMsg;
Q_DECLARE_METATYPE(stStationRSSIMsg);

typedef struct stStationaryKavachSysInfo {

    // ---------------- Header ----------------
    quint16 usStartFrame; // 0xAAAA
    quint8  ucMsgType;  // 0x1A
    quint16 usMsgLength;
    quint16 usMsgSeq;

    quint16 usStationKavachID;
    quint16 usNMSID;
    quint8  ucVersion;

    // ---------------- Date & Time ----------------
    quint8  ucDate[3];
    quint8  ucTime[3];

    // ---------------- System Status ----------------
    quint8  ucSystemCPUStatus;
    quint8  ucSystemHealth;
    quint8  ucPowerSupplyDiag;
    quint8  ucSystemComStatus;
    quint8  ucTimeSyncStatus;

    quint8  ucDIModuleBitmap;

    // ================= DI1 =================
    quint8  ucDI1_ModuleID;
    quint8  ucDI1_SlotID;
    quint8  ucDI1_ModuleStatus;
    quint32 uiDI1_CH_Value_1_32;
    quint32 uiDI1_CH_Value_33_64;
    quint32 uiDI1_CH_OK_1_32;
    quint32 uiDI1_CH_OK_33_64;

    // ================= DI2 =================
    quint8  ucDI2_ModuleID;
    quint8  ucDI2_SlotID;
    quint8  ucDI2_ModuleStatus;
    quint32 uiDI2_CH_Value_1_32;
    quint32 uiDI2_CH_Value_33_64;
    quint32 uiDI2_CH_OK_1_32;
    quint32 uiDI2_CH_OK_33_64;

    // ================= DI3 =================
    quint8  ucDI3_ModuleID;
    quint8  ucDI3_SlotID;
    quint8  ucDI3_ModuleStatus;
    quint32 uiDI3_CH_Value_1_32;
    quint32 uiDI3_CH_Value_33_64;
    quint32 uiDI3_CH_OK_1_32;
    quint32 uiDI3_CH_OK_33_64;

    // ================= DI4 =================
    quint8  ucDI4_ModuleID;
    quint8  ucDI4_SlotID;
    quint8  ucDI4_ModuleStatus;
    quint32 uiDI4_CH_Value_1_32;
    quint32 uiDI4_CH_Value_33_64;
    quint32 uiDI4_CH_OK_1_32;
    quint32 uiDI4_CH_OK_33_64;

    // ================= DI5 =================
    quint8  ucDI5_ModuleID;
    quint8  ucDI5_SlotID;
    quint8  ucDI5_ModuleStatus;
    quint32 uiDI5_CH_Value_1_32;
    quint32 uiDI5_CH_Value_33_64;
    quint32 uiDI5_CH_OK_1_32;
    quint32 uiDI5_CH_OK_33_64;

    // ================= RIU1 =================
    quint8  ucRIU1_ID;
    quint8  ucRIU1_CPUStatus;
    quint8  ucRIU1_SystemHealth;
    quint8  ucRIU1_CommStatus;
    quint32 uiRIU1_DI_State_1_32;
    quint32 uiRIU1_DI_Error_1_32;

    // ================= RIU2 =================
    quint8  ucRIU2_ID;
    quint8  ucRIU2_CPUStatus;
    quint8  ucRIU2_SystemHealth;
    quint8  ucRIU2_CommStatus;
    quint32 uiRIU2_DI_State_1_32;
    quint32 uiRIU2_DI_Error_1_32;

    // ================= RIU3 =================
    quint8  ucRIU3_ID;
    quint8  ucRIU3_CPUStatus;
    quint8  ucRIU3_SystemHealth;
    quint8  ucRIU3_CommStatus;
    quint32 uiRIU3_DI_State_1_32;
    quint32 uiRIU3_DI_Error_1_32;

    // ================= RIU4 =================
    quint8  ucRIU4_ID;
    quint8  ucRIU4_CPUStatus;
    quint8  ucRIU4_SystemHealth;
    quint8  ucRIU4_CommStatus;
    quint32 uiRIU4_DI_State_1_32;
    quint32 uiRIU4_DI_Error_1_32;

    // ================= RIU5 =================
    quint8  ucRIU5_ID;
    quint8  ucRIU5_CPUStatus;
    quint8  ucRIU5_SystemHealth;
    quint8  ucRIU5_CommStatus;
    quint32 uiRIU5_DI_State_1_32;
    quint32 uiRIU5_DI_Error_1_32;

    // ================= RIU6 =================
    quint8  ucRIU6_ID;
    quint8  ucRIU6_CPUStatus;
    quint8  ucRIU6_SystemHealth;
    quint8  ucRIU6_CommStatus;
    quint32 uiRIU6_DI_State_1_32;
    quint32 uiRIU6_DI_Error_1_32;

    // ---------------- Communication Status ----------------
    quint8 ucSMOCIP_Comm_Status;
    quint8 ucLTE_Comm_Status;
    quint8 ucUHF_Comm_Status;
    quint8 ucAdjLeft_Comm_Status;
    quint8 ucAdjRight_Comm_Status;
    quint8 ucNMS_Comm_Status;
    quint8 ucTSRMS_Comm_Status;
    quint8 ucKMS_Comm_Status;
    quint8 ucGNSS_Comm_Status;
    quint8 ucEventLogger_Comm_Status;
    quint8 ucEI_Comm_Status;
    quint8 ucLocalVDU_Comm_Status;

    // ---------------- CRC ----------------
    quint32 uiCRC;

} __attribute__((packed)) stStationaryKavachSysInfo;

Q_DECLARE_METATYPE(stStationaryKavachSysInfo);


typedef struct stOnboardKavachEventMsg
{
    // -------- Header --------
    quint16 usStartFrame;          // 0xBBBB
    quint8  ucMsgType;             // 0x1D
    quint16 usMsgLength;
    quint16 usMsgSeq;

    quint8  ucOnboardKavachID[3];  // 3 bytes
    quint16 usNMSID;
    quint8  ucVersion;

    // -------- Date & Time --------
    quint8  ucDate[3];             // DD/MM/YY
    quint8  ucTime[3];             // HH/MM/SS

    // -------- Event Info --------
    quint16 usEventID;

    quint16 usMode;                // Mode of Operation bitmap
    quint16 usSpeed;               // Current Speed
    quint16 usTargetDistance;      // Target Distance

    quint8  ucEventCount;          // Event Count

    quint16 usIncidentID;          // Incident ID

    quint8  ucEventStatus;         // Event Status
    quint8  ucAckStatus;           // Ack Status

    quint32 uiCRC;                 // CRC32

} __attribute__((packed)) stOnboardKavachEventMsg;

Q_DECLARE_METATYPE(stOnboardKavachEventMsg);

typedef struct stOnboardKavachBrakeEventMsg
{
    // -------- Header --------
    quint16 usStartFrame;          // 0xBBBB
    quint8  ucMsgType;             // 0x1E
    quint16 usMsgLength;
    quint16 usMsgSeq;

    quint8  ucOnboardKavachID[3];
    quint16 usNMSID;
    quint8  ucVersion;

    // -------- Date & Time --------
    quint8  ucDate[3];             // DD MM YY
    quint8  ucTime[3];             // HH MM SS

    // -------- Event Info --------
    quint16 usEventID;

    quint16 usOperatingMode;       // Field 11

    quint16 usCurrentSpeed;        // Field 12
    quint16 usPermittedSpeed;      // Field 13

    quint8  ucDirection;           // Field 14

    quint16 usDistanceToTarget;    // Field 15

    quint8  ucBrakeType;           // Field 16

    quint8  ucEventStatus;         // Field 17

    quint16 usBrakeCauseID;        // Field 18

    quint8  ucAckStatus;           // Field 19

    quint32 uiCRC;                 // Field 20

} __attribute__((packed)) stOnboardKavachBrakeEventMsg;

typedef struct stOnboardKavachBOKSHealthMsg {

    // -------- Header --------
    quint16 usStartFrame;   // 0xBBBB
    quint8  ucMsgType;      // 0x22
    quint16 usMsgLength;
    quint16 usMsgSeq;

    quint8  ucOnboardKavachID[3];
    quint16 usNMSID;
    quint8  ucVersion;

    quint8  ucDate[3];
    quint8  ucTime[3];

    // -------- BOKS --------
    quint8 ucBOKS_COM_Status;
    quint8 ucBOKS_System_Health;
    quint8 ucPowerSupplyDiag;

    // -------- F35 --------
    quint8 ucF35_CPU_State;
    quint8 ucF35_System_Health;
    quint8 ucF35_Comm_Status_1;
    quint8 ucF35_Comm_Status_2;
    quint8 ucF35_Comm_Status_3;

    quint8 ucF35_DO_Value;
    quint8 ucF35_DO_Error;
    quint8 ucF35_CI_Error;

    quint16 usF35_AI_CH1;
    quint16 usF35_AI_CH2;
    quint16 usF35_AI_CH3;
    quint16 usF35_AI_CH4;
    quint16 usF35_AI_CH5;
    quint16 usF35_AI_CH6;
    quint16 usF35_AI_CH7;
    quint16 usF35_AI_CH8;

    quint8 ucF35_AI_Error;

    quint8 ucF35_DI_1_8;
    quint8 ucF35_DI_9_16;
    quint8 ucF35_DI_17_24;

    quint8 ucF35_DI_Err_1_8;
    quint8 ucF35_DI_Err_9_16;
    quint8 ucF35_DI_Err_17_24;

    // -------- F30A --------
    quint8 ucF30A_CPU_State;
    quint8 ucF30A_System_Health;
    quint8 ucF30A_Comm_Status_1;
    quint8 ucF30A_Comm_Status_2;
    quint8 ucF30A_Comm_Status_3;

    quint8 ucF30A_DO_Value;
    quint8 ucF30A_DO_Error;

    quint8 ucF30A_DI_1_8;
    quint8 ucF30A_DI_9_16;
    quint8 ucF30A_DI_17_20;

    quint8 ucF30A_DI_Err_1_8;
    quint8 ucF30A_DI_Err_9_16;
    quint8 ucF30A_DI_Err_17_20;

    // -------- F30B --------
    quint8 ucF30B_CPU_State;
    quint8 ucF30B_System_Health;
    quint8 ucF30B_Comm_Status_1;
    quint8 ucF30B_Comm_Status_2;
    quint8 ucF30B_Comm_Status_3;

    quint8 ucF30B_DO_Value;
    quint8 ucF30B_DO_Error;

    quint8 ucF30B_DI_1_8;
    quint8 ucF30B_DI_9_16;
    quint8 ucF30B_DI_17_20;

    quint8 ucF30B_DI_Err_1_8;
    quint8 ucF30B_DI_Err_9_16;
    quint8 ucF30B_DI_Err_17_20;

    // -------- Communication --------
    quint8 ucLTE_Comm;
    quint8 ucUHF_Comm;
    quint8 ucNMS_Comm;
    quint8 ucKMS_Comm;
    quint8 ucGNSS_Comm;
    quint8 ucEventLogger_Comm;
    quint8 ucDMI1_Comm;
    quint8 ucDMI2_Comm;
    quint8 ucRFIDR1_Comm;
    quint8 ucRFIDR2_Comm;
    quint8 ucIRAB_Comm;
    quint8 ucETH_Comm;

    // -------- CRC --------
    quint32 uiCRC;

} __attribute__((packed)) stOnboardKavachBOKSHealthMsg;

Q_DECLARE_METATYPE(stOnboardKavachBOKSHealthMsg);

typedef struct stlocorssimsg {
    quint16 usStartFrame;     // 0xAAAA
    quint8  ucMsgType;        // 0x20
    quint16 usMsgLength;
    quint16 usMsgSeq;
    quint8  ucLocoKavachID[3];
    quint16 usNMSID;
    quint8  ucVersion;
    quint8  ucDate[3];        // dd mm yy
    quint8  ucTime[3];        // hh mm ss
    quint16 ucStationKavachID;
    quint8  ucStnRadio1RSSISamCnt;
    quint16 usRefRFIDTag;
    quint8  ucAbsRefRFIDTag[3];
    quint16 usRSSIValue;
    quint8  ucStnRadio2RSSISamCnt;
    quint16 usRefRFIDTag2;
    quint8  ucAbsRefRFIDTag2[3];
    quint16 usRSSIValue2;
    quint32 uiCRC;
} __attribute__((packed)) stLocoRSSIMsg;
Q_DECLARE_METATYPE(stLocoRSSIMsg);

typedef struct stpdivercheckcmdpkt
{
    uint8_t  ucSpecificProtocol;          // Byte 00 → F0
    uint16_t usMsgTyp;               // Bytes 01–02 → 0x0101
    uint8_t  ucSenderID[20];      // Bytes 03–22 → Stationary KAVACH ID (20 bytes)
    uint8_t  ucReceiverID[20];    // Bytes 23–42 → Neighbour Stationary KAVACH ID (20 bytes)
    uint16_t usMsgLen;             // Bytes 43–44 → Message length (2 bytes)
    uint8_t  ucPDIVer;                // Byte 45 → (SOURCE_STN_ILC_IBS_VERSION)
    uint16_t usRandomNum;              // Bytes 46–47 → Random number (Rp)
    uint32_t uiCRC;

} __attribute__((packed)) stPDIVerCheckCmdPkt;
Q_DECLARE_METATYPE(stPDIVerCheckCmdPkt);


typedef struct stpdivercheckmsgpkt
{
    uint8_t  ucSpecificProtocol;          // Byte 00 → F0
    uint16_t usMsgTyp;               // Bytes 01–02 → 0x0101
    uint8_t  ucSenderID[20];      // Bytes 03–22 → Stationary KAVACH ID (20 bytes)
    uint8_t  ucReceiverID[20];    // Bytes 23–42 → Neighbour Stationary KAVACH ID (20 bytes)
    uint16_t usMsgLen;             // Bytes 43–44 → Message length (2 bytes)
    uint8_t  ucPDIVerChk;          // bytes 45 ->  0x01 - PDI Version is Not OK , 0x02 - PDI Version is OK
    uint8_t  ucSecondaryStnPDIVer;                // Byte 46 → (SOURCE_STN_ILC_IBS_VERSION)
    uint16_t usSecondaryStnRandomNum;              // Bytes 47–48 → Random number (Rp)
    uint32_t uiMAC_Code;                           // bytes 49-52 ->mac code
    uint32_t uiCRC;

} __attribute__((packed)) stPDIVerCheckMsgPkt;
Q_DECLARE_METATYPE(stPDIVerCheckMsgPkt);

typedef struct stheartbeatpkt
{
    uint8_t  ucSpecificProtocol;          // Byte 00 → F0
    uint16_t usMsgTyp;               // Bytes 01–02 → 0x0101
    uint8_t  ucSenderID[20];      // Bytes 03–22 → Stationary KAVACH ID (20 bytes)
    uint8_t  ucReceiverID[20];    // Bytes 23–42 → Neighbour Stationary KAVACH ID (20 bytes)
    uint16_t usMsgLen;             // Bytes 43–44 → Message length (2 bytes)
    uint8_t  ucFrameNum[3];          // bytes 45 - 47 -> frame number
    uint16_t  usMsgSeq;                // Byte 48 - 49 → message sequence
    uint32_t uiMAC_Code;                           // bytes 49-52 ->mac code
    uint32_t uiCRC;

} __attribute__((packed)) stHeartBeatPkt;
Q_DECLARE_METATYPE(stHeartBeatPkt);

typedef struct sttrainhandoverreqpkt
{
    uint8_t  ucSpecificProtocol;          // Byte 00 → F0
    uint16_t usMsgTyp;               // Bytes 01–02 → 0x0101
    uint8_t  ucSenderID[20];      // Bytes 03–22 → Stationary KAVACH ID (20 bytes)
    uint8_t  ucReceiverID[20];    // Bytes 23–42 → Neighbour Stationary KAVACH ID (20 bytes)
    uint16_t usMsgLen;             // Bytes 43–44 → Message length (2 bytes)
    uint8_t  ucFrameNum[3];          // bytes 45 - 47 -> frame number
    uint16_t usMsgSeq;                // Byte 48 - 49 → message sequence
    uint16_t usRFIDTag;        //  Byte 50 - 51 → Border RFID Tag
    uint8_t  ucMAfrmRFIDTag;    // Byte 52 → movement authority from Border RFID Tag (in sections)
    uint16_t usDistToBorderTag; // Byte 53 - 54 → Dist to Border tag location
    uint8_t  ucLocotoStnRegPkt[21]; // Byte 55 - 75 → Dist to Border tag location
    uint32_t uiMAC_Code;                           // bytes 76-79 ->mac code
    uint32_t uiCRC;

} __attribute__((packed)) stTrainHandOverReqPkt;
Q_DECLARE_METATYPE(stTrainHandOverReqPkt);

typedef struct sttrainrripkt
{
    uint8_t  ucSpecificProtocol;          // Byte 00 → F0
    uint16_t usMsgTyp;               // Bytes 01–02 → 0x0101
    uint8_t  ucSenderID[20];      // Bytes 03–22 → Stationary KAVACH ID (20 bytes)
    uint8_t  ucReceiverID[20];    // Bytes 23–42 → Neighbour Stationary KAVACH ID (20 bytes)
    uint16_t usMsgLen;             // Bytes 43–44 → Message length (2 bytes)
    uint8_t  ucFrameNum[3];          // bytes 45 - 47 -> frame number
    uint16_t usMsgSeq;                // Byte 48 - 49 → message sequence
    uint16_t usRFIDTag;        //  Byte 50 - 51 → Border RFID Tag
    uint8_t  ucRefProfID;
    uint8_t  usOnBoardKavachID[3];    // Byte 52 - 54 → OnBoard kavach identification
    // uint32_t uiMAC_Code;                           // bytes 55 - 58 ->mac code
    // uint32_t uiCRC;

} __attribute__((packed)) stTrainRRIPkt;
Q_DECLARE_METATYPE(stTrainRRIPkt);

typedef struct sttraintakenoverpkt
{
    uint8_t  ucSpecificProtocol;          // Byte 00 → F0
    uint16_t usMsgTyp;               // Bytes 01–02 → 0x0101
    uint8_t  ucSenderID[20];      // Bytes 03–22 → Stationary KAVACH ID (20 bytes)
    uint8_t  ucReceiverID[20];    // Bytes 23–42 → Neighbour Stationary KAVACH ID (20 bytes)
    uint16_t usMsgLen;             // Bytes 43–44 → Message length (2 bytes)
    uint8_t  ucFrameNum[3];          // bytes 45 - 47 -> frame number
    uint16_t usMsgSeq;                // Byte 48 - 49 → message sequence
    uint16_t usRFIDTag;        //  Byte 50 - 51 → Border RFID Tag
    uint8_t  usOnBoardKavachID[3];    // Byte 52 - 54 → OnBoard kavach identification
    uint32_t uiMAC_Code;                           // bytes 55 - 58 ->mac code
    uint32_t uiCRC;

} __attribute__((packed)) stTrainTakenOverPkt;
Q_DECLARE_METATYPE(stTrainTakenOverPkt);

typedef struct sttrainhandoverCancellationpkt
{
    uint8_t  ucSpecificProtocol;          // Byte 00 → F0
    uint16_t usMsgTyp;               // Bytes 01–02 → 0x0101
    uint8_t  ucSenderID[20];      // Bytes 03–22 → Stationary KAVACH ID (20 bytes)
    uint8_t  ucReceiverID[20];    // Bytes 23–42 → Neighbour Stationary KAVACH ID (20 bytes)
    uint16_t usMsgLen;             // Bytes 43–44 → Message length (2 bytes)
    uint8_t  ucFrameNum[3];          // bytes 45 - 47 -> frame number
    uint16_t usMsgSeq;                // Byte 48 - 49 → message sequence
    uint16_t usRFIDTag;        //  Byte 50 - 51 → Border RFID Tag
    uint8_t usOnBoardKavachID[3];    // Byte 52 - 54 → OnBoard kavach identification
    uint32_t uiMAC_Code;                           // bytes 55 - 58 ->mac code
    uint32_t uiCRC;

} __attribute__((packed)) stTrainHandOverCancellationPkt;
Q_DECLARE_METATYPE(stTrainHandOverCancellationPkt);

typedef struct sttrainlengthinfopkt
{
    uint8_t  ucSpecificProtocol;          // Byte 00 → F0
    uint16_t usMsgTyp;               // Bytes 01–02 → 0x0101
    uint8_t  ucSenderID[20];      // Bytes 03–22 → Stationary KAVACH ID (20 bytes)
    uint8_t  ucReceiverID[20];    // Bytes 23–42 → Neighbour Stationary KAVACH ID (20 bytes)
    uint16_t usMsgLen;             // Bytes 43–44 → Message length (2 bytes)
    uint8_t  ucFrameNum[3];          // bytes 45 - 47 -> frame number
    uint16_t usMsgSeq;                // Byte 48 - 49 → message sequence
    uint16_t usRFIDTag;        //  Byte 50 - 51 → Border RFID Tag
    uint8_t usOnBoardKavachID[3];    // Byte 52 - 54 → OnBoard kavach identification
    uint8_t  ucTrainLenInfSts;       // Byte 55 → Train Length Informtion Status
    uint8_t  ucTrainLenMeasntframe[3];  // Byte 56 - 58 → Train Length measurement frame
    uint8_t  ucTrainLenMeasntframeOffset;  // Byte 59 → Train Length measurement frame offset
    uint32_t uiMAC_Code;                           // bytes 60 - 63 ->mac code
    uint32_t uiCRC;

} __attribute__((packed)) stTrainLengthInfoPkt;
Q_DECLARE_METATYPE(stTrainLengthInfoPkt);

typedef struct sttrainlengthinfoack
{
    uint8_t  ucSpecificProtocol;          // Byte 00 → F0
    uint16_t usMsgTyp;               // Bytes 01–02 → 0x0101
    uint8_t  ucSenderID[20];      // Bytes 03–22 → Stationary KAVACH ID (20 bytes)
    uint8_t  ucReceiverID[20];    // Bytes 23–42 → Neighbour Stationary KAVACH ID (20 bytes)
    uint16_t usMsgLen;             // Bytes 43–44 → Message length (2 bytes)
    uint8_t  ucFrameNum[3];          // bytes 45 - 47 -> frame number
    uint16_t usMsgSeq;                // Byte 48 - 49 → message sequence
    uint16_t usRFIDTag;        //  Byte 50 - 51 → Border RFID Tag
    uint8_t usOnBoardKavachID[3];    // Byte 52 - 54 → OnBoard kavach identification
    uint8_t  ucTrainLenInf;       // Byte 55 → Train Length Informtion Status
    uint32_t uiMAC_Code;                           // bytes 56 - 59 ->mac code
    uint32_t uiCRC;

} __attribute__((packed)) stTrainLengthInfoAck;
Q_DECLARE_METATYPE(stTrainLengthInfoAck);

typedef struct sttslreqpkt
{
    uint8_t  ucSpecificProtocol;          // Byte 00 → F0
    uint16_t usMsgTyp;               // Bytes 01–02 → 0x0101
    uint8_t  ucSenderID[20];      // Bytes 03–22 → Stationary KAVACH ID (20 bytes)
    uint8_t  ucReceiverID[20];    // Bytes 23–42 → Neighbour Stationary KAVACH ID (20 bytes)
    uint16_t usMsgLen;             // Bytes 43–44 → Message length (2 bytes)
    uint8_t  ucFrameNum[3];          // bytes 45 - 47 -> frame number
    uint16_t usMsgSeq;                // Byte 48 - 49 → message sequence
    uint16_t usRFIDTag;        //  Byte 50 - 51 → Border RFID Tag
    uint8_t usOnBoardKavachID[3];    // Byte 52 - 54 → OnBoard kavach identification
    uint8_t  ucRouteID;       // Byte 55 - 56 → Train Length Informtion Status
    uint32_t uiMAC_Code;                           // bytes 57 - 60 ->mac code
    uint32_t uiCRC;

} __attribute__((packed)) stTSLReqPkt;
Q_DECLARE_METATYPE(stTSLReqPkt);

typedef struct sttslinformationpkt
{
    uint8_t  ucSpecificProtocol;          // Byte 00 → F0
    uint16_t usMsgTyp;               // Bytes 01–02 → 0x0101
    uint8_t  ucSenderID[20];      // Bytes 03–22 → Stationary KAVACH ID (20 bytes)
    uint8_t  ucReceiverID[20];    // Bytes 23–42 → Neighbour Stationary KAVACH ID (20 bytes)
    uint16_t usMsgLen;             // Bytes 43–44 → Message length (2 bytes)
    uint8_t  ucFrameNum[3];          // bytes 45 - 47 -> frame number
    uint16_t usMsgSeq;                // Byte 48 - 49 → message sequence
    uint16_t usRFIDTag;        //  Byte 50 - 51 → Border RFID Tag
    uint8_t usOnBoardKavachID[3];    // Byte 52 - 54 → OnBoard kavach identification
    uint8_t  ucTSLReqReply;       // Byte 55 → Train Length Informtion Status
    uint32_t uiMAC_Code;                           // bytes 56 - 59 ->mac code
    uint32_t uiCRC;

} __attribute__((packed)) stTSLInformationPkt;
Q_DECLARE_METATYPE(stTSLInformationPkt);

typedef struct stfieldelementstatusreqpkt
{
    uint8_t  ucSpecificProtocol;          // Byte 00 → F0
    uint16_t usMsgTyp;               // Bytes 01–02 → 0x0101
    uint8_t  ucSenderID[20];      // Bytes 03–22 → Stationary KAVACH ID (20 bytes)
    uint8_t  ucReceiverID[20];    // Bytes 23–42 → Neighbour Stationary KAVACH ID (20 bytes)
    uint16_t usMsgLen;             // Bytes 43–44 → Message length (2 bytes)
    uint8_t  ucFrameNum[3];          // bytes 45 - 47 -> frame number
    uint16_t usMsgSeq;                // Byte 48 - 49 → message sequence
    uint32_t uiMAC_Code;                           // bytes 50 - 53 ->mac code
    uint32_t uiCRC;

} __attribute__((packed)) stFieldElementsStatusReqPkt;
Q_DECLARE_METATYPE(stFieldElementsStatusReqPkt);

typedef struct sttrainhandoverCancellationackpkt
{
    uint8_t  ucSpecificProtocol;          // Byte 00 → F0
    uint16_t usMsgTyp;               // Bytes 01–02 → 0x0101
    uint8_t  ucSenderID[20];      // Bytes 03–22 → Stationary KAVACH ID (20 bytes)
    uint8_t  ucReceiverID[20];    // Bytes 23–42 → Neighbour Stationary KAVACH ID (20 bytes)
    uint16_t usMsgLen;             // Bytes 43–44 → Message length (2 bytes)
    uint8_t  ucFrameNum[3];          // bytes 45 - 47 -> frame number
    uint16_t usMsgSeq;                // Byte 48 - 49 → message sequence
    uint16_t usRFIDTag;        //  Byte 50 - 51 → Border RFID Tag
    uint8_t usOnBoardKavachID[3];    // Byte 52 - 54 → OnBoard kavach identification
    uint32_t uiMAC_Code;                           // bytes 55 - 58 ->mac code
    uint32_t uiCRC;

} __attribute__((packed)) stTrainHandOverCancellationAckPkt;
Q_DECLARE_METATYPE(stTrainHandOverCancellationAckPkt);

typedef struct ststationhealthpkt {
    quint16 usStartFrame;     // 0xAAAA
    quint8  ucMsgType;        // 0x15,0x16,0x11
    quint16 usMsgLength;
    quint16 usMsgSeq;
    quint16 usStatKavachID;
    quint16 usNMSID;
    quint8  ucVersion;
    quint8  ucDate[3];        // dd mm yy
    quint8  ucTime[3];        // hh mm ss
    quint8  ucEventCnt;
    // quint16 usEventID;
    // quint8 uiEventData;
    // quint32 uiCRC;
} __attribute__((packed)) stStationHealthPkt;
Q_DECLARE_METATYPE(stStationHealthPkt);

typedef struct stonboardhealthpkt {
    quint16 usStartFrame;     // 0xAAAA
    quint8  ucMsgType;        // 0x15,0x16,0x11
    quint16 usMsgLength;
    quint16 usMsgSeq;
    quint8  ucOnBrdKavachID[3];
    quint16 usNMSID;
    quint8  ucVersion;
    quint8  ucDate[3];        // dd mm yy
    quint8  ucTime[3];        // hh mm ss
    quint8  ucEventCnt;
    quint16 usEventID;
    quint8  uiEventData;
    quint32 uiCRC;
} __attribute__((packed)) stOnBoardHealthPkt;
Q_DECLARE_METATYPE(stOnBoardHealthPkt);

// ====== Station Main Regular Header ======
struct StationRegularHeader
{
    uint8_t  PKT_TYPE;                   // 4 bits (1001)
    uint16_t PKT_LENGTH;                 // 10 bits (bytes, includes footer)
    uint32_t FRAME_NUM;                  // 17 bits (1..86400)
    uint16_t SOURCE_STN_ILC_IBS_ID;      // 16 bits
    uint8_t  SOURCE_STN_ILC_IBS_VERSION; // 3 bits (1=3.2, 2=4.0)
    uint32_t DEST_LOCO_ID;               // 20 bits (1..999999)
    uint8_t  REF_PROF_ID;                // 4 bits (0=none, 1..15 valid)
    uint16_t LAST_REF_RFID;              // 10 bits
    int16_t  DIST_PKT_START;             // 15 bits (signed)
    uint8_t  PKT_DIR;                    // 2 bits (00=unk,01=Nominal,10=Reverse)
    uint8_t  Padding;                   // 3bits
};
struct StationRegularFooter
{
    // Footer
    uint32_t LOCO_Specific_MAC_CODE;     // 32 bits
    uint32_t PKT_CRC;                    // 32 bits
};


// for CUR_SIG_INFO
struct CUR_SIG_INFO_t {
    uint32_t lineNumber   : 5;  // 0..31
    uint32_t lineName     : 6;  // enum LineName
    uint32_t signalType   : 6;  // enum TypeofSignal

    uint32_t toUInt() const {
        return (lineNumber & 0x1F) |
               ((lineName & 0x3F) << 5) |
               ((signalType & 0x3F) << 11);
    }

    void fromUInt(uint32_t val) {
        lineNumber = val & 0x1F;             // bits 0..4
        lineName   = (val >> 5) & 0x3F;      // bits 5..10
        signalType = (val >> 11) & 0x3F;     // bits 11..16
    }
};

struct MovementAuthorityPkt
{
    enmSubPktType  SUB_PKT_TYPE;       // 4 bits
    uint8_t  SUB_PKT_LENGTH;     // 7 bits
    uint8_t  FRAME_OFFSET;       // 4 bits
    SoSEmergencyCondition  DEST_LOCO_SOS;      // 4 bits
    SectionType  TRAIN_SECTION_TYPE; // 2 bits
    CUR_SIG_INFO_t CUR_SIG_INFO;       // 17 bits
    SIG_ASPECTS  CUR_SIG_ASPECT;     // 6 bits
    uint8_t  NEXT_SIG_ASPECT;    // 6 bits
    uint16_t APPR_SIG_DIST;      // 15 bits
    AUTH_TYPE  AUTHORITY_TYPE;     // 2 bits
    uint8_t  AUTHORIZED_SPEED;   // 6 bits
    uint16_t MA_WRT_SIG;         // 16 bits
    uint8_t  REQ_SHORTEN_MA;     // 1 bit
    uint16_t NEW_MA;             // 16 bits
    uint8_t  TRN_LEN_INFO_STS;   // 1 bit
    uint8_t  TRN_LEN_INFO_TYPE;  // 1 bit
    uint32_t REF_FRAME_NUM_TLM;  // 17 bits
    uint8_t  REF_OFFSET_INT_TL;  // 8 bits
    uint8_t  NEXT_STN_COMM;      // 1 bit
    uint16_t APPR_STN_ILC_IBS_ID;// 16 bits
   // uint8_t PADDING_BITS;

};

// ====== Sub packet 2. Static Speed Profile ======
struct StaticSpeedEntry {
    uint16_t LM_Static_Speed_Distance; // 15 bits
    uint8_t  LM_Static_Speed_Class;    // 1 bit
    uint8_t  SpeedValue;           // 6 bits
    // uint8_t  SpeedClassA;              // 6 bits
    // uint8_t  SpeedClassB;              // 6 bits
    // uint8_t  SpeedClassC;              // 6 bits
};

struct StaticSpeedProfilePkt {
    enmSubPktType SUB_PKT_TYPE;
    uint8_t SUB_PKT_LENGTH;
    uint8_t LM_Speed_Info_CNT; // 1–31

    QVector<StaticSpeedEntry> entries;
   // uint8_t PADDING_BITS;

};

// ====== Sub packet 3. Gradient Profile ======
struct GradientEntry {
    uint16_t LM_Gradient_Distance; // 15 bits
    uint8_t  LM_GDIR;              // 1 bit
    uint8_t  LM_Gradient_Value;    // 5 bits
};

struct GradientProfilePkt {
    enmSubPktType SUB_PKT_TYPE;
    uint8_t SUB_PKT_LENGTH;
    uint8_t LM_Grad_Info_CNT;

    QVector<GradientEntry> entries;
    //uint8_t PADDING_BITS;
};

// ====== Sub packet 4. LC Gate Profile ======
struct LCGateEntry {
    uint16_t LM_LC_Distance;    // 15 bits
    uint16_t LM_LC_ID_Numeric;  // 10 bits
    uint8_t  LM_LC_ID_Suffix;   // 3 bits
    uint8_t  LM_LC_Manning;     // 1 bit
    uint8_t  LM_LC_Class;       // 3 bits
    uint8_t  LM_LC_AW_Enabled;  // 1 bit
    uint8_t  LM_LC_AW_Type;     // 2 bits
};

struct LCGateProfilePkt {
    enmSubPktType SUB_PKT_TYPE;
    uint8_t SUB_PKT_LENGTH;
    uint8_t LM_LC_Info_CNT;

    QVector<LCGateEntry> entries;
   // uint8_t PADDING_BITS;

};


struct TurnoutSpeedEntry {

    uint8_t TO_SPEED;
    uint16_t DIFF_DIST_TO;
    uint16_t TO_SPEED_REL_DIST;
};

struct TurnoutSpeedProfilePkt {
    enmSubPktType SUB_PKT_TYPE;
    uint8_t SUB_PKT_LENGTH;
    uint8_t TO_CNT;

    QVector<TurnoutSpeedEntry> entries;

};

// ====== Sub packet 5. Tag Linking Information ======
struct TagLinkingEntry {
    uint16_t DIST_NXT_RFID;
    uint16_t NXT_RFID_TAG_ID;
    uint8_t  DUP_TAG_DIR;
    uint8_t  ABS_LOC_RESET;
    uint16_t ADJ_LOCO_DIST;
    uint8_t  ADJ_LOCO_DIR;
    uint32_t ABS_LOC_CORR;
    uint8_t  ADJ_LINE_CNT;

    //uint16_t LINE_TIN[1]; // flexible array
    QVector<uint16_t> LINE_TIN;
};

struct TagLinkingInfoPkt {
    enmSubPktType SUB_PKT_TYPE;
    uint8_t SUB_PKT_LENGTH;
    uint8_t DIST_DUP_TAG;
    uint8_t ROUTE_RFID_CNT;

    QVector<TagLinkingEntry> entries; // flexible array
   // uint8_t PADDING_BITS;

};

// ====== Sub packet 6. Track Condition ======
struct TrackConditionEntry {
    uint8_t  TRACK_COND_TYPE;
    uint16_t START_DIST_TRACKCOND;
    uint16_t LENGTH_TRACKCOND;
};

struct TrackConditionPkt {
    enmSubPktType SUB_PKT_TYPE;
    uint8_t SUB_PKT_LENGTH;
    uint8_t TRACK_COND_CNT;

    QVector<TrackConditionEntry> entries;
   // uint8_t PADDING_BITS;

};

// ====== Sub packet 7. Temporary Speed Restrictions ======
struct TSREntry {
    uint8_t  TSR_ID;
    uint16_t TSR_Distance;
    uint16_t TSR_Length;
    uint8_t  TSR_Class;
    uint8_t  TSR_Universal_Speed;
    uint8_t  TSR_ClassA_Speed;
    uint8_t  TSR_ClassB_Speed;
    uint8_t  TSR_ClassC_Speed;
    uint8_t  TSR_Whistle;
};

struct TempSpeedRestrictionPkt
{
    enmSubPktType SUB_PKT_TYPE;
    uint8_t SUB_PKT_LENGTH;
    uint8_t TSR_STATUS;
    uint8_t TSR_Info_CNT;

    QVector<TSREntry> entries;
  //  uint8_t PADDING_BITS;

};

#endif // _NMS_STRUCTS_H_
