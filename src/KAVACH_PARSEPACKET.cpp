#include "KAVACH_PARSEPACKET.h"
#include <QDebug>
/********* This class KAVACH_PARSEPACKET is designed to decode station packets
 *         received from the Kavach railway signaling system.
 *          Each packet contains multiple types of information   *******/
KAVACH_PARSEPACKET::KAVACH_PARSEPACKET(QObject *parent)
    : QObject{parent}
{
    // clear vectors
    sspPkt.entries.clear();
    gradPkt.entries.clear();
    lcPkt.entries.clear();
    tspPkt.entries.clear();
    tliPkt.entries.clear();
    tcdPkt.entries.clear();
    tsrPkt.entries.clear();
}
/******* This function is used to extract specific bits from the raw packet
 *       These functions help you pick the exact switches you want and interpret them correctly. *******/
quint64 KAVACH_PARSEPACKET::getBits(const QByteArray &buf, int &bitPos, int bits) const
{
    quint64 value = 0;
    for (int i = 0; i < bits; ++i) {
        int bytePos = bitPos / 8;
        int bitOffset = 7 - (bitPos % 8);
        if (bytePos >= buf.size()) break;
        uchar b = (uchar)buf[bytePos];
        int bit = (b >> bitOffset) & 1;
        value = (value << 1) | bit;
        bitPos++;
    }
    return value;
}

/******* getSignedBits is used when the field can be negative (like distances above or below a reference). *******/
qint64 KAVACH_PARSEPACKET::getSignedBits(const QByteArray &buf, int &bitPos, int bits) const
{
    quint64 raw = getBits(buf, bitPos, bits);
    if (bits == 64) return (qint64)raw;
    quint64 mask = (1ULL << bits) - 1ULL;
    raw &= mask;
    if (raw & (1ULL << (bits - 1))) {
        return (qint64)(raw | (~mask)); // sign extend
    }
    return (qint64)raw;
}
/******* Reads the general information about the packet like,
        Packet type,Length,Frame number,Source and destination IDs,Reference RFID and starting distance.
        Aligns the bit position to byte boundaries after reading *****/
bool KAVACH_PARSEPACKET::parseStationHeader(const QByteArray &buf, int &bitPos)
{
    StnRglrHPkt.PKT_TYPE  = getBits(buf, bitPos, 4);
    StnRglrHPkt.PKT_LENGTH= getBits(buf, bitPos, 10);
    StnRglrHPkt.FRAME_NUM = getBits(buf, bitPos, 17);
    StnRglrHPkt.SOURCE_STN_ILC_IBS_ID = getBits(buf, bitPos, 16);
    StnRglrHPkt.SOURCE_STN_ILC_IBS_VERSION = getBits(buf, bitPos, 3);
    StnRglrHPkt.DEST_LOCO_ID = getBits(buf, bitPos, 20);
    StnRglrHPkt.REF_PROF_ID  = getBits(buf, bitPos, 4);
    StnRglrHPkt.LAST_REF_RFID= getBits(buf, bitPos, 10);
    StnRglrHPkt.DIST_PKT_START = getSignedBits(buf, bitPos, 15);
    StnRglrHPkt.PKT_DIR = getBits(buf, bitPos, 2);

    int rem = bitPos % 8;
    if (rem) bitPos += (8 - rem);

    return true;
}

bool KAVACH_PARSEPACKET::parseMovementAuthority(const QByteArray &buf, int &bitPos, int subLength)
{
    int startBit = bitPos;


    maPkt.SUB_PKT_TYPE        = static_cast<enmSubPktType>(getBits(buf, bitPos, 4));
    maPkt.SUB_PKT_LENGTH      = static_cast<uint8_t>(getBits(buf, bitPos, 7));
    maPkt.FRAME_OFFSET        = getBits(buf, bitPos, 4);
    maPkt.DEST_LOCO_SOS       = static_cast<SoSEmergencyCondition>(getBits(buf, bitPos, 4));
    maPkt.TRAIN_SECTION_TYPE  = static_cast<SectionType>(getBits(buf, bitPos, 2));

    // --- CUR_SIG_INFO (17 bits) ---
    uint32_t sigVal = static_cast<uint32_t>(getBits(buf, bitPos, 17));
    maPkt.CUR_SIG_INFO.fromUInt(sigVal);


    maPkt.CUR_SIG_ASPECT      = static_cast<SIG_ASPECTS>(getBits(buf, bitPos, 6));
    maPkt.NEXT_SIG_ASPECT     = getBits(buf, bitPos, 6);
    maPkt.APPR_SIG_DIST       = getBits(buf, bitPos, 15);
    maPkt.AUTHORITY_TYPE      = static_cast<AUTH_TYPE>(getBits(buf, bitPos, 2));

    // ===== Conditional AUTHORIZED_SPEED =====
    if (maPkt.AUTHORITY_TYPE == 0b01) {
        maPkt.AUTHORIZED_SPEED = getBits(buf, bitPos, 6);
    } else {
        maPkt.AUTHORIZED_SPEED = 0; // default/pad
    }

    maPkt.MA_WRT_SIG          = getBits(buf, bitPos, 16);
    maPkt.REQ_SHORTEN_MA      = getBits(buf, bitPos, 1);

    // ===== Conditional NEW_MA =====
    if (maPkt.REQ_SHORTEN_MA) {
        maPkt.NEW_MA = getBits(buf, bitPos, 16);
    } else {
        maPkt.NEW_MA = 0;
    }

    maPkt.TRN_LEN_INFO_STS    = getBits(buf, bitPos, 1);

    // ===== Conditional TRN_LEN_INFO_TYPE, REF_FRAME_NUM_TLM, REF_OFFSET_INT_TL =====
    if (maPkt.TRN_LEN_INFO_STS) {
        maPkt.TRN_LEN_INFO_TYPE = getBits(buf, bitPos, 1);
        maPkt.REF_FRAME_NUM_TLM = getBits(buf, bitPos, 17);
        maPkt.REF_OFFSET_INT_TL = getBits(buf, bitPos, 8);
    } else {
        maPkt.TRN_LEN_INFO_TYPE = 0;
        maPkt.REF_FRAME_NUM_TLM = 0;
        maPkt.REF_OFFSET_INT_TL = 0;
    }

    maPkt.NEXT_STN_COMM       = getBits(buf, bitPos, 1);

    if (maPkt.NEXT_STN_COMM) {
        maPkt.APPR_STN_ILC_IBS_ID = getBits(buf, bitPos, 16);
    } else {
        maPkt.APPR_STN_ILC_IBS_ID = 0;
    }

   // emit SigInsertDBStnRegMASubPkt(maPkt);
    // Move bitPos to end of this subpacket
    bitPos = startBit + (subLength * 8);
    int consumedBits = bitPos - startBit;
    int expectedBits = subLength * 8;
    uint8_t ucPadding_Bits = 0;
    if (consumedBits < expectedBits)
    {
        ucPadding_Bits = expectedBits - consumedBits;
        bitPos = startBit + expectedBits; // resync safely
    }
    return true;
}

bool KAVACH_PARSEPACKET::parseStaticSpeedProfile(const QByteArray &data, int &bitPos, int subLength)
{
    int startBit = bitPos;

    // --- Header ---
    sspPkt.SUB_PKT_TYPE        = static_cast<enmSubPktType>(getBits(data, bitPos, 4));
    sspPkt.SUB_PKT_LENGTH      = static_cast<uint8_t>(getBits(data, bitPos, 7));
    quint8 entryCnt  = getBits(data, bitPos, 5);  // 1–31

    // --- Entries ---
    QVector<StaticSpeedEntry> entries;
    entries.reserve(entryCnt);

    for (int i = 0; i < entryCnt; ++i) {
        StaticSpeedEntry e{};

        e.LM_Static_Speed_Distance = getBits(data, bitPos, 15);
        e.LM_Static_Speed_Class    = getBits(data, bitPos, 1);
        e.SpeedValue = getBits(data, bitPos, 6);

        // if (e.LM_Static_Speed_Class == 0) {
        //     e.SpeedValue = getBits(data, bitPos, 6);
        //    // e.SpeedClassA = e.SpeedClassB = e.SpeedClassC = 0;
        // } else {
        //     e.SpeedValue = getBits(data, bitPos, 6);
        //     // e.SpeedClassB = getBits(data, bitPos, 6);
        //     // e.SpeedClassC = getBits(data, bitPos, 6);
        //     // e.UniversalSpeed = 0;
        // }

        entries.push_back(e);
    }

    // --- Store results ---
    sspPkt.LM_Speed_Info_CNT = entryCnt;
    sspPkt.entries = entries;

    // ensure we consumed exactly subLength
    int consumedBits = bitPos - startBit;
    int expectedBits = subLength * 8;
    uint8_t ucPadding_Bits = 0;
    if (consumedBits < expectedBits)
    {
        ucPadding_Bits = expectedBits - consumedBits;
        bitPos = startBit + expectedBits; // resync safely
    }
    return true;
}

bool KAVACH_PARSEPACKET::parseGradientProfile(const QByteArray &buf, int &bitPos, int subLength)
{
    int startBit = bitPos;
    gradPkt.SUB_PKT_TYPE        = static_cast<enmSubPktType>(getBits(buf, bitPos, 4));
    gradPkt.SUB_PKT_LENGTH      = static_cast<uint8_t>(getBits(buf, bitPos, 7));
    quint8 entryCnt  = getBits(buf, bitPos, 5);  // 1–31

    // --- Entries ---
    QVector<GradientEntry> entries;
    entries.reserve(entryCnt);

    for (int i = 0; i < entryCnt; ++i)
    {
        GradientEntry stGradEntry{};
        stGradEntry.LM_Gradient_Distance = getBits(buf,bitPos,15);
        stGradEntry.LM_GDIR =  getBits(buf, bitPos, 1);
        stGradEntry.LM_Gradient_Value = getBits(buf,bitPos,5);
        entries.push_back(stGradEntry);
    }

    gradPkt.LM_Grad_Info_CNT    = entryCnt;
    gradPkt.entries             = entries;

    int consumedBits = bitPos - startBit;
    int expectedBits = subLength * 8;
    uint8_t ucPadding_Bits = 0;
    if (consumedBits < expectedBits)
    {
        ucPadding_Bits = expectedBits - consumedBits;
        bitPos = startBit + expectedBits; // resync safely
    }
    return true;

}

bool KAVACH_PARSEPACKET::parseLCGateProfile(const QByteArray &buf, int &bitPos, int subLength)
{
    int startBit = bitPos;
    lcPkt.SUB_PKT_TYPE        = static_cast<enmSubPktType>(getBits(buf, bitPos, 4));
    lcPkt.SUB_PKT_LENGTH      = static_cast<uint8_t>(getBits(buf, bitPos, 7));
    quint8 entryCnt  = getBits(buf, bitPos, 5);  // 5 bits = number of LC gate entries (1–31)

    QVector<LCGateEntry> entries;
    entries.reserve(entryCnt);

    // --- Loop through each LC Gate Entry ---
    for (int i = 0; i < entryCnt; ++i)
    {
        LCGateEntry stLCGateEntry{};
        stLCGateEntry.LM_LC_Distance    = getBits(buf, bitPos, 15); // meters (0–32767)
        stLCGateEntry.LM_LC_ID_Numeric  = getBits(buf, bitPos, 10); // 1–1021 valid
        stLCGateEntry.LM_LC_ID_Suffix   = getBits(buf, bitPos, 3);  // 0–7 mapping suffix a/b/c…
        stLCGateEntry.LM_LC_Manning     = getBits(buf, bitPos, 1);  // 0=Manned, 1=Unmanned
        stLCGateEntry.LM_LC_Class       = getBits(buf, bitPos, 3);  // Class A/B/C etc.
        stLCGateEntry.LM_LC_AW_Enabled  = getBits(buf, bitPos, 1);  // Auto-whistling enabled
        stLCGateEntry.LM_LC_AW_Type     = getBits(buf, bitPos, 2);  // AW Type (00=distance, 01=time…)

        entries.push_back(stLCGateEntry);
    }

    // --- Save into packet struct ---
    lcPkt.LM_LC_Info_CNT   = entryCnt;
    lcPkt.entries          = entries;

    // --- Padding alignment ---
    int consumedBits = bitPos - startBit;
    int expectedBits = subLength * 8;
    uint8_t ucPadding_Bits = 0;
    if (consumedBits < expectedBits)
    {
        ucPadding_Bits = expectedBits - consumedBits;
        bitPos = startBit + expectedBits; // resync safely
    }
    return true;
}

bool KAVACH_PARSEPACKET::parseTurnoutSpeedProfile(const QByteArray &buf, int &bitPos, int subLength)
{
    int startBit = bitPos;
    tspPkt.SUB_PKT_TYPE        = static_cast<enmSubPktType>(getBits(buf, bitPos, 4));
    tspPkt.SUB_PKT_LENGTH      = static_cast<uint8_t>(getBits(buf, bitPos, 7));
    quint8 entryCnt  = getBits(buf, bitPos, 2);  // 5 bits = number of LC gate entries (1–31)

    QVector<TurnoutSpeedEntry> entries;
    entries.reserve(entryCnt);

    // --- Loop through each LC Gate Entry ---
    for (int i = 0; i < entryCnt; ++i)
    {
        TurnoutSpeedEntry stTSPEntry{};
        stTSPEntry.TO_SPEED    = getBits(buf, bitPos, 5); // meters (0–32767)
        stTSPEntry.DIFF_DIST_TO  = getBits(buf, bitPos, 15); // 1–1021 valid
        stTSPEntry.TO_SPEED_REL_DIST   = getBits(buf, bitPos, 12);  // 0–7 mapping suffix a/b/c…

        entries.push_back(stTSPEntry);
    }

    // --- Save into packet struct ---
    tspPkt.TO_CNT   = entryCnt;
    tspPkt.entries  = entries;

    // --- Padding alignment ---
    int consumedBits = bitPos - startBit;
    int expectedBits = subLength * 8;
    uint8_t ucPadding_Bits = 0;

    if (consumedBits < expectedBits)
    {
        ucPadding_Bits = expectedBits - consumedBits;


        bitPos = startBit + expectedBits; // resync safely
    }
    return true;
}

bool KAVACH_PARSEPACKET::parseTagLinkingInfo(const QByteArray &buf, int &bitPos, int subLength)
{
    int startBit = bitPos;
    tliPkt.SUB_PKT_TYPE        = static_cast<enmSubPktType>(getBits(buf, bitPos, 4));
    tliPkt.SUB_PKT_LENGTH      = static_cast<uint8_t>(getBits(buf, bitPos, 7));
    quint8 distDup  = getBits(buf, bitPos, 4);   // DIST_DUP_TAG (4)
    quint8 rfidCnt  = getBits(buf, bitPos, 6);   // ROUTE_RFID_CNT (6)

    QVector<TagLinkingEntry> entries;
    entries.reserve(rfidCnt);

    // --- Entries ---
    for (int i = 0; i < rfidCnt; ++i)
    {
        TagLinkingEntry entry{};
        entry.DIST_NXT_RFID   = getBits(buf, bitPos, 11);  // 0–2047
        entry.NXT_RFID_TAG_ID = getBits(buf, bitPos, 10);
        entry.DUP_TAG_DIR     = getBits(buf, bitPos, 1);
        entry.ABS_LOC_RESET   = getBits(buf, bitPos, 1);

        if (entry.ABS_LOC_RESET)
        {
            entry.ADJ_LOCO_DIST = getBits(buf, bitPos, 15);
            entry.ADJ_LOCO_DIR  = getBits(buf, bitPos, 2);
            entry.ABS_LOC_CORR  = getBits(buf, bitPos, 23);
            entry.ADJ_LINE_CNT  = getBits(buf, bitPos, 3);

            if (entry.ADJ_LINE_CNT <= 5)
            {
                int tinCount = entry.ADJ_LINE_CNT + 1;
                entry.LINE_TIN.resize(tinCount);

                for (int j = 0; j < tinCount; ++j)
                {
                    entry.LINE_TIN[j] = getBits(buf, bitPos, 9);
                }
            }
            else if (entry.ADJ_LINE_CNT == 6)
            {
                qWarning() << "ADJ_LINE_CNT=6 reserved";
            }
            else
            {
                qWarning() << "ADJ_LINE_CNT=7 unknown";
            }
        }

        entries.push_back(entry);

        qDebug() << "TLI[" << i << "] dist=" << entry.DIST_NXT_RFID
                 << "tagId=" << entry.NXT_RFID_TAG_ID
                 << "dupDir=" << entry.DUP_TAG_DIR
                 << "absLocReset=" << entry.ABS_LOC_RESET;
    }
    tliPkt.DIST_DUP_TAG   = distDup;
    tliPkt.ROUTE_RFID_CNT = rfidCnt;
    tliPkt.entries        = entries;

    int consumedBits = bitPos - startBit;
    int expectedBits = subLength * 8;
    uint8_t ucPadding_Bits = 0;
    if (consumedBits < expectedBits)
    {
        ucPadding_Bits = expectedBits - consumedBits;

        bitPos = startBit + expectedBits; // resync safely
    }

    return true;

}

bool KAVACH_PARSEPACKET::parseTrackCondition(const QByteArray &buf, int &bitPos, int subLength)
{
    int startBit = bitPos;
    tcdPkt.SUB_PKT_TYPE        = static_cast<enmSubPktType>(getBits(buf, bitPos, 4));
    tcdPkt.SUB_PKT_LENGTH      = static_cast<uint8_t>(getBits(buf, bitPos, 7));
    quint8 entryCnt   = getBits(buf, bitPos, 4);   // 5 bits (1–31 entries)

    QVector<TrackConditionEntry> entries;
    entries.reserve(entryCnt);

    // --- Entries parsing ---
    for (int i = 0; i < entryCnt; ++i)
    {
        TrackConditionEntry entry{};
        entry.TRACK_COND_TYPE        = getBits(buf, bitPos, 4);   // 4 bits
        entry.START_DIST_TRACKCOND   = getBits(buf, bitPos, 15);  // 15 bits
        entry.LENGTH_TRACKCOND       = getBits(buf, bitPos, 15);  // 15 bits

        entries.push_back(entry);
    }

    // --- Fill packet struct ---
    tcdPkt.TRACK_COND_CNT   = entryCnt;
    tcdPkt.entries          = entries;

    // --- Bit alignment check ---
    int consumedBits = bitPos - startBit;
    int expectedBits = subLength * 8;
    uint8_t ucPadding_Bits = 0;
    if (consumedBits < expectedBits)
    {
        ucPadding_Bits = expectedBits - consumedBits;
        qDebug() << "Gradient parse note: consumed" << consumedBits
                 << "bits, expected" << expectedBits
                 << "→ padding skipped =" << ucPadding_Bits;
        bitPos = startBit + expectedBits; // resync safely
    }

    return true;
}

bool KAVACH_PARSEPACKET::parseTempSpeedRestriction(const QByteArray &buf, int &bitPos, int subLength)
{
    int startBit = bitPos;
    tsrPkt.SUB_PKT_TYPE        = static_cast<enmSubPktType>(getBits(buf, bitPos, 4));
    tsrPkt.SUB_PKT_LENGTH      = static_cast<uint8_t>(getBits(buf, bitPos, 7));
    quint8 tsrStatus  = getBits(buf, bitPos, 2);  // 2 bits
    quint8 entryCnt   = getBits(buf, bitPos, 5);  // 5 bits (0–31)

    QVector<TSREntry> entries;
    entries.reserve(entryCnt);

    for (int i = 0; i < entryCnt; ++i)
    {
        TSREntry entry{};
        entry.TSR_ID              = getBits(buf, bitPos, 8);   // TSR ID
        entry.TSR_Distance        = getBits(buf, bitPos, 15);  // distance to TSR start
        entry.TSR_Length          = getBits(buf, bitPos, 15);  // TSR length
        entry.TSR_Class           = getBits(buf, bitPos, 1);   // 0=Universal, 1=Classified
        entry.TSR_Universal_Speed = getBits(buf, bitPos, 6);

        if (entry.TSR_Class == 1) {
            entry.TSR_ClassA_Speed = getBits(buf, bitPos, 6);
            entry.TSR_ClassB_Speed = getBits(buf, bitPos, 6);
            entry.TSR_ClassC_Speed = getBits(buf, bitPos, 6);
        }

        entry.TSR_Whistle         = getBits(buf, bitPos, 2);

        entries.push_back(entry);
    }

    // --- Fill packet struct ---
    tsrPkt.TSR_STATUS     = tsrStatus;
    tsrPkt.TSR_Info_CNT   = entryCnt;
    tsrPkt.entries        = entries;

    // --- Alignment check ---
    int consumedBits = bitPos - startBit;
    int expectedBits = subLength * 8;
    uint8_t ucPadding_Bits = 0;
    if (consumedBits < expectedBits)
    {
        ucPadding_Bits = expectedBits - consumedBits;
        qDebug() << "Gradient parse note: consumed" << consumedBits
                 << "bits, expected" << expectedBits
                 << "→ padding skipped =" << ucPadding_Bits;
        bitPos = startBit + expectedBits; // resync safely
    }

    return true;
}


bool KAVACH_PARSEPACKET::parseIncomingPacket(const QByteArray &data)
{
    int bitPos = 0;
    // Step 1: Parse Station Header
    if (!parseStationHeader(data, bitPos)) return false;
    int totalBytes = StnRglrHPkt.PKT_LENGTH ;

    if (totalBytes > data.size()) {
        qWarning() << "Packet truncated: expected" << totalBytes << "got" << data.size();
        return false;
    }

    int tototalpayloadbyte = data.size() - (PACKET_MAC_CRC_LEN  + 13);
    QByteArray ocByteSubData = QByteArray::fromRawData((data.constData() + 13),tototalpayloadbyte);

    int endBits = (ocByteSubData.size()*8);
    int startPos = 0;
    bitPos =0;

    while (startPos < endBits)
    {
        bitPos =0;
        int iStartPos1 = startPos;
        quint8 subType   = getBits(ocByteSubData, iStartPos1, 4);
        quint8 subLength = getBits(ocByteSubData, iStartPos1, 7);  // in bytes
        QByteArray ocByteSubData1 = QByteArray::fromRawData((ocByteSubData.constData() + startPos/8),subLength);
        startPos += subLength*8; // rewind before dispatch, so parser can re-read

        emit SigStationRegHeader(StnRglrHPkt);

        switch (subType)
        {
            case enmSubPktType::enmMovementAuthoritySubPkt: // = 0
            {
                if (!parseMovementAuthority(ocByteSubData1, bitPos, subLength))
                {
                    return false;
                }
                else
                {
                    emit SigInsertDBStnRegMASubPkt(maPkt);
                }
            }break;
            case enmSubPktType::enmStaticSpeedProfileSubPkt: // = 1
            {
                if (!parseStaticSpeedProfile(ocByteSubData1, bitPos, subLength))
                {
                    qDebug() <<"SSP False";

                    return false;
                }
                else
                {
                    emit SigInsertDBStnRegSSPSubPkt(sspPkt);
                }
            }break;
            case enmSubPktType::enmGradientProfileSubPkt: // = 2
            {
                if (!parseGradientProfile(ocByteSubData1, bitPos, subLength))
                {
                    return false;
                }
                else
                {
                    emit SigInsertDBStnRegGradientSubPkt(gradPkt);
                }
            }break;
            case enmSubPktType::enmLCGateSubPkt: // LC Gate
            {
                if (!parseLCGateProfile(ocByteSubData1, bitPos, subLength))
                {
                    return false;
                }
                else
                {
                    emit SigInsertDBStnRegLCGateSubPkt(lcPkt);
                }
            }break;
            case enmSubPktType::enmTurnoutSpeedProfileSubPkt:
            {
                if(!parseTurnoutSpeedProfile(ocByteSubData1, bitPos,subLength))
                {
                    return false;
                }
                else
                {
                    emit SigInsertDBStnRegTurnoutSpeedSubPkt(tspPkt);
                }
            }break;
            case enmSubPktType::enmTagLinkingInfSubPkt: // Tag Linking
            {
                if (!parseTagLinkingInfo(ocByteSubData1, bitPos,subLength))
                {
                    return false;
                }
                else
                {
                    emit SigInsertDBStnRegTagLinkingInfoSubPkt(tliPkt);
                }
            }break;
            case enmSubPktType::enmTrackConditionDataSubPkt: // Track Condition
            {
                if (!parseTrackCondition(ocByteSubData1, bitPos,subLength))
                {
                    return false;
                }
                else
                {
                    emit SigInsertDBStnRegTrackCondDataSubPkt(tcdPkt);
                }
            }break;
            case enmSubPktType::enmTempSpeedRestrctionProfileSubPkt: // TSR
            {
                if (!parseTempSpeedRestriction(ocByteSubData1, bitPos,subLength))
                {
                    return false;
                }
                else
                {
                    emit SigInsertDBStnRegTSRSubPkt(tsrPkt);
                }
            }break;
            default:
            {
                qWarning() << "Unknown subpacket type:" << subType;
            }break;
        }
    }

    // Step 3: Parse Footer (MAC + CRC)
    quint32 rxMac = getBits(data, bitPos, 32);
    quint32 rxCrc = getBits(data, bitPos, 32);

    quint32 calcCrc = crc32(data.left(totalBytes - 4)); // exclude CRC itself
    if (calcCrc != rxCrc) {
        qWarning() << "CRC mismatch! got" << rxCrc << "expected" << calcCrc;
        //return false;
    }

    //printParsedData();
    // Optional: verify CRC + MAC here
    return true;
}

void KAVACH_PARSEPACKET::printParsedData() const
{
    qDebug() << "========= Rx Header Packet =========";
    qDebug() << "PKT_TYPE:              " << StnRglrHPkt.PKT_TYPE ;
    qDebug() << "PKT_LENGTH:            " << StnRglrHPkt.PKT_LENGTH ;
    qDebug() << "FRAME_NUM:             " << StnRglrHPkt.FRAME_NUM ;
    qDebug() << "SOURCE_STN_ILC_IBS_ID: " << StnRglrHPkt.SOURCE_STN_ILC_IBS_ID ;
    qDebug() << "SOURCE_STN_ILC_IBS_VER:" << StnRglrHPkt.SOURCE_STN_ILC_IBS_VERSION ;
    qDebug() << "DEST_LOCO_ID:          " << StnRglrHPkt.DEST_LOCO_ID ;
    qDebug() << "REF_PROF_ID:           " << StnRglrHPkt.REF_PROF_ID ;
    qDebug() << "LAST_REF_RFID:         " << StnRglrHPkt.LAST_REF_RFID;
    qDebug() << "DIST_PKT_START:        " << StnRglrHPkt.DIST_PKT_START;
    qDebug() << "PKT_DIR:               " << StnRglrHPkt.PKT_DIR;
    qDebug() << "========= Movement Authority =========";

    qDebug() << "SUB_PKT_TYPE:      " << maPkt.SUB_PKT_TYPE;
    qDebug() << "SUB_PKT_LEN:       " << maPkt.SUB_PKT_LENGTH;
    qDebug() << "FRAME_OFFSET:      " << maPkt.FRAME_OFFSET;
    qDebug() << "DEST_LOCO_SOS:     " << maPkt.DEST_LOCO_SOS;
    qDebug() << "TRAIN_SECTION_TYPE:" << maPkt.TRAIN_SECTION_TYPE;
    qDebug() << "CUR_SIG_INFO.lineName:" << maPkt.CUR_SIG_INFO.lineName;
    qDebug() << "CUR_SIG_INFO.lineNumber:" << maPkt.CUR_SIG_INFO.lineNumber;
    qDebug() << "CUR_SIG_INFO.signalType:" << maPkt.CUR_SIG_INFO.signalType;

    qDebug() << "CUR_SIG_ASP:       " << maPkt.CUR_SIG_ASPECT;
    qDebug() << "NEXT_SIG_ASP:      " << maPkt.NEXT_SIG_ASPECT;
    qDebug() << "APPR_SIG_DIST:     " << maPkt.APPR_SIG_DIST;
    qDebug() << "AUTHORITY_TYPE:    " << maPkt.AUTHORITY_TYPE;
    qDebug() << "AUTHORIZED_SPEED:  " << maPkt.AUTHORIZED_SPEED;
    qDebug() << "MA_WRT_SIG:        " << maPkt.MA_WRT_SIG;
    qDebug() << "REQ_SHORTEN_MA:    " << maPkt.REQ_SHORTEN_MA;
    qDebug() << "NEW_MA:            " << maPkt.NEW_MA;
    qDebug() << "TRN_LEN_INFO_STS:  " << maPkt.TRN_LEN_INFO_STS;
    qDebug() << "TRN_LEN_INFO_TYPE: " << maPkt.TRN_LEN_INFO_TYPE;
    qDebug() << "REF_FRAME_NUM_TLM: " << maPkt.REF_FRAME_NUM_TLM;
    qDebug() << "REF_OFFSET_INT_TL: " << maPkt.REF_OFFSET_INT_TL;
    qDebug() << "NEXT_STN_COMM:     " << maPkt.NEXT_STN_COMM;
    qDebug() << "APPR_STN_ILC_IBS_ID:" << maPkt.APPR_STN_ILC_IBS_ID;

    qDebug() << "\n===== Static Speed Profile Packet =====";
    qDebug() << " SUB_PKT_TYPE       :" << sspPkt.SUB_PKT_TYPE;
    qDebug() << " SUB_PKT_LEN        :" << sspPkt.SUB_PKT_LENGTH;
    qDebug() << " LM_Speed_Info_CNT  :" << sspPkt.LM_Speed_Info_CNT;

    for (int i = 0; i < sspPkt.LM_Speed_Info_CNT; ++i) {
        const auto &entry = sspPkt.entries[i];
        qDebug() << "  Entry" << i
                 << "Dist=" << entry.LM_Static_Speed_Distance
                 << "Class=" << entry.LM_Static_Speed_Class;
        if (entry.LM_Static_Speed_Class == 0) {
            qDebug() << "    UniversalSpeed:" << entry.SpeedValue
                     << "=> " << entry.SpeedValue * 5 << " kmph";
        } else {
            qDebug() << "    SpeedA:" << entry.SpeedValue * 5
                   /*  << " SpeedB:" << entry.SpeedClassB * 5
                     << " SpeedC:" << entry.SpeedClassC * 5*/;
        }
    }

    ///////////////////////////////////////////////////////////////////////////////
    qDebug() << "\n===== Gradient Profile Packet =====";
    qDebug() << " SUB_PKT_TYPE       :" << gradPkt.SUB_PKT_TYPE;
    qDebug() << " SUB_PKT_LEN        :" << gradPkt.SUB_PKT_LENGTH;
    qDebug() << " LM_Grad_Info_CNT   :" << gradPkt.LM_Grad_Info_CNT;

    for (int i = 0; i < gradPkt.LM_Grad_Info_CNT; ++i) {
        const auto &entry = gradPkt.entries[i];
        qDebug() << "  Entry" << i
                 << "Dist=" << entry.LM_Gradient_Distance
                 << " Dir=" << (entry.LM_GDIR ? "Uphill" : "Downhill")
                 << " Value=" << entry.LM_Gradient_Value;
    }

    ///////////////////////////////////////////////////////////////////////////////
    qDebug() << "\n===== LC Gate Profile Packet =====";
    qDebug() << " SUB_PKT_TYPE       :" << lcPkt.SUB_PKT_TYPE;
    qDebug() << " SUB_PKT_LEN        :" << lcPkt.SUB_PKT_LENGTH;
    qDebug() << " LM_LC_Info_CNT     :" << lcPkt.LM_LC_Info_CNT;

    for (int i = 0; i < lcPkt.LM_LC_Info_CNT; ++i) {
        const auto &entry = lcPkt.entries[i];
        qDebug() << "  Entry" << i
                 << " Dist=" << entry.LM_LC_Distance
                 << " ID=" << entry.LM_LC_ID_Numeric
                 << (entry.LM_LC_ID_Suffix
                         ? QString(QChar('a' + entry.LM_LC_ID_Suffix - 1))
                         : QString("-"))
                 << " Manning=" << (entry.LM_LC_Manning ? "Unmanned" : "Manned")
                 << " Class=" << entry.LM_LC_Class
                 << " AW=" << (entry.LM_LC_AW_Enabled ? "Yes" : "No")
                 << " AWType=" << entry.LM_LC_AW_Type;
    }

    /////////////////////////////////////////////////////////////////////
    qDebug() << "\n=====Turnout Speed Profile Packet =====";
    qDebug() << " SUB_PKT_TYPE       :" << tspPkt.SUB_PKT_TYPE;
    qDebug() << " SUB_PKT_LEN        :" << tspPkt.SUB_PKT_LENGTH;
    qDebug() << " LM_LC_Info_CNT     :" << tspPkt.TO_CNT;

    for (int i = 0; i < tspPkt.TO_CNT; ++i)
    {
        const auto &entry = tspPkt.entries[i];
        qDebug() << "  Entry" << i;
        qDebug() << " TO_SPEED=" << entry.TO_SPEED;
        qDebug() << " DIFF_DIST_TO=" << entry.DIFF_DIST_TO;
        qDebug() << " TO_SPEED_REL_DIST=" << entry.TO_SPEED_REL_DIST;
    }

    ///////////////////////////////////////////////////////////////////////////////
    qDebug() << "\n===== Tag Linking Information Packet =====";
    qDebug() << " SUB_PKT_TYPE       :" << tliPkt.SUB_PKT_TYPE;
    qDebug() << " SUB_PKT_LEN        :" << tliPkt.SUB_PKT_LENGTH;
    qDebug() << " DIST_DUP_TAG       :" << tliPkt.DIST_DUP_TAG;
    qDebug() << " ROUTE_RFID_CNT     :" << tliPkt.ROUTE_RFID_CNT;

    for (int i = 0; i < tliPkt.entries.size(); ++i) {
        const auto &e = tliPkt.entries[i];
        qDebug() << "   Entry" << i;
        qDebug() << "   DIST_NXT_RFID    :" << e.DIST_NXT_RFID;
        qDebug() << "   NXT_RFID_TAG_ID  :" << e.NXT_RFID_TAG_ID;
        qDebug() << "   DUP_TAG_DIR      :" << e.DUP_TAG_DIR;
        qDebug() << "   ABS_LOC_RESET      :" << e.ABS_LOC_RESET;
        qDebug() << "   LOC_RESET_START_DIST :" << e.ADJ_LOCO_DIST;
        qDebug() << "   ADJ_LOCO_DIR         :" << e.ADJ_LOCO_DIR;
        qDebug() << "   ABS_LOC_CORRECTION   :" << e.ABS_LOC_CORR;
        qDebug() << " ADJ_LINE_CNT       :" << e.ADJ_LINE_CNT;

       // qDebug() << "  LINE_TIN[" "]:" << e.LINE_TIN[i];
    }

    ///////////////////////////////////////////////////////////////////////////////
    qDebug() << "\n===== Track Condition Data Packet =====";
    qDebug() << " SUB_PKT_TYPE       :" << tcdPkt.SUB_PKT_TYPE;
    qDebug() << " SUB_PKT_LEN        :" << tcdPkt.SUB_PKT_LENGTH;
    qDebug() << " TRACK_COND_CNT     :" << tcdPkt.TRACK_COND_CNT;

    for (int i = 0; i < tcdPkt.entries.size(); ++i) {
        const auto &e = tcdPkt.entries[i];
        qDebug() << "  Entry" << i;
        qDebug() << "   TRACK_COND_TYPE    :" << e.TRACK_COND_TYPE;
        qDebug() << "   START_DIST_TRACKCOND:" << e.START_DIST_TRACKCOND;
        qDebug() << "   LENGTH_TRACKCOND   :" << e.LENGTH_TRACKCOND;
    }

    qDebug() << "\n===== Temporary Speed Restriction Packet =====";
    qDebug() << " SUB_PKT_TYPE  :" << tsrPkt.SUB_PKT_TYPE;
    qDebug() << " SUB_PKT_LEN   :" << tsrPkt.SUB_PKT_LENGTH;
    qDebug() << " TSR_STATUS    :" << tsrPkt.TSR_STATUS;
    qDebug() << " TSR_Info_CNT  :" << tsrPkt.TSR_Info_CNT;

    for (int i = 0; i < tsrPkt.entries.size(); ++i) {
        const auto &entry = tsrPkt.entries[i];
        qDebug() << " --- Entry" << i+1 << " ---";
        qDebug() << " TSR_ID        :" << entry.TSR_ID;
        qDebug() << " TSR_Distance  :" << entry.TSR_Distance;
        qDebug() << " TSR_Length    :" << entry.TSR_Length;
        qDebug() << " TSR_Class     :" << entry.TSR_Class;

        if (entry.TSR_Class == 0) {
            qDebug() << "  Universal Speed :" << entry.TSR_Universal_Speed * 5 << "kmph";
        } else {
            qDebug() << "  Class A Speed   :" << entry.TSR_ClassA_Speed * 5 << "kmph";
            qDebug() << "  Class B Speed   :" << entry.TSR_ClassB_Speed * 5 << "kmph";
            qDebug() << "  Class C Speed   :" << entry.TSR_ClassC_Speed * 5 << "kmph";
        }
        qDebug() << " TSR_Whistle   :" << entry.TSR_Whistle;
    }


    qDebug() << "=======================================================================";
    qDebug() << "=======================================================================";
}

quint32 KAVACH_PARSEPACKET::crc32(const QByteArray& data)
{
    static quint32 table[256];
    static bool inited = false;
    if (!inited) {
        for (quint32 i = 0; i < 256; ++i) {
            quint32 c = i;
            for (int j = 0; j < 8; ++j)
                c = (c & 1) ? (0xEDB88320U ^ (c >> 1)) : (c >> 1);
            table[i] = c;
        }
        inited = true;
    }
    quint32 c = 0xFFFFFFFFU;
    for (uchar ch : data)
        c = table[(c ^ ch) & 0xFFU] ^ (c >> 8);
    return c ^ 0xFFFFFFFFU;
}

// Default MAC = CRC32 over (DEST_LOCO_ID || payload)
// Replace with official algorithm when provided.
quint32 KAVACH_PARSEPACKET::computeMacCode(const QByteArray& payload, quint32 destLocoId)
{
    QByteArray seeded;
    QDataStream ds(&seeded, QIODevice::WriteOnly);
    ds.setByteOrder(QDataStream::LittleEndian);
    ds << destLocoId;
    seeded.append(payload);
    return crc32(seeded);
}
