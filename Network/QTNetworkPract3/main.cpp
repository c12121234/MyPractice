#include <QCoreApplication>
#include <QFuture>
#include <QtConcurrent>
#include "commandline.h"
#include "chat.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CommandLine cli(&a,stdin);
    QFuture<void> future = QtConcurrent::run(&cli,&CommandLine::Monitor);
    Chat c;
    QObject::connect(&cli,&CommandLine::Command,&c,&Chat::HandleCommand,Qt::QueuedConnection);
    qInfo()<<"enter your name begin:";
    return a.exec();
}
