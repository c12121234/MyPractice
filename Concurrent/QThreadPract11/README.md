# QFutureWatcher的signal

## 概述
連接QFutureWatcher的signal來觀察future的流程

## 注意要點

progress並沒有如Pract9那樣被阻塞然後一次發送event，有好好的邊傳progress邊運行

可能是function內有sleep的關係(?)

應該是Pract9使用`WaitForFinished()`的關係，將Main thread sleep後，阻塞Main thread直到future結束才交回控制權(context switch)

Pract11則沒有使用`WaitForFinished()`

由此可知若有UI操作或觀察progress之類的行為，使用非同步function是較好的選擇

## 結果

![img](https://github.com/c12121234/MyPractice/blob/master/pic/QThreadPract11_1.PNG)
