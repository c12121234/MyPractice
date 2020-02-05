#include <QCoreApplication>
#include <QThread>
#include <QtConcurrent>
#include <QDebug>
#include "printprogress.h"
void MultiTen(int& nVal)
{
    qInfo()<<"MultiTen function: call"<<nVal<<":"<<QThread::currentThread();

    nVal *= 10;
}



/*
int MultiTen(const int& nVal)
{
    qInfo()<<"MultiTen function: call"<<nVal<<":"<<QThread::currentThread();

    int nNum = nVal;
    return nNum*10;
}
*/
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int> data;
    PrintProgress p;
    for(int i = 1; i<=50;++i)
    {
        data.append(i);
    }
    QFutureWatcher<void> watcher;
    //QFutureWatcher<int> watcher;
    QFuture<void> future = QtConcurrent::map(data,&MultiTen);
    QObject::connect(&watcher,&QFutureWatcher<void>::progressValueChanged,
                     [](int nVal){qInfo()<<"progrss:"<<nVal;});
    //QFuture<int> future = QtConcurrent::mapped(data,&MultiTen);
    watcher.setFuture(future);
    qInfo()<<"back for main.";
    watcher.waitForFinished();
    qInfo()<<"done.";
    qInfo()<<data;
    return a.exec();
}
