#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>

QT_BEGIN_NAMESPACE
class QTimer;
QT_END_NAMESPACE

class Producer : public QObject
{
    Q_OBJECT
public:
    explicit Producer(QObject *parent = nullptr);
public slots:
    void handleTimerTimeOut();
signals:
    void sendProducerSignal(const QString& strTxt);
private:
    QTimer* m_pTimer;

};

#endif // PRODUCER_H
