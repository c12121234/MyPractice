#include <QCoreApplication>
#include "worker.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Worker w;
    w.HandleStart();
    return a.exec();
}
