# StorageCheck

使用Qt的模組偵測掛載下的硬碟空間、剩餘空間。

關鍵在`QStorageInfo::mountedVolumes()`這個靜態function

會取得一QList，裡面有各硬碟的資訊


function名稱                  | 功能
----------------------------|:---:
**rootPath()**             | 顯示該硬碟的路徑
**name()**|Returns the human-readable name of a filesystem, usually called label.
**displayName()**|Returns the volume's name, if available, or the root path if not.
**fileSystemType()**|Returns the type name of the filesystem.
**bytesTotal()**|總容量，byte單位，若要換成MB則要/1000/1000
**bytesAvailable()**|剩餘容量，同上


![img](https://github.com/c12121234/WorkingExperence/blob/master/pic/QtStorage/storage001.png)

