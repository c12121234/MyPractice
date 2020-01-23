#ifndef CONSUMER_H
#define CONSUMER_H

#include <QObject>

class QMutex;
class QWaitCondition;
class Consumer : public QObject
{
    Q_OBJECT
public:
    explicit Consumer(QObject *parent = nullptr);
    void SetData(QList<int>* plstData);
    void SetMutex(QMutex* pMutex);
    void SetConditionVariable(QWaitCondition* pwCondition);
signals:
public slots:
    void HandleStart();
private:
    QList<int>* m_pListData;
    QMutex* m_pMutex;
    QWaitCondition* m_pwCondition;

};

#endif // CONSUMER_H
