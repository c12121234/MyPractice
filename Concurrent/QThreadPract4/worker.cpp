#include "worker.h"
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>
#include "counter.h"
Worker::Worker(QObject *parent, QMutex *pMutex, Counter *pCounter) : QObject(parent)
  ,QRunnable()
  ,m_pMutex(pMutex),m_pCounter(pCounter)
{

}

void Worker::run()
{
    if(!m_pCounter)
        return;
    qInfo() << this << "starting run.";
    for(int i = 0; i<100;++i)
    {
        QMutexLocker locker(m_pMutex);
        m_pCounter->Increment();
        qInfo()<< this <<"Count:"<<m_pCounter->GetCount();
        m_pCounter->Decrement();
    }
    qInfo() << this << "finished.";
}
