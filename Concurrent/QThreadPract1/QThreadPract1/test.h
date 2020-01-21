#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QTimer>
#include <memory>
class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject* parent = nullptr);
public slots:
    void TimeOut();
    void Start();
private:
    std::shared_ptr<QTimer> m_Timer;
};

#endif // TEST_H
