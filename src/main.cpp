#include <QCoreApplication>
#include "nmsUDPServer.h"
#include "nmsMainWindow.h"
#include "nmsQtInc.h"
#include "nmsDB.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString strCFGFilePath =QDir(QCoreApplication::applicationDirPath() + "/Config.cfg/").absolutePath();


    nmsMainWindow *pcMWnd = new nmsMainWindow(strCFGFilePath);

    return a.exec();
}
