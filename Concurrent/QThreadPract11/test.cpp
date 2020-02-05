#include <QDebug>
#include <QFuture>
#include <QFutureWatcher>
#include <QMutex>
#include <QMutexLocker>
#include <QThread>
#include <QtConcurrent>
#include "test.h"
Test::Test(QObject *parent) : QObject(parent)
  ,m_pWatcher(new QFutureWatcher<void>(this))
{
    connect(m_pWatcher,&QFutureWatcher<void>::canceled,this,&Test::HandleCancel);
    connect(m_pWatcher,&QFutureWatcher<void>::finished,this,&Test::HandleFinished);
    connect(m_pWatcher,&QFutureWatcher<void>::paused,this,&Test::HandlePaused);
    connect(m_pWatcher,&QFutureWatcher<void>::progressRangeChanged,this,&Test::HandleProgressRangeChanged);
    connect(m_pWatcher,&QFutureWatcher<void>::progressTextChanged,this,&Test::HandleProgressTextChanged);
    connect(m_pWatcher,&QFutureWatcher<void>::progressValueChanged,this,&Test::HandleProgressValueChanged);
    connect(m_pWatcher,&QFutureWatcher<void>::resultReadyAt,this,&Test::HandleResultReadyAt);
    connect(m_pWatcher,&QFutureWatcher<void>::resultsReadyAt,this,&Test::HandleResultsReadyAt);
    connect(m_pWatcher,&QFutureWatcher<void>::resumed,this,&Test::HandleResumed);
    connect(m_pWatcher,&QFutureWatcher<void>::started,this,&Test::HandleStarted);

}

Test::~Test()
{
    if(m_pFuture)
    {
        delete m_pFuture;
        m_pFuture = nullptr;
    }
}

void Test::Process()
{
    QMutex mutex;
    {
        QMutexLocker locker(&mutex);
        for(int i = 1; i<=100;++i)
            m_List.append(i);
    }
    QFuture<void> future = QtConcurrent::map(m_List,[this](int& nVal){this->Multiply(nVal);});//call member function
    //QFuture<void> future = QtConcurrent::map(m_List,&Test::Multiply); static member function use this.
    m_pWatcher->setFuture(future);
}

void Test::Multiply(int &nVal)
{
    qInfo()<<"called :"<<nVal;
    nVal *= 10;
    QThread::currentThread()->msleep(250);
}

void Test::HandleCancel()
{
    qInfo()<<"Canceled :";
}

void Test::HandleFinished()
{
    qInfo()<<"Finished :";
    qInfo()<<m_List;
}

void Test::HandlePaused()
{
    qInfo()<<"Paused :";
}

void Test::HandleProgressRangeChanged(int nMin, int nMax)
{
    qInfo()<<"Range "<<nMin<<"to "<<nMax;
}

void Test::HandleProgressTextChanged(const QString &strProgressText)
{
    qInfo()<<"TextChanged :"<<strProgressText;
}

void Test::HandleProgressValueChanged(int nPorgressValue)
{
    qInfo()<<"progress :"<<nPorgressValue;
}

void Test::HandleResultReadyAt(int nIndex)
{
    qInfo()<<"ReadyAt :"<<nIndex;
}

void Test::HandleResultsReadyAt(int nBeginIndex, int nEndIndex)
{
    qInfo()<<"ReadyAt :"<<nBeginIndex<<"and "<<nEndIndex;
}

void Test::HandleResumed()
{
    qInfo()<<"Resumed :";
}

void Test::HandleStarted()
{
    qInfo()<<"Started :";
}
