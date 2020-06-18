#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include "consumer.h"
#include "producer.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"main thread:"<<QThread::currentThread();
    Consumer c;
    Producer p;
    QThread tc,tp;
    c.moveToThread(&tc);
    p.moveToThread(&tp);
    QObject::connect(&p,&Producer::sendProducerSignal,&c,&Consumer::onSendProducerSignal,Qt::QueuedConnection);
    QObject::connect(&c,&Consumer::sendConsumer,&c,&Consumer::handleConsumer,Qt::QueuedConnection);
    tp.start();
    tc.start();

    return a.exec();
}
