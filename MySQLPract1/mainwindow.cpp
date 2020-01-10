#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pTableModel = new QSqlTableModel(this);
    m_pTableModel->setTable("student");
    m_pTableModel->select();
    m_pTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(m_pTableModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnCommitModified_clicked()
{
    m_pTableModel->database().transaction();
    if(m_pTableModel->submitAll())
    {
        if(m_pTableModel->database().commit())
            QMessageBox::information(this,"tablemodel","success modify!");
    }
    else
    {
        m_pTableModel->database().rollback();
        QMessageBox::warning(this,"tablemodel",tr("database error:%1").arg(m_pTableModel->lastError().text()),
                             QMessageBox::Ok);
    }
}

void MainWindow::on_btnCancelModified_clicked()
{
    m_pTableModel->revertAll();
}

void MainWindow::on_btnAddData_clicked()
{
    int nRowNum = m_pTableModel->rowCount();
    int id = nRowNum+1;
    m_pTableModel->insertRow(nRowNum);
    m_pTableModel->setData(m_pTableModel->index(nRowNum,0),id);
    m_pTableModel->submitAll();
}

void MainWindow::on_btnDeletedData_clicked()
{
    int nCurrRow = ui->tableView->currentIndex().row();
    m_pTableModel->removeRow(nCurrRow);
    int nOK = QMessageBox::warning(this,"delete","sure delete current row?",
                                   QMessageBox::Yes,QMessageBox::No);
    if(nOK == QMessageBox::No)
        m_pTableModel->revertAll();
    else
        m_pTableModel->submitAll();
}

void MainWindow::on_btnAscorder_clicked()
{
    m_pTableModel->setSort(0,Qt::AscendingOrder);
    m_pTableModel->select();
}

void MainWindow::on_btnDescorder_clicked()
{
    m_pTableModel->setSort(0,Qt::DescendingOrder);
    m_pTableModel->select();
}

void MainWindow::on_btnQuery_clicked()
{
    QString strName = ui->lineEdit->text();
    m_pTableModel->setFilter(QString("name = '%1'").arg(strName));
    m_pTableModel->select();
}

void MainWindow::on_btnShowAllTable_clicked()
{
    m_pTableModel->setTable("student");
    m_pTableModel->select();
}
