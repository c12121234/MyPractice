# QSemaphore

**1.** 用途

    可以視作陣列(容器、多元素)的mutexlocker.
**2.** 用法

    QSemaPhore sema(預定可使用的資源數量);
    sema.acquire(這次的操作預定使用多少資源數量);
    預定保護的操作
    sema.release(要釋放的資源數量，不填預設為1);
    
**3.** 注意事項

    由於要操作許多陣列內元素，先完成的元素必須要等待。
    QThreadPool要呼叫WaitForDone

**4.** 心得

老實說還是覺得在熟練QRunnable...總之記得使用QThreadpool就要繼承QRunnable
特別提一下QRunnable並*不*是QObject的子類，所以要使用signal/slot的話，要**多重繼承**QObject和QRunnable
