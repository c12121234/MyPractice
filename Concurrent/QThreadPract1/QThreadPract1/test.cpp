#include "test.h"
#include <QDebug>
#include <QDateTime>
#include <QThread>

test::test(QObject *parent):QObject(parent)
{
    m_Timer = std::make_shared<QTimer>();
}

void test::TimeOut()
{
    qInfo()<< QDateTime::currentDateTime().toString() << "on " << QThread::currentThread();
}

void test::Start()
{
    connect(m_Timer.get(),&QTimer::timeout,this,&test::TimeOut);
    m_Timer->setInterval(1000);
    m_Timer->start();
}
