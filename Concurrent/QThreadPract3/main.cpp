#include <QCoreApplication>
#include <QThreadPool>
#include <QThread>
#include <QDebug>
#include "counter.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThread::currentThread()->setObjectName("Main");
    QThreadPool* pool = QThreadPool::globalInstance();
    for(int i = 0; i<100;++i)
    {
        Counter* c = new Counter();
        c->setAutoDelete(true);
        pool->start(c);
    }
    return a.exec();
}
