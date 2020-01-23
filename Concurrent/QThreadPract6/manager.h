#ifndef MAMAGER_H
#define MAMAGER_H

#include <QObject>
class QThread;
class Consumer;
class Producer;
class QMutex;
class QWaitCondition;
class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);
public slots:
    void HandleStart();
    void HandleReady();
signals:


private:
    QThread* m_pProducerThread;
    QThread* m_pConsumerThread;
    Consumer* m_pConsumer;
    Producer* m_pProducer;
    QMutex* m_pMutex;
    QWaitCondition* m_pwCondition;
    QList<int> m_listData;
};

#endif // MAMAGER_H
