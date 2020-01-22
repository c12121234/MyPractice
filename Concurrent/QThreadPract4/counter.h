#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT
public:
    explicit Counter(QObject *parent = nullptr);
    void Increment();
    void Decrement();
    int GetCount();

private:
    int m_nCount;

};

#endif // COUNTER_H
