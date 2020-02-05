#ifndef TEST_H
#define TEST_H

#include <QObject>
//#include <QFuture>
//#include <QFutureWatcher>

template <typename T> class QFuture;
template <typename T> class QFutureWatcher;

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);
    ~Test();
    void Process();
    void Multiply(int& nVal);
public slots:
    void HandleCancel();
    void HandleFinished();
    void HandlePaused();
    void HandleProgressRangeChanged(int nMin,int nMax);
    void HandleProgressTextChanged(const QString& strProgressText);
    void HandleProgressValueChanged(int nPorgressValue);
    void HandleResultReadyAt(int nIndex);
    void HandleResultsReadyAt(int nBeginIndex,int nEndIndex);
    void HandleResumed();
    void HandleStarted();
signals:

private:
    QList<int> m_List;
    QFutureWatcher<void>* m_pWatcher;
    QFuture<void>* m_pFuture;
};

#endif // TEST_H
