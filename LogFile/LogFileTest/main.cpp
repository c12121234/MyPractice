#include <QCoreApplication>
#include "../LogFileLib/LogFileLib_global.h"
#include "../LogFileLib/logfilelib.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInstallMessageHandler(ErrorMessageHandler);
    qDebug()<<"test";
    qDebug()<<"test2";
    return a.exec();
}
