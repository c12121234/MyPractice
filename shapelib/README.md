# README

將cpp包成lib後提供給c code呼叫

## 注意事項:

1. `extern "C"`是給cpp編譯器看的，讓編譯器知道這些api是要提供給C code使用

2. 使用`__cplusplus` macro來分辨目前使用的是gcc還是g++

3. 使用pointer來接cpp的資料，因為pointer不需要知道該class的大小，但instance需要

4. 使用`typedef struct classname structname`來包裹class

ex:
```cpp 
typedef struct Shape Shape;
```
5. 在C code操作cpp物件請使用設計的api.

6. 將lib和execute做link時，正常情況要使用g++編譯器，但專案包袱太大時，gcc也可以加上 -lstdc++來編譯cpp code

7. 使用share lib編譯的話，執行期要加上LD_LIBRARY_PATH 靜態庫就不用
ex:
```sh
export LD_LIBRARY_PATH = LD_LIBRARY_PATH:lib的位置
```
