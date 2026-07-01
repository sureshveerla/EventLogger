#include "include/nmsDBQuerys.h"

nmsDBQuerys::nmsDBQuerys(NMSDB *pcDB, QObject *pcParent)
    : QObject(pcParent),m_pcDB((NMSDB*)pcDB),m_strFirmName('\0'),m_ulPktId(0)
{

}

void nmsDBQuerys::SlotFaultPktInserttoDB(stKavachtoNMS *pstKavachtoNMS, QString strFaultsCode, QString strFaultMsg)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(pstKavachtoNMS->usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(pstKavachtoNMS->ucMsgType,0,16).toUpper();
    QString strKavachTyp = QString("0x%1").arg(pstKavachtoNMS->ucKavachType,0,16).toUpper();
    QString strCrc = QString("0x%1").arg(pstKavachtoNMS->uiCRC,0,16).toUpper();



    m_uiStationID = (pstKavachtoNMS->ucKavachSubsysID[0] << 16) |
                    (pstKavachtoNMS->ucKavachSubsysID[1] << 8)  |
                     pstKavachtoNMS->ucKavachSubsysID[2];

    QString strQuery = QString("INSERT INTO public.faultspacket("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"DATE\", \"TIME\", "
                               "\"KAVACH_TYPE\", \"KAVACH_SUBSYS_ID\", \"TOTAL_FAULTS_CODES\", "
                               "\"FAULT_CODE\", \"FAULT_MSG\", \"CRC\")"
                                 "VALUES ('%1', '%2', '%3', '%4', '%5','%6', '%7', %8, '%9','%10','%11')")
                                 .arg(strStrtFrm)
                                 .arg(strmsgtyp)
                                 .arg(pstKavachtoNMS->usmsgLength)
                                 .arg(strdate)
                                 .arg(strtime)
                                 .arg(strKavachTyp)
                                 .arg(m_uiStationID)
                                 .arg(pstKavachtoNMS->ucTotalFaultsCode)
                                 .arg(strFaultsCode)
                                 .arg(strFaultMsg)
                                 .arg(strCrc);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the fault packet into database";
    }
    else
    {
        qDebug () << "Failed to insert the fault packet into database";
    }


}

void nmsDBQuerys::SlotStnFaultPktInserttoDB(stStationFaults *pstStnFaults, QStringList strLstModuleID,
                                            QStringList strLstFaultCodeTyp, QStringList strFaultsCode, QStringList strFaultMsg)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strStrtFrm = QString("0x%1").arg(pstStnFaults->usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(pstStnFaults->ucMsgType,0,16).toUpper();
    QString strKavachTyp = QString("0x%1").arg(pstStnFaults->ucKavachType,0,16).toUpper();
    QString strCrc = QString("0x%1").arg(pstStnFaults->uiCRC,0,16).toUpper();
    QString strDate = QString("20%1-%2-%3")
                          .arg(pstStnFaults->ucDate[2], 2, 10, QChar('0'))
                          .arg(pstStnFaults->ucDate[1], 2, 10, QChar('0'))
                          .arg(pstStnFaults->ucDate[0], 2, 10, QChar('0'));
    QString strtime = QString("%1:%2:%3")
                          .arg(pstStnFaults->ucTime[0])
                          .arg(pstStnFaults->ucTime[1])
                          .arg(pstStnFaults->ucTime[2]);
    m_uiStationID = (pstStnFaults->ucKavachSubsysID[0] << 16) |
                    (pstStnFaults->ucKavachSubsysID[1] << 8)  |
                    pstStnFaults->ucKavachSubsysID[2];
    QString fc[10];
    QString mc[10];
    QString fm[10];
    QString ft[10];

    for(int i = 0; i < 10; i++)
    {
        mc[i] = (i < strLstModuleID.size()) ? QString("%1").arg(strLstModuleID[i]) : "NULL";   // keep as-        ft[i] = (i < strLstFaultCodeTyp.size()) ? QString("%1").arg(strLstFaultCodeTyp[i]) : "NULL";   // keep as-is
        fm[i] = (i < strFaultMsg.size()) ? QString("%1").arg(strFaultMsg[i]) : "NULL";
        fc[i] = (i < strFaultsCode.size()) ? QString("%1").arg(strFaultsCode[i]) : "NULL";   // keep as-is
    }
    QString strQuery = QString("INSERT INTO public.stationfaultspkt("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", \"KAVACH_SUBSYSTEM_ID\","
                               "\"NMS_SYSTEM_ID\", \"SYSTEM_VER\", \"DATE\", \"TIME\", \"KAVACH_TYPE\", "
                               "\"TOTAL_FAULTS_CODES\", \"MODULE_ID_1\", \"MODULE_ID_2\", "
                               "\"MODULE_ID_3\", \"MODULE_ID_4\", \"MODULE_ID_5\", \"MODULE_ID_6\", "
                               "\"MODULE_ID_7\", \"MODULE_ID_8\", \"MODULE_ID_9\", \"MODULE_ID_10\", "
                               "\"FAULT_CODE_TYPE_1\", \"FAULT_CODE_TYPE_2\", \"FAULT_CODE_TYPE_3\", "
                               "\"FAULT_CODE_TYPE_4\", \"FAULT_CODE_TYPE_5\", \"FAULT_CODE_TYPE_6\", "
                               "\"FAULT_CODE_TYPE_7\", \"FAULT_CODE_TYPE_8\", \"FAULT_CODE_TYPE_9\", "
                               "\"FAULT_CODE_TYPE_10\", \"FAULT_CODE_1\", \"FAULT_CODE_2\", "
                               "\"FAULT_CODE_3\", \"FAULT_CODE_4\", \"FAULT_CODE_5\", \"FAULT_CODE_6\", "
                               "\"FAULT_CODE_7\", \"FAULT_CODE_8\", \"FAULT_CODE_9\", \"FAULT_CODE_10\", "
                               "\"MSG_1\", \"MSG_2\", \"MSG_3\", \"MSG_4\", \"MSG_5\", \"MSG_6\", "
                               "\"MSG_7\", \"MSG_8\", \"MSG_9\", \"MSG_10\", \"CRC\")"
                               "VALUES ('%1','%2','%3', %4, %5,%6, %7,'%8','%9','%10',%11,"
                               "'%12','%13','%14','%15','%16','%17','%18','%19','%20','%21','%22','%23','%24','%25',"
                               "'%26','%27','%28','%29','%30','%31','%32','%33','%34','%35','%36','%37','%38','%39',"
                               "'%40','%41','%42','%43','%44','%45','%46','%47','%48','%49','%50','%51','%52')")
                           .arg(strStrtFrm)
                           .arg(strmsgtyp)
                           .arg(pstStnFaults->usmsgLength)
                           .arg(pstStnFaults->usMsgSeq)
                           .arg(m_uiStationID)
                           .arg(pstStnFaults->usNMSID)
                           .arg(pstStnFaults->ucVersion)
                           .arg(strDate)
                           .arg(strtime)
                           .arg(strKavachTyp)
                           .arg(pstStnFaults->ucTotalFaultsCode)
                           .arg(mc[0]).arg(mc[1]).arg(mc[2]).arg(mc[3]).arg(mc[4])
                           .arg(mc[5]).arg(mc[6]).arg(mc[7]).arg(mc[8]).arg(mc[9])
                           .arg(ft[0]).arg(ft[1]).arg(ft[2]).arg(ft[3]).arg(ft[4])
                           .arg(ft[5]).arg(ft[6]).arg(ft[7]).arg(ft[8]).arg(ft[9])
                           .arg(fc[0]).arg(fc[1]).arg(fc[2]).arg(fc[3]).arg(fc[4])
                           .arg(fc[5]).arg(fc[6]).arg(fc[7]).arg(fc[8]).arg(fc[9])
                           .arg(fm[0]).arg(fm[1]).arg(fm[2]).arg(fm[3]).arg(fm[4])
                           .arg(fm[5]).arg(fm[6]).arg(fm[7]).arg(fm[8]).arg(fm[9])
                           .arg(strCrc);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the fault packet into database";
    }
    else
    {
        qDebug () << "Failed to insert the fault packet into database";
        qDebug() << "DB ERROR:" << pcQuery->lastError().text();
        qDebug() << "QUERY:" << strQuery;
    }

}

void nmsDBQuerys::SlotStationInfo()
{
    uint16_t usRowCount = 0;

    uint8_t ucColCount = 0;

    QString strSql = NULL;
    strSql = QString("SELECT * FROM stations_info");

    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    bool bQryResult = pcQuery->exec(strSql);

    // Get and print field names
    QStringList strlstFldNames,
        strlstrowValues;

    if ((bQryResult == true))
    {
        QSqlRecord record = pcQuery->record();
        ucColCount = record.count();

        for (uint16_t ucIndx = 0U; ucIndx < ucColCount; ucIndx++)
        {
            strlstFldNames.append(pcQuery->record().fieldName(ucIndx));
        }

        while (pcQuery->next() == true)
        {
            for (uint16_t ucIndx = 0U; ucIndx < ucColCount; ucIndx++)
            {
                strlstrowValues.append(pcQuery->value(ucIndx).toString());
            }
            usRowCount++;
        }
    }
    emit SigDBStationInfo(ucColCount,usRowCount,strlstFldNames,strlstrowValues);
}

void nmsDBQuerys::SlotLocoInfo()
{
    uint16_t usRowCount = 0;

    uint8_t ucColCount = 0;

    QString strSql = NULL;
    strSql = QString("SELECT * FROM loco_info");

    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    bool bQryResult = pcQuery->exec(strSql);

    // Get and print field names
    QStringList strlstFldNames,
                strlstrowValues;

    if ((bQryResult == true))
    {
        QSqlRecord record = pcQuery->record();
        ucColCount = record.count();

        for (uint16_t ucIndx = 0U; ucIndx < ucColCount; ucIndx++)
        {
            strlstFldNames.append(pcQuery->record().fieldName(ucIndx));
        }

        while (pcQuery->next() == true)
        {
            for (uint16_t ucIndx = 0U; ucIndx < ucColCount; ucIndx++)
            {
                strlstrowValues.append(pcQuery->value(ucIndx).toString());
            }
            usRowCount++;
        }
    }
    emit SigDBLocoInfo(ucColCount,usRowCount,strlstFldNames,strlstrowValues);

    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotPrvPromptInfo()
{
    QList<QStringList> listAllRows;
    QStringList strlstFldNames;
    uint8_t ucColCount = 0;
    uint16_t usRowCount = 0;

    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QStringList tableQueries = {
        "SELECT * FROM public.hbl_faultcodes",
        "SELECT * FROM public.sms_hbl_faultinfo",
        "SELECT * FROM public.medha_faultcodes",
        "SELECT * FROM public.sms_medha_faultinfo"
    };

    for (const QString &queryStr : tableQueries)
    {
        if (pcQuery->exec(queryStr)) {
            QSqlRecord record = pcQuery->record();
            int colCount = record.count();

            // Set header names only once (you may want to customize this)
            if (strlstFldNames.isEmpty()) {
                for (int i = 0; i < colCount; ++i) {
                    strlstFldNames.append(record.fieldName(i));
                }
            }

            while (pcQuery->next())
            {
                QStringList rowData;
                for (int i = 0; i < colCount; ++i)
                {
                    rowData << pcQuery->value(i).toString();
                }
                listAllRows.append(rowData);
                usRowCount++;
            }
        } else {
            qWarning() << "Query failed:" << pcQuery->lastError().text();
        }
    }

    emit SigDBSMSFaultsinfo(ucColCount, usRowCount, strlstFldNames, listAllRows);

    delete pcQuery;
}

// void nmsDBQuerys::SlotFaultMsginserttoDB(QString strMsgType, QString strTimestamp,
//                                          QList<uint16_t> faultByteArray,
//                                          QString strFirmNam, uint32_t uiID)
// {
//     for (int bit = 0; bit < 24; ++bit)
//     {
//         int byteIndex = bit / 8;
//         int bitIndex = bit % 8;

//         if (faultByteArray[byteIndex] & (1 << bitIndex))
//         {
//             uint16_t faultCode = bit + 1;  // 1-based fault code
//             QString strFaultMsg;

//             switch (faultCode)
//             {
//                 case 1: strFaultMsg = FAULT_CODE_01; break;
//                 case 2: strFaultMsg = FAULT_CODE_02; break;
//                 case 3: strFaultMsg = FAULT_CODE_03; break;
//                 case 4: strFaultMsg = FAULT_CODE_04; break;
//                 case 5: strFaultMsg = FAULT_CODE_05; break;
//                 case 6: strFaultMsg = FAULT_CODE_06; break;
//                 case 7: strFaultMsg = FAULT_CODE_07; break;
//                 case 8: strFaultMsg = FAULT_CODE_08; break;
//                 case 9: strFaultMsg = FAULT_CODE_09; break;
//                 case 10: strFaultMsg = FAULT_CODE_10; break;
//                 case 11: strFaultMsg = FAULT_CODE_11; break;
//                 case 12: strFaultMsg = FAULT_CODE_12; break;
//                 case 13: strFaultMsg = FAULT_CODE_13; break;
//                 case 14: strFaultMsg = FAULT_CODE_14; break;
//                 case 15: strFaultMsg = FAULT_CODE_15; break;
//                 case 16: strFaultMsg = FAULT_CODE_16; break;
//                 case 17: strFaultMsg = FAULT_CODE_17; break;
//                 case 18: strFaultMsg = FAULT_CODE_18; break;
//                 case 19: strFaultMsg = FAULT_CODE_19; break;
//                 case 20: strFaultMsg = FAULT_CODE_20; break;
//                 case 21: strFaultMsg = FAULT_CODE_21; break;
//                 case 22: strFaultMsg = FAULT_CODE_22; break;
//                 case 23: strFaultMsg = FAULT_CODE_23; break;
//                 case 24: strFaultMsg = FAULT_CODE_24; break;
//                 default: strFaultMsg = "Unknown Fault"; break;
//             }

//             if (m_strFirmName == "SANA")  // HBL Replace SANA
//             {
//               InsertHBLFaultMsg(strMsgType,strTimestamp, faultCode,strFirmNam,uiID,strFaultMsg);
//             }
//             else
//             {
//               InsertMEDHAFaultMsg(strMsgType,strTimestamp,faultCode,strFirmNam,uiID,strFaultMsg);
//             }
//         }
//     }
// }

void nmsDBQuerys::SlotFaultMsginserttoDB(QString strMsgType, QString strTimestamp,
                                         QList<uint16_t> faultByteArray,
                                         QString strFirmNam, uint32_t uiID)
{

    QStringList strlstFaultsCode, strlstFaultsDesc ;
    QString strFaultMsg = NULL;


    for (uint16_t faultCode : faultByteArray)
    {
        strlstFaultsCode.append(QString("0x%1").arg(faultCode, 2, 16, QLatin1Char('0')).toUpper());

        switch (faultCode)
        {
            case 1: strFaultMsg = FAULT_CODE_01; break;
            case 2: strFaultMsg = FAULT_CODE_02; break;
            case 3: strFaultMsg = FAULT_CODE_03; break;
            case 4: strFaultMsg = FAULT_CODE_04; break;
            case 5: strFaultMsg = FAULT_CODE_05; break;
            case 6: strFaultMsg = FAULT_CODE_06; break;
            case 7: strFaultMsg = FAULT_CODE_07; break;
            case 8: strFaultMsg = FAULT_CODE_08; break;
            case 9: strFaultMsg = FAULT_CODE_09; break;
            case 10: strFaultMsg = FAULT_CODE_10; break;
            case 11: strFaultMsg = FAULT_CODE_11; break;
            case 12: strFaultMsg = FAULT_CODE_12; break;
            case 13: strFaultMsg = FAULT_CODE_13; break;
            case 14: strFaultMsg = FAULT_CODE_14; break;
            case 15: strFaultMsg = FAULT_CODE_15; break;
            case 16: strFaultMsg = FAULT_CODE_16; break;
            case 17: strFaultMsg = FAULT_CODE_17; break;
            case 18: strFaultMsg = FAULT_CODE_18; break;
            case 19: strFaultMsg = FAULT_CODE_19; break;
            case 20: strFaultMsg = FAULT_CODE_20; break;
            case 21: strFaultMsg = FAULT_CODE_21; break;
            case 22: strFaultMsg = FAULT_CODE_22; break;
            case 23: strFaultMsg = FAULT_CODE_23; break;
            case 24: strFaultMsg = FAULT_CODE_24; break;
            default: strFaultMsg = "Unknown Fault"; break;
        }
        strlstFaultsDesc.append(strFaultMsg);
    }
    QString strFaultsCode = strlstFaultsCode.join(",");   // comma-separated
    QString strFaultsDesc = strlstFaultsDesc.join(",");
    qDebug() << "Joined Faults:" << strFaultsCode << strFaultsDesc;

    if (m_strFirmName == "SANA")  // HBL Replace SANA
    {
        InsertHBLFaultMsg(strMsgType,strTimestamp, strFaultsCode,strFirmNam,uiID,strFaultsDesc);
    }
    else if(m_strFirmName == "SaNa")
    {
        InsertHBLFaultMsg(strMsgType,strTimestamp, strFaultsCode,strFirmNam,uiID,strFaultsDesc);
    }
    else if(m_strFirmName == "sana")
    {
        InsertHBLFaultMsg(strMsgType,strTimestamp, strFaultsCode,strFirmNam,uiID,strFaultsDesc);
    }
    else
    {
        //InsertMEDHAFaultMsg(strMsgType,strTimestamp,strFaultsCode,strFirmNam,uiID,strFaultsDesc);
    }
}

void nmsDBQuerys::SlotStnFaultMsginserttoDB(QString strMsgType, QString strTimestamp,
                                            uint16_t usFaultCode, QString strFirmNam, uint32_t uiID)
{
    QString strFaultMsg;
    switch (usFaultCode)
    {
       case 0: strFaultMsg = FAULT_CODE_01; break;
       case 1: strFaultMsg = FAULT_CODE_02; break;
       case 2: strFaultMsg = FAULT_CODE_03; break;
       case 3: strFaultMsg = FAULT_CODE_04; break;
       case 4: strFaultMsg = FAULT_CODE_05; break;
       case 5: strFaultMsg = FAULT_CODE_06; break;
       case 6: strFaultMsg = FAULT_CODE_07; break;
       case 7: strFaultMsg = FAULT_CODE_08; break;
       case 8: strFaultMsg = FAULT_CODE_09; break;
       case 9: strFaultMsg = FAULT_CODE_10; break;
       case 10: strFaultMsg = FAULT_CODE_11; break;
       case 11: strFaultMsg = FAULT_CODE_12; break;
       case 12: strFaultMsg = FAULT_CODE_13; break;
       case 13: strFaultMsg = FAULT_CODE_14; break;
       case 14: strFaultMsg = FAULT_CODE_15; break;
       case 15: strFaultMsg = FAULT_CODE_16; break;
       case 16: strFaultMsg = FAULT_CODE_17; break;
       case 17: strFaultMsg = FAULT_CODE_18; break;
       case 18: strFaultMsg = FAULT_CODE_19; break;
       case 19: strFaultMsg = FAULT_CODE_20; break;
       case 20: strFaultMsg = FAULT_CODE_21; break;
       case 21: strFaultMsg = FAULT_CODE_22; break;
       case 22: strFaultMsg = FAULT_CODE_23; break;
       case 23: strFaultMsg = FAULT_CODE_24; break;
       default: strFaultMsg = "Unknown Fault"; break;
    }

    if (m_strFirmName == "SANA")  // HBL Replace SANA
    {
       // InsertHBLFaultMsg(strMsgType,strTimestamp, usFaultCode,strFirmNam,uiID,strFaultMsg);
    }
    else
    {
       // InsertMEDHAFaultMsg(strMsgType,strTimestamp,usFaultCode,strFirmNam,uiID,strFaultMsg);
    }
}

void nmsDBQuerys::SlotSMSFaultMsginserttoDB(QString strMsgType, QString strTimestamp,
                                            QList<uint16_t> faultByteArray, QString strFirmnamID)
{
    QStringList strlstFaultsCode, strlstFaultsDesc ;
    QString strFaultMsg = NULL;


    for (uint16_t faultCode : faultByteArray)
    {
        strlstFaultsCode.append(QString("0x%1").arg(faultCode, 2, 16, QLatin1Char('0')).toUpper());

        switch (faultCode)
        {
               case 1: strFaultMsg = FAULT_CODE_01; break;
               case 2: strFaultMsg = FAULT_CODE_02; break;
               case 3: strFaultMsg = FAULT_CODE_03; break;
               case 4: strFaultMsg = FAULT_CODE_04; break;
               case 5: strFaultMsg = FAULT_CODE_05; break;
               case 6: strFaultMsg = FAULT_CODE_06; break;
               case 7: strFaultMsg = FAULT_CODE_07; break;
               case 8: strFaultMsg = FAULT_CODE_08; break;
               case 9: strFaultMsg = FAULT_CODE_09; break;
               case 10: strFaultMsg = FAULT_CODE_10; break;
               case 11: strFaultMsg = FAULT_CODE_11; break;
               case 12: strFaultMsg = FAULT_CODE_12; break;
               case 13: strFaultMsg = FAULT_CODE_13; break;
               case 14: strFaultMsg = FAULT_CODE_14; break;
               case 15: strFaultMsg = FAULT_CODE_15; break;
               case 16: strFaultMsg = FAULT_CODE_16; break;
               case 17: strFaultMsg = FAULT_CODE_17; break;
               case 18: strFaultMsg = FAULT_CODE_18; break;
               case 19: strFaultMsg = FAULT_CODE_19; break;
               case 20: strFaultMsg = FAULT_CODE_20; break;
               case 21: strFaultMsg = FAULT_CODE_21; break;
               case 22: strFaultMsg = FAULT_CODE_22; break;
               case 23: strFaultMsg = FAULT_CODE_23; break;
               case 24: strFaultMsg = FAULT_CODE_24; break;
               default: strFaultMsg = "Unknown Fault"; break;
        }
         strlstFaultsDesc.append(strFaultMsg);
    }
    QString strFaultsCode = strlstFaultsCode.join(",");   // comma-separated
    QString strFaultsDesc = strlstFaultsDesc.join(",");
    qDebug() << "Joined Faults:" << strFaultsCode << strFaultsDesc;
    if (m_strFirmName == "SANA")
    {
        InsertSMSHBLFaultMsg(strMsgType,strTimestamp,strFaultsCode,strFirmnamID,strFaultsDesc);
    }
    else
    {
       // InsertSMSMEDHAFaultMsg(strMsgType,strTimestamp,strFaultsCode,strFirmnamID,strFaultsDesc);
    }
}

void nmsDBQuerys::SlotSMSStnFaultMsginserttoDB(QString strMsgType, QString strTimestamp,
                                               uint16_t usFaultCOde, QString strFirmNamID)
{
    QString strFaultMsg;
    switch (usFaultCOde)
    {
        case 0: strFaultMsg = FAULT_CODE_01; break;
        case 1: strFaultMsg = FAULT_CODE_02; break;
        case 2: strFaultMsg = FAULT_CODE_03; break;
        case 3: strFaultMsg = FAULT_CODE_04; break;
        case 4: strFaultMsg = FAULT_CODE_05; break;
        case 5: strFaultMsg = FAULT_CODE_06; break;
        case 6: strFaultMsg = FAULT_CODE_07; break;
        case 7: strFaultMsg = FAULT_CODE_08; break;
        case 8: strFaultMsg = FAULT_CODE_09; break;
        case 9: strFaultMsg = FAULT_CODE_10; break;
        case 10: strFaultMsg = FAULT_CODE_11; break;
        case 11: strFaultMsg = FAULT_CODE_12; break;
        case 12: strFaultMsg = FAULT_CODE_13; break;
        case 13: strFaultMsg = FAULT_CODE_14; break;
        case 14: strFaultMsg = FAULT_CODE_15; break;
        case 15: strFaultMsg = FAULT_CODE_16; break;
        case 16: strFaultMsg = FAULT_CODE_17; break;
        case 17: strFaultMsg = FAULT_CODE_18; break;
        case 18: strFaultMsg = FAULT_CODE_19; break;
        case 19: strFaultMsg = FAULT_CODE_20; break;
        case 20: strFaultMsg = FAULT_CODE_21; break;
        case 21: strFaultMsg = FAULT_CODE_22; break;
        case 22: strFaultMsg = FAULT_CODE_23; break;
        case 23: strFaultMsg = FAULT_CODE_24; break;
        default: strFaultMsg = "Unknown Fault"; break;
    }

    if (m_strFirmName == "SANA")
    {
       // InsertSMSHBLFaultMsg(strMsgType,strTimestamp,usFaultCOde,strFirmNamID,strFaultMsg);
    }
    else
    {
      //  InsertSMSMEDHAFaultMsg(strMsgType,strTimestamp,usFaultCOde,strFirmNamID,strFaultMsg);
    }
}

void nmsDBQuerys::SlotAccessReqInsertintoDB(stAccessRequestPkt stheader, uint32_t uiPktType, uint32_t uiPktLen,
                                            uint32_t uiFrmNo, uint32_t uiSrcLocoID, uint32_t uiSrcLocoVer,
                                            uint32_t uiAbsLoco_Loc, uint32_t uiTrainLen, uint32_t uiTrainSpd,
                                            uint32_t uiMovMntDir, uint32_t uiEmergencySts, uint32_t uiLocoMode,
                                            uint32_t uiApprStID, uint32_t uiLastRfidTag, uint32_t uitinNo,
                                            uint32_t uiLongitude, uint32_t uiLatitude, uint32_t uiLocoRandmrl,
                                            uint32_t uiMACCode, uint32_t uiPktCRC,
                                            uint8_t ucMASecCnt, uint16_t usRouteID, uint32_t uiCRC)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stheader.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stheader.ucMsgType,0,16).toUpper();
    QString strRadioTyp = QString("0x%1").arg(stheader.ucRadioType,0,16).toUpper();
    QString strSOFtxByte1 = QString("0x%1").arg(stheader.ucSOF1,0,16).toUpper();
    QString strSOFtxByte2 = QString("0x%1").arg(stheader.ucSOF2,0,16).toUpper();
    QString strMACCode = QString("0x%1").arg(uiMACCode,0,16).toUpper();
    QString strPktCRC = QString("0x%1").arg(uiPktCRC,0,16).toUpper();

    QString strCRC = QString("0x%1").arg(uiCRC,0,16).toUpper();
    int hours   = uiFrmNo / 3600;
    int minutes = (uiFrmNo % 3600) / 60;
    int seconds = uiFrmNo % 60;

    QString StrFrameTime = QString("%1:%2:%3")
                               .arg(hours, 2, 10, QChar('0'))
                               .arg(minutes, 2, 10, QChar('0'))
                               .arg(seconds, 2, 10, QChar('0'));

    QString strQuery = QString("INSERT INTO public.accessrequestpacket("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", \"STN_KAVACH_ID\", "
                               "\"NMS_SYSTEM_ID\", \"SYSTEM_VER\", \"DATE\", \"TIME\", "
                               "\"ONBOARD_ACTIVE_RADIO\", \"SOF_TX_BYTE1\", \"SOF_TX_BYTE2\", "
                               "\"PKT_TYPE\", \"PKT_LEN\", \"FRAME_NUM\", \"F_TIME\", \"SRC_LOCO_ID\", "
                               "\"SRC_LOCO_VER\", \"ABS_LOCO_LOC\", \"TRAIN_LEN\", \"TRAIN_SPEED\", "
                               "\"MOVEMENT_DIR\", \"EMERGENCY_STATUS\", \"LOCO_MODE\", \"APPROACH_STN_ID\", "
                               "\"LAST_RFID_TAG\", \"TIN\", \"LONGITUDE\", \"LATITUDE\", \"LOCO_RANDOM_RL\", "
                               "\"MAC_CODE\", \"PKT_CRC\", \"MA_SECTION_COUNT\", \"ROUTE_ID\", \"CRC\")"
                            "VALUES ('%1','%2',%3,%4,%5,%6,%7,'%8','%9','%10','%11','%12',%13,%14,%15,"
                            "'%16',%17,%18,%19,%20,%21,'%22','%23',%24,%25,%26,%27,%28,%29,%30,'%31','%32',%33,%34,'%35');")
                            .arg(strStrtFrm).arg(strmsgtyp).arg(stheader.usMsgLength)
                            .arg(stheader.usMsgSeq).arg(stheader.usStatKavachID).arg(stheader.usNMSID)
                            .arg(stheader.ucVersion).arg(strdate).arg(strtime).arg(strRadioTyp)
                            .arg(strSOFtxByte1).arg(strSOFtxByte2)
                            .arg(uiPktType).arg(uiPktLen).arg(uiFrmNo).arg(StrFrameTime).arg(uiSrcLocoID).arg(uiSrcLocoVer)
                            .arg(uiAbsLoco_Loc).arg(uiTrainLen).arg(uiTrainSpd).arg(uiMovMntDir).arg(uiEmergencySts)
                            .arg(uiLocoMode).arg(uiApprStID).arg(uiLastRfidTag).arg(uitinNo).arg(uiLongitude)
                            .arg(uiLatitude).arg(uiLocoRandmrl).arg(strMACCode).arg(strPktCRC)
                            .arg(ucMASecCnt).arg(usRouteID).arg(strCRC);

  bool bQryResult = pcQuery->exec(strQuery);

  /* Execute the Query */
  if(bQryResult == true)
  {
      qDebug () << "successfully insert the access request packet into database";
  }
  else
  {
      qDebug () << "Failed to insert the access request packet into database";
      qDebug() << "SQL Error:" << pcQuery->lastError().text();
  }
  delete pcQuery;
  pcQuery = NULL;
}

void nmsDBQuerys::SlotLocoRegularInsertintoDB(stAccessRequestPkt stheader, uint32_t uiPktType,
                                              uint32_t uiPktLen, uint32_t uiFrmNo, uint32_t uiSrcLocoID,
                                              uint32_t uiSrcLocoVer, uint32_t uiAbsLoco_Loc,
                                              uint32_t uidoubtover, uint32_t uidoubtunder, uint32_t uitrainint,
                                              uint32_t uiTrainLen, uint32_t uiTrainSpd, uint32_t uiMovMntDir,
                                              uint32_t uiEmergencySts, uint32_t uiLocoMode, uint32_t uiLastRfidTag,
                                              uint32_t uiTagDup, uint32_t uitagLinkInfo, uint32_t uitinNo,
                                              uint32_t uiBrkApply, uint32_t uinewMAReply, uint32_t uiLastRefProfNo,
                                              uint32_t uiSigOV, uint32_t uiInfoAck, uint32_t uiSpare,
                                              QString strLocoHlthSts, uint32_t uiMACCode, uint32_t uiPktCRC, uint8_t ucMASecCnt, uint16_t usRouteID,
                                              uint32_t uiCRC)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stheader.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stheader.ucMsgType,0,16).toUpper();
    QString strRadioTyp = QString("0x%1").arg(stheader.ucRadioType,0,16).toUpper();
    QString strSOFtxByte1 = QString("0x%1").arg(stheader.ucSOF1,0,16).toUpper();
    QString strSOFtxByte2 = QString("0x%1").arg(stheader.ucSOF2,0,16).toUpper();
    QString strCRC = QString("0x%1").arg(uiCRC,0,16).toUpper();
    QString strMACCode = QString("0x%1").arg(uiMACCode,0,16).toUpper();
    QString strPktCRC = QString("0x%1").arg(uiPktCRC,0,16).toUpper();

    int hours   = uiFrmNo / 3600;
    int minutes = (uiFrmNo % 3600) / 60;
    int seconds = uiFrmNo % 60;

    QString StrFrameTime = QString("%1:%2:%3")
                          .arg(hours, 2, 10, QChar('0'))
                          .arg(minutes, 2, 10, QChar('0'))
                          .arg(seconds, 2, 10, QChar('0'));


    QString strQuery = QString("INSERT INTO public.locoregularpacket("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", "
                               "\"STN_KAVACH_ID\", \"NMS_SYSTEM_ID\", \"SYSTEM_VER\", "
                               "\"DATE\", \"TIME\", \"ONBOARD_ACTIVE_RADIO\", \"SOF_TX_BYTE1\", "
                               "\"SOF_TX_BYTE2\", \"PKT_TYPE\", \"PKT_LEN\", \"FRAME_NUM\", \"F_TIME\", "
                               "\"SRC_LOCO_ID\", \"SRC_LOCO_VER\", \"ABS_LOCO_LOC\", \"L_DOUBTOVER\", "
                               "\"L_DOUBTUNDER\", \"TRAIN_INT\", \"TRAIN_LEN\", \"TRAIN_SPEED\", "
                               "\"MOVEMENT_DIR\", \"EMERGENCY_STATUS\", \"LOCO_MODE\", \"LAST_RFID_TAG\", "
                               "\"TAG_DUP\", \"TAG_LINK_INFO\", \"TIN\", \"BRAKE_APPLIED\", \"NEW_MA_REPLY\", "
                               "\"LAST_REF_PROF_NO\", \"SIG_OV\", \"INFO_ACK\", \"SPARE\", "
                               "\"LOCO_HEALTH_STATUS\", \"MAC_CODE\", \"PKT_CRC\", \"MA_SECTION_COUNT\", "
                               "\"ROUTE_ID\", \"CRC\")"
                               "VALUES ('%1','%2',%3,%4,%5,%6,%7,'%8','%9','%10','%11','%12',%13,%14,%15,"
                               "'%16',%17,%18,%19,%20,%21,%22,%23,%24,%25,%26,%27,%28,%29,%30,%31,%32,%33,"
                               "%34,%35,%36,%37,'%38','%39','%40',%41,%43,'%44');")
                            .arg(strStrtFrm).arg(strmsgtyp).arg(stheader.usMsgLength)
                            .arg(stheader.usMsgSeq).arg(stheader.usStatKavachID).arg(stheader.usNMSID)
                            .arg(stheader.ucVersion).arg(strdate).arg(strtime).arg(strRadioTyp)
                            .arg(strSOFtxByte1).arg(strSOFtxByte2)
                            .arg(uiPktType).arg(uiPktLen).arg(uiFrmNo).arg(StrFrameTime).arg(uiSrcLocoID).arg(uiSrcLocoVer)
                            .arg(uiAbsLoco_Loc).arg(uidoubtover).arg(uidoubtunder).arg(uitrainint)
                            .arg(uiTrainLen).arg(uiTrainSpd).arg(uiMovMntDir).arg(uiEmergencySts)
                            .arg(uiLocoMode).arg(uiLastRfidTag).arg(uiTagDup).arg(uitagLinkInfo).arg(uitinNo)
                            .arg(uiBrkApply).arg(uinewMAReply).arg(uiLastRefProfNo).arg(uiSigOV).arg(uiInfoAck)
                            .arg(uiSpare).arg(strLocoHlthSts).arg(strMACCode).arg(strPktCRC)
                            .arg(ucMASecCnt).arg(usRouteID).arg(strCRC);

  bool bQryResult = pcQuery->exec(strQuery);

  /* Execute the Query */
  if(bQryResult == true)
  {
      qDebug () << "successfully insert the Loco Regular packet into database";
  }
  else
  {
      qDebug () << "Failed to insert the Loco Regular packet into database";
      qDebug() << "SQL Error:" << pcQuery->lastError().text();
  }
  delete pcQuery;
  pcQuery = NULL;
}

void nmsDBQuerys::SlotAccessAuthorityPktInsertintoDB(stAccessRequestPkt stheader, uint32_t uiPktType, uint32_t uiPktLen,
                                                     uint32_t uiFrmNo, uint32_t uiSrcStnILCIBS_ID,
                                                     uint32_t uiSRCStnILCIBS_ver, uint32_t uiStnILCIBS_Loc,
                                                     uint32_t uiDestLoco_ID, uint32_t uiAlotUpLnk_Freq,
                                                     uint32_t uiAlotDnLnk_Freq, uint32_t uiAlotTDMA_Timeslots,
                                                     uint32_t uiStnRndNum_RS, uint32_t uiStnTDMA,
                                                     uint32_t uiMAC_Code, uint32_t uiPktCrc, uint32_t uiCRC)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stheader.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stheader.ucMsgType,0,16).toUpper();
    QString strRadioTyp = QString("0x%1").arg(stheader.ucRadioType,0,16).toUpper();
    QString strSOFtxByte1 = QString("0x%1").arg(stheader.ucSOF1,0,16).toUpper();
    QString strSOFtxByte2 = QString("0x%1").arg(stheader.ucSOF2,0,16).toUpper();
    QString strMACCode = QString("0x%1").arg(uiMAC_Code,0,16).toUpper();
    QString strCRC = QString("0x%1").arg(uiCRC,0,16).toUpper();

    QString strFrameTime = GetFrameTime(uiFrmNo);

    QString strQuery = QString("INSERT INTO public.accessauthoritypkt("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", "
                               "\"STN_KAVACH_ID\", \"NMS_SYSTEM_ID\", \"SYSTEM_VER\", "
                               "\"DATE\", \"TIME\", \"STN_ACTIVE_RADIO\", \"SOF_TX_BYTE1\", "
                               "\"SOF_TX_BYTE2\", \"PKT_TYPE\", \"PKT_LEN\", \"FRAME_NUM\", "
                               "\"F_TIME\", \"SRC_STN_ILC_IBS_ID\", \"SRC_STN_ILC_IBS_VER\", "
                               "\"STN_ILC_IBS_LOCO\", \"DEST_LOCO_ID\", \"ALLOTTED_UPLINK_FREQ\", "
                               "\"ALLOTTED_DOWNLINK_FREQ\", \"ALLOTTED_TDMA_TIMESLOT\", "
                               "\"STN_RND_NUM_RS\", \"STN_TDMA\", \"MAC_CODE\", \"PKT_CRC\", \"CRC\")"
                               "VALUES ('%1','%2',%3,%4,%5,%6,%7,'%8','%9','%10','%11','%12',%13,%14,%15,"
                               "'%16',%17,%18,%19,%20,%21,%22,%23,%24,%25,'%26','%27','%28');")
                           .arg(strStrtFrm).arg(strmsgtyp).arg(stheader.usMsgLength)
                           .arg(stheader.usMsgSeq).arg(stheader.usStatKavachID).arg(stheader.usNMSID)
                           .arg(stheader.ucVersion).arg(strdate).arg(strtime).arg(strRadioTyp)
                           .arg(strSOFtxByte1).arg(strSOFtxByte2)
                           .arg(uiPktType).arg(uiPktLen).arg(uiFrmNo).arg(strFrameTime).arg(uiSrcStnILCIBS_ID).arg(uiSRCStnILCIBS_ver)
                           .arg(uiStnILCIBS_Loc).arg(uiDestLoco_ID).arg(uiAlotUpLnk_Freq).arg(uiAlotDnLnk_Freq)
                           .arg(uiAlotTDMA_Timeslots).arg(uiStnRndNum_RS).arg(uiStnTDMA).arg(strMACCode)
                           .arg(uiPktCrc).arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the authority packet into database";
    }
    else
    {
        qDebug () << "Failed to insert the authority packet into database";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotAdditionalEmergencyPktInsertintoDB(stAccessRequestPkt stheader, uint32_t uiPktType,
                                                         uint32_t uiPktLen, uint32_t uiFrmNo,
                                                         uint32_t uiSrcStnILCIBS_ID, uint32_t uiSRCStnILCIBS_ver,
                                                         uint32_t uiStnILCIBS_Loc, uint32_t uiGenSoSCall, uint32_t uiCRC)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stheader.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stheader.ucMsgType,0,16).toUpper();
    QString strRadioTyp = QString("0x%1").arg(stheader.ucRadioType,0,16).toUpper();
    QString strSOFtxByte1 = QString("0x%1").arg(stheader.ucSOF1,0,16).toUpper();
    QString strSOFtxByte2 = QString("0x%1").arg(stheader.ucSOF2,0,16).toUpper();
    QString strCRC = QString("0x%1").arg(uiCRC,0,16).toUpper();
    QString strFrameTime = GetFrameTime(uiFrmNo);


    QString strQuery = QString("INSERT INTO public.additionalemergencypkt("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", "
                               "\"STN_KAVACH_ID\", \"NMS_SYSTEM_ID\", \"SYSTEM_VER\", "
                               "\"DATE\", \"TIME\", \"STN_ACTIVE_RADIO\", \"SOF_TX_BYTE1\", "
                               "\"SOF_TX_BYTE2\", \"PKT_TYPE\", \"PKT_LEN\", \"FRAME_NUM\", \"F_TIME\", "
                               "\"SRC_STN_ILC_IBS_ID\", \"SRC_STN_ILC_IBS_VER\", \"STN_ILC_IBS_LOCO\", "
                               "\"GEN_SOS_CALL\", \"CRC\")"
                               "VALUES ('%1','%2',%3,%4,%5,%6,%7,'%8','%9','%10','%11','%12',%13,%14,%15,"
                               "'%16',%17,%18,%19,%20,'%21');")
                           .arg(strStrtFrm).arg(strmsgtyp).arg(stheader.usMsgLength)
                           .arg(stheader.usMsgSeq).arg(stheader.usStatKavachID).arg(stheader.usNMSID)
                           .arg(stheader.ucVersion).arg(strdate).arg(strtime).arg(strRadioTyp)
                           .arg(strSOFtxByte1).arg(strSOFtxByte2)
                           .arg(uiPktType).arg(uiPktLen).arg(uiFrmNo).arg(strFrameTime)
                           .arg(uiSrcStnILCIBS_ID).arg(uiSRCStnILCIBS_ver)
                           .arg(uiStnILCIBS_Loc).arg(uiGenSoSCall).arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the Additional Emergency packet into database";
    }
    else
    {
        qDebug () << "Failed to insert the Additional Emergency packet into database";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBStnRegMASubPkt(MovementAuthorityPkt stMAPkt)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QString strSubPktTyp = GetSubPktType(stMAPkt.SUB_PKT_TYPE);

    QString strDistLocoSoS = GetDestLocoSoS(stMAPkt.DEST_LOCO_SOS);
    QString strTrnSecTyp = GetTrainSectionType(stMAPkt.TRAIN_SECTION_TYPE);
    QString strCurSigAsp = GetSignalAspects(stMAPkt.CUR_SIG_ASPECT);
    QString strAuthType = GetAuthorityType(stMAPkt.AUTHORITY_TYPE);

    // --- Insert into stnregmasubpkt ---
    QString strQuery1 = QString(
                            "INSERT INTO public.stnregmasubpkt("
                            "\"PKT_ID\", \"SUB_PKT_TYPE\", \"SUB_PKT_LENGTH\", "
                            "\"FRAME_OFFSET\", \"DEST_LOC_SOS\", \"TRAIN_SEC_TYPE\", "
                            "\"CUR_SIG_INFO\", \"CUR_SIG_ASPECT\", \"NEXT_SIG_ASPECT\", "
                            "\"APPR_SIG_DIST\", \"AUTHORITY_TYPE\", \"AUTHORISED_SPEED\", "
                            "\"MA_W_R_T_SIG\", \"REQ_SHORTEN_MA\", \"NEW_MA\", "
                            "\"NEXT_STN_COMM\", \"APPR_STN_ILC_IBC_ID\") "
                            "VALUES (%1, %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, "
                            "%12, %13, %14, %15, %16, %17);")
                            .arg(m_ulPktId).arg(stMAPkt.SUB_PKT_TYPE).arg(stMAPkt.SUB_PKT_LENGTH).arg(stMAPkt.FRAME_OFFSET)
                            .arg(stMAPkt.DEST_LOCO_SOS).arg(stMAPkt.TRAIN_SECTION_TYPE).arg(stMAPkt.CUR_SIG_INFO.toUInt())
                            .arg(stMAPkt.CUR_SIG_ASPECT).arg(stMAPkt.NEXT_SIG_ASPECT).arg(stMAPkt.APPR_SIG_DIST)
                            .arg(stMAPkt.AUTHORITY_TYPE).arg(stMAPkt.AUTHORIZED_SPEED).arg(stMAPkt.MA_WRT_SIG)
                            .arg(stMAPkt.REQ_SHORTEN_MA).arg(stMAPkt.NEW_MA)
                            .arg(stMAPkt.NEXT_STN_COMM).arg(stMAPkt.APPR_STN_ILC_IBS_ID);

    if (!pcQuery->exec(strQuery1))
    {
        qDebug() << "Failed stnregmasubpkt:" << pcQuery->lastError().text();
        return;
    }
    else
    {
        qDebug () << "successfully insert the Station Regular MA Sub packet into database";
    }

    // --- Insert into stnregmatlmsubpkt ---
    QString strQuery2 = QString(
                            "INSERT INTO public.stnregmatlmsubpkt("
                            "\"PKT_ID\", \"TRAIN_LENGTH_INFO_STS\", \"TRAIN_LENGTH_INFO_TYPE\", "
                            "\"REF_FRAMENUM_TLM\", \"REF_OFFSET_INT_TLM\", "
                            "\"NEXT_STN_COMM\", \"APPR_STN_ILC_IBC_ID\", \"PADDING_BITS\") "
                            "VALUES (%1, %2, %3, %4, %5, %6, %7, %8);")
                            .arg(m_ulPktId).arg(stMAPkt.TRN_LEN_INFO_STS).arg(stMAPkt.TRN_LEN_INFO_TYPE)
                            .arg(stMAPkt.REF_FRAME_NUM_TLM).arg(stMAPkt.REF_OFFSET_INT_TL)
                            .arg(stMAPkt.NEXT_STN_COMM).arg(stMAPkt.APPR_STN_ILC_IBS_ID).arg(0);

    if (!pcQuery->exec(strQuery2))
    {
        qDebug() << "Failed stnregmatlmsubpkt:" << pcQuery->lastError().text();
        return;
    }
    else
    {
        qDebug () << "successfully insert the Station Regular TLM Sub packet into database";
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBStnRegSSPSubPkt(StaticSpeedProfilePkt stSSPPkt)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());
    QString strSubPktTyp = GetSubPktType(stSSPPkt.SUB_PKT_TYPE);
    for (int i = 0; i < stSSPPkt.entries.size(); ++i)
    {
        const auto &entry = stSSPPkt.entries.at(i);

        QString strQuery = QString("INSERT INTO public.stnregsspsubpkt("
                                   "\"PKT_ID\", \"SUB_PKT_TYPE\", \"SUB_PKT_LENGTH\", "
                                   "\"LM_SPEED_INFO_CNT\", \"LM_STATIC_SPEED_DISTANCE\", "
                                   "\"LM_STATIC_SPEED_CLASS\", \"LM_STATIC_SPEED_VALUE\", \"PADDING_BITS\")"
                                   "VALUES (%1, '%2', %3, %4, %5, %6, %7,%8);").arg(m_ulPktId)
                               .arg(strSubPktTyp).arg(stSSPPkt.SUB_PKT_LENGTH).arg(stSSPPkt.LM_Speed_Info_CNT)
                               .arg(entry.LM_Static_Speed_Distance)
                               .arg(entry.LM_Static_Speed_Class)
                               .arg(entry.SpeedValue).arg(0);

        bool bQryResult = pcQuery->exec(strQuery);

        /* Execute the Query */
        if(bQryResult == true)
        {
            qDebug () << "successfully insert the Station Regular SSP Sub packet into database";
        }
        else
        {
            qDebug () << "Failed to insert the Station Regular SSP Sub packet into database";
            qDebug() << "SQL Error:" << pcQuery->lastError().text();
        }
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBStnRegGradientSubPkt(GradientProfilePkt stGradprofPkt)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());
    for (int i = 0; i < stGradprofPkt.entries.size(); ++i)
    {
        const auto &entry = stGradprofPkt.entries.at(i);

        QString strQuery = QString("INSERT INTO public.stnreggradientprofilesubpkt("
                                   "\"PKT_ID\", \"SUB_PKT_TYPE\", \"SUB_PKT_LENGTH\", "
                                   "\"LM_GRAD_INFO_CNT\", \"LM_GRADIENT_DISTANCE\", "
                                   "\"LM_GDIR\", \"LM_GRADIENT_VALUE\", \"PADDING_BITS\")"
                               "VALUES (%1, '%2', %3, %4, %5, '%6', %7, %8);")
                               .arg(m_ulPktId)
                               .arg(stGradprofPkt.SUB_PKT_TYPE)
                               .arg(stGradprofPkt.SUB_PKT_LENGTH)
                               .arg(stGradprofPkt.LM_Grad_Info_CNT)
                               .arg(entry.LM_Gradient_Distance)
                               .arg(entry.LM_GDIR)
                               .arg(entry.LM_Gradient_Value)
                               .arg(0);

        bool bQryResult = pcQuery->exec(strQuery);
        if(bQryResult == true)
        {
            qDebug () << "successfully insert the Station Regular Gradient Sub packet into database";
        }
        else
        {
            qDebug () << "Failed to insert the Station Regular Gradient Sub packet into database";
            qDebug() << "SQL Error:" << pcQuery->lastError().text();
        }
    }
}


void nmsDBQuerys::SlotInsertDBStnRegLCGateSubPkt(LCGateProfilePkt stLCGatePkt)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());
    QString strSubPktTyp = GetSubPktType(stLCGatePkt.SUB_PKT_TYPE);

    for (int i = 0; i < stLCGatePkt.entries.size(); ++i)
    {
        const auto &entry = stLCGatePkt.entries.at(i);
        QString strQuery = QString("INSERT INTO public.stnreglcgateprofilesubpkt("
                                   "\"PKT_ID\", \"SUB_PKT_TYPE\", \"SUB_PKT_LENGTH\", "
                                   "\"LM_LC_INFO_CNT\", \"LM_LC_DISTANCE\", \"LM_LC_ID_NUMERIC\", "
                                   "\"LM_LC_ID_ALPHA_SUFFIX\", \"LM_LC_MANNING_TYPE\", "
                                   "\"LM_LC_CLASS\", \"LM_LC_AUTO_WHISTLING_ENABLED\", "
                                   "\"LM_LC_AUTO_WHISTLING_TYPE\", \"PADDING_BITS\")"
                                   "VALUES (%1, '%2', %3, %4, %5, %6, '%7', '%8',"
                                   "'%9', '%10', '%11', %12);").arg(m_ulPktId)
                               .arg(strSubPktTyp).arg(stLCGatePkt.SUB_PKT_LENGTH)
                               .arg(stLCGatePkt.LM_LC_Info_CNT)
                               .arg(entry.LM_LC_Distance)
                               .arg(entry.LM_LC_ID_Numeric)
                               .arg(entry.LM_LC_ID_Suffix)
                               .arg(entry.LM_LC_Manning)
                               .arg(entry.LM_LC_Class)
                               .arg(entry.LM_LC_AW_Enabled)
                               .arg(entry.LM_LC_AW_Type).arg(0);

        bool bQryResult = pcQuery->exec(strQuery);
             /* Execute the Query */
        if(bQryResult == true)
        {
            qDebug () << "successfully insert the Station Regular LC Gate Sub packet into database";
            qDebug() << QString("✅ Inserted LC Gate Entry %1/%2")
                            .arg(i + 1)
                            .arg(stLCGatePkt.entries.size());
        }
        else
        {
            qDebug () << "Failed to insert the Station Regular LC Gate Sub packet into database";
            qDebug() << "SQL Error:" << pcQuery->lastError().text();
        }
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBStnRegTurnoutSpeedSubPkt(TurnoutSpeedProfilePkt stTSPPkt)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());
    QString strSubPktTyp = GetSubPktType(stTSPPkt.SUB_PKT_TYPE);

    for (int i = 0; i < stTSPPkt.entries.size(); ++i)
    {
        const auto &entry = stTSPPkt.entries.at(i);

        QString strQuery = QString("INSERT INTO public.stnregturnoutspeedprofilesubpkt("
                                   "\"PKT_ID\", \"SUB_PKT_TYPE\", \"SUB_PKT_LENGTH\", "
                                   "\"TO_CNT\", \"TO_SPEED\", \"DIFF_DIST_TO\", "
                                   "\"TO_SPEED_REL_DIST\", \"PADDING_BITS\")"
                                   "VALUES (%1, '%2', %3, %4, %5, %6, %7, %8);").arg(m_ulPktId)
                               .arg(strSubPktTyp).arg(stTSPPkt.SUB_PKT_LENGTH)
                               .arg(stTSPPkt.TO_CNT).arg(entry.TO_SPEED)
                               .arg(entry.DIFF_DIST_TO)
                               .arg(entry.TO_SPEED_REL_DIST).arg(0);

        bool bQryResult = pcQuery->exec(strQuery);

        /* Execute the Query */
        if(bQryResult == true)
        {
            qDebug () << "successfully insert the Station Regular TSP Sub packet into database";
        }
        else
        {
            qDebug () << "Failed to insert the Station Regular TSP Sub packet into database";
            qDebug() << "SQL Error:" << pcQuery->lastError().text();
        }
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBStnRegTagLinkingInfoSubPkt(TagLinkingInfoPkt stTagLinkInfPkt)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());
    QString strSubPktTyp = GetSubPktType(stTagLinkInfPkt.SUB_PKT_TYPE);

    // --- 1. stnregtlisubpkt ---
    for (int i = 0; i < stTagLinkInfPkt.entries.size(); ++i)
    {
        const auto &entry = stTagLinkInfPkt.entries.at(i);
        QString strQuery1 = QString("INSERT INTO public.stnregtlisubpkt("
                                    "\"PKT_ID\", \"SUB_PKT_TYPE\", \"SUB_PKT_LENGTH\", "
                                    "\"DIST_DUP_TAG\", \"ROUTE_RFID_CNT\", \"DIST_NEXT_RFID\", "
                                    "\"NEXT_RFID_TAG_ID\", \"DUP_TAG_DIR\") "
                                    "VALUES (%1, '%2', %3, %4, %5, %6, %7, %8);")
                                    .arg(m_ulPktId).arg(strSubPktTyp).arg(stTagLinkInfPkt.SUB_PKT_LENGTH)
                                    .arg(stTagLinkInfPkt.DIST_DUP_TAG).arg(stTagLinkInfPkt.ROUTE_RFID_CNT)
                                    .arg(entry.DIST_NXT_RFID)
                                    .arg(entry.NXT_RFID_TAG_ID)
                                    .arg(entry.DUP_TAG_DIR);

        if (!pcQuery->exec(strQuery1))
        {
            qDebug() << "Failed stnregtlisubpkt:" << pcQuery->lastError().text();
        }
        else
        {
            qDebug () << "successfully insert the Station Regular TLI Sub packet into database";
        }

    // --- 2. stnregtliabsresetsubpkt ---
        QString strQuery2 = QString(
                                "INSERT INTO public.stnregtliabsresetsubpkt("
                                "\"PKT_ID\", \"ABS_LOC_RESET\", \"START_DIST_TO_LOC_RESET\", "
                                "\"ADJ_LOCO_DIR\", \"ABS_LOC_CORRECTION\") "
                                "VALUES (%1, %2, %3, %4, %5);")
                                .arg(m_ulPktId)
                                .arg(entry.ABS_LOC_RESET)
                                .arg(entry.ADJ_LOCO_DIST)
                                .arg(entry.ADJ_LOCO_DIR)
                                .arg(entry.ABS_LOC_CORR);

        if (!pcQuery->exec(strQuery2))
        {
            qDebug() << "Failed stnregtliabsresetsubpkt:" << pcQuery->lastError().text();
        }
        else
        {
            qDebug () << "successfully insert the Station Regular TLI abs reset Sub packet into database";
        }

        // --- 3. stnregtliadjlinesubpkt ---
        QString strQuery3 = QString(
                                "INSERT INTO public.stnregtliadjlinesubpkt("
                                "\"PKT_ID\", \"ADJ_LINE_CNT\", \"LINE_TIN\", \"PADDING_BITS\") "
                                "VALUES (%1, %2, %3, %4);")
                                .arg(m_ulPktId).arg(entry.ADJ_LINE_CNT)
                                .arg(entry.LINE_TIN.isEmpty() ? 0 : entry.LINE_TIN[0]).arg(0);

        if (!pcQuery->exec(strQuery3))
        {
            qDebug() << "Failed stnregtliadjlinesubpkt:" << pcQuery->lastError().text();
        }
        else
        {
            qDebug () << "successfully insert the Station Regular TLI adj lines Sub packet into database";
        }
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBStnRegTrackCondDataSubPkt(TrackConditionPkt stTrackCondDataPkt)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());
    QString strSubPktTyp = GetSubPktType(stTrackCondDataPkt.SUB_PKT_TYPE);

    for (int i = 0; i < stTrackCondDataPkt.entries.size(); ++i)
    {
        const auto &entry = stTrackCondDataPkt.entries.at(i);

        QString strQuery = QString("INSERT INTO public.stnregtrackconditiondatasubpkt("
                                   "\"PKT_ID\", \"SUB_PKT_TYPE\", \"SUB_PKT_LENGTH\", "
                                   "\"TRACK_COND_CNT\", \"TRACK_COND_TYPE\", \"START_DIST_TRACKCOND\", "
                                   "\"LENGTH_TRACKCOND\", \"PADDING_BITS\")"
                                   "VALUES (%1, '%2', %3, %4, %5, %6, %7, %8);").arg(m_ulPktId)
                               .arg(strSubPktTyp).arg(stTrackCondDataPkt.SUB_PKT_LENGTH)
                               .arg(stTrackCondDataPkt.TRACK_COND_CNT)
                               .arg(entry.TRACK_COND_TYPE)
                               .arg(entry.START_DIST_TRACKCOND)
                               .arg(entry.LENGTH_TRACKCOND).arg(0);

        bool bQryResult = pcQuery->exec(strQuery);

        /* Execute the Query */
        if(bQryResult == true)
        {
            qDebug () << "successfully insert the Station Regular Track Condition data Sub packet into database";
        }
        else
        {
            qDebug () << "Failed to insert the Station Regular Track Condition data Sub packet into database";
            qDebug() << "SQL Error:" << pcQuery->lastError().text();
        }
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBStnRegTSRSubPkt(TempSpeedRestrictionPkt stTSRPkt)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());
    QString strSubPktTyp = GetSubPktType(stTSRPkt.SUB_PKT_TYPE);

    for (int i = 0; i < stTSRPkt.entries.size(); ++i)
    {
        const auto &entry = stTSRPkt.entries.at(i);

        QString strQuery = QString("INSERT INTO public.stnregtsrsubpkt("
                                   "\"PKT_ID\", \"SUB_PKT_TYPE\", \"SUB_PKT_LENGTH\", "
                                   "\"TSR_STATUS\", \"TSR_INFO_CNT\", \"TSR_ID\", "
                                   "\"TSR_DISTANCE\", \"TSR_LENGTH\", \"TSR_CLASS\", "
                                   "\"TSR_UNIVERSAL_SPEED\", \"TSR_CLASSA_SPEED\", "
                                   "\"TSR_CLASSB_SPEED\", \"TSR_CLASSC_SPEED\", "
                                   "\"TSR_WHISTLE\", \"PADDING_BITS\")"
                                   "VALUES (%1, '%2', %3, %4, %5, %6, %7, %8,"
                                   "%9,%10,%11,%12,%13,%14,%15);").arg(m_ulPktId)
                               .arg(strSubPktTyp).arg(stTSRPkt.SUB_PKT_LENGTH)
                               .arg(stTSRPkt.TSR_STATUS).arg(stTSRPkt.TSR_Info_CNT)
                               .arg(entry.TSR_ID).arg(entry.TSR_Distance)
                               .arg(entry.TSR_Length).arg(entry.TSR_Class)
                               .arg(entry.TSR_Universal_Speed)
                               .arg(entry.TSR_ClassA_Speed)
                               .arg(entry.TSR_ClassB_Speed)
                               .arg(entry.TSR_ClassC_Speed)
                               .arg(entry.TSR_Whistle).arg(0);

        bool bQryResult = pcQuery->exec(strQuery);

        /* Execute the Query */
        if(bQryResult == true)
        {
            qDebug () << "successfully insert the Station Regular TSR Sub packet into database";
        }
        else
        {
            qDebug () << "Failed to insert the Station Regular TSR Sub packet into database";
            qDebug() << "SQL Error:" << pcQuery->lastError().text();
        }
    }
    delete pcQuery;
    pcQuery = NULL;
}

quint64 nmsDBQuerys::SlotInsertDBStationRegHeader(stAccessRequestPkt stHeader, StationRegularHeader stStnRglrHPkt)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stHeader.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stHeader.ucMsgType,0,16).toUpper();
    QString strRadioTyp = QString("0x%1").arg(stHeader.ucRadioType,0,16).toUpper();
    QString strSOFtxByte1 = QString("0x%1").arg(stHeader.ucSOF1,0,16).toUpper();
    QString strSOFtxByte2 = QString("0x%1").arg(stHeader.ucSOF2,0,16).toUpper();
    QString strCRC = QString("0x%1").arg(0x3113099A,0,16).toUpper();
    QString strFrameTime = GetFrameTime(stStnRglrHPkt.FRAME_NUM);

    QString strQuery = QString("INSERT INTO public.stationregpkt("
                               "\"START_FRAME\", \"MESSAGE_TYPE\", \"MESSAGE_LENGTH\", "
                               "\"MESSAGE_SEQUENCE\", \"STN_KAVACH_ID\", \"NMS_SYSTEM_ID\", "
                               "\"SYSTEM_VERSION\", \"DATE\", \"TIME\", \"STATION_ACTIVE_RADIO\", "
                               "\"SOF_TX_BYTE1\", \"SOF_TX_BYTE2\", \"PKT_TYPE\", \"PKT_LENGTH\", "
                               "\"FRAME_NUM\", \"SRC_STN_ILC_IBS_ID\", \"SRC_STN_ILC_IBS_VERSION\", "
                               "\"DEST_LOCO_ID\", \"REF_PROF_ID\", \"LAST_REF_RFID\", \"DIST_PKT_START\", "
                               "\"PKT_DIR\", \"CRC\", \"F_TIME\")"
                               "VALUES ('%1','%2',%3,%4,%5,%6,%7,'%8','%9','%10','%11','%12',%13,%14,%15,"
                               "%16,%17,%18,%19,%20,%21,%22,'%23','%24')"
                               "RETURNING \"ID\";")
                           .arg(strStrtFrm).arg(strmsgtyp).arg(stHeader.usMsgLength)
                           .arg(stHeader.usMsgSeq).arg(stHeader.usStatKavachID).arg(stHeader.usNMSID)
                           .arg(stHeader.ucVersion).arg(strdate).arg(strtime).arg(strRadioTyp)
                           .arg(strSOFtxByte1).arg(strSOFtxByte2)
                           .arg(stStnRglrHPkt.PKT_TYPE).arg(stStnRglrHPkt.PKT_LENGTH)
                           .arg(stStnRglrHPkt.FRAME_NUM).arg(stStnRglrHPkt.SOURCE_STN_ILC_IBS_ID)
                           .arg(stStnRglrHPkt.SOURCE_STN_ILC_IBS_VERSION).arg(stStnRglrHPkt.DEST_LOCO_ID)
                           .arg(stStnRglrHPkt.REF_PROF_ID).arg(stStnRglrHPkt.LAST_REF_RFID)
                           .arg(stStnRglrHPkt.DIST_PKT_START).arg(stStnRglrHPkt.PKT_DIR).arg(strCRC).arg(strFrameTime);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if (bQryResult == true)
    {
        if(pcQuery->next())
        {
           m_ulPktId = pcQuery->value(0).toULongLong();

           qDebug () << "successfully insert the Station Regular packet header into database" ;
           qDebug() << "Inserted Pkt_Id =" << m_ulPktId << strFrameTime;
           return m_ulPktId;
        }
        else
        {
            qDebug() << "No Pkt_Id returned!";
            m_ulPktId = 0;
        }
    }
    else
    {
        qDebug () << "Failed to insert the Station Regular packet header into database";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
        return 0;
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBStationhealthPkt(stStationHealthPkt stStnHlthPkt,
                                               QStringList        strlstEvntID,
                                               QStringList        strlstEvntData,
                                               uint32_t           uiCrc)
{
    // ── Header formatting ─────────────────────────────────────────────────────
    QString strStrtFrm = QString("0x%1").arg(stStnHlthPkt.usStartFrame, 0, 16).toUpper();
    QString strMsgType = QString("0x%1").arg(stStnHlthPkt.ucMsgType,    0, 16).toUpper();
    QString strCRC     = QString("0x%1").arg(uiCrc,                     0, 16).toUpper();

    QString strDate = QString("%1-%2-%3")
                          .arg(2000 + stStnHlthPkt.ucDate[2], 4, 10, QChar('0'))
                          .arg(stStnHlthPkt.ucDate[1],         2, 10, QChar('0'))
                          .arg(stStnHlthPkt.ucDate[0],         2, 10, QChar('0'));

    QString strTime = QString("%1:%2:%3")
                          .arg(stStnHlthPkt.ucTime[0], 2, 10, QChar('0'))
                          .arg(stStnHlthPkt.ucTime[1], 2, 10, QChar('0'))
                          .arg(stStnHlthPkt.ucTime[2], 2, 10, QChar('0'));

    // ── Column name lookup : Event ID → (EVENT_ID_N column, DATA column) ──────
    // Named columns for events 1-45 (RDSO defined).
    // Events 46-255 use generic EVENT_ID_N / EVENT_DATA_N columns.
    static const QMap<uint16_t, QPair<QString,QString>> colMap = {
                                                                   {  1, {"EVENT_ID_1",  "SYSTEM_TEMPERATURE"}},
                                                                   {  2, {"EVENT_ID_2",  "ACTIVE_RADIO_NUMBER"}},
                                                                   {  3, {"EVENT_ID_3",  "RADIO_1_HEALTH"}},
                                                                   {  4, {"EVENT_ID_4",  "RADIO_2_HEALTH"}},
                                                                   {  5, {"EVENT_ID_5",  "RADIO_1_INPUT_SUPPLY"}},
                                                                   {  6, {"EVENT_ID_6",  "RADIO_2_INPUT_SUPPLY"}},
                                                                   {  7, {"EVENT_ID_7",  "RADIO_1_TEMPERATURE"}},
                                                                   {  8, {"EVENT_ID_8",  "RADIO_2_TEMPERATURE"}},
                                                                   {  9, {"EVENT_ID_9",  "RADIO_1_PA_TEMPERATURE"}},
                                                                   { 10, {"EVENT_ID_10", "RADIO_2_PA_TEMPERATURE"}},
                                                                   { 11, {"EVENT_ID_11", "RADIO_1_PA_SUPPLY_VOLTAGE"}},
                                                                   { 12, {"EVENT_ID_12", "RADIO_2_PA_SUPPLY_VOLTAGE"}},
                                                                   { 13, {"EVENT_ID_13", "RADIO_1_PA_TX_PA_CURRENT"}},
                                                                   { 14, {"EVENT_ID_14", "RADIO_2_PA_TX_PA_CURRENT"}},
                                                                   { 15, {"EVENT_ID_15", "RADIO_1_REVERSE_POWER"}},
                                                                   { 16, {"EVENT_ID_16", "RADIO_2_REVERSE_POWER"}},
                                                                   { 17, {"EVENT_ID_17", "RADIO_1_FORWARD_POWER"}},
                                                                   { 18, {"EVENT_ID_18", "RADIO_2_FORWARD_POWER"}},
                                                                   { 19, {"EVENT_ID_19", "CURRENT_RUNNING_KEY"}},
                                                                   { 20, {"EVENT_ID_20", "REMAINING_NUMBER_OF_KEYS"}},
                                                                   { 21, {"EVENT_ID_21", "SESSION_KEY_CHECKSUM"}},
                                                                   { 22, {"EVENT_ID_22", "ALLOWCATED_TIME_SLOT_FOR_NEW_LOCO"}},
                                                                   { 23, {"EVENT_ID_23", "NEW_LOCO_REGULAR_PACKET_RECEIVED_TIME_OFFSET"}},
                                                                   { 24, {"EVENT_ID_24", "LOCO_COUNT"}},
                                                                   { 25, {"EVENT_ID_25", "RADIO_1_RX_PACKET_COUNT"}},
                                                                   { 26, {"EVENT_ID_26", "RADIO_2_RX_PACKET_COUNT"}},
                                                                   { 27, {"EVENT_ID_27", "ACTIVE_GPS_NUMBER"}},
                                                                   { 28, {"EVENT_ID_28", "GPS_1_VIEW"}},
                                                                   { 29, {"EVENT_ID_29", "GPS_2_VIEW"}},
                                                                   { 30, {"EVENT_ID_30", "GPS_1_SECONDS"}},
                                                                   { 31, {"EVENT_ID_31", "GPS_2_SECONDS"}},
                                                                   { 32, {"EVENT_ID_32", "GPS_1_SATELLITES_IN_VIEW"}},
                                                                   { 33, {"EVENT_ID_33", "GPS_1_CNO_MAX"}},
                                                                   { 34, {"EVENT_ID_34", "GPS_2_SATELLITES_IN_VIEW"}},
                                                                   { 35, {"EVENT_ID_35", "GPS_2_CNO_MAX"}},
                                                                   { 36, {"EVENT_ID_36", "GSM_1_RSSI"}},
                                                                   { 37, {"EVENT_ID_37", "GSM_2_RSSI"}},
                                                                   { 38, {"EVENT_ID_38", "MISSING_RFID"}},
                                                                   { 39, {"EVENT_ID_39", "INVALID_RFID"}},
                                                                   { 40, {"EVENT_ID_40", "CONFLICT_ROUTE_RFID"}},
                                                                   { 41, {"EVENT_ID_41", "CONFLICTING_TIN"}},
                                                                   { 42, {"EVENT_ID_42", "MISSING_TIN"}},
                                                                   { 43, {"EVENT_ID_43", "LOCO_SPECIFIC_SOS"}},
                                                                   { 44, {"EVENT_ID_44", "TRAIN_EXIT_MODE"}},
                                                                   { 45, {"EVENT_ID_45", "STATION_MODULES_HEALTH"}},
                                                                   };

    // ── Default values for all 255 EVENT_ID and DATA columns ─────────────────
    // EVENT_ID_N defaults to 0, DATA columns default to 'NULL'
    QMap<QString, QString> columnValues;

    for (int n = 1; n <= 255; ++n)
    {
        QString idCol, dataCol;
        if (colMap.contains(static_cast<uint16_t>(n)))
        {
            idCol   = colMap[static_cast<uint16_t>(n)].first;
            dataCol = colMap[static_cast<uint16_t>(n)].second;
        }
        else
        {
            idCol   = QString("EVENT_ID_%1").arg(n);
            dataCol = QString("EVENT_DATA_%1").arg(n);
        }
        columnValues[idCol]   = "0";
        columnValues[dataCol] = "NULL";
    }

    // ── Overwrite defaults with actual received event data ────────────────────
    for (int i = 0; i < strlstEvntID.size(); ++i)
    {
        uint16_t evID = static_cast<uint16_t>(strlstEvntID[i].trimmed().toUShort());
        QString  evData = strlstEvntData[i].trimmed();

        QString idCol, dataCol;
        if (colMap.contains(evID))
        {
            idCol   = colMap[evID].first;
            dataCol = colMap[evID].second;
        }
        else
        {
            idCol   = QString("EVENT_ID_%1").arg(evID);
            dataCol = QString("EVENT_DATA_%1").arg(evID);
        }

        columnValues[idCol]   = QString::number(evID);
        columnValues[dataCol] = evData;

        qDebug() << "[StnHlth] Mapping EventID:" << evID
                 << "→ col:" << dataCol << "val:" << evData;
    }

    // ── Build INSERT column list and ? placeholders ───────────────────────────
    // Fixed header columns first, then all 255×2 event columns, then CRC.

    QStringList fixedCols = {
        "SOF", "MSG_TYPE", "MSG_LEN", "MSG_SEQ",
        "STN_KAVACH_ID", "NMS_SYSTEM_ID", "SYSTEM_VER",
        "DATE", "TIME", "EVENT_COUNT"
    };

    // Build ordered event column list (EVENT_ID_1, DATA_1, EVENT_ID_2, DATA_2, ...)
    QStringList eventCols;
    for (int n = 1; n <= 255; ++n)
    {
        if (colMap.contains(static_cast<uint16_t>(n)))
        {
            eventCols << colMap[static_cast<uint16_t>(n)].first;
            eventCols << colMap[static_cast<uint16_t>(n)].second;
        }
        else
        {
            eventCols << QString("EVENT_ID_%1").arg(n);
            eventCols << QString("EVENT_DATA_%1").arg(n);
        }
    }

    QStringList allCols;
    allCols << fixedCols << eventCols << "CRC";

    // Build quoted column name list and matching ? placeholder list
    QStringList quotedCols, placeholders;
    for (const QString &col : allCols)
    {
        quotedCols   << QString("\"%1\"").arg(col);
        placeholders << "?";
    }

    QString sql = QString("INSERT INTO public.stationhealthpkt (%1) VALUES (%2)")
                      .arg(quotedCols.join(", "))
                      .arg(placeholders.join(", "));

    // ── Bind all values in the same order ────────────────────────────────────
    QSqlQuery query(m_pcDB->Get());
    query.prepare(sql);

    // Fixed header
    query.addBindValue(strStrtFrm);
    query.addBindValue(strMsgType);
    query.addBindValue(static_cast<int>(stStnHlthPkt.usMsgLength));
    query.addBindValue(static_cast<int>(stStnHlthPkt.usMsgSeq));
    query.addBindValue(static_cast<int>(stStnHlthPkt.usStatKavachID));
    query.addBindValue(static_cast<int>(stStnHlthPkt.usNMSID));
    query.addBindValue(static_cast<int>(stStnHlthPkt.ucVersion));
    query.addBindValue(strDate);
    query.addBindValue(strTime);
    query.addBindValue(static_cast<int>(stStnHlthPkt.ucEventCnt));

    // Event columns (in same order as eventCols list)
    for (const QString &col : eventCols)
    {
        query.addBindValue(columnValues[col]);
    }

    // CRC
    query.addBindValue(strCRC);

    // ── Execute ───────────────────────────────────────────────────────────────
    if (!query.exec())
    {
        qDebug() << "[StnHlth] DB insert FAILED:" << query.lastError().text();
    }
    else
    {
        qDebug() << "[StnHlth] DB insert OK — KavachID:" << stStnHlthPkt.usStatKavachID
                 << "events:" << stStnHlthPkt.ucEventCnt;
    }
}

void nmsDBQuerys::SlotInsertDBOnBoardhealthPkt(stOnBoardHealthPkt stOnBrdHlthPkt, QString strEvntID, QString strEvntData, uint32_t uiCrc)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stOnBrdHlthPkt.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stOnBrdHlthPkt.ucMsgType,0,16).toUpper();
    QString strCRC = QString("0x%1").arg(uiCrc,0,16).toUpper();
    QString strOnBrdKavachID = QString("%1 %2 %3")
                                   .arg(stOnBrdHlthPkt.ucOnBrdKavachID[0], 2, 16, QChar('0'))
                                   .arg(stOnBrdHlthPkt.ucOnBrdKavachID[1], 2, 16, QChar('0'))
                                   .arg(stOnBrdHlthPkt.ucOnBrdKavachID[2], 2, 16, QChar('0')).toUpper();

    QString strQuery = QString("INSERT INTO public.onboardhealthpacket("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", "
                               "\"LOCO_KAVACH_ID\", \"NMS_SYSTEM_ID\", \"SYSTEM_VER\", "
                               "\"DATE\", \"TIME\", \"EVENT_COUNT\", \"EVENT_ID\", \"EVENT_DATA\", \"CRC\")"
                               "VALUES ('%1','%2',%3,%4,'%5',%6,%7,'%8','%9',%10,'%11','%12','%13');")
                           .arg(strStrtFrm).arg(strmsgtyp).arg(stOnBrdHlthPkt.usMsgLength)
                           .arg(stOnBrdHlthPkt.usMsgSeq).arg(strOnBrdKavachID).arg(stOnBrdHlthPkt.usNMSID)
                           .arg(stOnBrdHlthPkt.ucVersion).arg(strdate).arg(strtime).arg(stOnBrdHlthPkt.ucEventCnt)
                           .arg(strEvntID).arg(strEvntData).arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the OnBoard health packet into database";
    }
    else
    {
        qDebug () << "Failed to insert the OnBoard health packet into database";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBS2SPDIVerCmd(stPacketHeader stPktHdr, stPDIVerCheckCmdPkt stPDIVerCmd)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stPktHdr.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stPktHdr.ucMsgType,0,16).toUpper();

    QString strSpecProtl = QString("0x%1").arg(stPDIVerCmd.ucSpecificProtocol,0,16).toUpper();
    QString strSubmsgtyp = QString("0x%1").arg(stPDIVerCmd.usMsgTyp,0,16).toUpper();

    QString strCRC = QString("0x%1").arg(stPDIVerCmd.uiCRC,0,16).toUpper();

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
        strSenderId.append(QString("%1 ").arg(stPDIVerCmd.ucSenderID[i], 2, 16, QLatin1Char('0')).toUpper());
    for (int i = 0; i < 20; ++i)
        strReceiverId.append(QString("%1 ").arg(stPDIVerCmd.ucReceiverID[i], 2, 16, QLatin1Char('0')).toUpper());

    QString strQuery = QString("INSERT INTO public.s2spdivercheckcmdpkt("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", \"STN_KAVACH_ID\", "
                               "\"NMS_SYSTEM_ID\", \"SYSTEM_VER\", \"DATE\", \"TIME\", \"SPECIFIC_PROTOCOL\", "
                               "\"SUB_MSG_TYP\", \"SENDER_ID\", \"RECEIVER_ID\", \"SUB_MSG_LEN\", "
                               "\"PDI_VER_PRIMARY_STN\", \"PRIMARY_STN_RND_NUM\", \"CRC\")"
                               "VALUES ('%1','%2',%3,%4,%5,%6,%7,'%8','%9','%10','%11','%12','%13',%14,%15,%16,'%17');")
                           .arg(strStrtFrm).arg(strmsgtyp).arg(stPktHdr.usMsgLength)
                           .arg(stPktHdr.usMsgSeq).arg(stPktHdr.usStatKavachID).arg(stPktHdr.usNMSID)
                           .arg(stPktHdr.ucVersion).arg(strdate).arg(strtime).arg(strSpecProtl)
                           .arg(strSubmsgtyp).arg(strSenderId).arg(strReceiverId).arg(stPDIVerCmd.usMsgLen)
                           .arg(stPDIVerCmd.ucPDIVer).arg(stPDIVerCmd.usRandomNum).arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the station 2 station PDI Version Command packet into database";
    }
    else
    {
        qDebug () << "Failed to insert the station 2 station PDI Version Command packet into database";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBS2SPDIVerMsg(stPacketHeader stPktHdr, stPDIVerCheckMsgPkt stPDIVerMsg)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stPktHdr.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stPktHdr.ucMsgType,0,16).toUpper();

    QString strSpecProtl = QString("0x%1").arg(stPDIVerMsg.ucSpecificProtocol,0,16).toUpper();
    QString strSubmsgtyp = QString("0x%1").arg(stPDIVerMsg.usMsgTyp,0,16).toUpper();

    QString strCRC = QString("0x%1").arg(stPDIVerMsg.uiCRC,0,16).toUpper();

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
        strSenderId.append(QString("%1 ").arg(stPDIVerMsg.ucSenderID[i], 2, 16, QLatin1Char('0')).toUpper());
    for (int i = 0; i < 20; ++i)
        strReceiverId.append(QString("%1 ").arg(stPDIVerMsg.ucReceiverID[i], 2, 16, QLatin1Char('0')).toUpper());

    QString strQuery = QString("INSERT INTO public.s2spdivercheckmsgpkt("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", \"STN_KAVACH_ID\", "
                               "\"NMS_SYSTEM_ID\", \"SYSTEM_VER\", \"DATE\", \"TIME\", \"SPECIFIC_PROTOCOL\", "
                               "\"SUB_MSG_TYP\", \"SENDER_ID\", \"RECEIVER_ID\", \"SUB_MSG_LEN\", "
                               "\"RESULT_PDI_VER\", \"PDI_VER_SECONDARY_STN\", \"SECONDARY_STN_RND_NUM\", "
                               "\"MAC_CODE\", \"CRC\")"
                               "VALUES ('%1','%2',%3,%4,%5,%6,%7,'%8','%9','%10','%11','%12','%13',%14,%15,%16,%17,'%18','%19');")
                           .arg(strStrtFrm).arg(strmsgtyp).arg(stPktHdr.usMsgLength)
                           .arg(stPktHdr.usMsgSeq).arg(stPktHdr.usStatKavachID).arg(stPktHdr.usNMSID)
                           .arg(stPktHdr.ucVersion).arg(strdate).arg(strtime).arg(strSpecProtl)
                           .arg(strSubmsgtyp).arg(strSenderId).arg(strReceiverId).arg(stPDIVerMsg.usMsgLen)
                           .arg(stPDIVerMsg.ucPDIVerChk).arg(stPDIVerMsg.ucSecondaryStnPDIVer)
                           .arg(stPDIVerMsg.usSecondaryStnRandomNum).arg(stPDIVerMsg.uiMAC_Code).arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the station 2 station PDI Version message packet into database";
    }
    else
    {
        qDebug () << "Failed to insert the station 2 station PDI Version message packet into database";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBS2SHeartBeat(stPacketHeader stPktHdr, stHeartBeatPkt stHeartBeat)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stPktHdr.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stPktHdr.ucMsgType,0,16).toUpper();

    QString strSpecProtl = QString("0x%1").arg(stHeartBeat.ucSpecificProtocol,0,16).toUpper();
    QString strSubmsgtyp = QString("0x%1").arg(stHeartBeat.usMsgTyp,0,16).toUpper();

    QString strCRC = QString("0x%1").arg(stHeartBeat.uiCRC,0,16).toUpper();

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
        strSenderId.append(QString("%1 ").arg(stHeartBeat.ucSenderID[i], 2, 16, QLatin1Char('0')).toUpper());
    for (int i = 0; i < 20; ++i)
        strReceiverId.append(QString("%1 ").arg(stHeartBeat.ucReceiverID[i], 2, 16, QLatin1Char('0')).toUpper());

    QString strFrameNum = QString("%1 %2 %3")
                              .arg(stHeartBeat.ucFrameNum[0], 2, 16, QChar('0'))
                              .arg(stHeartBeat.ucFrameNum[1], 2, 16, QChar('0'))
                              .arg(stHeartBeat.ucFrameNum[2], 2, 16, QChar('0'));

    QString strQuery = QString("INSERT INTO public.s2sheartbeatpkt("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", \"STN_KAVACH_ID\", "
                               "\"NMS_SYSTEM_ID\", \"SYSTEM_VER\", \"DATE\", \"TIME\", \"SPECIFIC_PROTOCOL\", "
                               "\"SUB_MSG_TYP\", \"SENDER_ID\", \"RECEIVER_ID\", \"SUB_MSG_LEN\", "
                               "\"FRAME_NUM\", \"SUB_MSG_SEQ\", \"MAC_CODE\", \"CRC\")"
                               "VALUES ('%1','%2',%3,%4,%5,%6,%7,'%8','%9','%10','%11','%12','%13',%14,'%15',%16,'%17','%18');")
                           .arg(strStrtFrm).arg(strmsgtyp).arg(stPktHdr.usMsgLength)
                           .arg(stPktHdr.usMsgSeq).arg(stPktHdr.usStatKavachID).arg(stPktHdr.usNMSID)
                           .arg(stPktHdr.ucVersion).arg(strdate).arg(strtime).arg(strSpecProtl)
                           .arg(strSubmsgtyp).arg(strSenderId).arg(strReceiverId).arg(stHeartBeat.usMsgLen)
                           .arg(strFrameNum).arg(stHeartBeat.usMsgSeq)
                           .arg(stHeartBeat.uiMAC_Code).arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the station 2 station Heart Beat packet into database";
    }
    else
    {
        qDebug () << "Failed to insert the station 2 station Heart Beat packet into database";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBS2STrainHandOverReq(stPacketHeader stPktHdr, stTrainHandOverReqPkt stTrnHndOveReq)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stPktHdr.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stPktHdr.ucMsgType,0,16).toUpper();

    QString strSpecProtl = QString("0x%1").arg(stTrnHndOveReq.ucSpecificProtocol,0,16).toUpper();
    QString strSubmsgtyp = QString("0x%1").arg(stTrnHndOveReq.usMsgTyp,0,16).toUpper();

    QString strCRC = QString("0x%1").arg(stTrnHndOveReq.uiCRC,0,16).toUpper();

    QString strSenderId, strReceiverId,strLoco2StnRegPkt;
    for (int i = 0; i < 20; ++i)
        strSenderId.append(QString("%1 ").arg(stTrnHndOveReq.ucSenderID[i], 2, 16, QLatin1Char('0')).toUpper());
    for (int i = 0; i < 20; ++i)
        strReceiverId.append(QString("%1 ").arg(stTrnHndOveReq.ucReceiverID[i], 2, 16, QLatin1Char('0')).toUpper());
    for (int i = 0; i < 21; ++i)
        strLoco2StnRegPkt.append(QString("%1 ").arg(stTrnHndOveReq.ucLocotoStnRegPkt[i], 2, 16, QLatin1Char('0')).toUpper());


    QString strFrameNum = QString("%1 %2 %3")
                              .arg(stTrnHndOveReq.ucFrameNum[0], 2, 16, QChar('0'))
                              .arg(stTrnHndOveReq.ucFrameNum[1], 2, 16, QChar('0'))
                              .arg(stTrnHndOveReq.ucFrameNum[2], 2, 16, QChar('0'));

    QString strQuery = QString("INSERT INTO public.s2strainhandoverreqpkt("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", \"STN_KAVACH_ID\", "
                               "\"NMS_SYSTEM_ID\", \"SYSTEM_VER\", \"DATE\", \"TIME\", \"SPECIFIC_PROTOCOL\", "
                               "\"SUB_MSG_TYP\", \"SENDER_ID\", \"RECEIVER_ID\", \"SUB_MSG_LEN\", \"FRAME_NUM\", "
                               "\"SUB_MSG_SEQ\", \"BORDER_RFID_TAG\", \"MA_FROM_BORDER_RFID_TAG\", "
                               "\"DIST_TO_BORDER_TAG\", \"LOCO_TO_STN_REG_PKT\", \"MAC_CODE\", \"CRC\")"
                               "VALUES ('%1','%2',%3,%4,%5,%6,%7,'%8','%9','%10','%11','%12','%13',%14,'%15',"
                               "%16,%17,%18,%19,'%20','%21','%22');")
                           .arg(strStrtFrm).arg(strmsgtyp).arg(stPktHdr.usMsgLength)
                           .arg(stPktHdr.usMsgSeq).arg(stPktHdr.usStatKavachID).arg(stPktHdr.usNMSID)
                           .arg(stPktHdr.ucVersion).arg(strdate).arg(strtime).arg(strSpecProtl)
                           .arg(strSubmsgtyp).arg(strSenderId).arg(strReceiverId).arg(stTrnHndOveReq.usMsgLen)
                           .arg(strFrameNum).arg(stTrnHndOveReq.usMsgSeq).arg(stTrnHndOveReq.usRFIDTag)
                           .arg(stTrnHndOveReq.ucMAfrmRFIDTag).arg(stTrnHndOveReq.usDistToBorderTag)
                           .arg(strLoco2StnRegPkt).arg(stTrnHndOveReq.uiMAC_Code).arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the station 2 station Train Hand over requect packet into database";
    }
    else
    {
        qDebug () << "Failed to insert the station 2 station Train Hand over requect packet into database";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBS2STrainTakenOverMsg(stPacketHeader stPktHdr, stTrainTakenOverPkt stTrnTknOveMsg)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stPktHdr.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stPktHdr.ucMsgType,0,16).toUpper();

    QString strSpecProtl = QString("0x%1").arg(stTrnTknOveMsg.ucSpecificProtocol,0,16).toUpper();
    QString strSubmsgtyp = QString("0x%1").arg(stTrnTknOveMsg.usMsgTyp,0,16).toUpper();

    QString strCRC = QString("0x%1").arg(stTrnTknOveMsg.uiCRC,0,16).toUpper();

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
        strSenderId.append(QString("%1 ").arg(stTrnTknOveMsg.ucSenderID[i], 2, 16, QLatin1Char('0')).toUpper());
    for (int i = 0; i < 20; ++i)
        strReceiverId.append(QString("%1 ").arg(stTrnTknOveMsg.ucReceiverID[i], 2, 16, QLatin1Char('0')).toUpper());

    QString strFrameNum = QString("%1 %2 %3")
                              .arg(stTrnTknOveMsg.ucFrameNum[0], 2, 16, QChar('0'))
                              .arg(stTrnTknOveMsg.ucFrameNum[1], 2, 16, QChar('0'))
                              .arg(stTrnTknOveMsg.ucFrameNum[2], 2, 16, QChar('0')).toUpper();

    QString strOnBrdKavachID = QString("%1 %2 %3")
                              .arg(stTrnTknOveMsg.usOnBoardKavachID[0], 2, 16, QChar('0'))
                              .arg(stTrnTknOveMsg.usOnBoardKavachID[1], 2, 16, QChar('0'))
                              .arg(stTrnTknOveMsg.usOnBoardKavachID[2], 2, 16, QChar('0')).toUpper();

    QString strQuery = QString("INSERT INTO public.s2straintakenoverpkt("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", \"STN_KAVACH_ID\", "
                               "\"NMS_SYSTEM_ID\", \"SYSTEM_VER\", \"DATE\", \"TIME\", \"SPECIFIC_PROTOCOL\", "
                               "\"SUB_MSG_TYP\", \"SENDER_ID\", \"RECEIVER_ID\", \"SUB_MSG_LEN\", \"FRAME_NUM\", "
                               "\"SUB_MSG_SEQ\", \"BORDER_RFID_TAG\", \"ONBOARD_KAVACH_ID\", \"MAC_CODE\", \"CRC\")"
                               "VALUES ('%1','%2',%3,%4,%5,%6,%7,'%8','%9','%10','%11','%12','%13',%14,'%15',"
                               "%16,%17,'%18','%19','%20');")
                           .arg(strStrtFrm).arg(strmsgtyp).arg(stPktHdr.usMsgLength)
                           .arg(stPktHdr.usMsgSeq).arg(stPktHdr.usStatKavachID).arg(stPktHdr.usNMSID)
                           .arg(stPktHdr.ucVersion).arg(strdate).arg(strtime).arg(strSpecProtl)
                           .arg(strSubmsgtyp).arg(strSenderId).arg(strReceiverId).arg(stTrnTknOveMsg.usMsgLen)
                           .arg(strFrameNum).arg(stTrnTknOveMsg.usMsgSeq).arg(stTrnTknOveMsg.usRFIDTag)
                           .arg(strOnBrdKavachID).arg(stTrnTknOveMsg.uiMAC_Code).arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the station 2 station Train Taken over packet into database";
    }
    else
    {
        qDebug () << "Failed to insert the station 2 station Train Taken over packet into database";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBS2STrainHandOverCancellationReq(stPacketHeader stPktHdr, stTrainHandOverCancellationPkt stTrnHndOvrCnclPkt)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stPktHdr.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stPktHdr.ucMsgType,0,16).toUpper();

    QString strSpecProtl = QString("0x%1").arg(stTrnHndOvrCnclPkt.ucSpecificProtocol,0,16).toUpper();
    QString strSubmsgtyp = QString("0x%1").arg(stTrnHndOvrCnclPkt.usMsgTyp,0,16).toUpper();

    QString strCRC = QString("0x%1").arg(stTrnHndOvrCnclPkt.uiCRC,0,16).toUpper();

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
        strSenderId.append(QString("%1 ").arg(stTrnHndOvrCnclPkt.ucSenderID[i], 2, 16, QLatin1Char('0')).toUpper());
    for (int i = 0; i < 20; ++i)
        strReceiverId.append(QString("%1 ").arg(stTrnHndOvrCnclPkt.ucReceiverID[i], 2, 16, QLatin1Char('0')).toUpper());


    QString strFrameNum = QString("%1 %2 %3")
                              .arg(stTrnHndOvrCnclPkt.ucFrameNum[0], 2, 16, QChar('0'))
                              .arg(stTrnHndOvrCnclPkt.ucFrameNum[1], 2, 16, QChar('0'))
                              .arg(stTrnHndOvrCnclPkt.ucFrameNum[2], 2, 16, QChar('0')).toUpper();

    QString strOnBrdKavachID = QString("%1 %2 %3")
                                   .arg(stTrnHndOvrCnclPkt.usOnBoardKavachID[0], 2, 16, QChar('0'))
                                   .arg(stTrnHndOvrCnclPkt.usOnBoardKavachID[1], 2, 16, QChar('0'))
                                   .arg(stTrnHndOvrCnclPkt.usOnBoardKavachID[2], 2, 16, QChar('0')).toUpper();

    QString strQuery = QString("INSERT INTO public.s2strainhandovercancellationpkt("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", \"STN_KAVACH_ID\", "
                               "\"NMS_SYSTEM_ID\", \"SYSTEM_VER\", \"DATE\", \"TIME\", \"SPECIFIC_PROTOCOL\", "
                               "\"SUB_MSG_TYP\", \"SENDER_ID\", \"RECEIVER_ID\", \"SUB_MSG_LEN\", \"FRAME_NUM\", "
                               "\"SUB_MSG_SEQ\", \"BORDER_RFID_TAG\", \"ONBOARD_KAVACH_ID\", \"MAC_CODE\", \"CRC\")"
                               "VALUES ('%1','%2',%3,%4,%5,%6,%7,'%8','%9','%10','%11','%12','%13',%14,'%15',"
                               "%16,%17,'%18','%19','%20');")
                           .arg(strStrtFrm).arg(strmsgtyp).arg(stPktHdr.usMsgLength)
                           .arg(stPktHdr.usMsgSeq).arg(stPktHdr.usStatKavachID).arg(stPktHdr.usNMSID)
                           .arg(stPktHdr.ucVersion).arg(strdate).arg(strtime).arg(strSpecProtl)
                           .arg(strSubmsgtyp).arg(strSenderId).arg(strReceiverId).arg(stTrnHndOvrCnclPkt.usMsgLen)
                           .arg(strFrameNum).arg(stTrnHndOvrCnclPkt.usMsgSeq).arg(stTrnHndOvrCnclPkt.usRFIDTag)
                           .arg(strOnBrdKavachID).arg(stTrnHndOvrCnclPkt.uiMAC_Code).arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the station 2 station Train handover cancellation packet into database";
    }
    else
    {
        qDebug () << "Failed to insert the station 2 station Train handover cancellation packet into database";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBS2STrainLengthInformationReq(stPacketHeader stPktHdr, stTrainLengthInfoPkt stTrnLenInfoPkt)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stPktHdr.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stPktHdr.ucMsgType,0,16).toUpper();

    QString strSpecProtl = QString("0x%1").arg(stTrnLenInfoPkt.ucSpecificProtocol,0,16).toUpper();
    QString strSubmsgtyp = QString("0x%1").arg(stTrnLenInfoPkt.usMsgTyp,0,16).toUpper();

    QString strCRC = QString("0x%1").arg(stTrnLenInfoPkt.uiCRC,0,16).toUpper();

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
        strSenderId.append(QString("%1 ").arg(stTrnLenInfoPkt.ucSenderID[i], 2, 16, QLatin1Char('0')).toUpper());
    for (int i = 0; i < 20; ++i)
        strReceiverId.append(QString("%1 ").arg(stTrnLenInfoPkt.ucReceiverID[i], 2, 16, QLatin1Char('0')).toUpper());

    QString strFrameNum = QString("%1 %2 %3")
                              .arg(stTrnLenInfoPkt.ucFrameNum[0], 2, 16, QChar('0'))
                              .arg(stTrnLenInfoPkt.ucFrameNum[1], 2, 16, QChar('0'))
                              .arg(stTrnLenInfoPkt.ucFrameNum[2], 2, 16, QChar('0')).toUpper();

    QString strOnBrdKavachID = QString("%1 %2 %3")
                                   .arg(stTrnLenInfoPkt.usOnBoardKavachID[0], 2, 16, QChar('0'))
                                   .arg(stTrnLenInfoPkt.usOnBoardKavachID[1], 2, 16, QChar('0'))
                                   .arg(stTrnLenInfoPkt.usOnBoardKavachID[2], 2, 16, QChar('0')).toUpper();

    QString strTrnLenFrame = QString("%1 %2 %3")
                                   .arg(stTrnLenInfoPkt.ucTrainLenMeasntframe[0], 2, 16, QChar('0'))
                                   .arg(stTrnLenInfoPkt.ucTrainLenMeasntframe[1], 2, 16, QChar('0'))
                                   .arg(stTrnLenInfoPkt.ucTrainLenMeasntframe[2], 2, 16, QChar('0')).toUpper();

    QString strQuery = QString("INSERT INTO public.s2strainlengthinfopkt("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", \"STN_KAVACH_ID\", "
                               "\"NMS_SYSTEM_ID\", \"SYSTEM_VER\", \"DATE\", \"TIME\", \"SPECIFIC_PROTOCOL\", "
                               "\"SUB_MSG_TYP\", \"SENDER_ID\", \"RECEIVER_ID\", \"SUB_MSG_LEN\", \"FRAME_NUM\", "
                               "\"SUB_MSG_SEQ\", \"BORDER_RFID_TAG\", \"ONBOARD_KAVACH_ID\", \"TRAIN_LEN_INFO_STS\", "
                               "\"TRAIN_LEN_MEASUREMENT_FRAME\", \"TRAIN_LEN_MEASUREMENT_FRAME_OFFSET\", \"MAC_CODE\", \"CRC\")"
                               "VALUES ('%1','%2',%3,%4,%5,%6,%7,'%8','%9','%10','%11','%12','%13',%14,'%15',"
                               "%16,%17,'%18',%19,'%20',%21,'%22','%23');")
                           .arg(strStrtFrm).arg(strmsgtyp).arg(stPktHdr.usMsgLength)
                           .arg(stPktHdr.usMsgSeq).arg(stPktHdr.usStatKavachID).arg(stPktHdr.usNMSID)
                           .arg(stPktHdr.ucVersion).arg(strdate).arg(strtime).arg(strSpecProtl)
                           .arg(strSubmsgtyp).arg(strSenderId).arg(strReceiverId).arg(stTrnLenInfoPkt.usMsgLen)
                           .arg(strFrameNum).arg(stTrnLenInfoPkt.usMsgSeq).arg(stTrnLenInfoPkt.usRFIDTag)
                           .arg(strOnBrdKavachID).arg(stTrnLenInfoPkt.ucTrainLenInfSts)
                           .arg(strTrnLenFrame).arg(stTrnLenInfoPkt.ucTrainLenMeasntframeOffset)
                           .arg(stTrnLenInfoPkt.uiMAC_Code).arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the station 2 station Train Length Information packet into database";
    }
    else
    {
        qDebug () << "Failed to insert the station 2 station Train Length Information packet into database";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBS2SLengthInformationAck(stPacketHeader stPktHdr, stTrainLengthInfoAck stTrnLenInfoAck)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stPktHdr.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stPktHdr.ucMsgType,0,16).toUpper();

    QString strSpecProtl = QString("0x%1").arg(stTrnLenInfoAck.ucSpecificProtocol,0,16).toUpper();
    QString strSubmsgtyp = QString("0x%1").arg(stTrnLenInfoAck.usMsgTyp,0,16).toUpper();

    QString strCRC = QString("0x%1").arg(stTrnLenInfoAck.uiCRC,0,16).toUpper();

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
        strSenderId.append(QString("%1 ").arg(stTrnLenInfoAck.ucSenderID[i], 2, 16, QLatin1Char('0')).toUpper());
    for (int i = 0; i < 20; ++i)
        strReceiverId.append(QString("%1 ").arg(stTrnLenInfoAck.ucReceiverID[i], 2, 16, QLatin1Char('0')).toUpper());

    QString strFrameNum = QString("%1 %2 %3")
                              .arg(stTrnLenInfoAck.ucFrameNum[0], 2, 16, QChar('0'))
                              .arg(stTrnLenInfoAck.ucFrameNum[1], 2, 16, QChar('0'))
                              .arg(stTrnLenInfoAck.ucFrameNum[2], 2, 16, QChar('0')).toUpper();

    QString strOnBrdKavachID = QString("%1 %2 %3")
                                   .arg(stTrnLenInfoAck.usOnBoardKavachID[0], 2, 16, QChar('0'))
                                   .arg(stTrnLenInfoAck.usOnBoardKavachID[1], 2, 16, QChar('0'))
                                   .arg(stTrnLenInfoAck.usOnBoardKavachID[2], 2, 16, QChar('0')).toUpper();

    QString strQuery = QString("INSERT INTO public.s2strainlengthinfoackpkt("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", \"STN_KAVACH_ID\", "
                               "\"NMS_SYSTEM_ID\", \"SYSTEM_VER\", \"DATE\", \"TIME\", \"SPECIFIC_PROTOCOL\", "
                               "\"SUB_MSG_TYP\", \"SENDER_ID\", \"RECEIVER_ID\", \"SUB_MSG_LEN\", \"FRAME_NUM\", "
                               "\"SUB_MSG_SEQ\", \"BORDER_RFID_TAG\", \"ONBOARD_KAVACH_ID\", \"TRAIN_LEN_INFO_STS\", "
                               "\"MAC_CODE\", \"CRC\")"
                               "VALUES ('%1','%2',%3,%4,%5,%6,%7,'%8','%9','%10','%11','%12','%13',%14,'%15',"
                               "%16,%17,'%18',%19,'%20','%21');")
                           .arg(strStrtFrm).arg(strmsgtyp).arg(stPktHdr.usMsgLength)
                           .arg(stPktHdr.usMsgSeq).arg(stPktHdr.usStatKavachID).arg(stPktHdr.usNMSID)
                           .arg(stPktHdr.ucVersion).arg(strdate).arg(strtime).arg(strSpecProtl)
                           .arg(strSubmsgtyp).arg(strSenderId).arg(strReceiverId).arg(stTrnLenInfoAck.usMsgLen)
                           .arg(strFrameNum).arg(stTrnLenInfoAck.usMsgSeq).arg(stTrnLenInfoAck.usRFIDTag)
                           .arg(strOnBrdKavachID).arg(stTrnLenInfoAck.ucTrainLenInf)
                           .arg(stTrnLenInfoAck.uiMAC_Code).arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the station 2 station Train Length Information Ack packet into database";
    }
    else
    {
        qDebug () << "Failed to insert the station 2 station Train Length Information Ack packet into database";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBS2STSLRouteRequest(stPacketHeader stPktHdr, stTSLReqPkt stTSLRouteReq)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stPktHdr.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stPktHdr.ucMsgType,0,16).toUpper();

    QString strSpecProtl = QString("0x%1").arg(stTSLRouteReq.ucSpecificProtocol,0,16).toUpper();
    QString strSubmsgtyp = QString("0x%1").arg(stTSLRouteReq.usMsgTyp,0,16).toUpper();

    QString strCRC = QString("0x%1").arg(stTSLRouteReq.uiCRC,0,16).toUpper();

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
        strSenderId.append(QString("%1 ").arg(stTSLRouteReq.ucSenderID[i], 2, 16, QLatin1Char('0')).toUpper());
    for (int i = 0; i < 20; ++i)
        strReceiverId.append(QString("%1 ").arg(stTSLRouteReq.ucReceiverID[i], 2, 16, QLatin1Char('0')).toUpper());

    QString strFrameNum = QString("%1 %2 %3")
                              .arg(stTSLRouteReq.ucFrameNum[0], 2, 16, QChar('0'))
                              .arg(stTSLRouteReq.ucFrameNum[1], 2, 16, QChar('0'))
                              .arg(stTSLRouteReq.ucFrameNum[2], 2, 16, QChar('0')).toUpper();

    QString strOnBrdKavachID = QString("%1 %2 %3")
                                   .arg(stTSLRouteReq.usOnBoardKavachID[0], 2, 16, QChar('0'))
                                   .arg(stTSLRouteReq.usOnBoardKavachID[1], 2, 16, QChar('0'))
                                   .arg(stTSLRouteReq.usOnBoardKavachID[2], 2, 16, QChar('0')).toUpper();

    QString strQuery = QString("INSERT INTO public.s2stslroutereqpkt("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", \"STN_KAVACH_ID\", "
                               "\"NMS_SYSTEM_ID\", \"SYSTEM_VER\", \"DATE\", \"TIME\", \"SPECIFIC_PROTOCOL\", "
                               "\"SUB_MSG_TYP\", \"SENDER_ID\", \"RECEIVER_ID\", \"SUB_MSG_LEN\", \"FRAME_NUM\", "
                               "\"SUB_MSG_SEQ\", \"BORDER_RFID_TAG\", \"ONBOARD_KAVACH_ID\", "
                               "\"TSL_ROUTE_ID\", \"MAC_CODE\", \"CRC\")"
                               "VALUES ('%1','%2',%3,%4,%5,%6,%7,'%8','%9','%10','%11','%12','%13',%14,'%15',"
                               "%16,%17,'%18',%19,'%20','%21');")
                           .arg(strStrtFrm).arg(strmsgtyp).arg(stPktHdr.usMsgLength)
                           .arg(stPktHdr.usMsgSeq).arg(stPktHdr.usStatKavachID).arg(stPktHdr.usNMSID)
                           .arg(stPktHdr.ucVersion).arg(strdate).arg(strtime).arg(strSpecProtl)
                           .arg(strSubmsgtyp).arg(strSenderId).arg(strReceiverId).arg(stTSLRouteReq.usMsgLen)
                           .arg(strFrameNum).arg(stTSLRouteReq.usMsgSeq).arg(stTSLRouteReq.usRFIDTag)
                           .arg(strOnBrdKavachID).arg(stTSLRouteReq.ucRouteID)
                           .arg(stTSLRouteReq.uiMAC_Code).arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the station 2 station TSL Route request packet into database";
    }
    else
    {
        qDebug () << "Failed to insert the station 2 station TSL Route request packet into database";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBS2STSLAuthorityInformationPkt(stPacketHeader stPktHdr, stTSLInformationPkt stTSLInfoPkt)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stPktHdr.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stPktHdr.ucMsgType,0,16).toUpper();

    QString strSpecProtl = QString("0x%1").arg(stTSLInfoPkt.ucSpecificProtocol,0,16).toUpper();
    QString strSubmsgtyp = QString("0x%1").arg(stTSLInfoPkt.usMsgTyp,0,16).toUpper();

    QString strCRC = QString("0x%1").arg(stTSLInfoPkt.uiCRC,0,16).toUpper();

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
        strSenderId.append(QString("%1 ").arg(stTSLInfoPkt.ucSenderID[i], 2, 16, QLatin1Char('0')).toUpper());
    for (int i = 0; i < 20; ++i)
        strReceiverId.append(QString("%1 ").arg(stTSLInfoPkt.ucReceiverID[i], 2, 16, QLatin1Char('0')).toUpper());

    QString strFrameNum = QString("%1 %2 %3")
                              .arg(stTSLInfoPkt.ucFrameNum[0], 2, 16, QChar('0'))
                              .arg(stTSLInfoPkt.ucFrameNum[1], 2, 16, QChar('0'))
                              .arg(stTSLInfoPkt.ucFrameNum[2], 2, 16, QChar('0')).toUpper();

    QString strOnBrdKavachID = QString("%1 %2 %3")
                                   .arg(stTSLInfoPkt.usOnBoardKavachID[0], 2, 16, QChar('0'))
                                   .arg(stTSLInfoPkt.usOnBoardKavachID[1], 2, 16, QChar('0'))
                                   .arg(stTSLInfoPkt.usOnBoardKavachID[2], 2, 16, QChar('0')).toUpper();

    QString strQuery = QString("INSERT INTO public.s2stslauthorityinformationpkt("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", \"STN_KAVACH_ID\", "
                               "\"NMS_SYSTEM_ID\", \"SYSTEM_VER\", \"DATE\", \"TIME\", \"SPECIFIC_PROTOCOL\", "
                               "\"SUB_MSG_TYP\", \"SENDER_ID\", \"RECEIVER_ID\", \"SUB_MSG_LEN\", \"FRAME_NUM\", "
                               "\"SUB_MSG_SEQ\", \"BORDER_RFID_TAG\", \"ONBOARD_KAVACH_ID\", "
                               "\"TSL_ROUTE_REQ_REPLY\", \"MAC_CODE\", \"CRC\")"
                               "VALUES ('%1','%2',%3,%4,%5,%6,%7,'%8','%9','%10','%11','%12','%13',%14,'%15',"
                               "%16,%17,'%18',%19,'%20','%21');")
                           .arg(strStrtFrm).arg(strmsgtyp).arg(stPktHdr.usMsgLength)
                           .arg(stPktHdr.usMsgSeq).arg(stPktHdr.usStatKavachID).arg(stPktHdr.usNMSID)
                           .arg(stPktHdr.ucVersion).arg(strdate).arg(strtime).arg(strSpecProtl)
                           .arg(strSubmsgtyp).arg(strSenderId).arg(strReceiverId).arg(stTSLInfoPkt.usMsgLen)
                           .arg(strFrameNum).arg(stTSLInfoPkt.usMsgSeq).arg(stTSLInfoPkt.usRFIDTag)
                           .arg(strOnBrdKavachID).arg(stTSLInfoPkt.ucTSLReqReply)
                           .arg(stTSLInfoPkt.uiMAC_Code).arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the station 2 station TSL Authority packet into database";
    }
    else
    {
        qDebug () << "Failed to insert the station 2 station TSL Authority packet into database";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBS2SFieldElementsStatusReq(stPacketHeader stPktHdr, stFieldElementsStatusReqPkt stFldElementStsReq)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stPktHdr.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stPktHdr.ucMsgType,0,16).toUpper();

    QString strSpecProtl = QString("0x%1").arg(stFldElementStsReq.ucSpecificProtocol,0,16).toUpper();
    QString strSubmsgtyp = QString("0x%1").arg(stFldElementStsReq.usMsgTyp,0,16).toUpper();

    QString strCRC = QString("0x%1").arg(stFldElementStsReq.uiCRC,0,16).toUpper();

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
        strSenderId.append(QString("%1 ").arg(stFldElementStsReq.ucSenderID[i], 2, 16, QLatin1Char('0')).toUpper());
    for (int i = 0; i < 20; ++i)
        strReceiverId.append(QString("%1 ").arg(stFldElementStsReq.ucReceiverID[i], 2, 16, QLatin1Char('0')).toUpper());

    QString strFrameNum = QString("%1 %2 %3")
                              .arg(stFldElementStsReq.ucFrameNum[0], 2, 16, QChar('0'))
                              .arg(stFldElementStsReq.ucFrameNum[1], 2, 16, QChar('0'))
                              .arg(stFldElementStsReq.ucFrameNum[2], 2, 16, QChar('0')).toUpper();


    QString strQuery = QString("INSERT INTO public.s2sfieldelementsstatusreqpkt("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", \"STN_KAVACH_ID\", "
                               "\"NMS_SYSTEM_ID\", \"SYSTEM_VER\", \"DATE\", \"TIME\", \"SPECIFIC_PROTOCOL\", "
                               "\"SUB_MSG_TYP\", \"SENDER_ID\", \"RECEIVER_ID\", \"SUB_MSG_LEN\", \"FRAME_NUM\", "
                               "\"SUB_MSG_SEQ\", \"MAC_CODE\", \"CRC\")"
                               "VALUES ('%1','%2',%3,%4,%5,%6,%7,'%8','%9','%10','%11','%12','%13',%14,'%15',"
                               "%16,'%17','%18');")
                           .arg(strStrtFrm).arg(strmsgtyp).arg(stPktHdr.usMsgLength)
                           .arg(stPktHdr.usMsgSeq).arg(stPktHdr.usStatKavachID).arg(stPktHdr.usNMSID)
                           .arg(stPktHdr.ucVersion).arg(strdate).arg(strtime).arg(strSpecProtl)
                           .arg(strSubmsgtyp).arg(strSenderId).arg(strReceiverId).arg(stFldElementStsReq.usMsgLen)
                           .arg(strFrameNum).arg(stFldElementStsReq.usMsgSeq)
                           .arg(stFldElementStsReq.uiMAC_Code).arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the station 2 station Field elements status request packet into database";
    }
    else
    {
        qDebug () << "Failed to insert the station 2 station Field elements status request packet into database";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBS2STrainHandoverCancellationAck(stPacketHeader stPktHdr, stTrainHandOverCancellationAckPkt stTrnHndOvrCnclAck)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stPktHdr.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stPktHdr.ucMsgType,0,16).toUpper();

    QString strSpecProtl = QString("0x%1").arg(stTrnHndOvrCnclAck.ucSpecificProtocol,0,16).toUpper();
    QString strSubmsgtyp = QString("0x%1").arg(stTrnHndOvrCnclAck.usMsgTyp,0,16).toUpper();

    QString strCRC = QString("0x%1").arg(stTrnHndOvrCnclAck.uiCRC,0,16).toUpper();

    QString strSenderId, strReceiverId;
    for (int i = 0; i < 20; ++i)
        strSenderId.append(QString("%1 ").arg(stTrnHndOvrCnclAck.ucSenderID[i], 2, 16, QLatin1Char('0')).toUpper());
    for (int i = 0; i < 20; ++i)
        strReceiverId.append(QString("%1 ").arg(stTrnHndOvrCnclAck.ucReceiverID[i], 2, 16, QLatin1Char('0')).toUpper());

    QString strFrameNum = QString("%1 %2 %3")
                              .arg(stTrnHndOvrCnclAck.ucFrameNum[0], 2, 16, QChar('0'))
                              .arg(stTrnHndOvrCnclAck.ucFrameNum[1], 2, 16, QChar('0'))
                              .arg(stTrnHndOvrCnclAck.ucFrameNum[2], 2, 16, QChar('0')).toUpper();

    QString strOnBrdKavachID = QString("%1 %2 %3")
                                   .arg(stTrnHndOvrCnclAck.usOnBoardKavachID[0], 2, 16, QChar('0'))
                                   .arg(stTrnHndOvrCnclAck.usOnBoardKavachID[1], 2, 16, QChar('0'))
                                   .arg(stTrnHndOvrCnclAck.usOnBoardKavachID[2], 2, 16, QChar('0')).toUpper();

    QString strQuery = QString("INSERT INTO public.s2strainhandovercanellationackpkt("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", \"STN_KAVACH_ID\", "
                               "\"NMS_SYSTEM_ID\", \"SYSTEM_VER\", \"DATE\", \"TIME\", \"SPECIFIC_PROTOCOL\", "
                               "\"SUB_MSG_TYP\", \"SENDER_ID\", \"RECEIVER_ID\", \"SUB_MSG_LEN\", \"FRAME_NUM\", "
                               "\"SUB_MSG_SEQ\", \"BORDER_RFID_TAG\", \"ONBOARD_KAVACH_ID\", \"MAC_CODE\", \"CRC\")"
                               "VALUES ('%1','%2',%3,%4,%5,%6,%7,'%8','%9','%10','%11','%12','%13',%14,'%15',"
                               "%16,%17,'%18','%19','%20');")
                           .arg(strStrtFrm).arg(strmsgtyp).arg(stPktHdr.usMsgLength)
                           .arg(stPktHdr.usMsgSeq).arg(stPktHdr.usStatKavachID).arg(stPktHdr.usNMSID)
                           .arg(stPktHdr.ucVersion).arg(strdate).arg(strtime).arg(strSpecProtl)
                           .arg(strSubmsgtyp).arg(strSenderId).arg(strReceiverId).arg(stTrnHndOvrCnclAck.usMsgLen)
                           .arg(strFrameNum).arg(stTrnHndOvrCnclAck.usMsgSeq).arg(stTrnHndOvrCnclAck.usRFIDTag)
                           .arg(strOnBrdKavachID).arg(stTrnHndOvrCnclAck.uiMAC_Code).arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the station 2 station Train handover cancellation acknowledgement packet into database";
    }
    else
    {
        qDebug () << "Failed to insert the station 2 station Train handover cancellation acknowledgement packet into database";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBLocoRSSIMessage(stLocoRSSIMsg stLocoRSSI)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stLocoRSSI.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stLocoRSSI.ucMsgType,0,16).toUpper();
    QString strCRC = QString("0x%1").arg(stLocoRSSI.uiCRC,0,16).toUpper();

    QString strLocoKavachID = QString("%1 %2 %3")
                                  .arg(stLocoRSSI.ucLocoKavachID[0], 2, 16, QChar('0'))
                                  .arg(stLocoRSSI.ucLocoKavachID[1], 2, 16, QChar('0'))
                                  .arg(stLocoRSSI.ucLocoKavachID[2], 2, 16, QChar('0')).toUpper();

    QString strRad1AbsLoc = QString("%1 %2 %3")
                                .arg(stLocoRSSI.ucAbsRefRFIDTag[0], 2, 16, QChar('0'))
                                .arg(stLocoRSSI.ucAbsRefRFIDTag[1], 2, 16, QChar('0'))
                                .arg(stLocoRSSI.ucAbsRefRFIDTag[2], 2, 16, QChar('0')).toUpper();

    QString strRad2AbsLoc = QString("%1 %2 %3")
                                .arg(stLocoRSSI.ucAbsRefRFIDTag2[0], 2, 16, QChar('0'))
                                .arg(stLocoRSSI.ucAbsRefRFIDTag2[1], 2, 16, QChar('0'))
                                .arg(stLocoRSSI.ucAbsRefRFIDTag2[2], 2, 16, QChar('0')).toUpper();

    QString strQuery = QString("INSERT INTO public.locorssimsg("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", \"LOCO_KAVACH_ID\", "
                               "\"NMS_SYSTEM_ID\", \"SYSTEM_VER\", \"DATE\", \"TIME\", \"STATION_KAVACH_ID\", "
                               "\"STATION_RADIO1_RSSI_CNT\", \"RADIO1_REF_RFID_TAG\", "
                               "\"RADIO1_ABS_REF_RFID_TAG\", \"RADIO1_RSSI_VALUE\", "
                               "\"STATION_RADIO-2_RSSI_CNT\", \"RADIO2_REF_RFID_TAG\", "
                               "\"RADIO2_ABS_REF_RFID_TAG\", \"RADIO2_RSSI_VALUE\", \"CRC\")"
                               "VALUES ('%1','%2',%3,%4,'%5',%6,%7,'%8','%9',%10,%11,%12,'%13',%14,%15,%16,'%17',%18,'%19');")
                           .arg(strStrtFrm).arg(strmsgtyp).arg(stLocoRSSI.usMsgLength)
                           .arg(stLocoRSSI.usMsgSeq).arg(strLocoKavachID).arg(stLocoRSSI.usNMSID)
                           .arg(stLocoRSSI.ucVersion).arg(strdate).arg(strtime).arg(stLocoRSSI.ucStationKavachID)
                           .arg(stLocoRSSI.ucStnRadio1RSSISamCnt).arg(stLocoRSSI.usRefRFIDTag).arg(strRad1AbsLoc)
                           .arg(stLocoRSSI.usRSSIValue).arg(stLocoRSSI.ucStnRadio2RSSISamCnt).arg(stLocoRSSI.usRefRFIDTag2)
                           .arg(strRad2AbsLoc).arg(stLocoRSSI.usRSSIValue2).arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the Loco kavach RSSI message packet into database";
    }
    else
    {
        qDebug () << "Failed to insert the Loco kavach RSSI message packet into database";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBStationRSSIMessage(stStationRSSIMsg stStnRSSI)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stStnRSSI.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stStnRSSI.ucMsgType,0,16).toUpper();
    QString strCRC = QString("0x%1").arg(stStnRSSI.uiCRC,0,16).toUpper();
    QString strLocoKavachID = QString("%1 %2 %3")
                                   .arg(stStnRSSI.ucLocoKavachID[0], 2, 16, QChar('0'))
                                   .arg(stStnRSSI.ucLocoKavachID[1], 2, 16, QChar('0'))
                                   .arg(stStnRSSI.ucLocoKavachID[2], 2, 16, QChar('0')).toUpper();

    QString strRad1AbsLoc = QString("%1 %2 %3")
                                  .arg(stStnRSSI.ucAbsloc[0], 2, 16, QChar('0'))
                                  .arg(stStnRSSI.ucAbsloc[1], 2, 16, QChar('0'))
                                  .arg(stStnRSSI.ucAbsloc[2], 2, 16, QChar('0')).toUpper();

    QString strRad2AbsLoc = QString("%1 %2 %3")
                                  .arg(stStnRSSI.ucAbsloc2[0], 2, 16, QChar('0'))
                                  .arg(stStnRSSI.ucAbsloc2[1], 2, 16, QChar('0'))
                                  .arg(stStnRSSI.ucAbsloc2[2], 2, 16, QChar('0')).toUpper();


    QString strQuery = QString("INSERT INTO public.stationrssimsg("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", \"STN_KAVACH_ID\", "
                               "\"NMS_SYSTEM_ID\", \"SYSTEM_VER\", \"DATE\", \"TIME\", \"LOCO_KAVACH_ID\", "
                               "\"ONBOARD_RADIO1_RSSI_CNT\", \"RADIO1_REF_RFID_TAG\", "
                               "\"RADIO1_ABS_REF_RFID_TAG\", \"RADIO1_RSSI_VALUE\", "
                               "\"ONBOARD_RADIO-2_RSSI_CNT\", \"RADIO2_REF_RFID_TAG\", "
                               "\"RADIO2_ABS_REF_RFID_TAG\", \"RADIO2_RSSI_VALUE\", \"CRC\")"
                               "VALUES ('%1','%2',%3,%4,%5,%6,%7,'%8','%9','%10',%11,%12,'%13',%14,%15,%16,'%17',%18,'%19');")
                           .arg(strStrtFrm).arg(strmsgtyp).arg(stStnRSSI.usMsgLength)
                           .arg(stStnRSSI.usMsgSeq).arg(stStnRSSI.usStatKavachID).arg(stStnRSSI.usNMSID)
                           .arg(stStnRSSI.ucVersion).arg(strdate).arg(strtime).arg(strLocoKavachID)
                           .arg(stStnRSSI.ucOnBrdRadio1RSSISamCnt).arg(stStnRSSI.usRefRFIDTag).arg(strRad1AbsLoc)
                           .arg(stStnRSSI.usRSSIValue).arg(stStnRSSI.ucOnBrdRadio2RSSISamCnt).arg(stStnRSSI.usRefRFIDTag2)
                           .arg(strRad2AbsLoc).arg(stStnRSSI.usRSSIValue2).arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the Station kavach RSSI message packet into database";
    }
    else
    {
        qDebug () << "Failed to insert the Station kavach RSSI message packet into database";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBStatioKavachSysSts(stStationaryKavachSysInfo stStnKavchSysSts)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strDate = datetime.date().toString("yyyy-MM-dd");
    QString strTime = datetime.time().toString("hh:mm:ss");

    QString strSOF  = QString("0x%1").arg(stStnKavchSysSts.usStartFrame,0,16).toUpper();
    QString strType = QString("0x%1").arg(stStnKavchSysSts.ucMsgType,0,16).toUpper();
    QString strCRC  = QString("0x%1").arg(stStnKavchSysSts.uiCRC,0,16).toUpper();

    // Date & Time (packet)
    QString strPktDate = QString("%1-%2-%3")
                             .arg(stStnKavchSysSts.ucDate[0],2,10,QChar('0'))
                             .arg(stStnKavchSysSts.ucDate[1],2,10,QChar('0'))
                             .arg(stStnKavchSysSts.ucDate[2],2,10,QChar('0'));

    QString strPktTime = QString("%1:%2:%3")
                             .arg(stStnKavchSysSts.ucTime[0],2,10,QChar('0'))
                             .arg(stStnKavchSysSts.ucTime[1],2,10,QChar('0'))
                             .arg(stStnKavchSysSts.ucTime[2],2,10,QChar('0'));

    QString strQuery = QString(
                           "INSERT INTO public.station_kavach_sysinfo("
                           "\"SOF\",\"MSG_TYPE\",\"MSG_LEN\",\"MSG_SEQ\",\"STN_KAVACH_ID\",\"NMS_ID\",\"VERSION\","
                           "\"PKT_DATE\",\"PKT_TIME\","
                           "\"CPU_STATUS\",\"SYS_HEALTH\",\"PS_DIAG\",\"SYS_COM_STATUS\",\"TIME_SYNC\",\"DI_BITMAP\","

                           "\"DI1_MODULE_ID\",\"DI1_SLOT_ID\",\"DI1_STATUS\",\"DI1_VAL_1_32\",\"DI1_VAL_33_64\",\"DI1_OK_1_32\",\"DI1_OK_33_64\","
                           "\"DI2_MODULE_ID\",\"DI2_SLOT_ID\",\"DI2_STATUS\",\"DI2_VAL_1_32\",\"DI2_VAL_33_64\",\"DI2_OK_1_32\",\"DI2_OK_33_64\","
                           "\"DI3_MODULE_ID\",\"DI3_SLOT_ID\",\"DI3_STATUS\",\"DI3_VAL_1_32\",\"DI3_VAL_33_64\",\"DI3_OK_1_32\",\"DI3_OK_33_64\","
                           "\"DI4_MODULE_ID\",\"DI4_SLOT_ID\",\"DI4_STATUS\",\"DI4_VAL_1_32\",\"DI4_VAL_33_64\",\"DI4_OK_1_32\",\"DI4_OK_33_64\","
                           "\"DI5_MODULE_ID\",\"DI5_SLOT_ID\",\"DI5_STATUS\",\"DI5_VAL_1_32\",\"DI5_VAL_33_64\",\"DI5_OK_1_32\",\"DI5_OK_33_64\","

                           "\"RIU1_ID\",\"RIU1_CPU\",\"RIU1_HEALTH\",\"RIU1_COMM\",\"RIU1_STATE\",\"RIU1_ERROR\","
                           "\"RIU2_ID\",\"RIU2_CPU\",\"RIU2_HEALTH\",\"RIU2_COMM\",\"RIU2_STATE\",\"RIU2_ERROR\","
                           "\"RIU3_ID\",\"RIU3_CPU\",\"RIU3_HEALTH\",\"RIU3_COMM\",\"RIU3_STATE\",\"RIU3_ERROR\","
                           "\"RIU4_ID\",\"RIU4_CPU\",\"RIU4_HEALTH\",\"RIU4_COMM\",\"RIU4_STATE\",\"RIU4_ERROR\","
                           "\"RIU5_ID\",\"RIU5_CPU\",\"RIU5_HEALTH\",\"RIU5_COMM\",\"RIU5_STATE\",\"RIU5_ERROR\","
                           "\"RIU6_ID\",\"RIU6_CPU\",\"RIU6_HEALTH\",\"RIU6_COMM\",\"RIU6_STATE\",\"RIU6_ERROR\","

                           "\"SMOCIP\",\"LTE\",\"UHF\",\"ADJ_LEFT\",\"ADJ_RIGHT\",\"NMS\",\"TSRMS\",\"KMS\",\"GNSS\",\"EVT_LOG\",\"EI\",\"VDU\","
                           "\"CRC\") VALUES ("

                           "'%1','%2',%3,%4,%5,%6,%7,'%8','%9',"
                           "%10,%11,%12,%13,%14,%15,"

                           "%16,%17,%18,%19,%20,%21,%22,"
                           "%23,%24,%25,%26,%27,%28,%29,"
                           "%30,%31,%32,%33,%34,%35,%36,"
                           "%37,%38,%39,%40,%41,%42,%43,"
                           "%44,%45,%46,%47,%48,%49,%50,"

                           "%51,%52,%53,%54,%55,%56,"
                           "%57,%58,%59,%60,%61,%62,"
                           "%63,%64,%65,%66,%67,%68,"
                           "%69,%70,%71,%72,%73,%74,"
                           "%75,%76,%77,%78,%79,%80,"
                           "%81,%82,%83,%84,%85,%86,"

                           "%87,%88,%89,%90,%91,%92,%93,%94,%95,%96,%97,%98,"
                           "'%99');")

                           // Header
                           .arg(strSOF).arg(strType).arg(stStnKavchSysSts.usMsgLength).arg(stStnKavchSysSts.usMsgSeq)
                           .arg(stStnKavchSysSts.usStationKavachID).arg(stStnKavchSysSts.usNMSID).arg(stStnKavchSysSts.ucVersion)
                           .arg(strPktDate).arg(strPktTime)

                           // System
                           .arg(stStnKavchSysSts.ucSystemCPUStatus).arg(stStnKavchSysSts.ucSystemHealth)
                           .arg(stStnKavchSysSts.ucPowerSupplyDiag).arg(stStnKavchSysSts.ucSystemComStatus)
                           .arg(stStnKavchSysSts.ucTimeSyncStatus).arg(stStnKavchSysSts.ucDIModuleBitmap)

                           // DI1
                           .arg(stStnKavchSysSts.ucDI1_ModuleID).arg(stStnKavchSysSts.ucDI1_SlotID).arg(stStnKavchSysSts.ucDI1_ModuleStatus)
                           .arg(stStnKavchSysSts.uiDI1_CH_Value_1_32).arg(stStnKavchSysSts.uiDI1_CH_Value_33_64)
                           .arg(stStnKavchSysSts.uiDI1_CH_OK_1_32).arg(stStnKavchSysSts.uiDI1_CH_OK_33_64)

                           // DI2–DI5 (same pattern...)
                           .arg(stStnKavchSysSts.ucDI2_ModuleID).arg(stStnKavchSysSts.ucDI2_SlotID).arg(stStnKavchSysSts.ucDI2_ModuleStatus)
                           .arg(stStnKavchSysSts.uiDI2_CH_Value_1_32).arg(stStnKavchSysSts.uiDI2_CH_Value_33_64)
                           .arg(stStnKavchSysSts.uiDI2_CH_OK_1_32).arg(stStnKavchSysSts.uiDI2_CH_OK_33_64)

                           .arg(stStnKavchSysSts.ucDI3_ModuleID).arg(stStnKavchSysSts.ucDI3_SlotID).arg(stStnKavchSysSts.ucDI3_ModuleStatus)
                           .arg(stStnKavchSysSts.uiDI3_CH_Value_1_32).arg(stStnKavchSysSts.uiDI3_CH_Value_33_64)
                           .arg(stStnKavchSysSts.uiDI3_CH_OK_1_32).arg(stStnKavchSysSts.uiDI3_CH_OK_33_64)

                           .arg(stStnKavchSysSts.ucDI4_ModuleID).arg(stStnKavchSysSts.ucDI4_SlotID).arg(stStnKavchSysSts.ucDI4_ModuleStatus)
                           .arg(stStnKavchSysSts.uiDI4_CH_Value_1_32).arg(stStnKavchSysSts.uiDI4_CH_Value_33_64)
                           .arg(stStnKavchSysSts.uiDI4_CH_OK_1_32).arg(stStnKavchSysSts.uiDI4_CH_OK_33_64)

                           .arg(stStnKavchSysSts.ucDI5_ModuleID).arg(stStnKavchSysSts.ucDI5_SlotID).arg(stStnKavchSysSts.ucDI5_ModuleStatus)
                           .arg(stStnKavchSysSts.uiDI5_CH_Value_1_32).arg(stStnKavchSysSts.uiDI5_CH_Value_33_64)
                           .arg(stStnKavchSysSts.uiDI5_CH_OK_1_32).arg(stStnKavchSysSts.uiDI5_CH_OK_33_64)

                           // RIU1–RIU6 (same pattern)
                           .arg(stStnKavchSysSts.ucRIU1_ID).arg(stStnKavchSysSts.ucRIU1_CPUStatus).arg(stStnKavchSysSts.ucRIU1_SystemHealth)
                           .arg(stStnKavchSysSts.ucRIU1_CommStatus).arg(stStnKavchSysSts.uiRIU1_DI_State_1_32).arg(stStnKavchSysSts.uiRIU1_DI_Error_1_32)

                           .arg(stStnKavchSysSts.ucRIU2_ID).arg(stStnKavchSysSts.ucRIU2_CPUStatus).arg(stStnKavchSysSts.ucRIU2_SystemHealth)
                           .arg(stStnKavchSysSts.ucRIU2_CommStatus).arg(stStnKavchSysSts.uiRIU2_DI_State_1_32).arg(stStnKavchSysSts.uiRIU2_DI_Error_1_32)

                           // (continue same for RIU3–RIU6…)

                           // Comm status
                           .arg(stStnKavchSysSts.ucSMOCIP_Comm_Status).arg(stStnKavchSysSts.ucLTE_Comm_Status)
                           .arg(stStnKavchSysSts.ucUHF_Comm_Status).arg(stStnKavchSysSts.ucAdjLeft_Comm_Status)
                           .arg(stStnKavchSysSts.ucAdjRight_Comm_Status).arg(stStnKavchSysSts.ucNMS_Comm_Status)
                           .arg(stStnKavchSysSts.ucTSRMS_Comm_Status).arg(stStnKavchSysSts.ucKMS_Comm_Status)
                           .arg(stStnKavchSysSts.ucGNSS_Comm_Status).arg(stStnKavchSysSts.ucEventLogger_Comm_Status)
                           .arg(stStnKavchSysSts.ucEI_Comm_Status).arg(stStnKavchSysSts.ucLocalVDU_Comm_Status)

                           .arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    if(bQryResult)
        qDebug() << "Station Kavach System Info inserted successfully";
    else
        qDebug() << "DB Insert Failed:" << pcQuery->lastError().text();

    delete pcQuery;
}

void nmsDBQuerys::SlotInsertDBOnBoardEventMsg(stOnboardKavachEventMsg stOnBoardEvntMsg)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QString strSOF =
        QString("0x%1")
            .arg(stOnBoardEvntMsg.usStartFrame, 4, 16, QChar('0'))
            .toUpper();

    QString strType =
        QString("0x%1")
            .arg(stOnBoardEvntMsg.ucMsgType, 2, 16, QChar('0'))
            .toUpper();

    QString strCRC =
        QString("0x%1")
            .arg(stOnBoardEvntMsg.uiCRC, 8, 16, QChar('0'))
            .toUpper();

    // Onboard Kavach ID (3 bytes)
    QString strKavachID =
        QString("%1 %2 %3")
            .arg(stOnBoardEvntMsg.ucOnboardKavachID[0], 2, 16, QChar('0'))
            .arg(stOnBoardEvntMsg.ucOnboardKavachID[1], 2, 16, QChar('0'))
            .arg(stOnBoardEvntMsg.ucOnboardKavachID[2], 2, 16, QChar('0'))
            .toUpper();

    // ----------------------------------------------------
    // Date & Time from message (NOT system time)
    // ----------------------------------------------------
    QString strDate =
        QString("20%1-%2-%3")
            .arg(stOnBoardEvntMsg.ucDate[2], 2, 10, QChar('0')) // Year
            .arg(stOnBoardEvntMsg.ucDate[1], 2, 10, QChar('0')) // Month
            .arg(stOnBoardEvntMsg.ucDate[0], 2, 10, QChar('0')); // Day

    QString strTime =
        QString("%1:%2:%3")
            .arg(stOnBoardEvntMsg.ucTime[0], 2, 10, QChar('0')) // Hour
            .arg(stOnBoardEvntMsg.ucTime[1], 2, 10, QChar('0')) // Minute
            .arg(stOnBoardEvntMsg.ucTime[2], 2, 10, QChar('0')); // Second

    QString strQuery = QString(
                           "INSERT INTO public.onboardkavacheventmsg("
                           "\"SOF\","
                           "\"MSG_TYPE\","
                           "\"MSG_LEN\","
                           "\"MSG_SEQ\","
                           "\"ONBOARD_KAVACH_ID\","
                           "\"NMS_SYSTEM_ID\","
                           "\"SYSTEM_VER\","
                           "\"DATE\","
                           "\"TIME\","
                           "\"EVENT_ID\","
                           "\"MODE_OF_OPERATION\","
                           "\"CURRENT_SPEED\","
                           "\"TARGET_DISTANCE\","
                           "\"EVENT_COUNT\","
                           "\"INCIDENT_ID\","
                           "\"EVENT_STATUS\","
                           "\"ACK_STATUS\","
                           "\"CRC\") "

                           "VALUES("
                           "'%1',"
                           "'%2',"
                           "%3,"
                           "%4,"
                           "'%5',"
                           "%6,"
                           "%7,"
                           "'%8',"
                           "'%9',"
                           "%10,"
                           "%11,"
                           "%12,"
                           "%13,"
                           "%14,"
                           "%15,"
                           "%16,"
                           "%17,"
                           "'%18');")

                           .arg(strSOF)
                           .arg(strType)
                           .arg(stOnBoardEvntMsg.usMsgLength)
                           .arg(stOnBoardEvntMsg.usMsgSeq)
                           .arg(strKavachID)
                           .arg(stOnBoardEvntMsg.usNMSID)
                           .arg(stOnBoardEvntMsg.ucVersion)
                           .arg(strDate)
                           .arg(strTime)
                           .arg(stOnBoardEvntMsg.usEventID)
                           .arg(stOnBoardEvntMsg.usMode)              // Mode of Operation
                           .arg(stOnBoardEvntMsg.usSpeed)             // Current Speed
                           .arg(stOnBoardEvntMsg.usTargetDistance)
                           .arg(stOnBoardEvntMsg.ucEventCount)
                           .arg(stOnBoardEvntMsg.usIncidentID)
                           .arg(stOnBoardEvntMsg.ucEventStatus)
                           .arg(stOnBoardEvntMsg.ucAckStatus)
                           .arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    if (bQryResult)
    {
        qDebug() << "Successfully inserted Onboard Kavach Event Message";
    }
    else
    {
        qDebug() << "Failed to insert Onboard Kavach Event Message";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
        qDebug() << "Query:" << strQuery;
    }

    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBOnBoardBrakeEventMsg(
    stOnboardKavachBrakeEventMsg stOnBoardBrakeEvntMsg)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QString strSOF =
        QString("0x%1")
            .arg(stOnBoardBrakeEvntMsg.usStartFrame,
                 4,16,QChar('0'))
            .toUpper();

    QString strType =
        QString("0x%1")
            .arg(stOnBoardBrakeEvntMsg.ucMsgType,
                 2,16,QChar('0'))
            .toUpper();

    QString strCRC =
        QString("0x%1")
            .arg(stOnBoardBrakeEvntMsg.uiCRC,
                 8,16,QChar('0'))
            .toUpper();

    QString strKavachID =
        QString("%1 %2 %3")
            .arg(stOnBoardBrakeEvntMsg.ucOnboardKavachID[0],2,16,QChar('0'))
            .arg(stOnBoardBrakeEvntMsg.ucOnboardKavachID[1],2,16,QChar('0'))
            .arg(stOnBoardBrakeEvntMsg.ucOnboardKavachID[2],2,16,QChar('0'))
            .toUpper();

    QString strDate =
        QString("20%1-%2-%3")
            .arg(stOnBoardBrakeEvntMsg.ucDate[2],2,10,QChar('0'))
            .arg(stOnBoardBrakeEvntMsg.ucDate[1],2,10,QChar('0'))
            .arg(stOnBoardBrakeEvntMsg.ucDate[0],2,10,QChar('0'));

    QString strTime =
        QString("%1:%2:%3")
            .arg(stOnBoardBrakeEvntMsg.ucTime[0],2,10,QChar('0'))
            .arg(stOnBoardBrakeEvntMsg.ucTime[1],2,10,QChar('0'))
            .arg(stOnBoardBrakeEvntMsg.ucTime[2],2,10,QChar('0'));

    QString strModeDesc =
        GetModeDescription(stOnBoardBrakeEvntMsg.usOperatingMode);

    QString strBrakeCause =
        GetIncidentDescription(stOnBoardBrakeEvntMsg.usBrakeCauseID);

    QString strEventStatus =
        GetEventStatusDescription(stOnBoardBrakeEvntMsg.ucEventStatus);

    QString strAckStatus =
        GetAckStatusDescription(stOnBoardBrakeEvntMsg.ucAckStatus);

    QString strBrakeType;

    switch(stOnBoardBrakeEvntMsg.ucBrakeType)
    {
    case 0:
        strBrakeType = "NONE";
        break;

    case 1:
        strBrakeType = "FSB";
        break;

    case 2:
        strBrakeType = "EB";
        break;

    default:
        strBrakeType = "UNKNOWN";
        break;
    }

    QString strDirection;

    switch(stOnBoardBrakeEvntMsg.ucDirection)
    {
    case 0:
        strDirection = "FORWARD";
        break;

    case 1:
        strDirection = "REVERSE";
        break;

    default:
        strDirection = "UNKNOWN";
        break;
    }

    QString strQuery = QString(
                           "INSERT INTO public.onboardkavachbrakeeventmsg("
                           "\"SOF\","
                           "\"MSG_TYPE\","
                           "\"MSG_LEN\","
                           "\"MSG_SEQ\","
                           "\"ONBOARD_KAVACH_ID\","
                           "\"NMS_SYSTEM_ID\","
                           "\"SYSTEM_VER\","
                           "\"DATE\","
                           "\"TIME\","
                           "\"EVENT_ID\","
                           "\"OPERATING_MODE\","
                           "\"CURRENT_SPEED\","
                           "\"PERMITTED_SPEED\","
                           "\"DIRECTION\","
                           "\"DISTANCE_TO_TARGET\","
                           "\"BRAKE_TYPE\","
                           "\"EVENT_STATUS\","
                           "\"BRAKE_CAUSE_ID\","
                           "\"ACK_STATUS\","
                           "\"CRC\") "

                           "VALUES("
                           "'%1',"
                           "'%2',"
                           "%3,"
                           "%4,"
                           "'%5',"
                           "%6,"
                           "%7,"
                           "'%8',"
                           "'%9',"
                           "%10,"
                           "'%11',"
                           "%12,"
                           "%13,"
                           "'%14',"
                           "%15,"
                           "'%16',"
                           "'%17',"
                           "'%18',"
                           "'%19',"
                           "'%20');")

                           .arg(strSOF)
                           .arg(strType)
                           .arg(stOnBoardBrakeEvntMsg.usMsgLength)
                           .arg(stOnBoardBrakeEvntMsg.usMsgSeq)
                           .arg(strKavachID)
                           .arg(stOnBoardBrakeEvntMsg.usNMSID)
                           .arg(stOnBoardBrakeEvntMsg.ucVersion)
                           .arg(strDate)
                           .arg(strTime)
                           .arg(stOnBoardBrakeEvntMsg.usEventID)
                           .arg(strModeDesc)
                           .arg(stOnBoardBrakeEvntMsg.usCurrentSpeed)
                           .arg(stOnBoardBrakeEvntMsg.usPermittedSpeed)
                           .arg(strDirection)
                           .arg(stOnBoardBrakeEvntMsg.usDistanceToTarget)
                           .arg(strBrakeType)
                           .arg(strEventStatus)
                           .arg(strBrakeCause)
                           .arg(strAckStatus)
                           .arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    if(bQryResult)
    {
        qDebug() << "Successfully inserted OnBoard Brake Event Message";
    }
    else
    {
        qDebug() << "Failed to insert OnBoard Brake Event Message";
        qDebug() << "SQL Error :" << pcQuery->lastError().text();
        qDebug() << "Query :" << strQuery;
    }

    delete pcQuery;
    pcQuery = nullptr;
}
QString nmsDBQuerys::GetModeDescription(quint16 usMode)
{
    QStringList modes;

    if (usMode & (1 << 0))  modes << "SB";
    if (usMode & (1 << 1))  modes << "FS";
    if (usMode & (1 << 2))  modes << "SR";
    if (usMode & (1 << 3))  modes << "OS";
    if (usMode & (1 << 4))  modes << "LS";
    if (usMode & (1 << 5))  modes << "SH";
    if (usMode & (1 << 6))  modes << "TR";
    if (usMode & (1 << 7))  modes << "PT";
    if (usMode & (1 << 8))  modes << "IS";
    if (usMode & (1 << 9))  modes << "RV";
    if (usMode & (1 << 10)) modes << "SF";
    if (usMode & (1 << 11)) modes << "NL";
    if (usMode & (1 << 12)) modes << "OV";

    if (modes.isEmpty())
        return "UNKNOWN";

    return modes.join("|");
}
QString nmsDBQuerys::GetEventStatusDescription(quint8 ucStatus)
{
    if (ucStatus & 0x01)
        return "ACTIVE";

    if (ucStatus & 0x02)
        return "CLEARED";

    return "UNKNOWN";
}

QString nmsDBQuerys::GetAckStatusDescription(quint8 ucAckStatus)
{
    QStringList lstAck;

    if (ucAckStatus & 0x01)
        lstAck << "ACK_REQUIRED";

    if (ucAckStatus & 0x02)
        lstAck << "ACK_RECEIVED";

    if (ucAckStatus & 0x04)
        lstAck << "TIMEOUT";

    if (lstAck.isEmpty())
        return "NONE";

    return lstAck.join("|");
}
QString nmsDBQuerys::GetIncidentDescription(quint16 usIncidentID)
{
    switch(usIncidentID)
    {
    case 1001: return "SPAD";
    case 1002: return "Head-on collision detected (Non-communication zone)";
    case 1003: return "Head-on collision detected (Communication zone)";
    case 1004: return "Rear-end collision detected (Non-communication zone)";
    case 1005: return "Rear-end collision detected (Communication zone)";
    case 1006: return "Train trip enforced by system";
    case 1007: return "Unusual stoppage detected in block section";
    case 1008: return "Unusual stoppage released";
    case 1009: return "Dead-end detected with brake application";
    case 1010: return "Standstill protection activated";
    case 1011: return "Rollback protection activated";
    case 1012: return "Shunting limit exceeded with brake application";
    case 1013: return "Station General SOS brake enforcement";
    case 1014: return "SPAD-triggered brake enforcement";

    case 1101: return "Manual SOS cancellation";
    case 1102: return "SOS due to odometry error";
    case 1103: return "SOS due to foreign RFID";
    case 1104: return "SOS due to shunt limit violation";
    case 1105: return "SOS Self loco (manual)";
    case 1106: return "SOS Self loco (unusual stoppage)";
    case 1107: return "SOS Self loco (train parted)";
    case 1108: return "SOS received from other loco (manual)";
    case 1109: return "SOS received from other loco (unusual stoppage)";
    case 1110: return "SOS received from other loco (train parted)";
    case 1111: return "SOS received from station (broadcast)";
    case 1112: return "SOS received from station (loco-specific)";

    case 1201: return "Override mode activated";
    case 1202: return "Reverse mode timeout approaching";
    case 1203: return "SR mode authorization received";
    case 1204: return "SR mode due to radio communication failure";
    case 1205: return "SR mode due to missing RFID tags";
    case 1206: return "SR mode due to GPS failure";

    case 1301: return "Overspeed warning";
    case 1302: return "Brake applied due to speed limit exceedance";
    case 1303: return "FSB application warning";
    case 1304: return "Emergency Brake application warning";

    case 1401: return "BIU isolated";
    case 1402: return "EB bypass detected";
    case 1403: return "System fault";
    case 1404: return "Standby mode";
    case 1405: return "Leading and non-leading inputs active";

    case 1501: return "Train configuration selected";
    case 1502: return "Train length computation in progress";
    case 1503: return "Train length computation successful";
    case 1504: return "Train length computation failed";

    case 1601: return "Waiting for traction command";
    case 1602: return "Fouling mark entry detected";
    case 1603: return "Acknowledgement required for SR mode";
    case 1614: return "KAVACH territory entry detected";

    default:
        return QString("Unknown Incident (%1)").arg(usIncidentID);
    }
}

QString nmsDBQuerys::GetBrakeTypeDescription(quint8 ucBrakeType)  //0x1E
{
    switch(ucBrakeType)
    {
    case 0:
        return "Normal Brake (NB)";

    case 1:
        return "Full Service Brake (FSB)";

    case 2:
        return "Emergency Brake (EB)";

    case 3:
        return "Light Engine Brake (LEB)";

    case 4:
        return "Unknown";

    default:
        return QString("Reserved (%1)").arg(ucBrakeType);
    }
}

QString nmsDBQuerys::GetDirectionDescription(quint8 ucDirection)  //0x1E
{
    switch(ucDirection)
    {
    case 1:
        return "Forward";

    case 2:
        return "Reverse";

    case 3:
        return "Standstill";

    case 4:
        return "Unknown";

    default:
        return QString("Reserved (%1)").arg(ucDirection);
    }
}

QString nmsDBQuerys::GetBrakeEventStatusDescription(quint8 ucStatus) //0x1E
{
    if(ucStatus & 0x01)
        return "Brake Applied";

    if(ucStatus & 0x02)
        return "Brake Released";

    return "Unknown";
}

QString nmsDBQuerys::GetBrakeAckStatusDescription(quint8 ucAckStatus)  //0x1E
{
    QStringList lst;

    if(ucAckStatus & 0x01)
        lst << "LP Ack Required";

    if(ucAckStatus & 0x02)
        lst << "LP Ack Received";

    if(ucAckStatus & 0x04)
        lst << "LP Ack Timeout";

    if(lst.isEmpty())
        return "None";

    return lst.join(" | ");
}


QString nmsDBQuerys::GetBrakeCauseDescription(quint16 usCauseID)   //0x1E
{
    switch(usCauseID)
    {
    case 1001: return "Standstill Protection in Standby Mode";
    case 1002: return "System Brake Test - NB/FSB/EB/LEB";
    case 1003: return "System Brake Test - LEB";
    case 1004: return "Manual Brake Test";
    case 1101: return "Absence of Traction Feedback";
    case 1102: return "Brake System Malfunction";

    case 1201: return "Overspeed - NB Application";
    case 1202: return "Overspeed - FSB Application";
    case 1203: return "Overspeed - EB Application";

    case 1301: return "Manual Onboard SOS Generation";
    case 1302: return "Automatic SOS";
    case 1303: return "SOS Received From Rear Train";
    case 1304: return "SOS Received From Stationary KAVACH";
    case 1305: return "SOS Received At Speed >30 km/h";

    case 1401: return "Reverse Movement in SR Mode";
    case 1402: return "Reverse Movement in FS Mode";
    case 1403: return "Reverse Movement in OS Mode";
    case 1404: return "Reverse Movement in LS Mode";
    case 1405: return "Unauthorized Direction Change";
    case 1406: return "Reverse Mode Distance/Timeout Violation";
    case 1407: return "Forward Movement Violation in Reverse Mode";

    case 1501: return "Rollback Detected (Reverse)";
    case 1502: return "Rollback Detected (Forward)";
    case 1503: return "Rollback Protection";
    case 1504: return "Rollback Protection Reverse";

    case 1601: return "Head-On Collision Detected";
    case 1602: return "Rear-End Collision Detected";

    case 1701: return "Radio Communication Failure";
    case 1702: return "Radio Failure Leading to Mode Degradation";
    case 1703: return "Radio Failure with MA Less Than Braking Distance";
    case 1704: return "Three Consecutive RFID Tags Missed";
    case 1705: return "RFID Missing During Exit";
    case 1706: return "Track Profile Unavailable";

    case 1801: return "Movement Authority Overrun";
    case 1802: return "Movement Authority Overrun (Missing Tag)";
    case 1803: return "OSMA Expiry";
    case 1804: return "Movement Detected in PT Mode";
    case 1805: return "No LP Acknowledgement";
    case 1806: return "Direction Unknown";
    case 1807: return "End Tag Detection";

    case 1901: return "Critical System Fault";
    case 1902: return "Slip/Slide Detection";
    case 1903: return "Odometer Error";
    case 1904: return "TIN Conflict Detected";

    case 2001: return "Reverse Mode Speed Limit Exceeded";
    case 2002: return "Shunt Mode Speed Limit Exceeded";
    case 2003: return "Calling-On Speed Limit Exceeded";

    case 2101: return "EM Cock Closed Detection";
    case 2102: return "Foreign RFID Tag Detected";

    default:
        return QString("Unknown Brake Cause (%1)")
            .arg(usCauseID);
    }
}
void nmsDBQuerys::SlotInsertDBOnboardBOKSHealthMsg(stOnboardKavachBOKSHealthMsg stOnBoardSysHealth)
{
    QSqlQuery query(m_pcDB->Get());

    QDateTime dt = QDateTime::currentDateTime();

    QString strDate =
        QString("20%1-%2-%3")
            .arg(stOnBoardSysHealth.ucDate[2], 2, 10, QChar('0'))
            .arg(stOnBoardSysHealth.ucDate[1], 2, 10, QChar('0'))
            .arg(stOnBoardSysHealth.ucDate[0], 2, 10, QChar('0'));

    QString strTime =
        QString("%1:%2:%3")
            .arg(stOnBoardSysHealth.ucTime[0], 2, 10, QChar('0'))
            .arg(stOnBoardSysHealth.ucTime[1], 2, 10, QChar('0'))
            .arg(stOnBoardSysHealth.ucTime[2], 2, 10, QChar('0'));

    QString strSOF  = QString("0x%1").arg(stOnBoardSysHealth.usStartFrame,0,16).toUpper();
    QString strType = QString("0x%1").arg(stOnBoardSysHealth.ucMsgType,0,16).toUpper();
    QString strCRC  = QString("0x%1").arg(stOnBoardSysHealth.uiCRC,0,16).toUpper();

    QString strKavachID = QString("%1 %2 %3")
                              .arg(stOnBoardSysHealth.ucOnboardKavachID[0],2,16,QChar('0'))
                              .arg(stOnBoardSysHealth.ucOnboardKavachID[1],2,16,QChar('0'))
                              .arg(stOnBoardSysHealth.ucOnboardKavachID[2],2,16,QChar('0')).toUpper();

    query.prepare(
        "INSERT INTO public.onboardkavachbokshealthmsg ("
        "\"SOF\",\"MSG_TYPE\",\"MSG_LEN\",\"MSG_SEQ\","
        "\"ONBOARD_KAVACH_ID\",\"NMS_SYSTEM_ID\",\"SYSTEM_VER\","
        "\"DATE\",\"TIME\","
        "\"BOKS_COM_STATUS\",\"BOKS_SYSTEM_HEALTH\",\"POWER_SUPPLY_DIAG\","
        "\"F35_CPU\",\"F35_HEALTH\",\"F35_COMM_ERR_CNT\",\"F35_COMM_WARN_CNT\",\"F35_COMM_STATUS\","
        "\"F35_DO_VAL\",\"F35_DO_ERR\",\"F35_CI_ERR\","
        "\"F35_AI1\",\"F35_AI2\",\"F35_AI3\",\"F35_AI4\",\"F35_AI5\",\"F35_AI6\",\"F35_AI7\",\"F35_AI8\","
        "\"F35_AI_ERR\","
        "\"F35_DI1_8\",\"F35_DI9_16\",\"F35_DI17_24\","
        "\"F35_DI_ERR1_8\",\"F35_DI_ERR9_16\",\"F35_DI_ERR17_24\","
        "\"F30A_CPU\",\"F30A_HEALTH\",\"F30A_COMM1\",\"F30A_COMM2\",\"F30A_COMM3\","
        "\"F30A_DO_VAL\",\"F30A_DO_ERR\","
        "\"F30A_DI1_8\",\"F30A_DI9_16\",\"F30A_DI17_20\","
        "\"F30A_DI_ERR1_8\",\"F30A_DI_ERR9_16\",\"F30A_DI_ERR17_20\","
        "\"F30B_CPU\",\"F30B_HEALTH\",\"F30B_COMM1\",\"F30B_COMM2\",\"F30B_COMM3\","
        "\"F30B_DO_VAL\",\"F30B_DO_ERR\","
        "\"F30B_DI1_8\",\"F30B_DI9_16\",\"F30B_DI17_20\","
        "\"F30B_DI_ERR1_8\",\"F30B_DI_ERR9_16\",\"F30B_DI_ERR17_20\","
        "\"LTE\",\"UHF\",\"NMS\",\"KMS\",\"GNSS\",\"EVENTLOGGER\",\"DMI1\",\"DMI2\",\"RFIDR1\",\"RFIDR2\",\"IRAB\",\"ETH\","
        "\"CRC\") "
        "VALUES (?,?,?,?,?,?,?,?,?,"
        "?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,"
        "?,?,?,?,?,?,?,?,?,?,?,?);"
        );

    int i = 0;

    // -------- Header --------
    query.bindValue(i++, strSOF);
    query.bindValue(i++, strType);
    query.bindValue(i++, stOnBoardSysHealth.usMsgLength);
    query.bindValue(i++, stOnBoardSysHealth.usMsgSeq);
    query.bindValue(i++, strKavachID);
    query.bindValue(i++, stOnBoardSysHealth.usNMSID);
    query.bindValue(i++, stOnBoardSysHealth.ucVersion);
    query.bindValue(i++, strDate);
    query.bindValue(i++, strTime);

    // -------- BOKS --------
    query.bindValue(i++, stOnBoardSysHealth.ucBOKS_COM_Status);
    query.bindValue(i++, stOnBoardSysHealth.ucBOKS_System_Health);
    query.bindValue(i++, stOnBoardSysHealth.ucPowerSupplyDiag);

    // -------- F35 --------
    query.bindValue(i++, stOnBoardSysHealth.ucF35_CPU_State);
    query.bindValue(i++, stOnBoardSysHealth.ucF35_System_Health);
    query.bindValue(i++, stOnBoardSysHealth.ucF35_Comm_Status_1);
    query.bindValue(i++, stOnBoardSysHealth.ucF35_Comm_Status_2);
    query.bindValue(i++, stOnBoardSysHealth.ucF35_Comm_Status_3);

    query.bindValue(i++, stOnBoardSysHealth.ucF35_DO_Value);
    query.bindValue(i++, stOnBoardSysHealth.ucF35_DO_Error);
    query.bindValue(i++, stOnBoardSysHealth.ucF35_CI_Error);

    query.bindValue(i++, stOnBoardSysHealth.usF35_AI_CH1);
    query.bindValue(i++, stOnBoardSysHealth.usF35_AI_CH2);
    query.bindValue(i++, stOnBoardSysHealth.usF35_AI_CH3);
    query.bindValue(i++, stOnBoardSysHealth.usF35_AI_CH4);
    query.bindValue(i++, stOnBoardSysHealth.usF35_AI_CH5);
    query.bindValue(i++, stOnBoardSysHealth.usF35_AI_CH6);
    query.bindValue(i++, stOnBoardSysHealth.usF35_AI_CH7);
    query.bindValue(i++, stOnBoardSysHealth.usF35_AI_CH8);

    query.bindValue(i++, stOnBoardSysHealth.ucF35_AI_Error);

    query.bindValue(i++, stOnBoardSysHealth.ucF35_DI_1_8);
    query.bindValue(i++, stOnBoardSysHealth.ucF35_DI_9_16);
    query.bindValue(i++, stOnBoardSysHealth.ucF35_DI_17_24);

    query.bindValue(i++, stOnBoardSysHealth.ucF35_DI_Err_1_8);
    query.bindValue(i++, stOnBoardSysHealth.ucF35_DI_Err_9_16);
    query.bindValue(i++, stOnBoardSysHealth.ucF35_DI_Err_17_24);

    // -------- F30A --------
    query.bindValue(i++, stOnBoardSysHealth.ucF30A_CPU_State);
    query.bindValue(i++, stOnBoardSysHealth.ucF30A_System_Health);
    query.bindValue(i++, stOnBoardSysHealth.ucF30A_Comm_Status_1);
    query.bindValue(i++, stOnBoardSysHealth.ucF30A_Comm_Status_2);
    query.bindValue(i++, stOnBoardSysHealth.ucF30A_Comm_Status_3);

    query.bindValue(i++, stOnBoardSysHealth.ucF30A_DO_Value);
    query.bindValue(i++, stOnBoardSysHealth.ucF30A_DO_Error);

    query.bindValue(i++, stOnBoardSysHealth.ucF30A_DI_1_8);
    query.bindValue(i++, stOnBoardSysHealth.ucF30A_DI_9_16);
    query.bindValue(i++, stOnBoardSysHealth.ucF30A_DI_17_20);

    query.bindValue(i++, stOnBoardSysHealth.ucF30A_DI_Err_1_8);
    query.bindValue(i++, stOnBoardSysHealth.ucF30A_DI_Err_9_16);
    query.bindValue(i++, stOnBoardSysHealth.ucF30A_DI_Err_17_20);

    // -------- F30B --------
    query.bindValue(i++, stOnBoardSysHealth.ucF30B_CPU_State);
    query.bindValue(i++, stOnBoardSysHealth.ucF30B_System_Health);
    query.bindValue(i++, stOnBoardSysHealth.ucF30B_Comm_Status_1);
    query.bindValue(i++, stOnBoardSysHealth.ucF30B_Comm_Status_2);
    query.bindValue(i++, stOnBoardSysHealth.ucF30B_Comm_Status_3);

    query.bindValue(i++, stOnBoardSysHealth.ucF30B_DO_Value);
    query.bindValue(i++, stOnBoardSysHealth.ucF30B_DO_Error);

    query.bindValue(i++, stOnBoardSysHealth.ucF30B_DI_1_8);
    query.bindValue(i++, stOnBoardSysHealth.ucF30B_DI_9_16);
    query.bindValue(i++, stOnBoardSysHealth.ucF30B_DI_17_20);

    query.bindValue(i++, stOnBoardSysHealth.ucF30B_DI_Err_1_8);
    query.bindValue(i++, stOnBoardSysHealth.ucF30B_DI_Err_9_16);
    query.bindValue(i++, stOnBoardSysHealth.ucF30B_DI_Err_17_20);

    // -------- Communication --------
    query.bindValue(i++, stOnBoardSysHealth.ucLTE_Comm);
    query.bindValue(i++, stOnBoardSysHealth.ucUHF_Comm);
    query.bindValue(i++, stOnBoardSysHealth.ucNMS_Comm);
    query.bindValue(i++, stOnBoardSysHealth.ucKMS_Comm);
    query.bindValue(i++, stOnBoardSysHealth.ucGNSS_Comm);
    query.bindValue(i++, stOnBoardSysHealth.ucEventLogger_Comm);
    query.bindValue(i++, stOnBoardSysHealth.ucDMI1_Comm);
    query.bindValue(i++, stOnBoardSysHealth.ucDMI2_Comm);
    query.bindValue(i++, stOnBoardSysHealth.ucRFIDR1_Comm);
    query.bindValue(i++, stOnBoardSysHealth.ucRFIDR2_Comm);
    query.bindValue(i++, stOnBoardSysHealth.ucIRAB_Comm);
    query.bindValue(i++, stOnBoardSysHealth.ucETH_Comm);

    // -------- CRC --------
    query.bindValue(i++, strCRC);

    if(query.exec())
        qDebug() << "BOKS Health Inserted Successfully";
    else
        qDebug() << "DB Insert Failed:" << query.lastError().text();
}

void nmsDBQuerys::SlotInsertDBFieldInputStatus(stPacketHeader stPktHdr, uint16_t usRelayCnt, QByteArray byArrRelayImage, uint32_t uiCRC)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stPktHdr.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stPktHdr.ucMsgType,0,16).toUpper();
    QString strCRC = QString("0x%1").arg(uiCRC,0,16).toUpper();
    QString relayHex = "\\x"+byArrRelayImage.toHex().toUpper();  // <-- important

    QString strQuery = QString("INSERT INTO public.fieldinputstatusmsg("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", \"STN_KAVACH_ID\", "
                               "\"NMS_SYSTEM_ID\", \"SYSTEM_VER\", \"DATE\", \"TIME\", "
                               "\"TOTAL_EVENT_RELAYS\", \"RELAY_STATUS_IMAGE\", \"CRC\")"
                               "VALUES ('%1','%2',%3,%4,%5,%6,%7,'%8','%9',%10,'%11','%12');")
                           .arg(strStrtFrm).arg(strmsgtyp).arg(stPktHdr.usMsgLength)
                           .arg(stPktHdr.usMsgSeq).arg(stPktHdr.usStatKavachID).arg(stPktHdr.usNMSID)
                           .arg(stPktHdr.ucVersion).arg(strdate).arg(strtime).arg(usRelayCnt)
                           .arg(relayHex).arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the Field Input status packet into database";
    }
    else
    {
        qDebug () << "Failed to insert the Field Input status packet into database";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInsertDBFieldInputEventData(stFieldEventData stFldEvntData)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QDateTime datetime = QDateTime::currentDateTime();

    QString strdate = datetime.date().toString("yyyy-MM-dd");
    QString strtime = datetime.time().toString("hh:mm:ss");

    QString strStrtFrm = QString("0x%1").arg(stFldEvntData.usStartFrame,0,16).toUpper();
    QString strmsgtyp = QString("0x%1").arg(stFldEvntData.ucMsgType,0,16).toUpper();
    QString strCRC = QString("0x%1").arg(stFldEvntData.uiCRC,0,16).toUpper();
    QString relayAddr = QString("0x%1").arg(stFldEvntData.usRelayAddr,0,16).toUpper();

    QString strQuery = QString("INSERT INTO public.fieldinputeventdata("
                               "\"SOF\", \"MSG_TYPE\", \"MSG_LEN\", \"MSG_SEQ\", "
                               "\"STN_KAVACH_ID\", \"NMS_SYSTEM_ID\", \"SYSTEM_VER\", \"DATE\", "
                               "\"TIME\", \"TOTAL_EVENT_COUNT\", \"RELAY_ADDRESS\", \"RELAY_STATUS\", \"CRC\")"
                               "VALUES ('%1','%2',%3,%4,%5,%6,%7,'%8','%9',%10,'%11',%12,'%13');")
                           .arg(strStrtFrm).arg(strmsgtyp).arg(stFldEvntData.usMsgLength)
                           .arg(stFldEvntData.usMsgSeq).arg(stFldEvntData.usStatKavachID).arg(stFldEvntData.usNMSID)
                           .arg(stFldEvntData.ucVersion).arg(strdate).arg(strtime).arg(stFldEvntData.ucEvntCnt)
                           .arg(relayAddr).arg(stFldEvntData.ucRelayStatus).arg(strCRC);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the Field Input Event packet into database";
    }
    else
    {
        qDebug () << "Failed to insert the Field Input Event packet into database";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::SlotInserttoDBFieldStatus(QString strFieldId, uint8_t ucStatus)
{
    QSqlQuery query(m_pcDB->Get());

    query.prepare(
        "UPDATE public.gullagudabitchart "
        "SET \"STATUS\" = :status "
        "WHERE \"BIT\" = :bit"
        );

    query.bindValue(":status", static_cast<int>(ucStatus)); // 0 / 1
    query.bindValue(":bit", strFieldId);                    // QString

    if (!query.exec())
    {
        qDebug() << "DB UPDATE failed:" << query.lastError().text();
    }
    else
    {
        qDebug() << "DB UPDATE success for BIT =" << strFieldId
                 << "STATUS =" << ucStatus;
    }
}


void nmsDBQuerys::SlotInsertRemoteUser(QString strName, QString strUName, QString strPwd, bool bStatus)
{
    if (!m_pcDB || !m_pcDB->IsDBOpen())
    {
        qWarning() << "Database is not open.";
        return;
    }

    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());
    QString strSql = NULL;
    bool bRCode = false;

    qDebug()<<"Database is connected" << strUName;

    QString strCheckSql = QString("select count(*) from remote_users WHERE \"USER_ID\" = '%1';").arg(strUName);

    if (!pcQuery->exec(strCheckSql))
    {
        qWarning() << "Error checking number:" << pcQuery->lastError().text();
        delete pcQuery;
        return;
    }
    if (pcQuery->next())
    {
        int count = pcQuery->value(0).toInt();
        if (count > 0)
        {
            qDebug() << "Insert aborted: UserName" << strUName << "already exists in the database.";
            delete pcQuery;
            return;
        }
    }
    strSql= QString("INSERT INTO public.remote_users("
                    "\"NAME\", \"USER_ID\", \"PASSWORD\", \"ACTIVE_STATUS\")"
                    "VALUES ('%1','%2','%3',%4);").arg(strName).arg(strUName).arg(strPwd).arg((bStatus) ? 1:0);

    bRCode = pcQuery->exec(strSql);

    if (bRCode == false)
    {
        qWarning() << "Insert failed:" << pcQuery->lastError().text();
    }
    else
    {
        qDebug()<< "Success," "Remote User added successfully.";
    }
    qDebug() << "Query" <<strSql;
    delete pcQuery; pcQuery = NULL;
}

void nmsDBQuerys::SlotFetchRemoteUsers()
{
    uint16_t usRowCount = 0;

    uint8_t ucColCount = 0;

    QString strSql = NULL;
    strSql = QString("SELECT * FROM remote_users ORDER BY \"NAME\" ASC");

    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    bool bQryResult = pcQuery->exec(strSql);

    // Get and print field names
    QStringList strlstFldNames,
        strlstrowValues;

    if ((bQryResult == true))
    {
        QSqlRecord record = pcQuery->record();
        ucColCount = record.count();

        for (uint16_t ucIndx = 0U; ucIndx < ucColCount; ucIndx++)
        {
            strlstFldNames.append(pcQuery->record().fieldName(ucIndx));
        }

        while (pcQuery->next() == true)
        {
            for (uint16_t ucIndx = 0U; ucIndx < ucColCount; ucIndx++)
            {
                strlstrowValues.append(pcQuery->value(ucIndx).toString());
            }
            usRowCount++;
        }
    }
    emit SigDBRemoteUserResults(ucColCount,usRowCount,strlstFldNames,strlstrowValues);
}

void nmsDBQuerys::SlotDeleteRemoteUser(QString strUserID)
{
    QString strDelQuery = NULL;
    strDelQuery = QString("delete from remote_users where \"USER_ID\" = '%1'").arg(strUserID);

    qDebug ()<< "Query" << strDelQuery;

    /* get the Database Status */
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    bool bQryResult = pcQuery->exec(strDelQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        SlotFetchRemoteUsers();
    }
    else
    {
        qDebug () << "Failed to delete Remote user:";
    }
    delete pcQuery; pcQuery = NULL;
}

void nmsDBQuerys::SlotUpdateRemoteUser(QList<QList<QString> > lstvalues)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    for (const QList<QString> &row : lstvalues)
    {
        if (row.size() < 3) {
            qDebug() << "Skipping invalid row:" << row;
            continue;
        }

        QString strStatus = row[0].trimmed();
        QString strName = row[1].trimmed();
        QString strUserName = row[2].trimmed();
        QString strPwd = row[3].trimmed();

        uint8_t ucStatus = (strStatus == "Active") ? 1 : 0;  // convert to int

        QString strQuery =
            QString("INSERT INTO public.remote_users (\"NAME\", \"USER_ID\", \"PASSWORD\",\"ACTIVE_STATUS\") "
                    "VALUES (?, ?, ?,?) "
                    "ON CONFLICT (\"USER_ID\") DO UPDATE SET "
                    "\"NAME\" = EXCLUDED.\"NAME\", "
                    "\"PASSWORD\" = EXCLUDED.\"PASSWORD\", "
                    "\"ACTIVE_STATUS\" = EXCLUDED.\"ACTIVE_STATUS\";");

        pcQuery->prepare(strQuery);
        pcQuery->addBindValue(strName);
        pcQuery->addBindValue(strUserName);
        pcQuery->addBindValue(strPwd);
        pcQuery->addBindValue(ucStatus);

        if (!pcQuery->exec())
        {
            qDebug() << "Failed to insert/update:" << pcQuery->lastError().text();
        }
    }
    qDebug() << "All rows processed.";
    delete pcQuery; pcQuery = NULL;
}

quint64 nmsDBQuerys::getLastPktId()
{
    return m_ulPktId;
}

void nmsDBQuerys::InsertHBLFaultMsg(QString strMsgType, QString strTimestamp, QString strFaultCode,
                                    QString strFirmNam, uint32_t uiID, QString strFaultMsg)
{
    qDebug() << "HBL" << strFaultCode <<strFaultMsg;
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QString strFirmID = strFirmNam + ":" + QString::number(uiID);

    QString strQuery = QString ("INSERT INTO public.hbl_faultcodes("
                                "\"MSG_TYPE\", \"DATE_TIME_STAMP\", \"FAULT_CODE\", \"FIRM_NAME\", \"FAULT_MSG\")"
                                "VALUES ('%1', '%2', '%3', '%4','%5');")
                                .arg(strMsgType)
                                .arg(strTimestamp)
                                .arg(strFaultCode)
                                .arg(strFirmID)
                                .arg(strFaultMsg);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the HBL_fault into database";
    }
    else
    {
        qDebug () << "Failed to insert the HBL_fault into database";
        qDebug() << "SQL Error:" << pcQuery->lastError().text();
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::InsertMEDHAFaultMsg(QString strMsgType, QString strTimestamp, uint16_t usFaultCode,
                                      QString strFirmNam,uint32_t uiID,QString strFaultMsg)
{

    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());
    QString strFirmID = strFirmNam + ":" + QString::number(uiID);

    QString strQuery = QString("INSERT INTO public.medha_faultcodes("
                               "\"MSG_TYPE\", \"DATE_TIME_STAMP\", \"FAULT_CODE\", \"FIRM_NAME\", \"FAULT_MSG\")"
                               "VALUES ('%1', '%2', %3, '%4','%5');")
                           .arg(strMsgType)
                           .arg(strTimestamp)
                           .arg(usFaultCode)
                           .arg(strFirmID)
                           .arg(strFaultMsg);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the MEDHA_fault into database";
    }
    else
    {
        qDebug () << "Failed to insert the MEDHA_fault into database";
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::InsertSMSHBLFaultMsg(QString strMsgType, QString strTimestamp,
                                       QString strFaultCode, QString strFirmnamid, QString strFaultMsg)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QString strQuery = QString ("INSERT INTO public.sms_hbl_faultinfo("
                                "\"MSG_TYPE\", \"DATE_TIME_STAMP\", \"FAULT_CODE\", \"FIRM_NAME\", \"FAULT_MSG\")"
                                   "VALUES ('%1', '%2', '%3', '%4','%5');")
                           .arg(strMsgType)
                           .arg(strTimestamp)
                           .arg(strFaultCode)
                           .arg(strFirmnamid)
                           .arg(strFaultMsg);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the sms_HBL_fault into database";
    }
    else
    {
        qDebug () << "Failed to insert the sms_HBL_fault into database";
    }
    delete pcQuery;
    pcQuery = NULL;
}

void nmsDBQuerys::InsertSMSMEDHAFaultMsg(QString strMsgType, QString strTimestamp,
                                         uint16_t usFaultCode, QString strFirmnamid, QString strFaultMsg)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());

    QString strQuery = QString("INSERT INTO public.sms_medha_faultinfo("
                               "\"MSG_TYPE\", \"DATE_TIME_STAMP\", \"FAULT_CODE\", \"FIRM_NAME\", \"FAULT_MSG\")"
                               "VALUES ('%1', '%2', %3, '%4','%5');")
                           .arg(strMsgType)
                           .arg(strTimestamp)
                           .arg(usFaultCode)
                           .arg(strFirmnamid)
                           .arg(strFaultMsg);

    bool bQryResult = pcQuery->exec(strQuery);

    /* Execute the Query */
    if(bQryResult == true)
    {
        qDebug () << "successfully insert the sms_MEDHA_fault into database";
    }
    else
    {
        qDebug () << "Failed to insert the sms_MEDHA_fault into database";
    }
    delete pcQuery;
    pcQuery = NULL;
}

QString nmsDBQuerys::GetDestLocoSoS(SoSEmergencyCondition enmSoS)
{
    QString strDestLocoSoS = NULL;
    switch(enmSoS)
    {
        case NoSoSEmergency:strDestLocoSoS = "No SoS";break;
        case ForeignRFID:strDestLocoSoS = "Foreign RFID";break;
        case Reserved1:strDestLocoSoS = "Reserved.";break;
        case OnboardOdoError:strDestLocoSoS = "Onboard Odo error";break;
        case SPADDetected:strDestLocoSoS = "Detection of SPAD";break;
        case RearEndCollision:strDestLocoSoS = "Rear-end collision";break;
        case HeadOnCollision:strDestLocoSoS = "Head-On collision";break;
        case ViolationOfShuntingLimits:strDestLocoSoS = "Violation of Shunting limits in shunt mode";break;
        case StationGeneralSoS:strDestLocoSoS = "Station General SoS";break;
        default: strDestLocoSoS = "UnKnown";break;
    }
    return strDestLocoSoS;
}

QString nmsDBQuerys::GetTrainSectionType(SectionType enmTrnSecTyp)
{
    QString strTrnSecTyp = NULL;
    switch(enmTrnSecTyp)
    {
       case StationSection:strTrnSecTyp = "Station Section";break;
       case AbsoluteBlock:strTrnSecTyp = "Absolute Block";break;
       case Autoblock:strTrnSecTyp = "Autoblock.";break;
       case Reserved:strTrnSecTyp = "Reserved";break;
       default: strTrnSecTyp = "UnKnown";break;
    }
    return strTrnSecTyp;
}

QString nmsDBQuerys::GetSignalAspects(SIG_ASPECTS enmSigAsp)
{
    QString strSigAsp = NULL;

    switch(enmSigAsp)
    {
        case UNIDENTIFIED:strSigAsp = "Unidentified";break;
        case RED:strSigAsp = "Red";break;
        case DOUBLE_YELLOW:strSigAsp = "Double yellow";break;
        case GREEN:strSigAsp = "Green";break;
        case RED_WITH_CALLING_OFF:strSigAsp = "Red with Calling off";break;
        default: strSigAsp = "UnKnown";break;
    }
    return strSigAsp;
}

QString nmsDBQuerys::GetAuthorityType(AUTH_TYPE enmAuthType)
{
    QString strAuthTyp = NULL;

    switch(enmAuthType)
    {
        case None:strAuthTyp = "None";break;
        case OS_Authority:strAuthTyp = "OS Authority";break;
        case FS_Authority:strAuthTyp = "FS Authority";break;
        case SR_Authority:strAuthTyp = "SR Authority";break;
        default: strAuthTyp = "UnKnown";break;
    }
    return strAuthTyp;
}

QString nmsDBQuerys::GetSubPktType(enmSubPktType enmSubPktTyp)
{
    QString  strSubPktTyp = NULL;
    switch(enmSubPktTyp)
    {
        case enmMovementAuthoritySubPkt:
        {
            strSubPktTyp = "Movement Authority";
        }break;
        case enmStaticSpeedProfileSubPkt:
        {
            strSubPktTyp = "Static Speed Profile";
        }break;
        case enmGradientProfileSubPkt:
        {
            strSubPktTyp = "Gradient Profile";
        }break;
        case enmLCGateSubPkt:
        {
            strSubPktTyp = "LC Gate";
        }break;
        case enmTurnoutSpeedProfileSubPkt:
        {
            strSubPktTyp = "Turn Out Speed";
        }break;
        case enmTagLinkingInfSubPkt:
        {
            strSubPktTyp = "Tag Linking Info";
        }break;
        case enmTrackConditionDataSubPkt:
        {
            strSubPktTyp = "Track Condition Data";
        }break;
        case enmTempSpeedRestrctionProfileSubPkt:
        {
            strSubPktTyp = "TSR";
        }break;
        default:
        {
            strSubPktTyp = "UnKnown";
        }break;
    }
    return strSubPktTyp;
}

QString nmsDBQuerys::GetStationFirmName(uint32_t uiID)
{
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());
    QString stationQuery = QString("SELECT \"FIRM_NAME\" FROM stations_info WHERE \"STATION_ID\" = '%1'").arg(uiID);
        if (pcQuery->exec(stationQuery) && pcQuery->next())
        {
            m_strFirmName = pcQuery->value(0).toString();
            qDebug() << "Firm Name for" << uiID << ":" << m_strFirmName;
        }
        else
        {
            m_strFirmName = "UnKnown";
            qDebug() << "No firm name found for station ID:" << uiID << m_strFirmName;
        }
        return m_strFirmName;

        delete pcQuery;
        pcQuery = NULL;
}

QString nmsDBQuerys::GetLocoFirmName(uint32_t uiID)
{
    m_strFirmName = NULL;
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());
    QString stationQuery = QString("SELECT \"FIRM_NAME\" FROM loco_info WHERE \"LOCO_ID\" = '%1'").arg(uiID);

    if (pcQuery->exec(stationQuery) && pcQuery->next())
    {
        m_strFirmName = pcQuery->value(0).toString();
        qDebug() << "Firm Name for" << uiID << ":" << m_strFirmName;
    }
    else
    {
        m_strFirmName = "UnKnown";
        qDebug() << "No firm name found for station ID:" << uiID << m_strFirmName;
    }
    return m_strFirmName;

    delete pcQuery;
    pcQuery = NULL;
}

QString nmsDBQuerys::GetMobileNumberForName(QString strFirmName)
{
    QString strMobNo;
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());
    QString stationQuery = QString("SELECT \"MOBILE_NUMBER\" FROM sms_numbers WHERE \"NAME\" = '%1'").arg(strFirmName);
    if (pcQuery->exec(stationQuery) && pcQuery->next())
    {
        strMobNo = pcQuery->value(0).toString();
        qDebug() << "Firm Name for" << strFirmName << ":" << strMobNo;
    }
    else
    {
        strMobNo = "UnKnown";
        qDebug() << "No firm name found for station ID:" << strFirmName << strMobNo;
    }
    return strMobNo;

    delete pcQuery;
    pcQuery = NULL;
}

QString nmsDBQuerys::GetFaultDescription(uint16_t usFaultCode)
{
    QString strFaultMsg = NULL,strQuery;
    bool bQryResult = false;
    QSqlQuery *pcQuery = new QSqlQuery(m_pcDB->Get());
    if(m_strFirmName == "SANA")   //HBL replace to SANA
    {
       strQuery =  QString("SELECT \"FAULT_MSG\" FROM hbl_faultcodes WHERE \"FAULT_CODE\" = '%1'").arg(usFaultCode);
     // bool bQryResult = pcQuery->exec(strQuery);

        if (pcQuery->exec(strQuery))
        {
          if(pcQuery->next())
          {
            strFaultMsg = pcQuery->value(0).toString();
            qDebug() << "Fault message for" << usFaultCode << ":" << strFaultMsg;
          }
        }

    }
    else
    {
        strQuery =  QString("SELECT FAULT_MSG FROM medha_faultcodes WHERE FAULT_CODE = '%1'").arg(usFaultCode);
        if (pcQuery->exec(strQuery) && pcQuery->next())
        {
            strFaultMsg = pcQuery->value(0).toString();
            qDebug() << "Fault message for" << usFaultCode << ":" << strFaultMsg;
        }
    }
    return strFaultMsg;

    pcQuery = NULL;

}

bool nmsDBQuerys::Exec (QSqlQuery *&pcQry, const QString strSqlStmt)
{
    bool bRCode = m_pcDB->IsDBOpen ();

    if (bRCode == false)
    {
      qDebug () <<("Database Not Connected");
    }
    else
    {
        pcQry = new QSqlQuery (m_pcDB->Get ());

        bRCode = pcQry->exec (strSqlStmt);

        if (bRCode == false)
        {
            const QString strEString = pcQry->lastError().text();
            Q_UNUSED(strEString);
        }
    }
    return bRCode;
}

QString nmsDBQuerys::GetLocoMode(uint8_t ucLocoMode)
{
    QString strLocoModeType = NULL;
    switch(ucLocoMode)
    {
    case 0:strLocoModeType = "None";break;
    case 1:strLocoModeType = "Stand By";break;
    case 2:strLocoModeType = "Staff Responsible Mode";break;
    case 3:strLocoModeType = "Limited Supervision";break;
    case 4:strLocoModeType = "Full Supervision";break;
    case 5:strLocoModeType = "Override";break;
    case 6:strLocoModeType = "On Sight";break;
    case 7:strLocoModeType = "Trip";break;
    case 8:strLocoModeType = "Post Trip";break;
    case 9:strLocoModeType = "Reverse";break;
    case 10:strLocoModeType = "Shunt";break;
    case 11:strLocoModeType = "Non Leading";break;
    case 12:strLocoModeType = "System Failure";break;
    case 13:strLocoModeType = "Isolation";break;
    default: strLocoModeType = "UnKnown";break;
    }
    return strLocoModeType;
}

QString nmsDBQuerys::GetEmergencyStatus(uint8_t ucEmergSts)
{
    QString strEmrgSts = NULL;
    switch(ucEmergSts)
    {
    case 0:strEmrgSts = "No Emergency";break;
    case 1:strEmrgSts = "Side Collision";break;
    case 2:strEmrgSts = "SoS";break;
    case 3:strEmrgSts = "Roll Back Detected";break;
    case 4:strEmrgSts = "Head On Collision";break;
    case 5:strEmrgSts = "Rear End Collision";break;
    case 6:strEmrgSts = "Parting SoS";break;
    case 7:strEmrgSts = "Spare";break;
    default: strEmrgSts = "UnKnown";break;
    }
    return strEmrgSts;
}

QString nmsDBQuerys::GetFrameTime(uint32_t uiFrmNo)
{
    // Keep it within a day (0–86399 seconds)
    uiFrmNo = uiFrmNo % 86400;

    int hours   = uiFrmNo / 3600;
    int minutes = (uiFrmNo % 3600) / 60;
    int seconds = uiFrmNo % 60;

    QTime frameTime(hours, minutes, seconds);
    return frameTime.toString("HH:mm:ss");
}
void nmsDBQuerys::EnsureGradientColumns(int count)
{
    QString strFunc = QString("SELECT repeat_stnreggradientprofilesubpkt_columns(%1);").arg(count);
    QSqlQuery query(m_pcDB->Get());
    if (!query.exec(strFunc))
        qDebug() << "Failed to extend table columns:" << query.lastError().text();
    else
        qDebug() << "Ensured" << count << "gradient column groups exist.";
}
