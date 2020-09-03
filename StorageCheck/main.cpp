#include <QCoreApplication>
#include <QStorageInfo>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //QStorageInfo storage = QStorageInfo::root();

    //    qDebug() << storage.rootPath();
    //    if (storage.isReadOnly())
    //        qDebug() << "isReadOnly:" << storage.isReadOnly();

    //    qDebug() << "name:" << storage.name();
    //    qDebug() << "fileSystemType:" << storage.fileSystemType();
    //    qDebug() << "size:" << storage.bytesTotal()/1000/1000 << "MB";
    //    qDebug() << "availableSize:" << storage.bytesAvailable()/1000/1000 << "MB";

    for (const QStorageInfo &storage: QStorageInfo::mountedVolumes())
    {
        if (storage.isValid() && storage.isReady())
        {
            if (!storage.isReadOnly()) {
                qDebug() << "";
                qDebug() << "rootpath:"<< storage.rootPath();
                qDebug() << "name:" << storage.name();
                qDebug() << "displayname:" << storage. displayName();
                qDebug() << "fileSystemType:" << storage.fileSystemType();
                qDebug() << "size:" << storage.bytesTotal()/1000/1000 << "MB";
                qDebug() << "availableSize:" << storage.bytesAvailable()/1000/1000 << "MB";
            }
        }
    }



    return a.exec();
}
