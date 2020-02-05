#include <QCoreApplication>
#include <QtConcurrent/QtConcurrent>
#include <QDebug>
#include <vector>
int MultiTen(int nVal)
{
    qInfo()<<"multi 10!"<<nVal;
    int nAns = nVal*10;
    return nAns;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int> Nums;
    //std::vector<int> Nums;
    for(int i = 1; i<153;++i)
    {
        Nums<<i;
    }
    qInfo()<<"start block.";
    QList<int> TempNums = QtConcurrent::blockingMapped(Nums,&MultiTen);
    qInfo()<<TempNums;
    qInfo()<<"finished.";
    return a.exec();
}
