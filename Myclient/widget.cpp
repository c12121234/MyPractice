#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QtNetwork>
#include <QTimer>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_pSocket(nullptr)
    , m_bstart(false)
{
    ui->setupUi(this);
    vector<pair<int,int>> vTemp(2,std::make_pair(0,0));
    m_vec = vTemp;
    connect(ui->btnSend,&QPushButton::clicked,this,&Widget::HandleclickBtnSend);
    connect(ui->btnOnOff,&QPushButton::clicked,this,&Widget::HandleclickBtnOnOff);
    connect(this,&Widget::SwitchedBtn,this,&Widget::HandleSwitchedBtn);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::HandleclickBtnSend()
{
    if(m_pSocket == nullptr)
    {
        ui->plainTextEdit->appendPlainText("client dosen't start.\n");
        return;
    }
    QString strText = ui->lineEditSend->text();
    QStringList arr = strText.split(",");

    m_vec[0].first = arr[0].toInt();
    m_vec[0].second = arr[1].toInt();
    m_vec[1].first = arr[2].toInt();
    m_vec[1].second = arr[3].toInt();
    ui->plainTextEdit->appendPlainText("data saved.\n");
    ui->lineEditSend->clear();

    QByteArray data;
    data.resize(4);
    data[0] = 0x00;
    data[1] = 0x00;
    data[2] = 0x00;
    data[3] = 0x00;
    data[0] = m_vec[0].first;
    data[1] = m_vec[0].second;
    data[2] = m_vec[1].first;
    data[3] = m_vec[1].second;

    m_pSocket->write(data,4);
    ui->plainTextEdit->appendPlainText("send data.\n");
}

void Widget::HandleclickBtnOnOff()
{
    m_bstart = !m_bstart;
    if(m_bstart)
    {
        ui->btnOnOff->setText("Stop");
        m_pSocket = new QTcpSocket(this);
        QString strHost = ui->lineEditIP->text();
        QString strPort = ui->lineEditPort->text();
        ui->plainTextEdit->appendPlainText("ready to connect :"+strHost+" port:"+strPort+"\n");
        m_pSocket->connectToHost(strHost,strPort.toUInt());
        connect(m_pSocket,&QAbstractSocket::readyRead,this,&Widget::receiveSocketData);
        connect(m_pSocket,&QAbstractSocket::disconnected,this,&Widget::HandleDisconnect);
        connect(m_pSocket,&QAbstractSocket::disconnected,m_pSocket,&QAbstractSocket::deleteLater);

    }
    else
    {
        ui->plainTextEdit->appendPlainText("disconnect from host.");
        m_pSocket->abort();
        m_pSocket->disconnectFromHost();
        m_pSocket->close();
        ui->btnOnOff->setText("Start");
    }
}

void Widget::receiveSocketData()
{
    char Temp[4] ={0x00,0x00,0x00,0x00};
    QByteArray data(Temp,4);
    data = m_pSocket->readAll();
    ui->plainTextEdit->appendPlainText("receive data !\n");
    vector<int> vTemp(4,0);
    for(int i = 0; i<4;++i)
    {
        vTemp[i] = data[i];

    }
    m_vec[0].first = vTemp[0];
    m_vec[0].second = vTemp[1];
    m_vec[1].first = vTemp[2];
    m_vec[1].second = vTemp[3];
    QString strText = QString("%1,%2,%3,%4").arg(m_vec[0].first).arg(m_vec[0].second).arg(m_vec[1].first).arg(m_vec[1].second);
    ui->plainTextEdit->appendPlainText(strText);
}

void Widget::HandleDisconnect()
{
    m_bstart = false;
    m_pSocket->abort();
    m_pSocket->disconnectFromHost();
    m_pSocket->close();
    QTimer::singleShot(20,this,&Widget::HandleSwitchedBtn);

}

void Widget::HandleSwitchedBtn()
{
    ui->btnOnOff->setText("Start");
    ui->plainTextEdit->appendPlainText("disconnect.");
}

