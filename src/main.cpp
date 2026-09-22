#include <QCoreApplication>
#include <QTimer>

#include "nmsUDPServer.h"
#include "nmsMainWindow.h"
#include "nmsQtInc.h"
#include "nmsDB.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString strCFGFilePath =
        QDir(QCoreApplication::applicationDirPath() +
             "/Config.cfg/")
            .absolutePath();

    qDebug() << "======================================";
    qDebug() << "[MAIN] Creating nmsMainWindow";
    qDebug() << "======================================";

    nmsMainWindow *pcMWnd =
        new nmsMainWindow(strCFGFilePath);

    qDebug() << "[MAIN] nmsMainWindow constructor RETURNED:"
             << pcMWnd;

    // ---------------------------------------------------------
    // Start KMS after Qt event loop starts
    // ---------------------------------------------------------

    QTimer::singleShot(
        100,
        pcMWnd,
        [pcMWnd]()
        {
            qDebug() << "[MAIN] Starting KMS";

            pcMWnd->StartKMS();
        });

    // ---------------------------------------------------------
    // Start Status LEDs
    // ---------------------------------------------------------

    QTimer::singleShot(
        200,
        pcMWnd,
        [pcMWnd]()
        {
            qDebug()
            << "[MAIN] Starting EventLoggerStatusLED";

            pcMWnd->StartStatusLED();
        });

    qDebug() << "======================================";
    qDebug() << "[MAIN] EventLogger initialization completed";
    qDebug() << "[MAIN] ABOUT TO ENTER Qt EVENT LOOP";
    qDebug() << "======================================";

    return a.exec();
}