#include "widget.h"
#include "ui_widget.h"
#include <QtCore>
#include <QString>
#include <QMessageBox>
#include <QtNetwork>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)    
    , m_pServer(nullptr)
    , m_pClient(nullptr)
    , m_bStartOn(false)
{
    ui->setupUi(this);
    vector<pair<int,int>> vTemp(2,std::make_pair(0,0));
    m_vec = vTemp;

    connect(ui->btnSend,&QPushButton::clicked,this,&Widget::HandleClickedSendText);
    connect(ui->btnOnOff,&QPushButton::clicked,this,&Widget::HandleClickStart);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::HandleClickedSendText()
{
    if(m_pClient)
    {
        QString strText = ui->lineEditText->text();
        QStringList strList = strText.split(",");
        m_vec[0].first = strList[0].toInt();
        m_vec[0].second = strList[1].toInt();
        m_vec[1].first = strList[2].toInt();
        m_vec[1].second = strList[3].toInt();
        QString strData = QString("%1,%2,%3,%4").arg(m_vec[0].first).arg(m_vec[0].second).arg(m_vec[1].first).arg(m_vec[1].second);
        ui->plainTextEdit->appendPlainText("your data are saved.\n");
        ui->plainTextEdit->appendPlainText(strData);
        ui->lineEditText->clear();

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

        m_pClient->write(data,4);
        ui->plainTextEdit->appendPlainText("send to client!\n");
    }
    else
    {
        ui->plainTextEdit->appendPlainText("no connect client.\n");
    }
}

void Widget::HandleClickStart()
{
    m_bStartOn = !m_bStartOn;
    if(m_bStartOn)
    {
        ui->btnOnOff->setText("Stop");
        m_pServer = new QTcpServer(this);
        QString strPort = ui->lineEditPort->text();
        bool blisten = m_pServer->listen(QHostAddress::Any,strPort.toInt());
        if(!blisten)
        {
            QMessageBox::critical(this, tr("Fortune Server"),
                                  tr("Unable to start the server."));
            close();
            return;
        }
        QString strIPAdress = QHostAddress(QHostAddress::LocalHost).toString();
        ui->plainTextEdit->appendPlainText("The server is running on\n\nIP:"+strIPAdress+"\nport: "+strPort+"\n\n"
                                           "Run the Client now.");

        connect(m_pServer,&QTcpServer::newConnection,this,&Widget::SendDataToClient);

    }
    else
    {
        if(m_pServer)
        {
            m_pServer->close();
            m_pServer->deleteLater();
        }
        m_vec[0].first = 0;
        m_vec[0].second = 0;
        m_vec[1].first = 0;
        m_vec[1].second = 0;
        ui->plainTextEdit->appendPlainText("close server listen.");
        ui->btnOnOff->setText("Start");
    }
}

void Widget::ReceiveData()
{
    char Temp[4] ={0x00,0x00,0x00,0x00};
    QByteArray data(Temp,4);
    data = m_pClient->readAll();
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

void Widget::ClientDisconnect()
{
    m_vec[0].first = 0;
    m_vec[0].second = 0;
    m_vec[1].first = 0;
    m_vec[1].second = 0;
    ui->plainTextEdit->appendPlainText("client disconnect");
}

void Widget::SendDataToClient()
{
    QTcpSocket *clientConnection = m_pServer->nextPendingConnection();
    m_pClient = clientConnection;
    connect(m_pClient, &QAbstractSocket::disconnected,
            m_pClient, &QObject::deleteLater);
    connect(m_pClient,&QAbstractSocket::disconnected,this,&Widget::ClientDisconnect);
    connect(m_pClient,&QAbstractSocket::readyRead,this,&Widget::ReceiveData);

    //clientConnection->disconnectFromHost();
}

