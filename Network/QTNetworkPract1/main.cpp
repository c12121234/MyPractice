#include <QCoreApplication>
#include <QDebug>
#include <QtNetwork>
#include <QObject>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    for(auto address:list)
    {
        qInfo()<<address.toString();
        qInfo()<<"\t loopback:"<<address.isLoopback();
        qInfo()<<"\t multicast:"<<address.isMulticast();

        switch(address.protocol())
        {
        case QAbstractSocket::UnknownNetworkLayerProtocol:
            qInfo()<<"\t protocol:unknown";
            break;
        case QAbstractSocket::AnyIPProtocol:
            qInfo()<<"\t protocol:AnyIP";
            break;

        case QAbstractSocket::IPv4Protocol:
            qInfo()<<"\t protocol:IPv4";
            break;

        case QAbstractSocket::IPv6Protocol:
            qInfo()<<"\t protocol:IPv6";
            break;
        }

    }

    return a.exec();
}
