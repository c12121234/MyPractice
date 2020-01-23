#include <QCoreApplication>
#include "manager.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Manager ma;
    ma.HandleStart();
    return a.exec();
}
