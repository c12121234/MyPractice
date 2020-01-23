#include "producer.h"
#include <QRandomGenerator>
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>
Producer::Producer(QObject *parent) : QObject(parent)
{

}

void Producer::SetData(QList<int> *lstData)
{
    m_pListData = lstData;
}

void Producer::SetMutex(QMutex *mutex)
{
    m_pMutex = mutex;
}

void Producer::HandleStart()
{
    do
    {
        int nVal = QRandomGenerator::global()->bounded(1000);
        QMutexLocker locker(m_pMutex);
        m_pListData->append(nVal);
        if(m_pListData->size()>=100)
            emit ready();
    } while (true);
}
