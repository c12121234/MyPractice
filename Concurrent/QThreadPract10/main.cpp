#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QFutureSynchronizer>
#include <QRandomGenerator>
#include <QFuture>
#include <QtConcurrent>
void DoStuff(int nVal)
{
    for(int i = 0; i<10;++i)
    {
        QThread::currentThread()->msleep(QRandomGenerator::global()->bounded(200));
        qInfo()<<"thread value ="<<nVal<<"="<<i<<"thread:"<<QThread::currentThread();
    }
}

void RunThread()
{
    QFutureSynchronizer<void> sync;
    for(int i = 0; i<10;++i)
    {
        QFuture<void> f = QtConcurrent::run(&DoStuff,i);
        sync.addFuture(f);
    }
    //waitForFinished called in the QFutureSynchronizer destructor
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    RunThread();
    qInfo()<<"done.";
    return a.exec();
}
