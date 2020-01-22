#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QRunnable>
class QSemaphore;
class Worker : public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr,QStringList* pList = nullptr,QSemaphore* pSema = nullptr,int nPos = -1);
    void run() override;
private:
    QStringList* m_pList;
    QSemaphore* m_pSema;
    int m_nPosition;
};

#endif // WORKER_H
