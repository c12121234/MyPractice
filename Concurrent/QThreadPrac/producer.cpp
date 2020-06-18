#include "producer.h"
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QThread>

Producer::Producer(QObject *parent) : QObject(parent)
  ,m_pTimer(new QTimer(this))
{
    m_pTimer->setInterval(1000);
    connect(m_pTimer,&QTimer::timeout,this,&Producer::handleTimerTimeOut);
    m_pTimer->start();
    qDebug()<<"producer thread:"<<QThread::currentThread();
}

void Producer::handleTimerTimeOut()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    QString strDateTime = currentTime.toString("hh:mm:ss");
    qDebug()<<"producer thread:"<<QThread::currentThread();
    emit sendProducerSignal(strDateTime);
}
