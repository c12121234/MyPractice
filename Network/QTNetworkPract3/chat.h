#ifndef CHAT_H
#define CHAT_H

#include <QObject>

class QUdpSocket;
class Chat : public QObject
{
    Q_OBJECT
public:
    explicit Chat(QObject *parent = nullptr);

public slots:
    void HandleCommand(QString strCommand);
    void Send(QString strValue);
    void HandleReadyRead();
signals:

private:
    QString m_strName;
    QUdpSocket* m_pUdpSocket;
    qint16 m_nPort;
};

#endif // CHAT_H
