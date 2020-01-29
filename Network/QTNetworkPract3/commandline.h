#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <QObject>

class QTextStream;
class CommandLine : public QObject
{
    Q_OBJECT
public:
    explicit CommandLine(QObject *parent = nullptr,FILE* pFileHandle = nullptr);
    ~CommandLine();
    [[noreturn]] void Monitor();
signals:
    void Command(QString strCommand);
private:
    QTextStream* m_pCin;
};

#endif // COMMANDLINE_H
