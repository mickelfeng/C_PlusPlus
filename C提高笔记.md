零散笔记:善用查找
`gcc -m64 file.h      // 编译后是64位程序`

``#define _CRT_SECURE_NO_WARNINGS         // win vs`

接口的封装和设计(功能的抽象和封装)
  接口api的使用能力 (要会用别的人写的接口)
  接口api的查找能力 (要找到手册,linux用man,头文件,函数名字.功能,参数,返回值)
  接口api的实现能力 (要会写)

建立正确程序运行内存分布图
   内存四区模型  (很重要)
   函数调用模型  (比如递归)

CS:客户端服务器   (安全不灵活)
BS:浏览器和服务器 (灵活但不安全)


术语: 打桩  (就是先写函数之类的声明放在那里,函数体并不实现,能够编译通过)

```c
#if 0  
#endif    //这两个很好用  可以用来阶段测试代码.中间的代码是不会预处理和编译的

system("");    // pause 暂停;   cls 清屏;   

sscanf(); 和 sprintf(); 在程序中使用的特别多,因为有正则表达式,所以需要的时候去查找就好了.
```

内存出错误一般有两种情况:
    1: 
    2: 
    
内存泄漏解决方案:(每个平台有会有检测工具)
    vs方案:还是要写代码,检测内存,然后打开 项目->属性->c/c++ ->预处理器-> 添加预处理器定义

   **就算在检测也不如写代码的时候多多注意,多多留意.写好代码.**





程序中很容易出现bug,但是经常把各个细节运行状况存入到日志文件中就很容易来排查错误了.(最好写个接口)

```c
#define FILENAME "./debug.log"     //这个宏定义代表在当前目录的一个文件 debug.log 日志

 
经常用来调试BUG的宏定义:
__FILE__   // 输出文件位置 %s
__LINE__   // 输出调用这个宏 的行数
```



## 错误日志的一些格式和包含的内容:

文件名`__FILE__`,文件行号`__LINE__`,
以及 错误级别:  

0. 没有日志       // 没问题;
1. dubug 级别     // 级别最低，可以随意的使用于任何觉得有利于在调试时更详细的了解系统运行状态的东西;
2. info级别       // 重要，输出信息：用来反馈系统的当前状态给最终用户的；
3. warning 级别   // 警告, 可修复，系统可继续运行下去；
4. err 级别       // 错误,可修复性，但无法确定系统会正常的工作下去;
5. fatal级别      // 严重错误, 相当严重，可以肯定这种错误已经无法修复，并且如果系统继续运行下去的话后果严重。

```c
//实际例子:
// log.h  

#ifndef _ITCAST_LOG_H_
#define _ITCAST_LOG_H_
 
/*
#define IC_NO_LOG_LEVEL			0
#define IC_DEBUG_LEVEL			1
#define IC_INFO_LEVEL			2
#define IC_WARNING_LEVEL		3
#define IC_ERROR_LEVEL			4
#define IC_FATAL_LEVEL			5
---------------------------------
                          
const char *file：文件名称
int line：文件行号
int level：错误级别
0 -- 没有日志
1 -- debug级别
2 -- info级别
3 -- warning级别
4 -- err级别
5 -- fatal级别
int status：错误码
const char *fmt：可变参数
*/
/************************************************************************/
//实际使用的Level
extern int  LogLevel[6];
void ITCAST_LOG(const char *file, int line, int level, int status, const char *fmt, ...);

--------------------- 

//log.c 的实现 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 我修改过,也可能不完美,需要再次修改!!!
#define _CRT_SECURE_NO_WARNINGS
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "ItcastLog.h"
 
#define ITCAST_DEBUG_FILE_	"socketclient.log"
#define ITCAST_MAX_STRING_LEN 		10240
 
//Level类别
#define IC_NO_LOG_LEVEL			0
#define IC_DEBUG_LEVEL			1
#define IC_INFO_LEVEL			2
#define IC_WARNING_LEVEL		3
#define IC_ERROR_LEVEL			4
#define IC_FATAL_LEVEL			5
 
int  LogLevel[6] = { IC_NO_LOG_LEVEL, IC_DEBUG_LEVEL, IC_INFO_LEVEL, IC_WARNING_LEVEL, IC_ERROR_LEVEL,
                        IC_FATAL_LEVEL };
 
//Level的名称
char ICLevelName[6][10] = { "NOLOG", "DEBUG", "INFO", "WARNING", "ERROR" ,"FATAL"};
 
static int ITCAST_Error_GetCurTime(char* strTime)
{
	struct tm*		tmTime = NULL;
	size_t			timeLen = 0;
	time_t			tTime = 0;
 
	tTime = time(NULL);
	tmTime = localtime(&tTime);
	//timeLen = strftime(strTime, 33, "%Y(Y)%m(M)%d(D)%H(H)%M(M)%S(S)", tmTime);
	timeLen = strftime(strTime, 33, "%Y.%m.%d %H:%M:%S", tmTime);
 
	return timeLen;
}
 
static int ITCAST_Error_OpenFile(int* pf)
{
	char	fileName[1024];
 
	memset(fileName, 0, sizeof(fileName));
#ifdef WIN32
	sprintf(fileName, "c:\\debuglog\\%s", ITCAST_DEBUG_FILE_);//log文件路径
#else
	sprintf(fileName, "%s/log/%s", getenv("HOME"), ITCAST_DEBUG_FILE_);
#endif
 
	*pf = open(fileName, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (*pf < 0)
	{
		return -1;
	}
 
	return 0;
}
 
static void ITCAST_Error_Core(const char *file, int line, int level, int status, const char *fmt, va_list args)
{
	char str[ITCAST_MAX_STRING_LEN];
	int	 strLen = 0;
	char tmpStr[64];
	int	 tmpStrLen = 0;
	int  pf = 0;
 
	//初始化
	memset(str, 0, ITCAST_MAX_STRING_LEN);
	memset(tmpStr, 0, 64);
 
	//加入LOG时间
	tmpStrLen = ITCAST_Error_GetCurTime(tmpStr);
	tmpStrLen = sprintf(str, "[%s] ", tmpStr);
	strLen = tmpStrLen;
 
	//加入LOG等级
	tmpStrLen = sprintf(str + strLen, "[%s] ", ICLevelName[level]);
	strLen += tmpStrLen;
 
	//加入LOG状态
	if (status != 0)
	{
		tmpStrLen = sprintf(str + strLen, "[ERRNO is %d] ", status);
	}
	else
	{
		tmpStrLen = sprintf(str + strLen, "[SUCCESS] ");
	}
	strLen += tmpStrLen;
 
	//加入LOG信息
	tmpStrLen = vsprintf(str + strLen, fmt, args);
	strLen += tmpStrLen;
 
	//加入LOG发生文件
	tmpStrLen = sprintf(str + strLen, " [%s]", file);
	strLen += tmpStrLen;
 
	//加入LOG发生行数
	tmpStrLen = sprintf(str + strLen, " [%d]\n", line);
	strLen += tmpStrLen;
 
	//打开LOG文件
	if (ITCAST_Error_OpenFile(&pf))
	{
		return;
	}
 
	//写入LOG文件
	write(pf, str, strLen);
	//IC_Log_Error_WriteFile(str);
 
	//关闭文件
	close(pf);
 
	return;
}
 
 
void ITCAST_LOG(const char *file, int line, int level, int status, const char *fmt, ...)
{
	va_list args;
 
	//判断是否需要写LOG
	//	if(level!=IC_DEBUG_LEVEL && level!=IC_INFO_LEVEL && level!=IC_WARNING_LEVEL && level!=IC_ERROR_LEVEL)
	if (level == IC_NO_LOG_LEVEL)
	{
		return;
	}
 
	//调用核心的写LOG函数
	va_start(args, fmt);
	ITCAST_Error_Core(file, line, level, status, fmt, args);
	va_end(args);
 
	return;
}
 
int main()
{
	int rv = -3;
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], rv, "func cltSocketRev2: (buflen == NULL) [%d]", rv);
	system("pause");
}

//结束
```

### 日志格式:

```c
总结起来， 错误日志格式可以为：
  log.error(“[接口名或操作名] [Some Error Msg] happens. [params] [Probably Because]. [Probably need to do].”);

log.error(String.format(“[接口名或操作名] [Some Error Msg] happens. [%s]. [Probably Because]. [Probably need to do].”, params));
```



## 反转链表和宏

```c
    宏定义:
    #define    ID
    #undef     ID   // ID宏定义不生效
    
    
条件编译:
    #ifndef    ID   // 如果没定义 ID 则进入
    #ifdef     ID   // 前面如果定义了 ID 则进入
    #else           // 如果没定义则运行这里
    #endif          // 正常#if结束语局
    
    #define MAX2(a,b) (a)>(b)? (a): (b)           //宏定义两个数比较大小(经常出现在面试题,注意括号)
    #define MAX3(a,b,c)  (a) >(MAX2(a,c)) ? (a) : (MAX2(b,c))     //只是替换不存在多次运行.三个数比较大小
    
    #ifdef __cplusplus     // 条件编译  使c代码可以使用 c++编译器来执行和编译
    extern "C";            // 如果成功则调用c++编译器的 c 编译器部分,如果没有那就说明用的是c编译器
    {
    #endif
    ......
    
    #ifdef __cplusplus
    {
    #endif                 //条件编译结束  , 一般用在头文件中的代码想用c 编译器的时候
    
    
    #ifndef    ID    //  这是才是常用的
    #else
    #endif
    
    
链表:
    (有头链表)(数据大于5个)
    把一个双向链表写入文件,可以读取到内存,也可以排序然后存入文件,按照顺序读取,可以修改删除翻转插入
    可以打印全部数据,可以任意添加节点,操纵文件.


    
双向链表反转(精髓)
typedef struct Node
{
    num data;

    struct Node * last;
    struct Node * next
}Node;

typedef struct R_Node
{
    num data;

    struct Node * next;
    struct Node * last;
}R_Node;

 // 使用内存模型进行反转.主要的一步就是强制类型转换
 
Node * p = (Node*)malloc(sizeof(Node));
R_Node * rp = (R_Node*)malloc(sizeof(R_Node));

rp = (R_Node*)p;

// 访问rp就会得到反转的链表   
// 指针是不会改变大小的(都是固定内存)

假设ElemType是int
那么struct node在内存中就是
+----+----+----+
| data  | perv | next |
+----+----+----+
而struct reverse_node在内存中就是

那么struct node在内存中就是
+----+----+----+
| data  | next | perv |
+----+----+----+


```





## 动态库封装和使用

```c
动态库封装 (不可以出现中文路径名称)
    不需要主函数,只需要集团口头文件和接口实现文件就好了.
 
    每个平台的封装动态库都是不一样的,要详细查阅.
 
 
 
 windows::::: 这个平台会生成 .dll 文件
 
    // windows 的 vs 平台下  使用__declspec(dllexport) 这个 宏 来实现动态库(死规定)
    // 需要在 项目属性中->项目默认值->配置类型:(动态库dll) , 目标拓展名:(dll).
    // 这样才能生产成功
    
__declspec(dllexport)
void fun(void)
{
    std::cout << std::endl << "fun \n" << std::endl;
}
    
    // 直接把 宏 添加到 函数实现 开头就好了.然后选择编译就可以 ,会生成dll
    // 可以没有头文件,但是还是得写,然后详细记录后给提供给用户
    
 生成后会出现 .dll 和 .lib 这两个主要的文件, 
   .dll 是程序运行时候需要(大部分应用都是这样的),编译的时候可以不用
   .lib 是编译的时候需要(要放在同一个文件夹内,运行还是得要dll),里面记录了 dll 内包含的函数.
   .h 的头文件也要提供,就是告诉这个动态库里面都有什么函数,给用户提供一个声明.
 
使用:
    首先创建工程,然后 .lib 和 .h 文件放在工程 main.c 的文件同目录下,
    然后把 .h 添加到工程头文件中,
    接着打开 项目属性 -> 配置属性 -> 链接器 -> 输入 -> 附加依赖项:(添加 .lib文件名).
    这样就可以通过编译,但是运行的时候还是需要把.dll放入到工程文件内.
    但是单独的运行 .exe 则要把 .dll 两项都放在一起,才可以正常运行.    
    
```

```c
 Linux::::::: 这个平台下生成的是 .so  文件

 
 Linux动态库生成与使用指南
相关阅读: Linux静态库生成指南

Linux下动态库文件的文件名形如 libxxx.so，其中so是 Shared Object 的缩写，即可以共享的目标文件。

在链接动态库生成可执行文件时，并不会把动态库的代码复制到执行文件中，而是在执行文件中记录对动态库的引用。

程序执行时，再去加载动态库文件。如果动态库已经加载，则不必重复加载，从而能节省内存空间。

Linux下生成和使用动态库的步骤如下：

编写源文件。
1, 将一个或几个源文件编译链接，生成共享库。
2, 通过 -L<path> -lxxx 的gcc选项链接生成的libxxx.so。
3, 把libxxx.so放入链接库的标准路径，或指定 LD_LIBRARY_PATH，才能运行链接了libxxx.so的程序。
4, 下面通过实例详细讲解。

编写源文件
建立一个源文件： max.c，代码如下：
----------------------------------------------
int max(int n1, int n2, int n3)
{
    int max_num = n1;
    max_num = max_num < n2? n2: max_num;
    max_num = max_num < n3? n3: max_num;
    return max_num;
}
-----------------------------------------------
编译生成共享库：

gcc -fPIC -shared -o libmax.so max.c
 我们会得到libmax.so。

 实际上上述过程分为编译和链接两步， -fPIC是编译选项，PIC是 Position Independent Code 的缩写，
    表示要生成位置无关的代码，这是动态库需要的特性； -shared是链接选项，告诉gcc生成动态库而不是可执行文件。

 上述的一行命令等同于：

 gcc -c -fPIC max.c
 gcc -shared -o libmax.so max.o
 为动态库编写接口文件
 为了让用户知道我们的动态库中有哪些接口可用，我们需要编写对应的头文件。
 
 
建立 max.h ，输入以下代码：
---------------------------------
#ifndef __MAX_H__
#define __MAX_H__

int max(int n1, int n2, int n3);

#endif
----------------------------------

测试，链接动态库生成可执行文件
建立一个使用max函数的test.c，代码如下：
------------------------------------------------------------------
#include <stdio.h>
#include "max.h"

int main(int argc, char *argv[])
{
    int a = 10, b = -2, c = 100;
    printf("max among 10, -2 and 100 is %d.\n", max(a, b, c));
    return 0;
}
-------------------------------------------------------------------
gcc test.c -L. -lmax 生成a.out，其中-lmax表示要链接libmax.so。
-L.表示搜索要链接的库文件时包含当前路径。

注意，如果同一目录下同时存在同名的动态库和静态库，比如 libmax.so 和 libmax.a 都在当前路径下，
则gcc会优先链接动态库。

运行
运行 ./a.out 会得到以下的错误提示。

./a.out: error while loading shared libraries: libmax.so: cannot open shared object file: No 
such file or directory

找不到libmax.so，原来Linux是通过 /etc/ld.so.cache 文件搜寻要链接的动态库的。
而 /etc/ld.so.cache 是 ldconfig 程序读取 /etc/ld.so.conf 文件生成的。
（注意， /etc/ld.so.conf 中并不必包含 /lib 和 /usr/lib，ldconfig程序会自动搜索这两个目录）

如果我们把 libmax.so 所在的路径添加到 /etc/ld.so.conf 中，再以root权限运行 ldconfig 程序，
更新 /etc/ld.so.cache ，a.out运行时，就可以找到 libmax.so。

但作为一个简单的测试例子，让我们改动系统的东西，似乎不太合适。
还有另一种简单的方法，就是为a.out指定 LD_LIBRARY_PATH。

LD_LIBRARY_PATH=. ./a.out
程序就能正常运行了。LD_LIBRARY_PATH=. 是告诉 a.out，先在当前路径寻找链接的动态库。

对于elf格式的可执行程序，是由ld-linux.so*来完成的，它先后搜索elf文件的 DT_RPATH 段, 
环境变量 LD_LIBRARY_PATH, /etc/ld.so.cache文件列表, /lib/,/usr/lib目录, 找到库文件后将其载入内存.


makefile让工作自动化
编写makefile，内容如下：
----------------------------------
.PHONY: build test clean

build: libmax.so

libmax.so: max.o
    gcc -o $@  -shared $<

max.o: max.c
    gcc -c -fPIC $<

test: a.out

a.out: test.c libmax.so
    gcc test.c -L. -lmax
    LD_LIBRARY_PATH=. ./a.out

clean:
    rm -f *.o *.so a.out
----------------------------------
make build就会生成libmax.so， make test就会生成a.out并执行，make clean会清理编译和测试结果。
 
 
 
 
 
 
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
UNIX_MAC:::::: 这个平台下生成的是  so 和 dylib 文件
//  创建实例
// 通过命令行来实现,需要gcc, 而不是xcode, 一般来说其他的ide 也差不多

 //下面是 add.cpp

int add(int a, int b)
{
    return a + b;
}


// 下面hi main.cpp

#include<stdio.h>
int add(int a, int b);
int main()
{
    printf("%d\n", add(1,2));
    return 0;
}

//编译成静态库所需要的命令和流程

$ gcc -c -o add.o add.cpp
$ ar -r libadd.a add.o
$ gcc -o main -L. -ladd main.cpp
$ ./main

//编译成动态库所需要的命令和流程

$ gcc -shared -fPIC -o libadd.so add.cpp
$ gcc -o main -L. -ladd main.cpp
$ ./main

我对动态库的一个理解是： 
第一次编译时需要libadd.so参与编译 
而第一次编完后，如果main.cpp不改动，add.cpp改动，那么不需要重新编译整个main，只需要重新编译libadd.so，
替换原来的libadd.so即可运行main。
 
.备注 
鉴于链接静态库和动态库的命令是一样的，系统会优先链接动态库。

```





正常开发.h 中的代码格式(重要)(强调了兼容性)(这段代码可以使用C++编译器来执行)

```c
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







如何看懂带算法的程序
  1, 流程
  2, 每个语句功能
  3, 试数
  4, 调试
  5, 模仿 改
  6, 不看代码写

如果数组作为函数形参,数组形参退化为指针.(面试经常考)
   例如 void arra( int arr[10]);   //等价于下面两项,其中的10这个参数不生效 
        void arra(int arr[]);  或者 void arra(int* arr)

