# Shared memory

使用Qt的QSharedMemory的練習程式

實作IPC功能

透過sharedmemory來完成跨process的資料交換

在讀取完資料後記得要detach data

另外使用交換資料的機制時，建議使用QBuffer/QByteArray這種暫存區

以及DataStream來確保資料的順序。


```cpp
QBuffer buffer;
QDataStream out(&buffer);
buffer.open(QIODdevice::READWRITE);
out << imgData;
//...
```
