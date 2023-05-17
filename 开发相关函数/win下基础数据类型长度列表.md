> `<assert.h>`

**断言不会影响性能**

**断言只会在 debug 模式下有效.**



## 断言

执行时报错.

```c++
#include <assert.h>   //断言, 调试使用的

int main(void){
  char* p = nullptr;
  assert(nullptr == p);  //断言, p必须等于nullptr 否则就运行报错. 如果p等于了nullptr 那么就不会报错.
}
```



## 静态断言

编译时报错

```c++
#include <assert.h>   //断言, 调试使用的

int main(void){
  char* p = nullptr;
  static_assert(nullptr,p);  //断言, p必须等于nullptr 否则就编译报错. 如果p等于了nullptr 那么就不会报错.
}
```

