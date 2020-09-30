#include "widget.h"
#include "ui_widget.h"
#include <QSharedMemory>
#include <QBuffer>
#include <QDataStream>
#include <QFileDialog>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    ,m_pSharedMem(new QSharedMemory("sharedMem",this))
{
    ui->setupUi(this);
    ConnectionUIControl();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleClickedLoadFile()
{
    QString strFilePath = QFileDialog::getOpenFileName(this,"select img file:","../",
                                                       "image Files *jpg *png *bmp");
    if(strFilePath.isEmpty())
    {
        qDebug()<<"no select file,return";
        return;
    }

    QImage imgData(strFilePath);
    ui->labelImage->setPixmap(QPixmap::fromImage(imgData));

    QBuffer buffer;
    QDataStream out(&buffer);
    buffer.open(QIODevice::ReadWrite);
    out << imgData;
    int nSize = buffer.size();

    if(!m_pSharedMem->create(nSize))
    {
        qDebug()<<"could't create shared mem,return";
        return;
    }


    m_pSharedMem->lock();
    char* pcharDes = (char*)m_pSharedMem->data();
    const char* pcharSource = buffer.data().data();
    memcpy(pcharDes,pcharSource,qMin(nSize,m_pSharedMem->size()));
    m_pSharedMem->unlock();

    qDebug()<<"store data to shared mem.";
}

void Widget::handleClickedReadShared()
{
    if(!m_pSharedMem->attach())
    {
        qDebug()<<"can't find shared mem,return.";
        return;
    }

    QBuffer buffer;
    QDataStream in(&buffer);
    QImage imgData;

    m_pSharedMem->lock();
    buffer.setData((const char*)m_pSharedMem->data(),m_pSharedMem->size());
    buffer.open(QIODevice::ReadOnly);
    in >> imgData;
    m_pSharedMem->unlock();

    m_pSharedMem->detach();
    ui->labelImage->setPixmap(QPixmap::fromImage(imgData));

}

void Widget::ConnectionUIControl()
{
    connect(ui->btnLoadFile,&QPushButton::clicked,this,&Widget::handleClickedLoadFile);
    connect(ui->btnReadFromShared,&QPushButton::clicked,this,&Widget::handleClickedReadShared);
}

