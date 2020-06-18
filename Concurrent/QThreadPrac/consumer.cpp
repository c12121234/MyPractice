#include "consumer.h"
#include <QMutexLocker>
#include <QDebug>
#include <QThread>
Consumer::Consumer(QObject *parent) : QObject(parent)
{

}

void Consumer::onSendProducerSignal(const QString &strTxt)
{
    QMutexLocker locker(&m_Mutex);
    m_List.push_back(strTxt);
    emit sendConsumer();
    qDebug()<<"[Consumer][onSendProducerSignal] push element."<<"consumer thread: "<<QThread::currentThread();
}

void Consumer::handleConsumer()
{
    QMutexLocker locker(&m_Mutex);
    if(!m_List.empty())
    {
        QString strTxt = m_List.front();
        m_List.pop_front();
        qDebug()<<"[Consumer]"<<strTxt<<" "<<QThread::currentThread();
    }
}
