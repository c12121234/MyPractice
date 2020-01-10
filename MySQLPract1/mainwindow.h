#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QSqlTableModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnCommitModified_clicked();

    void on_btnCancelModified_clicked();

    void on_btnAddData_clicked();

    void on_btnDeletedData_clicked();

    void on_btnAscorder_clicked();

    void on_btnDescorder_clicked();

    void on_btnQuery_clicked();

    void on_btnShowAllTable_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel* m_pTableModel;
};
#endif // MAINWINDOW_H
