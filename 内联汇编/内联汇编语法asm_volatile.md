- [拓展内联汇编](#拓展内联汇编)
- [Volatile作用](#Volatile作用)
- [Mac下的内联汇编](#Mac下的内联汇编)



## 拓展内联汇编

拓展内联汇编使用的是 AT&T 汇编格式。

**约束的作用： 就是让C代码的操作数变成汇编代码能够使用的操作数，就是映射过去， 所有的约束形式都是给汇编用的。**

寄存器约束和内存约束表示:

- 寄存器约束：
  - a :表示寄存器 eax、ax、al
  - b :表示寄存器 ebx、bx、bl
  - c :表示寄存器 ecx、cx、cl
  - D :表示寄存器 edi、di
  - S :表示寄存器 esi、si
  - q :表示任意这4个寄存器之一 eax、ebx、ecx、edx
  - r :表示任意这6个寄存器之一 eax、ebx、ecx、edx、esi、edi
  - g :表示可以放到任意地点（寄存器和内存）。比r多了个内存。
  - A :把 eax 和 edx 组合成 64 位整数
  - f :表示第1个浮点寄存器
  - u :表示第2个浮点寄存器
- 内存约束：
  - m :表示操作数可以使用任意一种内存形式
  - o :操作数为内存变量，但访问他是通过偏移量的形式方法， 包括偏移地址的汇编格式。
    - AT&T汇编内存寻址格式:  `基地址 +（偏移地址 ,  索引值, 长度值）`，计算方式：`基地址+偏移地址+索引值 * 长度值`
      - 基地址： 可以是整数、变量名、可正可负
      - 偏移地址：必须是8个通用寄存器之一
      - 索引值：必须是8个通用寄存器之一
      - 长度值：只能是 1、2、4、8
- 立即数约束：
  - i :表示操作数为整数立即数
  - F :表示操作数为浮点数立即数
  - I J N O X :分别表示 I 0~31、J 0~63、 N 0~255、X 0~32 之间的立即数。
  - X :表示操作数为任何类型立即数
- 只用在输出参数的约束： 这些约束可同时出现
  -  =  :表示操作数是只写的。
  -  `+` :表示操作数和可读可写的。  告诉gcc 所约束的寄存器和内存 先被读入、再被写入。
  -  & :表示操作数独占这个寄存器。 (有多个& 操作数的时候，需要紧挨着)
  -  % : 该操作数可以和下一个输入操作数互换。

一般拓展内联汇编格式: `asm volatile ("汇编代码" : 输出约束(C变量) : 输入约束(C变量) : 需要gcc保护的寄存器)`

拓展汇编用两个百分号来表示寄存器。  (`%%ebx 表示寄存器 ebx`)



```c
// 范例 使用寄存器约束
int in_a =1, in_b = 2, out_sum;
asm volatile ("addl %%ebx, %%eax" : "=a"(out_sum) : "a"(in_a),"b"(in_b));
printf("sum is %d\n", out_sum );		// 会输出 sum is 3
// 说明： 相当于做了个加法
 -	: 冒号是分隔符。语法规定的。
 -	"addl %%ebx, %%eax"  为汇编语句， %%ebx 表示寄存器 ebx, 拓展汇编用两个百分号来表示寄存器。
 -  "=a"(out_sum)  表示汇编的输出结果放到 eax寄存器中，也就是 out_sum 这个变量里。 (= 等号起到的作用)。
 -  "a"(in_a),"b"(in_b)  表示两个输入参数。 in_a变量放到 eax寄存器中, in_b变量放到 ebx寄存器中。
```

```c++
// 范例 使用内存约束 m
#include <stdio.h>
void main() 
{
	int in_a =1, in_b = 2;
	printf("in_a is %d\n", in_a );  // 输出 in_a is 1
	asm ("movb %b0, %1" : : "a"(in_a),"m"(in_b));  // 编译后代码为 movb %al, -16(%ebp)
	printf("in_b now is %d\n", in_b );		// 输出 in_b now is 1
}
// 说明 ，只有两个输入参数，没有输出
 - "movb %b0, %1"   编译后代码为 movb %al, -16(%ebp)
   		-  "a"(in_a)  in_a变量放到 eax寄存器中， 变为 %al   (%b0) 
   				- %b0     b 表示使用32位数据的低8位，也就是寄存器 al， 而0 表示 对相应操作数的引用(就是参数)
   		-  "m"(in_b)  in_b变量的指针作为内联代码的操作数放到内存中(就是指针)， 变为 -16(%ebp)   (%1) 
   				- %1      表示对相应操作数的引用，就是第几个参数，从%0开始， in_a就是%0， in_b就是%1 
```

```c
// 范例 使用序号占位符和指定操作数宽度。
void main() 
{
	int in_a =0x12345678, in_b = 0;

	asm ("movw %w1, %w0" : "=m"(in_b) : "a"(in_a));	// 翻译后为： movw %ax, -32(%ebp)
	printf("movw in_b is 0x%x \n", in_b );		// 输出： movw in_b is 0x5678 
	in_b = 0;

	asm ("movb %b1, %b0" : "=m"(in_b) : "a"(in_a));	// 翻译后为： movb %al, -32(%ebp)
	printf("low byte  in_b is 0x%x \n", in_b );		// 输出： low byte  in_b is 0x78 
	in_b = 0;

	asm ("movb %h1, %h0" : "=m"(in_b) : "a"(in_a));	// 翻译后为： movb %ah, -32(%ebp)
	printf("high byte  in_b is 0x%x \n", in_b );		// 输出： high byte  in_b is 0x56 
	in_b = 0;
  
  asm ("movl %1, %0" : "=m"(in_b) : "a"(in_a)); // 翻译后为： movl %eax, -32(%ebp)
	printf("l 4 byte  in_b is 0x%x \n", in_b );		// 输出：	high byte  in_b is 0x12345678 
	in_b = 0;
}

说明：
  - h 代表 ah、bh 等， ax、bx 的高1字节寄存器。 al和bl是低一字节寄存器。
  - w 代表 ax、bx 等 2字节长度寄存器。
  - b 代表 al、bl 等， ax、bx 的低1字节寄存器。
  - k 代表 4 字节，eax、ebx 等4字节寄存器。
```

```c
// 范例 使用名称占位符
void main ()
{
	int in_a = 18, in_b = 3, out =0;
	asm("divb %[divisor]; movb %%al, %[result]"  
		 : [result]"=m"(out) 
		 : "a"(in_a), [divisor]"m"(in_b)
		 );	   // 翻译后：  divb -20(%ebp); movb %al, -16(%ebp) ；8位除法商在al，余数在ah，被除数是ax
	printf("result is %d\n",out );
}
说明
  - result ：该名称被带入到汇编语句中， 被替换成具体的数值。 %[名称]
```

```c
// 范例  显式告诉gcc  那些寄存器在内联汇编中 会被修改
int ret_value = 0;
asm ("movl %%eax, %0; movl %%eax, %%ebx" : "=m"(ret_value) :  : "ebx, eax,memory,cc");
说明：
	- 最后的 "ebx,eax,memory,cc" 代表内联汇编会修改 ebx这和ebx这个寄存器, 
  		memory代表会修改内存， cc 代表会修改 eflags 寄存器
```





**volatile ——定义类型为易变**

```c
unsigned long low, high;
asm volatile ( "rdtsc" : "=a" (low), "=d" (high) );

```

***const volatile 对象***——类型为 const-volatile-限定的 对象，const volatile 对象的非 mutable 子对象，volatile 对象的 const 子对象，或 const 对象的非 mutable volatile 子对象。同时表现为 const 对象与 volatile 对象。

## Volatile作用

有些变量是用**volatile** 关键字声明的。 当两个线程都要用到某一个变量且该变量的值会被改变时，应该用**volatile** 声明，该关键字的**作用**是防止优化编译器把变量从内存装入CPU 寄存器中。



```cpp
#include <iostream>
 
extern "C" int func();
// func 的定义以汇编语言书写
// 原始字符串字面量可以很有用
asm(R"(
.globl func
    .type func, @function
    func:
    .cfi_startproc
    movl $7, %eax
    ret
    .cfi_endproc
)");
 
int main()
{
    int n = func();
    // 扩展内联汇编
    asm ("leal (%0,%0,4),%0"
         : "=r" (n)
         : "0" (n));
    std::cout << "7*5 = " << n << std::endl; // 冲刷缓冲区是有意的
 
    // 标准内联汇编
    asm ("movq $60, %rax\n\t" // Linux 上的“退出”的系统调用序号
         "movq $2,  %rdi\n\t" // 此程序返回 2
         "syscall");
}
输出：

7*5 = 35

```





```assembly
+------------------------------+------------------------------------+
|       Intel Code             |      AT&T Code                     |
+------------------------------+------------------------------------+
| mov     eax,1                |  movl    $1,%eax                   |   
| mov     ebx,0ffh             |  movl    $0xff,%ebx                |   
| int     80h                  |  int     $0x80                     |   
| mov     ebx, eax             |  movl    %eax, %ebx                |
| mov     eax,[ecx]            |  movl    (%ecx),%eax               |
| mov     eax,[ebx+3]          |  movl    3(%ebx),%eax              | 
| mov     eax,[ebx+20h]        |  movl    0x20(%ebx),%eax           |
| add     eax,[ebx+ecx*2h]     |  addl    (%ebx,%ecx,0x2),%eax      |
| lea     eax,[ebx+ecx]        |  leal    (%ebx,%ecx),%eax          |
| sub     eax,[ebx+ecx*4h-20h] |  subl    -0x20(%ebx,%ecx,0x4),%eax |
+------------------------------+------------------------------------+


+---+--------------------+
| r |    Register(s)     |
+---+--------------------+
| a |   %eax, %ax, %al   |
| b |   %ebx, %bx, %bl   |
| c |   %ecx, %cx, %cl   |
| d |   %edx, %dx, %dl   |
| S |   %esi, %si        |
| D |   %edi, %di        |
+---+--------------------+


Some other constraints used are:

"m" : A memory operand is allowed, with any kind of address that the machine supports in general.
"o" : A memory operand is allowed, but only if the address is offsettable. ie, adding a small offset to the address gives a valid address.
"V" : A memory operand that is not offsettable. In other words, anything that would fit the `m’ constraint but not the `o’constraint.
"i" : An immediate integer operand (one with constant value) is allowed. This includes symbolic constants whose values will be known only at assembly time.
"n" : An immediate integer operand with a known numeric value is allowed. Many systems cannot support assembly-time constants for operands less than a word wide. Constraints for these operands should use ’n’ rather than ’i’.
"g" : Any register, memory or immediate integer operand is allowed, except for registers that are not general registers.
Following constraints are x86 specific.

"r" : Register operand constraint, look table given above.
"q" : Registers a, b, c or d.
"I" : Constant in range 0 to 31 (for 32-bit shifts).
"J" : Constant in range 0 to 63 (for 64-bit shifts).
"K" : 0xff.
"L" : 0xffff.
"M" : 0, 1, 2, or 3 (shifts for lea instruction).
"N" : Constant in range 0 to 255 (for out instruction).
"f" : Floating point register
"t" : First (top of stack) floating point register
"u" : Second floating point register
"A" : Specifies the `a’ or `d’ registers. This is primarily useful for 64-bit integer values intended to be returned with the `d’ register holding the most significant bits and the `a’ register holding the least significant bits.

```







```c
asm("movl %ecx %eax"); /* moves the contents of ecx to eax */
__asm__("movb %bh (%eax)"); /*moves the byte from bh to the memory pointed by eax */


 __asm__ ("movl %eax, %ebx\n\t"
          "movl $56, %esi\n\t"
          "movl %ecx, $label(%edx,%ebx,$4)\n\t"
          "movb %ah, (%ebx)");

asm ( assembler template 
     : output operands                  /* optional */
     : input operands                   /* optional */
     : list of clobbered registers      /* optional */
    );

int a=10, b;
asm ("movl %1, %%eax; \
     movl %%eax, %0;"
     :"=r"(b)        /* output */
     :"r"(a)         /* input */
     :"%eax"         /* clobbered register */
    );       





int main(void)
{
        int foo = 10, bar = 15;
        __asm__ __volatile__("addl  %%ebx,%%eax"
                             :"=a"(foo)
                             :"a"(foo), "b"(bar)
                             );
        printf("foo+bar=%d\n", foo);
        return 0;
}


```



## Mac下的内联汇编

```c
// 使用inline方式将函数在调用处强制展开，防止被hook和追踪符号
static __attribute__((always_inline)) void _tswitch() {
// 判断是否是ARM64处理器指令集
#ifdef __arm64__
    // volatile修饰符能够防止汇编指令被编译器忽略
    __asm__ __volatile__(
                         "mov x0, #31\n"
                         "mov x1, #0\n"
                         "mov x2, #0\n"
                         "mov x3, #0\n"
                         "mov x16, #26\n"
                         "svc #0x80\n"
                         );
#endif
}
```



