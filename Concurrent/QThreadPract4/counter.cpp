#include "counter.h"

Counter::Counter(QObject *parent) : QObject(parent)
  ,m_nCount(0)
{

}

void Counter::Increment()
{
    m_nCount++;
}

void Counter::Decrement()
{
    m_nCount--;
}

int Counter::GetCount()
{
    return m_nCount;
}
