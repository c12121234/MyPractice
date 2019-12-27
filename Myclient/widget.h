#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
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
    void HandleclickBtnSend();
    void HandleclickBtnOnOff();
    void receiveSocketData();
    void HandleDisconnect();
    void HandleSwitchedBtn();
signals:
    void SwitchedBtn();
private:
    Ui::Widget *ui;
    QTcpSocket* m_pSocket;
    vector<pair<int,int>> m_vec;
    bool m_bstart;
};
#endif // WIDGET_H
