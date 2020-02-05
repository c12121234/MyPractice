#include "printprogress.h"
#include <QDebug>
PrintProgress::PrintProgress(QObject *parent):QObject(parent)
{

}

PrintProgress::~PrintProgress()
{

}

void PrintProgress::HandleProgressChanged(int nVal)
{
    qInfo()<<"progress: "<<nVal;
}
