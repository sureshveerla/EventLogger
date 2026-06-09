#ifndef KAVACH_PARSEPACKET_H
#define KAVACH_PARSEPACKET_H

#include <QVector>

#include "nmsStructs.h"
#include "nmsEnum.h"
#include "nmsDefines.h"
#include "nmsQtInc.h"

class KAVACH_PARSEPACKET : public QObject
{
    Q_OBJECT
public:
    explicit KAVACH_PARSEPACKET(QObject* parent=nullptr);
    // Main API
    bool parseIncomingPacket(const QByteArray &data);
    void printParsedData() const;

signals:

    void SigInsertDBStnRegMASubPkt(MovementAuthorityPkt stMAPkt);
    void SigInsertDBStnRegSSPSubPkt(StaticSpeedProfilePkt stSSPPkt);
    void SigInsertDBStnRegGradientSubPkt(GradientProfilePkt stGradprofPkt);
    void SigInsertDBStnRegLCGateSubPkt(LCGateProfilePkt stLCGatePkt);
    void SigInsertDBStnRegTurnoutSpeedSubPkt(TurnoutSpeedProfilePkt stTSPPkt);
    void SigInsertDBStnRegTagLinkingInfoSubPkt(TagLinkingInfoPkt stTagLinkInfPkt);
    void SigInsertDBStnRegTrackCondDataSubPkt(TrackConditionPkt stTrackCondDataPkt);
    void SigInsertDBStnRegTSRSubPkt(TempSpeedRestrictionPkt stTSRPkt);



    void SigStationRegHeader(StationRegularHeader stStnRglrHPkt);
private:
    // === Bit extractors ===
    quint64 getBits(const QByteArray &buf, int &bitPos, int bits) const;
    qint64  getSignedBits(const QByteArray &buf, int &bitPos, int bits) const;
    stAccessRequestPkt m_stHeader2;

    static quint32 crc32(const QByteArray& data);
    static quint32 computeMacCode(const QByteArray& headerPlusSubs, quint32 destLocoId);

    // === Sub-packet parsers ===
    bool parseStationHeader(const QByteArray &buf, int &bitPos);
    bool parseMovementAuthority(const QByteArray &buf, int &bitPos, int subLength);
    bool parseStaticSpeedProfile(const QByteArray &data, int &bitPos, int subLength);

    bool parseGradientProfile(const QByteArray &buf, int &bitPos,int subLength);
    bool parseLCGateProfile(const QByteArray &buf, int &bitPos, int subLength);
    bool parseTurnoutSpeedProfile(const QByteArray &buf, int &bitPos, int subLength);

    bool parseTagLinkingInfo(const QByteArray &buf, int &bitPos, int subLength);
    bool parseTrackCondition(const QByteArray &buf, int &bitPos, int subLength);
    bool parseTempSpeedRestriction(const QByteArray &buf, int &bitPos, int subLength);

    // === Data structures ===
    StationRegularHeader StnRglrHPkt;
    MovementAuthorityPkt maPkt;
    StaticSpeedProfilePkt sspPkt;
    GradientProfilePkt gradPkt;
    LCGateProfilePkt lcPkt;
    TurnoutSpeedProfilePkt tspPkt;
    TagLinkingInfoPkt tliPkt;
    TrackConditionPkt tcdPkt;
    TempSpeedRestrictionPkt tsrPkt;
};

#endif // KAVACH_PARSEPACKET_H
