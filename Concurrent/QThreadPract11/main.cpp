#include <QCoreApplication>
#include <QDebug>
#include "test.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Test t;
    t.Process();
    return a.exec();
}
