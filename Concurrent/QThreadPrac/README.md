# QThreadPrac

#### 大綱:

分辨QThread MoveToThread

以及Connection type的練習

**注意**

當使用`QueuedConnection`時，slot函數會在*接收端*的執行緒上

當使用`DirectConnection`時，slot函數則會在*發送端*的執行緒上

`autoConnection`，判斷兩object所在執行緒，若同一執行緒則使用`DirectConnection`

若不同執行緒則使用`QueueConnection`

