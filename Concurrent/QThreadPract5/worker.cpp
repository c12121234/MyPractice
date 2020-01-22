#include "worker.h"
#include <QRunnable>
#include <QSemaphore>
#include <QThread>
#include <QDebug>
Worker::Worker(QObject *parent, QStringList *pList, QSemaphore *pSema, int nPos) : QObject(parent),
    QRunnable()
  ,m_pList(pList),m_pSema(pSema),m_nPosition(nPos)
{

}

void Worker::run()
{
    if(!m_pList || !m_pSema)
    {
        qInfo()<<" a pointer is null.";
        return;
    }
    QString strThread;
    strThread.sprintf("%08p",QThread::currentThread());
    m_pSema->acquire(1);
    m_pList->replace(m_nPosition,QString::number(m_nPosition)+"-"+strThread);
    m_pSema->release(1);

    qInfo()<<strThread<<"finished"<<m_nPosition;
}
