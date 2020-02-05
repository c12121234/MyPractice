# QtConcurrent::blockingMapped

1. 先來看看function長怎樣


| function        | 樣式           |
| ------------- |-------------|
| `QtConcurrent::blockingMapped`       | OutputSequence **QtConcurrent::blockingMapped**(const InputSequence &sequence, MapFunctor function)     | 
|         | Sequence **QtConcurrent::blockingMapped**(Iterator begin, Iterator end, MapFunctor function)     |

當MapFunctor不為return void時使用QtConcurrent::blockingMapped，反之則是QtConcurrent::blockingMap

所有參數都和BlockingMapped一樣。

2. 注意點

InputSequence和Iterator都屬於Qt framework內的class，因此無法和std標準庫那些container交互使用，乖乖用QList吧


