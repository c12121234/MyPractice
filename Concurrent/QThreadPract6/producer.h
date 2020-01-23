#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>
class QMutex;
class Producer : public QObject
{
    Q_OBJECT
public:
    explicit Producer(QObject *parent = nullptr);
    void SetData(QList<int>* lstData);
    void SetMutex(QMutex* mutex);

signals:
    void ready();
public slots:
    void HandleStart();
private:
    QList<int>* m_pListData;
    QMutex* m_pMutex;
};

#endif // PRODUCER_H
