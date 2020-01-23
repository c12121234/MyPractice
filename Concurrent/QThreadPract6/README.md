# QWaitCondition

**1.** 利用producer/consumer模型來觀察QWaitCondition如何運作

**2.** 需要一個mutex

**3.** 流程

    Producer->send ready to manager->manager wakeall->consumer阻塞的lock釋放，往下執行
    
**4.**

    在使用wakeall的地方也記得使用lock 確保順序正確
    
**5.**

    QWaitCondition需要一個鎖定中的mutex來進行wait()
