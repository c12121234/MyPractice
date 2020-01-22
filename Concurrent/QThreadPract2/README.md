# QThread 練習2

**1.** 要MoveToThread的物件不能有parent，但由main thread生產的 sub thread **可以有**parent.(有點繞口)

    例如在sub thread上計時的timer 這個不能有parent，但 QThread* subThread = new QThread(parent) <- 這種可以

**2.** 請使用thread->start()來啟動sub thread

    物件MoveToThread後請使用 thread->start()啟動多緒執行

    直接call物件的function會造成在main thread執行.
