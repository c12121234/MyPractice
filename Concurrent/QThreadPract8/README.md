# QtConcurrent::run和QFuture


## 概述

創建QThreadPool，利用pool和main thread來觀察多執行緒

## 用法

|    |    |
|----|----|
|`1` |`QFuture<T> QtConcurrent::run(Function function, ...)`|
|`2` |`QFuture<T> QtConcurrent::run(QThreadPool *pool, Function function, ...)`|

參數的function都可替換成lambda表示式

返回值QFuture<T>，可使用WaitForFinished()來做同步


## 結果圖
![img](https://github.com/c12121234/MyPractice/blob/master/pic/QThreadPract8_1.PNG)
