
/******************************************************************************
 *                                                                            *
 * Application Name : ECDSCommon                                              *
 *                                                                            *
 * File name        : ECDSQtInc.h                                             *
 *                                                                            *
 * Class name       : N/A                                                     *
 *                                                                            *
 * Author           : SaNa Software                                           *
 *                                                                            *
 * Description      : The file is base header file, which inludes all the Qt  *
 *                    related classes being used in the project.              *
 *                                                                            *
 * Date             : 20 Jun, 2023                                            *
 *                                                                            *
 * Version          : 0.1                                                     *
 *                                                                            *
 * Reference        : None                                                    *
 *                                                                            *
 * Remarks          : Taken from the older project.                           *
 *                                                                            *
 ******************************************************************************/


#ifndef _ECDS_QT_INC_H_
#define _ECDS_QT_INC_H_


#include <stdio.h>
#include <stdlib.h>

#include <QCoreApplication>
#include <QtCore>
#include <QDate>
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QMutex>
#include <QObject>
#include <QProcess>
#include <QRegularExpression>
#include <QString>
#include <QStringList>
#include <QStorageInfo>
#include <QTimer>
#include <QThread>
#include <QTime>


  /* network socket related */
#include <QtNetwork>
#include <QUdpSocket>

  /* database related */
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include "unistd.h"

  /* use the datavisualization namespace  */
using namespace std;

#endif /* _ECDS_QT_INC_H_ */
