# QtConcurrent::map和QFutureWatcher

## 概述

利用QtConcurrent::map來讓QList內的每個element平行處理MultiTen 最後得到一QList

## QtConcurrent::map形式:


|1   |`QFuture<void> QtConcurrent::map(Sequence &sequence, MapFunctor function)`
|---|---|
|2   |`QFuture<void> QtConcurrent::map(Iterator begin, Iterator end, MapFunctor function)`

和前面的QtConcurrent::run長得很像，而且也同樣有`QFuture<T>`的形式，叫做**QtConcurrent::mapped**

|1   |`QFuture<typename QtPrivate::MapResultType<void, MapFunctor>::ResultType> QtConcurrent::mapped(const Sequence &sequence, MapFunctor function)`
|---|---|
|2   |`QFuture<typename QtPrivate::MapResultType<void, MapFunctor>::ResultType> QtConcurrent::mapped(Iterator begin, Iterator end, MapFunctor function)`

## 流程

建立了QFutureWatcher，有QFuture，讓Watcher執行`void QFutureWatcher::setFuture(const QFuture<T> &future)`

可以讓watcher進行等待，即`QFutureWatcher::void QFutureWatcher::waitForFinished()`

直到完成前會阻塞，像本練習中watcher有和progressChanged signal 連接，subthread發出的event(progress更新)傳到main thread的event loop中被阻塞

map完成後，eventloop運行，才處理progress更新的slot。於是看到結果都跑完了才跳進度...


![img](https://github.com/c12121234/MyPractice/blob/master/pic/QThreadPract9_1.PNG)

喔對，progress的值是看sequence的element有多少個來決定
