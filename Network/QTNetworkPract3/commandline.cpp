#include "commandline.h"
#include <QTextStream>
#include <QThread>
#include <QDebug>
#include <QtConcurrent>
CommandLine::CommandLine(QObject *parent, FILE *pFileHandle) : QObject(parent)
  ,m_pCin(new QTextStream(pFileHandle))
{

}

CommandLine::~CommandLine()
{
    if(m_pCin)
    {
        delete m_pCin;
        m_pCin = nullptr;
    }
}

void CommandLine::Monitor()
{
    while (true)
    {
        QString strCommand = m_pCin->readLine();
        emit Command(strCommand);
        this->thread()->msleep(500);
    }
}
