#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
class QSharedMemory;
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void handleClickedLoadFile();
    void handleClickedReadShared();

private:
    void ConnectionUIControl();

private:
    Ui::Widget *ui;
    QSharedMemory* m_pSharedMem;
};
#endif // WIDGET_H
