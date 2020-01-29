#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class QTimer;
class QUdpSocket;

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

public slots:
    void HandleStart();
    void HandleStop();
    void HandleTimeOut();
    void HandleReadyRead();
    void DoBroadcast();

private:
    QUdpSocket* m_pUdpSocket;
    QTimer* m_pTimer;
    qint16 m_nPort;
};

#endif // WORKER_H
