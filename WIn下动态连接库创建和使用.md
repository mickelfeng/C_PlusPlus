```c++

	//单字节类型 -128 到 127,  或者  0 - 255  
	__int8  D_int8;
	CHAR    D_char;

	//无符号单字节 0 - 255  , ascii
	BYTE    D_BYTE;
	UCHAR   D_UCHAR;   // unsigned char 

	// 双字节 ,  unicode
	WCHAR     D_CHAR;
	wchar_t   D_wchar_t;

	//自适应 字节,  
	TCHAR  D_TCHAR; // 字符集为 多字节时为 char, 字符集 unicode 时 为 wchar_t  两字节	
	DWORD_PTR  D_DWORD_PTR;  // x86时 为unsigned long,  x64时为  unsigned __int64


	/*短整形, 占用 2 个字节 -32768 到 32767  */
	SHORT    D_SHORT;
	__int16  D_int16;
	 
   //无符号整形 0-65534     , 2字节
	USHORT D_USHORT;
	unsigned __int16   D_unsigned__int16;
	WORD     D_WORD;


	// 长整型-2147483648 到 2147483647  , 4字节
	__int32 D__int32;
	int     D_int;
	long    D_long;

	// 无符号长整型 0 到 4294967295  , 4字节 , 区别 x86 和 x64
	unsigned int     D_unsigned_int;
	unsigned long    D_unsigned_long;
	unsigned __int32  D_unsigned_int32;
	DWORD      D_DWORD;   // unsigned long
	DWORD32    D_DWORD32;   // unsigned int
	size_t     D_size_t;    // x86   unsigned int,  x64  unsigned __int64 
	ULONG      D_ULONG;     // unsigned long


	// 超长整形 , -9223372036854775808 到 9223372036854775807, 8字节
	long long   D_long_long;
	__int64     D_int64;
	LONG64      D_long64;


	// 0 到 18446744073709551615
	DWORD64    D_DOWRD64;  // unsigned __int6
	ULONG64    D_ULONG64;  // unsigned __int6
	unsigned  long long  D_longlong;
	unsigned  __int64    D_int64;


	//浮点数
	FLOAT  D_FLOAT;   // float
	DOUBLE D_DOUBLE;  // double

```

