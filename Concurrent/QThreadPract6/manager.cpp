#include "manager.h"
#include "consumer.h"
#include "producer.h"
#include <QDebug>
#include <QMutex>
#include <QMutexLocker>
#include <QThread>
#include <QWaitCondition>

Manager::Manager(QObject *parent) : QObject(parent)
  ,m_pProducerThread(new QThread(this))
  ,m_pConsumerThread(new QThread(this))
  ,m_pConsumer(new Consumer)
  ,m_pProducer(new Producer)
  ,m_pMutex(new QMutex)
  ,m_pwCondition(new QWaitCondition)
{
    connect(m_pProducerThread,&QThread::started,m_pProducer,&Producer::HandleStart,Qt::QueuedConnection);
    connect(m_pProducer,&Producer::ready,this,&Manager::HandleReady,Qt::QueuedConnection);
    connect(m_pConsumerThread,&QThread::started,m_pConsumer,&Consumer::HandleStart,Qt::QueuedConnection);


    m_pProducerThread->setObjectName("Producer thread");
    m_pConsumerThread->setObjectName("Consumer thread");
    this->thread()->setObjectName("Manager thread");

    m_pProducer->moveToThread(m_pProducerThread);
    m_pConsumer->moveToThread(m_pConsumerThread);
}

void Manager::HandleStart()
{
    m_pProducer->SetData(&m_listData);
    m_pProducer->SetMutex(m_pMutex);
    m_pConsumer->SetData(&m_listData);
    m_pConsumer->SetMutex(m_pMutex);
    m_pConsumer->SetConditionVariable(m_pwCondition);

    m_pProducerThread->start();
    m_pConsumerThread->start();

}

void Manager::HandleReady()
{
    qInfo()<<"data is ready"<<this->thread();
    QMutexLocker locker(m_pMutex);
    m_pwCondition->wakeAll();
}
