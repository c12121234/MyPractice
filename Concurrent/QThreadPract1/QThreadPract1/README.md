# QThread練習

**1.** 確認 QObject::MoveToThread的眉眉角角

**2.** 確認 可用A Thread影響B Thread的行為

**3.** 簡單的QSharedPointer操作


這邊簡單說明一下關於**1**項目的內容

除了設定有parent的QObject無法使用MoveToThread之外，我碰到的狀況是

在Thread B，某物件(Timer)把 class B設定為parent

但Timer無法啟動，所以推論要移動到Thread的內容都別設定parent會比較好。
