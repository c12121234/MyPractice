#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
class QTcpServer;
class QTcpSocket;
using std::vector;
using std::pair;
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void HandleClickedSendText();
    void HandleClickStart();
    void ReceiveData();
    void ClientDisconnect();
    void SendDataToClient();
private:
    Ui::Widget *ui;
    QTcpServer* m_pServer;
    QTcpSocket* m_pClient;
    vector<pair<int,int>> m_vec;
    bool m_bStartOn;
};
#endif // WIDGET_H
