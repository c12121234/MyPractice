#include <QCoreApplication>
#include <QThreadPool>
#include <QRunnable>
#include <QSemaphore>
#include <QDebug>
#include "worker.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThreadPool* pool = QThreadPool::globalInstance();
    qInfo()<<"max pool size:"<< pool->maxThreadCount();
    QStringList list;
    for(int i = 0; i<100;i++)
        list.append(QString::number(i));
    QSemaphore sema(100);
    for(int i = 0; i<list.size();++i)
    {
        Worker* TempWorker = new Worker(nullptr,&list,&sema,i);
        TempWorker->setAutoDelete(true);
        pool->start(TempWorker);
    }
    pool->waitForDone();
    for(auto strElement :list)
        qInfo()<< strElement;
    return a.exec();
}
