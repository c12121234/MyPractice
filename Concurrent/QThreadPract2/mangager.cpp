#include "mangager.h"
#include <QThread>
#include <QDebug>

Manager::Manager(QObject *parent) : QObject(parent)
{
    for(int i = 0; i<5;++i)
    {
        QThread* thread = new QThread(this);
        thread->setObjectName("Thread"+QString::number(i));
        qInfo()<<"Create: "<<thread->objectName();

        connect(thread,&QThread::started,this,&Manager::started);
        connect(thread,&QThread::finished,this,&Manager::finished);

        m_Threads.push_back(thread);
    }
}

void Manager::start()
{
    qInfo()<<"start...";
    for(auto thread : m_Threads)
    {
        qInfo()<<"starting: "<<thread->objectName();
        Counter* c = new Counter(); //!!!! TAKE CARE OBJ WHITCH WANT WORK ON THREAD MUST NOT HAVE PARENT.
        c->moveToThread(thread);
        //c->start() call start directly instead of MoveToThread would cause work on single thread(main thread).
        connect(thread,&QThread::started,c,&Counter::Start);
        thread->start();
    }
}

void Manager::started()
{
    QThread* thread = qobject_cast<QThread*>(sender());
    if(!thread)
        return;
    qInfo()<<"Started:"<<thread->objectName();
}

void Manager::finished()
{
    QThread* thread = qobject_cast<QThread*>(sender());
    if(!thread)
        return;
    qInfo()<<"finished:"<<thread->objectName();
}
