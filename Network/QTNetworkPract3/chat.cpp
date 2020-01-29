#include "chat.h"
#include <QtNetwork>
#include <QDebug>
Chat::Chat(QObject *parent) : QObject(parent)
  ,m_strName("")
  ,m_pUdpSocket(new QUdpSocket(this))
  ,m_nPort(1989)
{
    if(!m_pUdpSocket->bind(m_nPort,QUdpSocket::ShareAddress))
    {
        qInfo()<<m_pUdpSocket->errorString();
    }
    else
    {
        qInfo()<<"Started on:"<<m_pUdpSocket->localAddress()<<"port :"<<m_pUdpSocket->localPort();
        connect(m_pUdpSocket,&QAbstractSocket::readyRead,this,&Chat::HandleReadyRead);
    }
}

void Chat::HandleCommand(QString strCommand)
{
    QString strMessage = m_strName+" :";
    if(m_strName.isEmpty())
    {
        m_strName = strCommand;
        strMessage = m_strName+": joined";
        Send(strMessage);
        return;
    }
    strMessage += strCommand;
    Send(strMessage);
}

void Chat::Send(QString strValue)
{
    QByteArray data = strValue.toLocal8Bit();
    QNetworkDatagram datagram(data,QHostAddress::Broadcast,m_nPort);

    if(!m_pUdpSocket->writeDatagram(datagram))
    {
        qInfo()<<m_pUdpSocket->errorString();
    }
}

void Chat::HandleReadyRead()
{
    while(m_pUdpSocket->hasPendingDatagrams())
    {
        QNetworkDatagram datagram = m_pUdpSocket->receiveDatagram();
        qInfo()<<QString::fromLocal8Bit(datagram.data());
    }
}
