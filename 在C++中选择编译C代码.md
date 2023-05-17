```c++
正常开发.h 中的代码格式(重要)(强调了兼容性)(这段代码可以使用C++编译器来执行)
  #pragma once   //防止头文件重复包含(也可以替换 #ifndef xx #define xx) 
  #ifdef __cplusplus   //告诉编译器这段代码用C语言编译而不是C++的,(可以用c++的编译器)
          // 是cpp中自定义的一个宏,而不是我们自己写的,最主要是兼容C++,可以使用g++命令
          // 如果是 C++ 编译器,按C标准编译,(两个下横线) .如果定义了则向下进行
         
  extern "C"   //而这一部分就是告诉编译器，如果定义了__cplusplus(即如果是cpp文件，
          //   extern "C"{ //因为cpp文件默认定义了该宏),则采用C语言方式进行编译.

  {     // 记住这个大括号位置

  #endif      // 结束上一个 __cplusplus  的声明  ,但是上面有个括号 ,与最近的做匹配

   //  这里写真正要写的东西 , 函数声明,变量声明之类的,是C类型的
  .......

  #ifdef __cplusplus    // 这段代码 只是为了声明下面的括号

  }     // 这是对应上面那个大括号

  #endif   //这个只是照顾这个 大括号
```

### extern "C"

- 被 extern 限定的函数或变量是 extern 类型的
- 被 `extern "C"` 修饰的变量和函数是按照 C 语言方式编译和链接的

`extern "C"` 的作用是让 C++ 编译器将 `extern "C"` 声明的代码当作 C 语言代码处理，可以避免 C++ 因符号修饰导致代码不能和C语言库中的符号进行链接的问题。

extern "C" 使用

```cpp
#ifdef __cplusplus
extern "C" {
#endif

void *memset(void *, int, size_t);

#ifdef __cplusplus
}
#endif
```
