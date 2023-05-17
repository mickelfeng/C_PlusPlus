### C 实现 C++ 类

C 实现 C++ 的面向对象特性（封装、继承、多态）

- 封装：使用函数指针把属性与方法封装到结构体中
- 继承：结构体嵌套
- 多态：父类与子类方法的函数指针不同

```c
#include <stdio.h>

// The top-level class.

typedef struct sCommClass {
    int (*open)(struct sCommClass *self, char *fspec);
} tCommClass;


// Function for the TCP 'class'.

static int tcpOpen (tCommClass *tcp, char *fspec) {
    printf ("Opening TCP: %s\n", fspec);
    return 0;
}
static int tcpInit (tCommClass *tcp) {
    tcp->open = &tcpOpen;
    return 0;
}


// Function for the HTTP 'class'.

static int httpOpen (tCommClass *http, char *fspec) {
    printf ("Opening HTTP: %s\n", fspec);
    return 0;
}
static int httpInit (tCommClass *http) {
    http->open = &httpOpen;
    return 0;
}

// Test program.

int main (void) {
    int status;
    tCommClass commTcp, commHttp;

    // Same 'base' class but initialised to different sub-classes.

    tcpInit (&commTcp);
    httpInit (&commHttp);

    // Called in exactly the same manner.

    status = (commTcp.open)(&commTcp, "bigiron.box.com:5000");
    status = (commHttp.open)(&commHttp, "http://www.microsoft.com");

    return 0;
}

```

```c
输出如下：
Opening TCP: bigiron.box.com:5000
Opening HTTP: http://www.microsoft.com
```







