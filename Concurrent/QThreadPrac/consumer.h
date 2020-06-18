#ifndef CONSUMER_H
#define CONSUMER_H

#include <QObject>
#include <QList>
#include <QMutex>

class Consumer : public QObject
{
    Q_OBJECT
public:
    explicit Consumer(QObject *parent = nullptr);
public slots:
    void onSendProducerSignal(const QString& strTxt);
    void handleConsumer();
signals:
    void sendConsumer();
private:
    QList<QString> m_List;
    QMutex m_Mutex;
};

#endif // CONSUMER_H
