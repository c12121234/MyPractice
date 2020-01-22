# QThreadPool 執行緒池

**1.** counter透過繼承QRunnable來讓QThreadPool可使用

**2.** 繼承QRunnable的calss要override run public函數，QThreadPool使用start函數時會調用run來運行

**3.** QRunnable的setAutoDelete預設為true
