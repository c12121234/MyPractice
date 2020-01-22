#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QRunnable>
class QMutex;
class Counter;
class Worker : public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr,QMutex* pMutex = nullptr,Counter* pCounter = nullptr);
    void run() override;
private:
    QMutex* m_pMutex;
    Counter* m_pCounter;

};

#endif // WORKER_H
