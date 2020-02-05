#include <QCoreApplication>
#include <QThreadPool>
#include <QtConcurrent>
#include <QThread>
#include <QDebug>

void DoLoop()
{
    for(int i = 0; i<10;++i)
    {
        qInfo()<<"loop on"<<i<<QThread::currentThread();
    }
}

void Test()
{
    qInfo()<<"ready Test function on " <<QThread::currentThread();
    DoLoop();    
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThreadPool pool;
    qInfo()<<"max thread count:"<<pool.maxThreadCount();
    qInfo()<<"global Instance max thread count:"<<QThreadPool::globalInstance()->maxThreadCount();
    QThread::currentThread()->setObjectName("Main Thread");
    QFuture<void> fucture = QtConcurrent::run(&pool,&Test);
    qInfo()<<"progrss value:"<<fucture.progressValue();
    qInfo()<<"progrss max:"<<fucture.progressMaximum();
    qInfo()<<"Main on"<<QThread::currentThread();
    DoLoop();
    return a.exec();
}
