#include "mainwindow.h"
#include <QApplication>
#include "myconnection.cpp"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!Connection())
        return 1;
    MainWindow w;
    w.show();
    return a.exec();
}
