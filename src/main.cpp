#include <QCoreApplication>
#include "nmsUDPServer.h"
#include "nmsMainWindow.h"
#include "nmsQtInc.h"
#include "nmsDB.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString strCFGFilePath =QDir(QCoreApplication::applicationDirPath() + "/Config.cfg/").absolutePath();

    QSettings *ocCfgSettings = new QSettings(strCFGFilePath,QSettings::IniFormat);

    ocCfgSettings->beginGroup("Database");

    QString strDBip        = ocCfgSettings->value("DB_IP").toString();
    QString strDBPort      = ocCfgSettings->value("DB_Port").toString();
    QString strDBName      = ocCfgSettings->value("DB_Name").toString();
    QString strDBUsrName   = ocCfgSettings->value("DB_Username").toString();
    QString strDBPassword  = ocCfgSettings->value("DB_Password").toString();

    ocCfgSettings->endGroup();

    qDebug() << strDBip << strDBPort << strDBName << strDBUsrName;

    nmsMainWindow *pcMWnd = new nmsMainWindow(strCFGFilePath);

    return a.exec();
}
