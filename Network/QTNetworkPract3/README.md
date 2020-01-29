# udp chatroom

## 程式流程:
    輸入ID 會顯示ID joined
    從stdin擷取輸入，用broadcast傳出
    
## 使用函式:
    基本上和Pract2一樣，但在QUdpSocket::bind時使用了第二個參數QUdpSocket::ShareAddress
    不過在windows其參數是預設的，特別注意。
修正:如果用單獨裝置測試的話，參數要使用**QAbstractSocket::ReuseAddressHint**

enum QAbstractSocket::BindFlag
flags QAbstractSocket::BindMode


|**Constant**   |**Value**   |**Description**|   
|------------------------------------|------------|---------------|
|QAbstractSocket::ShareAddress|0x1|Allow other services to bind to the same address and port. This is useful when multiple processes share the load of a single service by listening to the same address and port (e.g., a web server with several pre-forked listeners can greatly improve response time). However, because any service is allowed to rebind, this option is subject to certain security considerations. Note that by combining this option with ReuseAddressHint, you will also allow your service to rebind an existing shared address. On Unix, this is equivalent to the SO_REUSEADDR socket option. On Windows, this is the default behavior, so this option is ignored.
|QAbstractSocket::DontShareAddress|0x2|Bind the address and port exclusively, so that no other services are allowed to rebind. By passing this option to QAbstractSocket::bind(), you are guaranteed that on successs, your service is the only one that listens to the address and port. No services are allowed to rebind, even if they pass ReuseAddressHint. This option provides more security than ShareAddress, but on certain operating systems, it requires you to run the server with administrator privileges. On Unix and macOS, not sharing is the default behavior for binding an address and port, so this option is ignored. On Windows, this option uses the SO_EXCLUSIVEADDRUSE socket option.
|QAbstractSocket::ReuseAddressHint|0x4|Provides a hint to QAbstractSocket that it should try to rebind the service even if the address and port are already bound by another socket. On Windows and Unix, this is equivalent to the SO_REUSEADDR socket option.
|QAbstractSocket::DefaultForPlatform|0x0|The default option for the current platform. On Unix and macOS, this is equivalent to (DontShareAddress + ReuseAddressHint), and on Windows, it is equivalent to ShareAddress.
