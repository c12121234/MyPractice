#include "consumer.h"
#include <QDebug>
#include <QMutex>
#include <QMutexLocker>
#include <QWaitCondition>
#include <QThread>

Consumer::Consumer(QObject *parent) : QObject(parent)
{

}

void Consumer::SetData(QList<int> *plstData)
{
    m_pListData = plstData;
}

void Consumer::SetMutex(QMutex *pMutex)
{
    m_pMutex = pMutex;
}

void Consumer::SetConditionVariable(QWaitCondition *pwCondition)
{
    m_pwCondition =pwCondition;
}

void Consumer::HandleStart()
{
    qInfo()<<"starting consumer on"<<this->thread();
    do
    {
        qInfo()<<"Consuming on "<<this->thread();
        QMutexLocker locker(m_pMutex);
        m_pListData->clear();
        m_pwCondition->wait(m_pMutex);
    } while(true);
}
