#include "logfilelib.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>

void ErrorMessageHandler(QtMsgType type, const QMessageLogContext &ctx, const QString &msg)
{
    QString txt;
    switch (type)
    {
    case QtDebugMsg:
        txt = QString("Debug: %1").arg(msg);
        break;
    case QtWarningMsg:
        txt = QString("Warning: %1").arg(msg);
        break;
    case QtCriticalMsg:
        txt = QString("Critical: %1").arg(msg);
        break;
    case QtFatalMsg:
        txt = QString("Fatal: %1").arg(msg);
        break;
    }
    QFile outFile("log");
    if(outFile.exists())
    {
        outFile.open(QIODevice::WriteOnly | QIODevice::Append);
        QTextStream ts(&outFile);
        ts << txt << endl;
    }

}
