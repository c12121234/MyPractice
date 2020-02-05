#ifndef PRINTPROGRESS_H
#define PRINTPROGRESS_H

#include <QObject>

class PrintProgress : public QObject
{
    Q_OBJECT
public:
    explicit PrintProgress(QObject* parent = nullptr);
    ~PrintProgress();
public slots:
    void HandleProgressChanged(int nVal);

signals:

};

#endif // PRINTPROGRESS_H
