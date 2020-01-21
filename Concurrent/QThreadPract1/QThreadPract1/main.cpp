#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QDateTime>
#include <QSharedPointer>
#include "test.h"

static QSharedPointer<QThread> sptr;
void gTimeOut()
{
    if(!sptr.isNull())
    {
        qInfo()<<"time out -stopping other thread from" <<QThread::currentThread();
        sptr.data()->quit();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo()<< "current thread :" << QThread::currentThread();
    test t;
    qInfo()<<"Timer thread before move :" << t.thread();
    QThread thread;
    t.moveToThread(&thread);
    sptr.reset(&thread);
    qInfo()<<"Timer thread after move :" << t.thread();
    t.Start();
    thread.start();

    QTimer::singleShot(5000,&gTimeOut);
    return a.exec();
}
