# QFutureSynchronizer

## 概述

透過迴圈執行QtConcurrent::run來觀察QFutureSynchronizer的自動waitforfinished機制

## 作法

宣告QFutureSynchronizer後，對取得的QFuture使用`void QFutureSynchronizer::addFuture(const QFuture<T> &future)`

## 結果

![img](https://github.com/c12121234/MyPractice/blob/master/pic/QThreadPract10_1.PNG)
