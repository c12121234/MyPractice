# QHostAddress

1.**QNetworkInterface::allAddresses()**

    列出本地的所有address，返回QList<QHostAddress>。
    
2.**QHostAddress::isLoopback()**    

    判斷QHostAddress是否為loopback。
    
3.**QHostAddress::isMulticast()**    

    判斷QHostAddress是否為multicast。
    
4.**QHostAddress::protocol()**

    返回QAbstractSocket::NetworkLayerProtocol的enum
    
5.**QAbstractSocket::NetworkLayerProtocol:**   

    QAbstractSocket::UnknownNetworkLayerProtocol
    
    QAbstractSocket::AnyIPProtocol
    
    QAbstractSocket::IPv4Protocol
    
    QAbstractSocket::IPv6Protocol
    
    以enum來判斷address在使用那些protocol.
