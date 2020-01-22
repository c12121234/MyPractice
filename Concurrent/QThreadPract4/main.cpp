#include <QCoreApplication>
#include <QThreadPool>
#include <QThread>
#include <QMutex>
#include <QDebug>
#include "worker.h"
#include "counter.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThreadPool* pool = QThreadPool::globalInstance();
    QMutex mutex(QMutex::Recursive);
    Counter c;
    qInfo()<<"Count :" << c.GetCount();
    for(int i =0; i<pool->maxThreadCount();++i)
    {
        Worker* w = new Worker(nullptr,&mutex,&c);
        w->setAutoDelete(true);
        pool->start(w);
    }
    pool->waitForDone();
    qInfo()<<"Done. Count is :"<<c.GetCount();
    return a.exec();
}
