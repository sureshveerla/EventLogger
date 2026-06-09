#ifndef _NMS_ENUM_H_
#define _NMS_ENUM_H_

typedef enum enmpackettype
{
    enmReservedPkt = 0b1000,
    enmStnToOnBoardRegPkt = 0b1001,
    enmOnBoardToStnRegPkt = 0b1010,
    enmAccessAuthorityPkt = 0b1011,
    enmAdditionalEmergencyPkt = 0b1100,
    enmAccessRequestPkt = 0b1101

}enmPacketType;

typedef enum enmsubpkttype
{
    enmMovementAuthoritySubPkt = 0b0000,
    enmStaticSpeedProfileSubPkt = 0b0001,
    enmGradientProfileSubPkt = 0b0010,
    enmLCGateSubPkt = 0b0011,
    enmTurnoutSpeedProfileSubPkt = 0b0100,
    enmTagLinkingInfSubPkt = 0b0101,
    enmTrackConditionDataSubPkt = 0b0110,
    enmTempSpeedRestrctionProfileSubPkt = 0b0111
}enmSubPktType;

typedef enum enmfaults
{
    enmSystemInternalFault,
    enmSpeedSensor1Fault,
    enmEBDriveFault,
    enmEBApplicationFault,
    enmRFIDReader1LinkFail,
    enmRFIDReader2LinkFail,
    enmRadio1LinkFail,
    enmRadio2LinkFail,
    enmLPOCIPDMI1LinkFail,
    enmLPOCIPDMI2LinkFail,
    enmGPS1PPS1Fail,
    enmGPS2PPS2Fail,
    enmGPS1viewnotavailsince2hrs,
    enmGPS2viewnotavailsince2hrs,
    enmTaglinkingincorrect,
    enmGSM1Fault,
    enmGSM2Fault,
    enmRadio1RSSIWeak,
    enmRadio2RSSIWeak,
    enmSessionKeyMismatch,
    enmRemainingkeys5,
    enmBIUconnectivityfault,
    enmSpeedSensor2fault,
    enmCabInputfault
}enmFaults;

enum LineNumber : uint8_t {
    LINE_NONE        = 0b00000, // no line number applicable
    LINE_1           = 0b00001,
    LINE_2           = 0b00010,
    LINE_3           = 0b00011,
    // ...
    LINE_29          = 0b11101,
    LINE_GOODS       = 0b11110, // goods line special case
    LINE_EXCESS      = 0b11111  // >30
};

enum LineName :uint32_t{
    DIR_NONE        = 16,
    DIR_UP          = 0,
    DIR_DN          = 1,
    DIR_UP_FAST     = 2,
    DIR_DN_FAST     = 3,
    DIR_UP_SLOW     = 8,
    DIR_DN_SLOW     = 9,
    DIR_UP_MAIN     = 10,
    DIR_DN_MAIN     = 11,
    DIR_UP_SUB      = 12,
    DIR_DN_SUB      = 13,
    DIR_UP_BI_DIR   = 14,
    DIR_DN_BI_DIR   = 15,
};
// for CUR_SIG_INFO
enum TypeofSignal :uint32_t{
    DIST              = 16,
    INR_DIST          = 17,
    GATE_DIST         = 18,
    GATE_INR_DIST     = 19,
    IB_DIST           = 20,
    IB_INR_DIST       = 21,
    AUTO              = 22,
    SEMI_AUTO         = 23,
    HOME              = 24,
    HOME_L_X          = 25,
    R_HOME            = 26,
    R_HOME_L_X        = 27,
    ML_STR_L_X        = 28,
    LL_STR_L_X        = 29,
    INT_STR           = 30,
    ADV_STR           = 01,
    IB_STOP           = 02,
    GATE_STOP         = 03,
    CALLING_ON        = 04,
    ADV_STR_CUM_GATE  = 05,
    GATE_CUM_DIST     = 06,
    ADV_STR_CUM_DIST  = 07,
    AUTO_GATE         = 35,
    SEMI_AUTO_WITHOUT = 36,
    ADV_STR_CUM_G_ID  = 37,
    GATE_CUM_ID       = 38,
    GATE_ID_CUM_DIST  = 39,
    IB_CUM_GATE_DIST  = 40,
    IB_CUM_GATE_ID    = 41,
    IB_CUM_DIST       = 42,
    ADV_STR_CUM_IB_D  = 43,
    STR_CUM_IB_DIST   = 44,
    STOP_BOARD        = 45,
    GATE_CUM_IB_DIST  = 46,
    GATE_CUM_IB_ID    = 47,
    ADV_STR_CUM_G_D   = 48,
};

enum SIG_ASPECTS :uint8_t{
    UNIDENTIFIED = 0,                             // 0
    RED = 0x1,                                    // 000001
    YELLOW_NO_ROUTE_IND = 0x2,                    // 000010
    YELLOW_POS1_LEFT = 0x3,                       // 000011
    YELLOW_POS2_LEFT = 0x4,                       // 000100
    YELLOW_POS3_LEFT = 0x5,                       // 000101
    YELLOW_POS4_RIGHT = 0x6,                      // 000110
    YELLOW_POS5_RIGHT = 0x7,                      // 000111
    YELLOW_POS6_RIGHT = 0x8,                      // 001000
    SPARE1 = 0x9,                                 // 001001
    DOUBLE_YELLOW = 0xA,                          // 001010
    GREEN = 0xB,                                  // 001011
    DOUBLE_YELLOW_POS1_LEFT = 0xC,                // 001100
    DOUBLE_YELLOW_POS4_RIGHT = 0xD,               // 001101
    AG_MARKER_OFF = 0xE,                          // 001110
    RED_WITH_CALLING_OFF = 0xF,                   // 001111
    SPARE2 = 0x10,                                // '01000 0 to 010111
    BUFFER_STOP_BOARD = 0x18,                            // '01100 0
    SPARE3 = 0x19,                                // 011001 to 011111
    YELLOW_STENCIL_ROUTE_1_TO_32 = 0x20,          // 100000 to 111111
};

enum AUTH_TYPE :uint8_t{
    None = 0x0,
    OS_Authority = 0x1,
    FS_Authority =0x2,
    SR_Authority = 0x3,
};

// ====== Sub packet 1. Movement Authority ======
// ====== MA SoS Emergency Condition ======
enum SoSEmergencyCondition : uint8_t {
    NoSoSEmergency           = 0b0000,
    ForeignRFID              = 0b0001,
    Reserved1                = 0b0010,
    OnboardOdoError          = 0b0011,
    SPADDetected             = 0b0100,
    RearEndCollision         = 0b0101,
    HeadOnCollision          = 0b0110,
    ViolationOfShuntingLimits= 0b0111,
    StationGeneralSoS        = 0b1000,
};

enum SectionType : uint8_t {
    StationSection =0b00,
    AbsoluteBlock =0b01,
    Autoblock =0b10,
    Reserved =0b11,
};
#endif // _NMS_ENUM_H_
