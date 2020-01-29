#include "worker.h"
#include <QDebug>
#include <QTimer>
#include <QtNetwork>

Worker::Worker(QObject *parent) : QObject(parent)
  ,m_pUdpSocket(new QUdpSocket(this))
  ,m_pTimer(new QTimer(this))
  ,m_nPort(1989)
{
    connect(m_pTimer,&QTimer::timeout,this,&Worker::HandleTimeOut);
    connect(m_pUdpSocket,&QAbstractSocket::readyRead,this,&Worker::HandleReadyRead);
    m_pTimer->setInterval(1000);
}

void Worker::HandleStart()
{
    if(!m_pUdpSocket->bind(m_nPort))
    {
        qInfo()<<m_pUdpSocket->errorString();
        return;
    }
    qInfo()<<"started UDP on "<<m_pUdpSocket->localAddress()<<": port "<<m_pUdpSocket->localPort();
    DoBroadcast();
}

void Worker::HandleStop()
{
    m_pTimer->stop();
    m_pUdpSocket->close();
    qInfo()<<"stop.";
}

void Worker::HandleTimeOut()
{
    QString strTime = QDateTime::currentDateTime().toString();
    QByteArray data = strTime.toLocal8Bit();
    QNetworkDatagram datagram(data,QHostAddress::Broadcast,m_nPort);
    qInfo()<<"send :"<<QString::fromLocal8Bit(data);
    m_pUdpSocket->writeDatagram(datagram);
}

void Worker::HandleReadyRead()
{
    while(m_pUdpSocket->hasPendingDatagrams())
    {
        QNetworkDatagram Datagram = m_pUdpSocket->receiveDatagram();
        qInfo()<<"read :"<<QString::fromLocal8Bit(Datagram.data())
              <<"from :"<<m_pUdpSocket->localAddress()<<"port :"<<m_pUdpSocket->localPort();
    }
}

void Worker::DoBroadcast()
{
    qInfo()<<"Broadcasting...";
    m_pTimer->start();
}
