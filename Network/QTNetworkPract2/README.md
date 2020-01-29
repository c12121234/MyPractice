# QUdpSocket

## 程式流程：

    設定一Timer每秒發出udp datagram並顯示
    
## 使用函數：

**1.** QUdpSocket::bind(qint16 port)    
    
    指定port進行綁定
    
**2.** QUdpSocket::localAddress()
    
    顯示localAddress
**3.** QUdpSocket::localPort()
    
    顯示localPort
**4.** QUdpSocket::close()    
    
    關閉udp socket
**5.** QNetworkDatagram建構式 

    QNetworkDatagram::QNetworkDatagram(const QByteArray &data, const QHostAddress &destinationAddress = QHostAddress(), quint16 port = 0)
    這裡使用的是 QHostAddress::Broadcast
**6.** QUdpSocket::WriteDatagram(const QNetworkDatagram &datagram)

    將data包成datagram後利用此函數傳出
**7.** QUdpSocket::hasPendingDatagrams()

    判斷socket內是否有pending的資料，通常用在while迴圈判斷
**8.** QNetworkDatagram QUdpSocket::receiveDatagram(qint64 maxSize = -1)

    return 一個QNetworkDatagrm，maxSize參數預設為-1，代表一次讀完整個datagram
    
## 本次問題：
    遇到需要顯示本地時間的中文，從QString存成QByteArray會變成raw data顯示，若要顯示正常文字需使用
    QString::fromLocal8Bit(QByteArray)
