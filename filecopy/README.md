# 使用c++標準庫的檔案複製

## 概述

利用標準庫來操作檔案複製，或移動

## 程式碼

```cpp
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>

int main()
{
    std::string strFilePath("MyFile.txt");
    std::string strDesFilePath("..//MyFile.txt");
    std::ifstream in(strFilePath, std::ios::in | std::ios::binary);
    std::ofstream out(strDesFilePath, std::ios::out | std::ios::binary);
    out << in.rdbuf();
    std::cout << "copy complete" << std::endl;
}
```    
## 說明

c++17引入了`std::filesystem`來方便操作檔案，不過並不是所有編譯器都支援到c++17

在社團看到有人詢問怎麼複製檔案，順手記錄下來並實作一番。

大致上是將檔案讀入`ifstream`，將欲複製的地點寫到`ofstream`，最後再將`ifstream`的內容寫入`ofstream`

如果是要"移動"操作的話，最後再remove原檔案就好。

上面的code是將MyFile.txt複製到上一層。

這範例是可以跨磁區複製，如果是同磁區，會更加簡單，來看看

```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cerrno>

int main() {
  if(std::rename("from.txt", "to.txt") < 0) {
    std::cout << strerror(errno) << '\n';
  }
  return 0;
}
```
使用到`cstdio`內的`rename`，非常簡單

那如果編譯器支援c++17的話

跨磁區複製
```cpp
#include <iostream>
#include <filesystem>

int main()
{
  try {
    std::filesystem::copy("from.txt", "to.txt");
    std::filesystem::remove("from.txt");
  } catch (std::filesystem::filesystem_error& e) {
    std::cout << e.what() << '\n';
  }
  return 0;
}
```

同磁區複製
```cpp
#include <iostream>
#include <filesystem>

int main() {
  try {
    std::filesystem::rename("from.txt", "to.txt");
  } catch (std::filesystem::filesystem_error& e) {
    std::cout << e.what() << '\n';
  }
  return 0;
}
```

## 心得

先熟悉可向下相容的寫法吧!

## 參考資料

https://stackoverflow.com/questions/22201663/find-and-move-files-in-c
