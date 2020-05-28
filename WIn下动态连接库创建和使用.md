## 创建

**使用 VS2019 的 Windows桌面向导项目来创建一个DLL文件即可**

具体可以看 [链接.md](链接.md)

## 使用



### Windows下 C++创建和使用(仅仅是C++)

```c++
#ifndef  __CPP_NET_100_DLL_H__
#define  __CPP_NET_100_DLL_H__

/* 下面这种方式 只可以让 Windows下的 C++ 的程序来使用, 不能跨语言和平台 */
/* _declspec(dllexport)   代表这个函数是导出的,表示提供给使用该动态库的程序使用的 */
 int _declspec(dllexport) Add(int a, int b) {
	return a + b;
}

int _declspec(dllexport) del(int a, int b) {
	return a - b;
}

#endif
```



### Windows 下 C++创建, 但其他编程语言都可以使用

```c++
#ifndef  __CPP_NET_100_DLL_H__
#define  __CPP_NET_100_DLL_H__

/*  extern "C"  按照C的规范和方式进行编译和导出,让外部可以使用 */
extern "C" {
	int _declspec(dllexport) Add(int a, int b) {
		return a + b;
	}

	int _declspec(dllexport) del(int a, int b) {
		return a - b;
	}

}

#endif
```

