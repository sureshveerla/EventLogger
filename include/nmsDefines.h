#ifndef NMS_DEFINES_H
#define NMS_DEFINES_H

// ====== Constants ======
#define PACKET_MAC_CRC_LEN   8   // bytes (MAC 4 + CRC 4)

#define MAX_SSP_LM_CNT   31U
#define MAX_LSI          2U
#define MAX_TO           3U
#define MAX_ADJ_TINS     6U
#define MAX_TRACK_COND   15U
#define MAX_GRAD_LM      31U
#define MAX_LCG_LM       31U
#define MAX_TSR          31U
#define MAX_ROUTE_TAGS   62U
#define STATION_KV_REG_PKT_TO_NMS               0x11
#define LOCO_KV_REG_PKT_TO_NMS                  0x12
#define STATION_KV_HEALTH_PKT_TO_NMS            0x17
#define ONBOARD_KV_HEALTH_PKT_TO_NMS            0x18
#define STATION_KV_FAULT_PKT_TO_NMS             0x19

#define FAULT_CODE_01                           "System Internal Fault"
#define FAULT_CODE_02                           "Speed sensor1 Fault"
#define FAULT_CODE_03                           "EB Drive Fault"
#define FAULT_CODE_04                           "EB Application (Feedback) Fault"
#define FAULT_CODE_05                           "RFID Reader1 Link Fail"
#define FAULT_CODE_06                           "RFID Reader2 Link Fail"
#define FAULT_CODE_07                           "Radio1 Link Fail"
#define FAULT_CODE_08                           "Radio2 Link Fail"
#define FAULT_CODE_09                           "LP-OCIP (DMI)1 Link Fail"
#define FAULT_CODE_10                           "LP-OCIP (DMI)2 Link Fail"
#define FAULT_CODE_11                           "GPS1/PPS1 Fail"
#define FAULT_CODE_12                           "GPS2/PPS2 Fail"
#define FAULT_CODE_13                           "GPS1view not available since 2 hrs"
#define FAULT_CODE_14                           "GPS2 view not available since 2 hrs"
#define FAULT_CODE_15                           "Tag linking incorrect"
#define FAULT_CODE_16                           "GSM1 Fault"
#define FAULT_CODE_17                           "GSM2 Fault"
#define FAULT_CODE_18                           "Radio 1 RSSI Weak"
#define FAULT_CODE_19                           "Radio 2 RSSI Weak"
#define FAULT_CODE_20                           "Session Key Mismatch"
#define FAULT_CODE_21                           "Remaining keys < 5"
#define FAULT_CODE_22                           "BIU connectivity fault"
#define FAULT_CODE_23                           "Speed Sensor 2 fault"
#define FAULT_CODE_24                           "Cab Input fault"

#endif // NMSDEFINES_H
