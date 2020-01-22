#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QRunnable>
class Counter : public QRunnable
{    
public:
    void run() override;
};

#endif // COUNTER_H
