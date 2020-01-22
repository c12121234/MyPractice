#ifndef MANGAGER_H
#define MANGAGER_H

#include <QObject>
#include <vector>
#include "counter.h"

class QThread;
class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);
    ~Manager();
    void start();

public slots:
    void started();
    void finished();
private:
    std::vector<QThread*> m_Threads;

};

#endif // MANGAGER_H
