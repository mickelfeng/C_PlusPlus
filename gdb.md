# GDB

## GDB

GUN 的调试器 GDB 提供了许多有用的特性, 支持机器级程序的运行时评估和分析.

### 命令以及效果

* **开始和停止**
  * run
    * **`运行程序 (在此给出命令行参数)`**
  * start
    * 运行并停在main函数上
  * ignore
    * 忽略某函数或文件
  * checkpoint
    * 设置书签
  * quit
    * **`退出GDB`**
  * kill
    * **`停止程序`**

* **断点**
  * break   multstore
    * **`在函数 multstore 入口处设置断点`**
  * break  \* 0x400540
    * **`在地址  0x400540 处 设置断点`**
  * delete 1
    * **`删除断点1`**
  * delete
    * **`删除所有断点`**

* **执行**
  * stepi
    * **`执行1条指令`**

  * stepi 4 
    * **`执行4条指令`**

  * nexti
    * **`类似于stepi ,但以函数调用为单位, 执行一个函数.`**

  * continue
    * **`继续执行`**

  * finish
    * **`运行到当前函数返回`**

  * skip 函数名

    * 跳过某个函数,   info skip   会获得列表

      * `<linespec>`是一个冒号分隔的列表，它可以包括文件名， 函数名。（filename:linenum, function:label, filename:function, label)

        示例如下：

        ```elixir
        (gdb) skip -rfu ^std::(allocator|basic_string)<.*>::~?\1 *\(
        #第一个命令忽略std::string的构造和解构函数
        
        (gdb) skip -rfu ^std::([a-zA-z0-9_]+)<.*>::~?\1 *\(
        #第二个命令忽略所有来自std namespace的函数的构造和解构函数
        ```

  * checkpoint

    * **gdb可以在程序执行的过程中保留快照(状态)信息, 从提示信息看来，其实每建立一个checkpoint，都会fork出一个子进程，所以每个checkpoint都有一个唯一的进程ID所对应着**
      *  info checkpoints
        * 查看所有的checkpoint，包括进程ID、代码地址和当时的行号或者符号。
      *  restart checkpoint-id
        * 恢复程序状态到checkpoint-id指明的checkpoint，所有的程序变量、寄存器、栈都会被还原到那个状态，同时gdb还会将时钟信息回退到那个点。恢复过程中程序的状态和系统的部分状态是支持的，比如文件指针等信息，但是写入文件的数据、传输到外部设备的数据都无法被回退
      * 

* **检查代码**

  * disas
    * **`反汇编当前函数`**
  * disas   multstore
    * **`反汇编函数  multstore`**
  * disas  0x400544
    * **`反汇编位于地址  0x400544 附近的函数,  一般是上5行 + 下5行`**
  * disas  0x400540, 0x40054d
    * **`反汇编制定地址范围内的代码`**
  * print   /x   $rip
    * **`以十六进制输出程序计数器的值`**
  * frame
    * **当前运行到的代码位置和函数**
  * list
    * 当前代码段列表

* **检查数据**
  * print  $rax
    * **`以十进制输出%rax 寄存器的内容`**
  * print  /x  $rax
    * **`以十六进制输出 %rax 寄存器的内容`**
  * print  /t  $rax
    * **`以二进制输出 %rax 寄存器的内容`**
  * print  0x100
    * **`输出 0x100 的十进制表示 ( 跟正在调试的程序没关系 )`**
  * print /x 555
    * **`输出 555 的十六进制表示 ( 跟正在调试的程序没关系 )`**
  * print  \*\(long\*\) 0x7fffffffe818
    * **`输出位于 0x7fffffffe818 的长整数`**
  * printf  \*\(long\*\) \($rsp +8 \)
    * **`输出位于地址 %rsp + 8 处的长整数`**
  * x/2g   0x7fffffffe818
    * **`检查从地址 0x7fffffffe818 开始的双(8字节)字`**
  * x/20b    multstore
    * **`检查函数 multstore 的前20个字节`**

* **有用的信息**
  * info  frame 
    * **`有关当前栈帧的信息`**
  * info  registers
    * **`所有寄存器的值`**
  * help
    * **`获取有关GDB 的信息`**

* **终端shell 命令**

  * shell 命令
  * ! 命令

* **命令搜索**

  * apropos  模糊的命令名




启动gdb的方法和参数

```shell
gdb program
gdb program core
gdb program
gdb --args gcc -O2 -c foo.c
gdb --silent


-symbol file
-s file

-exec file
-e file

-se file          #read symbol table from file file and use it as the executable file

-core file
-c file

-pid number
-p number

-command file
-x command

-eval-command command
-ex command         #execute a signal GDB command

-init-comamnd file
-ix file

-init-eval-command comand
-iex command

```









- [启动gdb](#启动gdb)
  - [几种方法](#几种方法)
  - [shell_command](#shell_command)
  - [log](#log)
- [使用帮助](#使用帮助)
  - [help](#help)
  - [apropos](#apropos)
- [运行](#运行)





**Stack（栈)**

当调试的程序暂停时，你首先想知道的是它停在了什么地方，以及它是怎样到达那里的。

调试的程序每调用一个函数，就会产生关于这个调用的相关信息。这些信息包括调用前的位置、传递的参数、以及被调用函数的局部变量。这些信息保存在一个名为栈帧（stack frame）的数据块中。栈帧是在内存中分配的成为“调用栈”（call stack）的一块区域。

当程序暂停的时候，gdb中一些检查栈的命令允许你查看这些所有的信息。

gdb和gdb命令会选择其中的一个栈帧作为“当前栈帧”。不管什么时候用gdb来显示程序中的变量的值，这个变量总是指当前帧中的变量。有一些特殊的gdb命令可以让你选择你感兴趣的帧。

被调试的程序暂停时，gdb自动选择当前程序在其中运行的帧，并对其作一简短描述，类似于frame命令。



**Frames（帧）**

调用栈是被在内存中分割成一些连续的相邻的数据块，它们被称为“栈帧”，简称“帧”。每个帧都包含有调用一个函数的相关数据，包括被调用函数的局部变量和被调用函数的地址等等。

当程序运行时，栈里只有一个帧，即main函数的帧，它被称为初始化帧或者最层的帧。每调用一个函数就会产生一个新的帧，当函数返回时，相应的帧就会被删除。如果函数是递归调用的，则可能产生很多针对调用这个函数的帧。每次实际调用一次这个函数，产生的帧被成为“最内层的帧”。这是所有帧里最新产生的。

在程序中，帧是用地址来标识的，每个帧都有很多个字节，每个字节都有自己的地址。每种计算机都有各自不同的约定来选择一个代表帧地址的字节。通常这个地址是记录在名为“帧指针”$FP(Frame Pointer Register)的一个寄存器里。

gdb将每个存在的栈帧赋予了一个数字，从0开始，编号为0的帧代表最内层的帧，编号为1的帧代表调用它的帧，以此类推。这些数字编号实际上并不存在于被调试的程序中，它们只是由gdb赋予的值，以便在gdb命令里可以方便地标识帧。

一些编译器提供了一种使程序不使用栈帧的编译方法（例如gcc编译器使用-fomit-frame-pointer选项时就可以产生不使用帧的函数）。 这只是偶尔用在大量的库函数调用时的一种方法，以便程序可以节省建立帧的时间。如果最内层的帧没有栈帧的话，gdb还是可以像往常一样认为它有一个单独的帧并标识为编号为0，以便正确地对函数调用链进行跟踪。但是gdb没有办法对其它的函数调用帧进行标识。

# 启动gdb

### 几种方法

```bash
gdb program
gdb program core
gdb program
gdb --args gcc -O2 -c foo.c
gdb --silent

参数:

-symbol file
-s file

-exec file
-e file

-se file          #read symbol table from file file and use it as the executable file

-core file
-c file

-pid number
-p number

-command file
-x command

-eval-command command
-ex command         #execute a signal GDB command

-init-comamnd file
-ix file

-init-eval-command comand
-iex command

-directory directory
-d directory            # add directory to the path to search for the source and scrip files
```

**上面的`gdb --args gcc -O2 -c foo.c`将调试gcc, 并把-O2 -c foo.c作为参数传递给gcc**



### shell_command

如果要执行shell comands, 可以用 shell 开头就行

```bash
shell command-string
!command-string
```

如果是make, 则可以直接输入`make make-args`



### log

如果你想把GDB命令输出到一个文件有，有几种方法控制

```bash
set logging on
set logging off
set logging file <filename>
set logging overwrite [on|off]     #默认会追加到logfile里
set logging redirect [on|off]        #默认GDB输出会在terminal和logfile里显示，用redirect让它只在logfile里显示
show logging
```



## 使用帮助

主要有两个命令

### help

如果知道命令名， 直接输入`help <command_name>`

### apropos

如果不记得命令名，可以搜索关键字， `apropos <regexp>`

```pgsql
(gdb) apropos args
advance -- Continue the program up to the given location (same form as args for break command)
collect -- Specify one or more data items to be collected at a tracepoint
handle -- Specify how to handle a signal
info args -- Argument variables of current stack frame
l -- List specified function or line
list -- List specified function or line
r -- Start debugged program
run -- Start debugged program
set args -- Set argument list to give program being debugged when it is started
show args -- Show argument list to give program being debugged when it is started
u -- Execute until the program reaches a source line greater than the current
until -- Execute until the program reaches a source line greater than the current
```



## 运行

包含三个命令：
run : 开始运行
start ： 运行并停在main函数上
continue ：继续运行
ignore ： 忽略某函数或文件
checkpoint: 设置书签

### start

后面可以跟参数, 如`start 1 2 3`

### 2.2 ignore

忽略某函数或文件
在调试程序中可能会不关心某个函数或文件，这时可以用`skip`来略过他们。
语法如下：

```subunit
skip -file <file>
skip -gfile <file_glob_pattern>
skip -function <linespec>
skip -rfunction <regexp>
info skip [range]
skip  delete   
```

`<linespec>`是一个冒号分隔的列表，它可以包括文件名， 函数名。（filename:linenum, function:label, filename:function, label)

示例如下：

```elixir
(gdb) skip -rfu ^std::(allocator|basic_string)<.*>::~?\1 *\(

(gdb) skip -rfu ^std::([a-zA-z0-9_]+)<.*>::~?\1 *\(
```

第一个命令忽略std::string的构造和解构函数
第二个命令忽略所有来自std namespace的函数的构造和解构函数

### 2.3 checkpoint

gdb可以在程序执行的过程中保留快照(状态)信息，称之为checkpoint，可以在进来返回到该处再次查看当时的信息，比如内存、寄存器以及部分系统状态。通过设置checkpoint，万一调试的过程中错误发生了但是已经跳过了错误发生的地方，就可以快速返回checkpoint再开始调试，而不用重启程序重新来过。

#### 2.3.1 checkpoint

对当前执行状态保存一个快照，gdb会自动产生一个对应的编号供后续标识使用。从提示信息看来，其实每建立一个checkpoint，都会fork出一个子进程，所以每个checkpoint都有一个唯一的进程ID所对应着。

#### 2.3.2 info checkpoints

查看所有的checkpoint，包括进程ID、代码地址和当时的行号或者符号。

#### 2.3.3 restart checkpoint-id

恢复程序状态到checkpoint-id指明的checkpoint，所有的程序变量、寄存器、栈都会被还原到那个状态，同时gdb还会将时钟信息回退到那个点。恢复过程中程序的状态和系统的部分状态是支持的，比如文件指针等信息，但是写入文件的数据、传输到外部设备的数据都无法被回退。

#### 2.3.4 delete checkpoint checkpoint-id

删除指定的checkpoint。

此外，checkpoint的作用还在于断点、观测点不是什么情况下都可用的情况下，因为Linux系统有时候为了安全考虑，会随机化新进程的地址空间，这样重启调试程序会导致之前使用绝对地址设置的断点、观测点不可用。





## 四. 断点

在一个位置上设置断点，可以对应多个位置，gdb要自动在需要的位置插入断点。在动态库里也可以设置断点，不过其地址在加载后才能解析。
断点的设置有几种方法

```less
break
b
break [Function Name]
break [File Name]:[Line Number]
break [Line Number]
break *[Address]
break [...] if [Condition]
break [...] thread [Thread-id]
b [...]
rbreak [regexp]
rbreak [File Name]:[regexp]
tbreak [args]
```

#### 4.1 Function name和Address

不要混淆[Function name]和[Address]， 比如你想在地址0x40138c上设定断点，如果用

```kotlin
gdb> break 0x4007d9
```

会失败， GDB会0x40138c解释成函数而不是地址。正确的做法是

```kotlin
(gdb) break *0x4007d9
```

可以用下面命令得到相应行的地址：

```x86asm
(gdb) i line gdbprog.cc:14
Line 14 of "gdbprog.cc" starts at address 0x4007d9 <InitArrays(int*)+17> and ends at 0x4007f7 <InitArrays(int*)+47>.
```

或者

```llvm
(gdb) disas /m InitArrays
Dump of assembler code for function InitArrays(int*):
8    void InitArrays(int* array)
  0x00000000004007c8 <+0>:    push  %rbp
  0x00000000004007c9 <+1>:    mov    %rsp,%rbp
  0x00000000004007cc <+4>:    mov    %rdi,-0x18(%rbp)

9    {
10    
11    
12        for(int i = 0;i < 10;i++)
  0x00000000004007d0 <+8>:    movl  $0x0,-0x4(%rbp)
  0x00000000004007d7 <+15>:    jmp    0x40080a <InitArrays(int*)+66>
  0x0000000000400807 <+63>:    incl  -0x4(%rbp)
  0x000000000040080a <+66>:    cmpl  $0x9,-0x4(%rbp)
  0x000000000040080e <+70>:    jle    0x4007d9 <InitArrays(int*)+17>

13        {
14            ptrArray[i] = array + i;
  0x00000000004007d9 <+17>:    mov    -0x4(%rbp),%ecx
  0x00000000004007dc <+20>:    mov    -0x4(%rbp),%eax
  0x00000000004007df <+23>:    cltq  
  0x00000000004007e1 <+25>:    shl    $0x2,%rax
  0x00000000004007e5 <+29>:    mov    %rax,%rdx
  0x00000000004007e8 <+32>:    add    -0x18(%rbp),%rdx
  0x00000000004007ec <+36>:    movslq %ecx,%rax
  0x00000000004007ef <+39>:    mov    %rdx,0x6013e0(,%rax,8)

15            iArray[i] = i;
  0x00000000004007f7 <+47>:    mov    -0x4(%rbp),%eax
  0x00000000004007fa <+50>:    movslq %eax,%rdx
  0x00000000004007fd <+53>:    mov    -0x4(%rbp),%eax
  0x0000000000400800 <+56>:    mov    %eax,0x6013a0(,%rdx,4)

16        }
17    }
  0x0000000000400810 <+72>:    leaveq 
  0x0000000000400811 <+73>:    retq  

End of assembler dump.
```

### 4.2. Pending breakpoints

如果试图将断点设在位于还未加载的shared library代码内，那么就会显示类似下面warning

> Make breakpoint pending on future shared library load? (y or [n])

但它可能永远不会工作，如果是下列情况：

- shared library不包含任何debugging symbols (被用‘strip’命令移除掉)
- GDB无法检测到library被加载 (比如，在android上使用GDB 6.x)
- 你输入的是一个错误文件名或函数名

所以可以用下面几个命令来做调试

- `info sharedlibrary` : 目前加载的shared library
- `info sources` : 被GDB识别的源文件
- `info breakpoints` : 创建的断点和它们的状态

### 4.3. 条件断点

大约有以下几种形式

```apache
break main if argc > 1
break 180 if (string == NULL && i < 0)
break test.c:34 if (x & y) == 1
break myfunc if i % (j+3) != 0
break 44 if strlen(mystring) == 0
b 10 if ((int)$gdb_strcmp(a,"chinaunix") == 0)
b 10 if ((int)aa.find("dd",0) == 0)
```

经常犯的一个错误就是 **在if和后面的（之间没放空格**
另外注意**条件表达式的返回值类型是int**

当设置了断点后， 后面可以使用condition和ignore来修改这个断点条件

### 4.4. condition

```mel
condition <break_list> (condition)
```

比如

```abnf
cond 3 (i==4)
```

上面命令把breakpoint 3的条件修改成(i==4)

### 4.5. ignore

```mipsasm
ignore <break_list> count
```

上面命令表示break_list指定的断点将被忽略count次
比如现在i=0, 设置i>4为条件，那么忽略3次后，它停在i=8， 忽略了i=5, 6, 7

### 4.6. commands

```xml
commands <break_list>
```

当断点被触发时，运行相应的命令
可以用`info breakpoints`来查看相应断点上附着的命令

```mipsasm
(gdb) i b
Num    Type          Disp Enb Address            What
3      breakpoint    keep y  0x00000000004007d9 in InitArrays(int*) at gdbprog.cc:14
    stop only if (i>4)
    breakpoint already hit 5 times
        silent
        printf "hz: i=%d\n",i
        c
7      breakpoint    keep y  0x0000000000400962 in main() at gdbprog.cc:51
    breakpoint already hit 1 time
```

一个断点上只允许附着一条命令，再次调用`commands 3`后会覆盖掉前面的命令
因此如果要删除相应的命令，只需用空的commands 3就行了

### 4.7. define

用define可以录制宏，这些宏就像shell脚本一样，可以传入参数，依次是$arg0, $arg1, ...
可以把这些宏放在.gdbinit文件中
录制好宏后就可以在commands中使用
宏并不支持所有GDB命令，比如silent就不能用于宏中, 它会在运行时报错： Undefined commands: "silent"

```livecodeserver
(gdb) define printAndGo
Type commands for definition of "printAndGo".
End with a line saying just "end".
>printf "i=%d\n",$arg0
>cont
>end
(gdb) commands 3
Type commands for breakpoint(s) 3, one per line.
End with a line saying just "end".
>silent
>printAndGo
>end
(gdb) i b
Num    Type          Disp Enb Address            What
3      breakpoint    keep y  0x00000000004007d9 in InitArrays(int*) at gdbprog.cc:14
    stop only if (i>4)
        silent
        printAndGo i
7      breakpoint    keep y  0x0000000000400962 in main() at gdbprog.cc:51
```

如果要查看这些宏的定义，可以用`show user`来查看

```routeros
(gdb) show user
User command "pbuf":
  set $i=0
  while ($i<strlen(netiring.supply))
    print netiring.supply[$i]
    set $i=$i+1
  end

User command "pobuf":
  set $i=0
  while ($i<strlen(netoring.consume))
    print netoring.consume[$i]
    set $i=$i+1
  end
```

### 4.8 tbreak

只生效一次临时断点

### 4.9 rbreak

在所有匹配regexp的函数名处都设置断点。它的regexp和grep相同

### 4.10 管理

`clear localtion`
location可以是function, file:func, linenum, file:linenum
`delete [breakpoints] [range...]`
[breakpoints]是可选项
`disable|enable [breakpoints] [range...]`
禁用|启用断点
`enable [breakpoints] once range...`
启用断点一次
`enable [breakpoints] once range...`
雇用断点cnt次
`enable [breakpoints] delete range...`
临时启用断点，一旦被激活就会把删除，和tbreak相似



## 五. 检查数据

```arduino
pirnt
x
display
set
watch
catch
tracepoint
```

### 5.1 print

print接受表达式和计算它的值。任何该语言支持常值，变量和操作符都可以使用，像条件表达式，函数调用，类型转换，字符常量。GDB还支持数组常量，语法是{element, element...}, 比如print {1,2,3}.GDB支持还支持下面操作符

- @

二进制操作符， 可以把momery当成数组。

```c
int *array = (int*) malloc( len * sizeof(int));
```

可以使用下面命令来打印它的值：

```scss
(gdb) p *array@len
(gdb) p/x (short[2])0x12345678
$1 = {0x1234, 0x5678}
```

另外还可以自定义变量

```stata
set $i = 0
p dtab[$i++]->fv
RET
RET
```

上面的RET表示重复上面的表达式

- ::

定义属于某个文件或函数的变量

- {type} addr

把addr的变量按{type}类型解释

### 5.2 x

```llvm
x/nfu addr
x addr
x
```

n, the repeat count
f, the display format (x, d, u, o, t, a, c, f, s, i)
u, the unit size (b: bytes, h: halfwords, w: words, g: giant words)

```excel
(gdb) x/5i $pc-6
  0x804837f <main+11>: mov    %esp,%ebp
  0x8048381 <main+13>: push  %ecx
  0x8048382 <main+14>: sub    $0x4,%esp
=> 0x8048385 <main+17>: movl  $0x8048460,(%esp)
  0x804838c <main+24>: call  0x80482d4 <puts@plt>
```

### 5.3 display

如果你发现你经常要打印某个表达式，你可以把它加入到"automatic display list"

```mipsasm
display expr
display/fmt expr
display/fmt addr
undisplay <dnums>
delete display dnums
disable display dnums
enable display dnums
```

### 5.4 set

可以使用`set <var>=<expr>`来修改程序中变量的值

### 5.5 数值历史(value Hisitory)

通过使用print命令显示的值会被自动保存在GDB的数值历史当中，该值会一直被保留直到符号表被重新读取或者放弃的时候(比如使用file或symbol-file)，此时所有的值历史将会被丢弃。在使用print打印值的时候，会将值编以整形的历史编号，然后可以使用&dollar;num的方式方便的引用，单个的&dollar;表示最近的数值历史，而&dollar;&dollar;表示第二新的数值历史，&dollar;&dollar;n表示倒数第n新的数值历史(所以可以推断&dollar;&dollar;0==&dollar;; &dollar;&dollar;1==&dollar;&dollar;;)。
　　比如刚刚打印了一个指向结构体的指针，那么print $就可以显示结构体的信息，而命令print \$.nex甚至可以显示结构体中的某些字段。

### 5.6 Convenience变量

GDB允许自由创建便捷变量用于保存值，后续可以方便的引用该值，该类型的变量由GDB管理而与正在调试的程序没有直接的关联。便捷变量也是使用符号$打头的，可以使用任意名字(除了GDB使用的寄存器名)。
在任意时候使用一个便捷变量都会创建他，如果没有提供初始化值那么该变量就是void，直到给其进行赋值操作为止。便捷变量没有固定的类型，可以为普通变量、数组、结构体等，而且其类型可以在赋值过程中改变(为当前值的类型)。
`show convenience|conv`
显示道目前所有的便捷变量和便捷函数，以及其值。
`init-if-undefined $variable = expr`
如果该变量还没有被创建或初始化，则创建这个变量。如果该变量已经被创建了，则不会创建和初始化该变量，并且expr表达式也不会被求值，所以这种情况下也不会有expr的副作用发生。
便捷变量的一种经典用法，就是之前提到的连续查看变量时候用于计数作用：

```routeros
set $i = 0
print bar[$i++]->contents
```

下面的一些便捷变量是GDB自动创建的：

- &dollar;_exitcode

当调试程序终止的时候，GDB将会根据程序的退出值自动设置该变量，并且将&dollar;_exitsignal变量设置为void。

- &dollar;_exitsignal

当调试中的程序因为一个未捕获信号而终止，此时GDB会自动将变量&dollar;_exitsignal设置为该信号，同时重置变量&dollar;_exitcode为void。

### 5.7 Convenience函数

便捷函数和便捷变量一样使用&dollar;打头引用，其可以像一个普通函数一样在表达式中使用，便捷函数只被GDB内部使用。`

```routeros
(gdb) print $_isvoid ($_exitsignal)
```

&dollar;_isvoid (expr): 如果expr是void则返回1，否则返回0。
GDB还有很多的便捷函数支持，但是需要在编译GDB的时候提供Python的支持才可以使用。下面的这些函数意义显而易见，就不在啰嗦了。
&dollar;_memeq(buf1, buf2, length); &dollar;_regex(str, regex); &dollar;_streq(str1, str2); &dollar;_strlen(str)

### 5.8 watch

监视点是监视特定内存位置、特定表达式的值是否改变而触发程序暂停执行，而不用去关心该值到底在代码的哪个位置被修改的。监视的表达式可以是：某个变量的引用、强制地址解析(比如(int )0x12345678，你无法watch一个地址，因为地址是永远也不会改变的)、合理的表达式(比如a-b+c/d，gdb会检测其中引用的各个变量)。

```css
　　watch [-l|-location] expr [thread thread-id] [mask maskvalue]
```

thread-id可以设置特定线程改变expr的时候触发中断，默认情况下针对硬件模式的检测点所有的线程都会检测该表达式；-location会让gdb计算expr的表达式，并将计算的结果作为地址，并探测该地址上的值(数据类型由expr计算结果决定)。
很多平台都有实现监视点的专有硬件，如果没有GDB也会采用虚拟内存技术来实现监视点，而如果前面两种技术都不可用，则GDB会采用软件实现监事点本身。软件模式速度会非常慢，因为如果不支持硬件模式gdb会每次step并计算检测的表达式，x86构架支持硬件模式，而且监视点的作用也有限，只能当前单个线程能侦测其变化，虽然该值也可能会被其他线程修改。
监视点在跟踪那种变量不知道哪里被修改的情形特别的有效。不过监视点需要变量在当前上下文可访问的情况下才可以使用，所以在使用中会通常配合断点先到达事发的附近位置，然后再创建对应的监测点。
watch命令还存在两个变体：rwatch当expr被程序读的时候触发中断；awatch会在程序读取或者写入expr的时候被中断。rwatch和awatch只支持硬件模式的检测点

### 5.9 catch

可以让gdb在某些事件发生的时候暂停执行，比如C++抛出异常、捕获异常、调用fork()、加载动态链接库以及某些系统调用的时候，其格式为catch event，还有一个变体tcatch event设置临时捕获点，其中event的参数可以为：

```coq
throw|rethrow|catch|exec|fork|vfork|syscall|exception|unhandled|assert
```

在C++异常抛出、重新抛出、捕获的时候触发，可选使用regex参数限定特定的异常类型(在gcc-4.8开始支持)，内置变量&dollar;_exception会记录在catchpoint激活时候的异常。
当异常发生时候，程序通常会停留在libstdc++的异常支持点，此时可以通过使用up命令切换帧跳转到用于异常代码处。
syscall如果不带参数，则捕获任意系统调用。

```coq
syscall [name | number | group:groupname | g:groupname] …
```

在进入和/或返回系统调用的时候触发。name可以指明catch的系统调用名(定义在/usr/include/asm/unistd.h，且gdb会帮助智能补全)，group|g:groupname可以用来指定一组类别的系统调用，比如g:network，通过智能补全可以查看支持的group信息。

`load|unload [regex]` : 加载和卸载共享库时候触发，可选regex进行过滤。

```vhdl
signal [signal… | ‘all’]
```

可以在软件收到信号的时候触发。gdb本身会占用SIGTRAP和SIGINT两个信号，如果不添加额外参数，会catch除了这两个信号之外的所有信号。
使用info break命令，watchpoint的信息会被展示出来，可以像普通断点一样管理之。



## 五. Stack命令

主要包含以下几个

```nginx
bt
frame
info frame
where
```

### 5.1 bt

```mipsasm
bt
bt [Frame count]
bt full
```

可以使用负数， -1是第一层，-2是第二层

```x86asm
(gdb) backtrace 
#0 level0 () at recursion.cpp:5
#1 0x08048462 in test (level=0) at recursion.cpp:17
#2 0x0804845b in test (level=1) at recursion.cpp:14
#3 0x0804845b in test (level=2) at recursion.cpp:14
#4 0x0804845b in test (level=3) at recursion.cpp:14
#5 0x0804845b in test (level=4) at recursion.cpp:14
#6 0x0804845b in test (level=5) at recursion.cpp:14
#7 0x08048479 in main () at recursion.cpp:22
(gdb) backtrace -2
#6 0x0804845b in test (level=5) at recursion.cpp:14
#7 0x08048479 in main () at recursion.cpp:22
```

### 5.2 frame

frame是非常有用的命令，它可以用来显示当前帧的信息
基本语法是

```apache
frame
frame [Frame number]
f
```

**如果没有参数，就是当前行的信息**

```routeros
(gdb) frame
#0 level0 () at recursion.cpp:5
5 printf("Reached level 0\n");
(gdb) info args
No arguments.
(gdb) frame 1
#1 0x08048462 in test (level=0) at recursion.cpp:17
17 level0();
(gdb) info args
level = 0
(gdb) frame 2
#2 0x0804845b in test (level=1) at recursion.cpp:14
14 test(prevLevel);
(gdb) info args
level = 1
```

可以用`info line *$rip`和`list *$rip`获得类似当前行的信息

### 5.3 info frame

语法如下：

```routeros
info frame
info frame [addr]
```

相比直接的`frame`， 这个命令输出更详细的stack frame信息，包括

- frame的地址
- 下一层frame的地址
- 上一层frame的地址(caller)
- 当前frame是用什么语言所写
- frame的变量地址
- frame的local变量
- pc值
- 在当前frame里保存的registers

```x86asm
(gdb) i frame
Stack level 0, frame at 0x7fffffffe250:
rip = 0x4009e0 in PrintArray (gdbprog.cc:40); saved rip 0x400a3f
called by frame at 0x7fffffffe280
source language c++.
Arglist at 0x7fffffffe240, args: 
Locals at 0x7fffffffe240, Previous frame's sp is 0x7fffffffe250
Saved registers:
  rbp at 0x7fffffffe240, rip at 0x7fffffffe248

(gdb) bt
#0  PrintArray () at gdbprog.cc:40
#1  0x0000000000400a3f in main () at gdbprog.cc:57
(gdb) i f 0x0000000000400a3f
Stack frame at 0x400a3f:
rip = 0x0; saved rip 0x7ffff7ff9720
called by frame at 0x7fffffffe240
Arglist at 0x7fffffffe228, args: 
Locals at 0x7fffffffe228, Previous frame's sp is 0x7fffffffe238
Saved registers:
  rip at 0x7fffffffe230
```

## 六. 程序信息

主要包含

```routeros
info proc
info variables
info functions
info source
info sources
info sharedlibrary
info flies
```

### 6.1 info proc

`info proc all`可以打印出所有进程相关信息

`info proc mappings`显示正在运行的进程中映射的内存区域的列表。与 /prod/pid/maps 的输出相同

### 6.2 info functions

列出程序中的函数
语法如下：

```pgsql
info functions
info functions [Regex]
```

示例如下：

```arduino
(gdb) info functions
All defined functions:

File gdbprog.cc:
int DoOperation(int**);
void InitArrays(int*);
void PrintArray();
int main();
static void __static_initialization_and_destruction_0(int, int);
static void __tcf_0(void*);
static void global constructors keyed to iArray();

Non-debugging symbols:
0x0000000000400660  _init
0x0000000000400688  std::basic_ostream<char, std::char_traits<char> >::operator<<(int)
0x0000000000400688  _ZNSolsEi@plt
0x0000000000400698  std::ios_base::Init::Init()
...
```

### 6.3 info source

显示当前源文件名

#### info sources

显示加载的symbols涉及的源文件

```gradle
(gdb) info sources
Source files for which symbols have been read in:

<<C++-namespaces>>, /home/harriszh/cpp/e1/gdbprog.cc, 
/grid/common/pkgsData/gcc-v4.1.2p2/Linux/RHEL3.0-1H2006-x86_64/include/c++/4.1.2/bits/locale_facets.h, 
/grid/common/pkgsData/gcc-v4.1.2p2/Linux/RHEL3.0-1H2006-x86_64/include/c++/4.1.2/x86_64-redhat-linux/bits/ctype_base.h, 
/grid/common/pkgsData/gcc-v4.1.2p2/Linux/RHEL3.0-1H2006-x86_64/include/c++/4.1.2/bits/stl_iterator.h, 
/grid/common/pkgsData/gcc-v4.1.2p2/Linux/RHEL3.0-1H2006-x86_64/include/c++/4.1.2/bits/allocator.h, 
/grid/common/pkgsData/gcc-v4.1.2p2/Linux/RHEL3.0-1H2006-x86_64/include/c++/4.1.2/ext/new_allocator.h, 
/grid/common/pkgsData/gcc-v4.1.2p2/Linux/RHEL3.0-1H2006-x86_64/include/c++/4.1.2/bits/stringfwd.h, /usr/include/bits/pthreadtypes.h, 
/grid/common/pkgsData/gcc-v4.1.2p2/Linux/RHEL3.0-1H2006-x86_64/include/c++/4.1.2/x86_64-redhat-linux/bits/gthr-default.h, 
/grid/common/pkgsData/gcc-v4.1.2p2/Linux/RHEL3.0-1H2006-x86_64/include/c++/4.1.2/bits/locale_classes.h, 
/grid/common/pkgsData/gcc-v4.1.2p2/Linux/RHEL3.0-1H2006-x86_64/include/c++/4.1.2/bits/basic_string.tcc, 
/grid/common/pkgsData/gcc-v4.1.2p2/Linux/RHEL3.0-1H2006-x86_64/include/c++/4.1.2/bits/basic_string.h, 
/grid/common/pkgsData/gcc-v4.1.2p2/Linux/RHEL3.0-1H2006-x86_64/include/c++/4.1.2/limits, 
/grid/common/pkgsData/gcc-v4.1.2p2/Linux/RHEL3.0-1H2006-x86_64/include/c++/4.1.2/x86_64-redhat-linux/bits/atomic_word.h, 
/grid/common/pkgsData/gcc-v4.1.2p2/Linux/RHEL3.0-1H2006-x86_64/include/c++/4.1.2/bits/ios_base.h, 
/grid/common/pkgsData/gcc-v4.1.2p2/Linux/RHEL3.0-1H2006-x86_64/include/c++/4.1.2/iosfwd, 
/grid/common/pkgsData/gcc-v4.1.2p2/Linux/RHEL3.0-1H2006-x86_64/include/c++/4.1.2/new, /usr/include/wctype.h, 
/grid/common/pkgsData/gcc-v4.1.2p2/Linux/RHEL3.0-1H2006-x86_64/include/c++/4.1.2/cwctype, /usr/include/stdlib.h, 
/grid/common/pkgsData/gcc-v4.1.2p2/Linux/RHEL3.0-1H2006-x86_64/include/c++/4.1.2/cstdlib, 
/grid/common/pkgsData/gcc-v4.1.2p2/Linux/RHEL3.0-1H2006-x86_64/include/c++/4.1.2/cwchar, /usr/include/time.h, 
/grid/common/pkgsData/gcc-v4.1.2p2/Linux/RHEL3.0-1H2006-x86_64/include/c++/4.1.2/ctime, /usr/include/locale.h, 
/grid/common/pkgsData/gcc-v4.1.2p2/Linux/RHEL3.0-1H2006-x86_64/include/c++/4.1.2/clocale, /usr/include/wchar.h, /usr/include/_G_config.h, 
/usr/include/bits/types.h, /usr/include/libio.h, /usr/include/stdio.h, 
...
```

### 6.4 info files

显示执行文件名称和加载的段

```1c
(gdb) i file
Symbols from "/home/harriszh/trunk/cpp/exercise/gdbprog".
Unix child process:
    Using the running image of child process 42226.
    While running this, GDB does not access memory from...
Local exec file:
    `/home/harriszh/trunk/cpp/exercise/gdbprog', file type elf64-x86-64.
    Entry point: 0x4007f0
    0x0000000000400200 - 0x000000000040021c is .interp
    0x000000000040021c - 0x000000000040023c is .note.ABI-tag
    0x000000000040023c - 0x0000000000400260 is .note.gnu.build-id
    0x0000000000400260 - 0x0000000000400294 is .gnu.hash
    0x0000000000400298 - 0x00000000004003e8 is .dynsym
    0x00000000004003e8 - 0x0000000000400592 is .dynstr
    0x0000000000400592 - 0x00000000004005ae is .gnu.version
    0x00000000004005b0 - 0x0000000000400600 is .gnu.version_r
    0x0000000000400600 - 0x0000000000400630 is .rela.dyn
    0x0000000000400630 - 0x0000000000400720 is .rela.plt
    0x0000000000400720 - 0x0000000000400738 is .init
    0x0000000000400738 - 0x00000000004007e8 is .plt
    0x00000000004007f0 - 0x0000000000400ba8 is .text
    0x0000000000400ba8 - 0x0000000000400bb6 is .fini
    0x0000000000400bb8 - 0x0000000000400bf4 is .rodata
    0x0000000000400bf4 - 0x0000000000400c40 is .eh_frame_hdr
    0x0000000000400c40 - 0x0000000000400d84 is .eh_frame
    0x0000000000601000 - 0x0000000000601018 is .ctors
    0x0000000000601018 - 0x0000000000601028 is .dtors
    0x0000000000601028 - 0x0000000000601030 is .jcr
    0x0000000000601030 - 0x00000000006011f0 is .dynamic
    0x00000000006011f0 - 0x00000000006011f8 is .got
    0x00000000006011f8 - 0x0000000000601260 is .got.plt
    0x0000000000601260 - 0x0000000000601264 is .data
    0x0000000000601280 - 0x0000000000601438 is .bss
    0x000000347b8001c8 - 0x000000347b8001ec is .note.gnu.build-id in /lib64/ld-linux-x86-64.so.2
    0x000000347b8001f0 - 0x000000347b8002a8 is .hash in /lib64/ld-linux-x86-64.so.2
...
```

### 6.5 info sharedlibrary

显示共享库及它们的地址
语法如下：

```routeros
info sharedlibrary
info shared
```

示例如下：

```gradle
(gdb) info sharedlibrary 
From To Syms Read Shared Object Library
0xb7fde820 0xb7ff6b9f Yes /lib/ld-linux.so.2
0xb7fd83a0 0xb7fd84c8 Yes /home/testuser/libtest/libTest.so
0xb7e30f10 0xb7f655cc Yes /lib/i386-linux-gnu/libc.so.6
...
```

### 6.6 set stop-on-solib-events command

当一个shared library加载或卸载时，是否暂停

```livecodeserver
set stop-on-solib-events 0
set stop-on-solib-events 1
show stop-on-solib-events
```

默认是不暂停， 如果想暂停设成1

## 七. 源文件

主要命令是

```routeros
list
info line
disassemble
set disassemble-next-line
set disassemble-flavor
```

### 7.1 list

查看当前运行源代码
语法如下：

```lsl
list <linenum>
list <first>, <last>
list <function>
list
list -
list *<addr>
```

示例如下：

```scss
(gdb) list *$pc
0x4009e0 is in PrintArray() (gdbprog.cc:40).
35    
36    void PrintArray()
37    {
38        int i;
39        
40        for(i = 0;i < 10;i++)
41        {
42            if (iArray[i] == 6)
43                cout << "This is an error\n";
44            else
```

### 7.2 info line

基本语法是

```pgsql
info line [File]:[Line]
info line [Function]
info line [File]:[Function]
info line *[Address]
```

比如：

```pgsql
(gdb) info line test.cpp:5
Line 5 of "test.cpp" starts at address 0x80483f0 <main(int, char**)+3> and ends at 0x80483f5 <main(int, char**)+8>.
(gdb) info line *0x80483f0
Line 5 of "test.cpp" starts at address 0x80483f0 <main(int, char**)+3> and ends at 0x80483f5 <main(int, char**)+8>.
(gdb) info line *0x80483f6
Line 6 of "test.cpp" starts at address 0x80483f5 <main(int, char**)+8> and ends at 0x80483f7.
(gdb) info line main
Line 4 of "test.cpp" starts at address 0x80483ed <main(int, char**)> and ends at 0x80483f0 <main(int, char**)+3>.
```

### 7.3 disassemble

显示某个函数或某函数中一段代码的汇编
语法如下：

```css
disassemble
disassemble [Function]
disassemble [Address]
disassemble [Start],[End]
disassemble [Function],+[Length]
disassemble [Address],+[Length]
disassemble /m [...]
disassemble /r [...]
```

/m 表示 把源代码和汇编一一对应显示出来，在新版本中建议中/s, 它会考虑compiler优化
/r 表示 显示汇编指令的原生字节码

#### set disassemble-next-line

控制断点暂停或step后是否显示下一行的汇编，默认是off
语法如下：

```vim
set disassemble-next-line on
set disassemble-next-line off
show disassemble-next-line
```

示例如下：

```excel
(gdb) set disassemble-next-line on
(gdb) next
4 }
=> 0x080483f8 <func+11>: 5d pop %ebp
0x080483f9 <func+12>: c3 ret 
(gdb) next
main () at test.c:9
9 }
=> 0x08048414 <main+26>: c9 leave 
0x08048415 <main+27>: c3 ret
```

#### set disassemble-flavor

控制汇编和x命令的风格，有AT&T和intel两种
语法如下：

```gams
set disassembly-flavor att
set disassembly-flavor intel
show disassembly-flavor
```

## 八. record & replay

GDB提供加载功能，可以记录程序的执行过程（execution log)，然后在后续时间上进行前进、后退的程序运行。在调试目标运行时，如果接下来的执行指令在log中存在，就会进入replay mode，该模式下不会真正执行指令，而是将事件、寄存器，内存值从日志中提取出来，如果接下来的执行指令不在log中，那么GDB就会在record mode下执行，所有指令将会按归照正常方式执行，GDB会记录执行。

### 8.1 Record

默认的方法是使用full recording, 该模式不支持non-stop mode和异步执行模式的多线程调试。只能调试正在执行的进程

```pgsql
record [full| btrace bts|btrace pt]
record stop
record goto [begin|start|end|n]
info record
record delete
```

#### 8.1.1 record <method>

开启进程的R&RT模式

#### 8.1.2 record stop

停止进程的R&RT， 并将所有的execution log删除。如果在record的中间位置执行本命令，那么会从这个点开始Live调试

#### 8.1.3 record goto

中转到指定位置， n表示execution log中的instruction的序号。
可以用info record查看

#### 8.1.4 record save|restore file

保存和恢复execution log

#### 8.1.5 set record full insn-number-max limit|unlimited

默认最多200,000。

#### 8.1.6 set record full stop-at-limit on|off

当保存指令数目超过限制的话，如果on（默认）， 那么GDB会在首次超过限制的地方停止；如果off，则会自动删除最旧记录

#### 8.1.7 record delete

在replay模式下执行该命令，会删除当前指令之后的所有log, 并开始新的record

### 8.2 Replay

```sqf
reverse-continue [ignore-count]
rc [ignore-count]
reverse-step [count]
reverse-stepi [count]
reverse-next [count]
reverse-nexti [count]
reverse-finish
set exec-direction [reverse|forward]
```

它们的行为如他们名字一样，这里就不再多解释

## 九. 变量查看

### 9.1 generate-core-file

产生当前运行进程的一份memory image和它的process status(register values etc...)

```apache
gcore [file]
```

### 9.2 info registers

```x86asm
(gdb) i registers
rax            0x601280    6296192
rbx            0x0    0
rcx            0x400    1024
rdx            0x3487ae9d18    225614667032
rsi            0x7ffff7ff8000    140737354104832
rdi            0xffffffff    4294967295
rbp            0x7fffffffe240    0x7fffffffe240
rsp            0x7fffffffe230    0x7fffffffe230
r8            0x7ffff7ff8002    140737354104834
r9            0x7ffff7ff9720    140737354110752
r10            0xcccccccccccccccd    -3689348814741910323
r11            0x246    582
r12            0x4007f0    4196336
r13            0x7fffffffe350    140737488347984
r14            0x0    0
r15            0x0    0
rip            0x4009e0    0x4009e0 <PrintArray()+88>
eflags        0x206    [ PF IF ]
cs            0x33    51
ss            0x2b    43
ds            0x0    0
es            0x0    0
fs            0x0    0
gs            0x0    0
```

### 9.3 info variable

显示全局或静态的变量

```routeros
info variables
info variables [Regex]
```

**可以用`i var <varName>`来查看某个全局或静态变量是在哪个文件定义的**

### 9.4 info locals

显示当前帧的本地变量， 配合frame, up和down来使用

### 9.5 info args

显示当前帧的函数的参数， 配合frame，up和down来使用

## 十. 编辑和搜索

### 10.1 编辑

可以直接打开编辑器编辑源文件

```routeros
edit <number>
edit <function>
```

### 10.2 搜索

```vim
forward-search <regexp>
fo <regexp>
search <regexp>
reverse-search <regex>
rev <regexp>
```

可以通过`directory dirname ...`来添加源文件路径

### 10.3 内存查找

使用find可以对内存进行序列字节查找

```vim
find [/sn] start_addr, +len, val1 [, val2, …]
find [/sn] start_addr, end_addr, val1 [, val2, …]
```

该命令会在内存中搜索var1、var2…字符序，其范围从startaddr开始，以结束地址或者长度结束。
参数s表示搜索的大小，可以是b、h、w、g(跟之前的x命令一样)，如果该参数没有指定，GDB会考虑当前调试程序的语言环境确定，比如0x43这种整数就默认为w(4字节)类型；n表示打印最大搜索命中数量，默认行为是全部打印。该命令还可以搜索字符串，字符串使用双引号括住。
对于查找结果，命中数目保存在变量$numfound中，而最后一个值命令的地址保存在**$**中。

```c
void
hello ()
{
  static char hello[] = "hello-hello";
  static struct { char c; short s; int i; }
    __attribute__ ((packed)) mixed
    = { 'c', 0x1234, 0x87654321 };
  printf ("%s\n", hello);
}
```

可以进行如下查找

```routeros
(gdb) find &hello[0], +sizeof(hello), "hello"
0x804956d <hello.1620+6>
1 pattern found
(gdb) find &hello[0], +sizeof(hello), 'h', 'e', 'l', 'l', 'o'
0x8049567 <hello.1620>
0x804956d <hello.1620+6>
2 patterns found.
(gdb) find &hello[0], +sizeof(hello), {char[5]}"hello"
0x8049567 <hello.1620>
0x804956d <hello.1620+6>
2 patterns found.
(gdb) find /b1 &hello[0], +sizeof(hello), 'h', 0x65, 'l'
0x8049567 <hello.1620>
1 pattern found
(gdb) find &mixed, +sizeof(mixed), (char) 'c', (short) 0x1234, (int) 0x87654321
0x8049560 <mixed.1625>
1 pattern found
(gdb) print $numfound
$1 = 1
(gdb) print $_
$2 = (void *) 0x8049560
```

## 十一. 多进程

GDB对fork产生新进程的调试没有特殊的支持，当使用fork产生子进程的时候，GDB会继续调试父进程，子进程不会被阻碍而是继续执行，而此时如果子进程遇到断点后，子进程会收到SIGTRAP信号，当在非调试模式下默认会导致子进程中止。如果要调试子进程，可以让子进程启动后睡眠一段时间(或者监测某个文件是否创建)，在这个空隙中使用ps查看子进程的进程号，然后再启动gdb去attach到这个进程上面去调试。
通过catch命令可以让gdb在fork/vfork/exec调用的时候暂停执行。
影响fork多进程调试还有以下几个变量：
`follow-fork-mode`
可选值是parent或child，指明当正在被调试的进程fork出子进程的时候，如果该值是parent，那么父进程被调试子进程正常执行，这也是默认行为；而当其为child的时候，则新创建的子进程被调试，父进程正常执行。
`detach-on-fork`
可选值是on或off，知名当被调试的进程fork出子进程后，是否detach某个进程还是调试他们俩，如果是on，那么子进程(或父进程，取决于上面follow-fork-mode的值)将会被detach正常执行，这是默认行为；否则两个进程都会被gdb控制，其中的一个进程被正常调试，另外一个进程被suspend住。
`follow-exec-mode`
gdb对于exec调用的反应，其值可以为new或same，当值为new的时候，之前fork的子进程和exec后的进程都会被保留；如果是same，则exec的进程使用之前fork的进程，exec会用新的执行镜像替代原先的可执行程序，这是默认行为。

## 十二. 多线程

在多线程程序中，有两种工作模式： all-stop和non-stop
**all-stop**
当进程中任意线程因为某种原因停止执行的时候，所有其他线程也同时被GDB停止执行。好处是程序停止的时候所有线程的状态都被保留下来了，可以切换线程查看整个程序当时的所有状态(缺点是整个业务全部阻塞暂停了)。
有些操作系统支持OS调试锁定，可以修改GDB的默认行为

- scheduler-locking

off：不会锁定，所有线程可以自由运行；
on：当程序resume的时候，只有当前线程可以运行；
step：该模式是为单步模式优化的模式，当跟踪的时候阻止其他线程抢占当前线程。当step的时候其他线程无法运行，而在使用continue、until、finish类似指令的时候其他线程可以自由运行。除非其他线程运行时候触发了断点，否则GDB不会切换当前调试的线程。

- schedule-multiple

该设置是针对多进程情况下的调试。
off：只有当前线程所在的进程的所有线程允许恢复执行，该off为默认值。
on：所有进程的所有线程都可以执行。

**non-stop**
当进程中任意线程停止时，在跟踪检查停止线程的时候其他的线程任然继续执行，其好处就是对线上系统进行最小化的干扰入侵，整个程序还是可以继续响应外部请求的。
通过下面的设置可以开启non-stop模式，一般都是在gdb开始的时候或者连接调试目标的时候设置才会生效，且在调试过程中不能切换该模式，不是所有平台都支持non-stop模式，所以即使设置了GDB还是有可能fallback到all-stop模式。

```vbnet
set pagination off
set non-stop on
```

non-stop模式的验证也十分的简单，在一个多线程的网络程序中先设置断点，此时发送一个请求那么处理线程会被停止，接下来删除该断点，再次发送一个请求，看该请求是否得到正常响应。如果non-stop正常开启生效的话，此时的info threads会显示其他线程都是running的状态。
non-stop模式下的命令默认都是针对当前线程的，如果要针对所有线程，通常需要使用-a参数，比如continue -a

## 十三. 针对语言的支持

### 13.1 对C的特殊支持

C语言预处理宏
宏本身是个比较麻烦的东西，因为可以某些点定义、某些点取消定义、某些点重新定义，GDB支持对含有宏的表达式进行展开并显示展开后结果的功能。如果要让编译后的程序具有宏调试功能，需要额外的编译参数-gdwarf-2和-g3(-g是不够的)

```glsl
 gdb gcc -gdwarf-2 -g3 sample.c -o sample
```

上面的gdwarf-2具有gdwarf-3、gdwarf-4等版本，推荐支持的情况下使用最新版本的调试格式。
`macro exp|expand expression`
显示expression中所有宏被展开后的结果。因为GDB只会进行宏展开而不会对表达式取值，所以这里的expression不需要是合法的表达式。
`info macro [-a|-all] [–] macro`
显示当前的或者全部的macro宏定义，同时显示该宏定义所在的源代码文件及其所在行号位置信息。其中的–表示参数列表结束，因为C中有些宏是可以使用-开头的，这里用于消除歧义作用。
`info macros location`
显示所有在location位置有效的宏定义及他们的位置信息。(显示结果有点多哦)
`macro define macro replacement-list`
`macro define macro(arglist) replacement-list`
自定义宏及其展开式，通过该命令创建的宏会在GDB求值的每个表达式中都会生效(只对GDB本身作用，与代码中使用的宏无关)，直到其显式使用macro undef进行删除，同时该宏还会覆盖程序中同名宏的展开(有点诡异)。
`macro undef macro`
只会删除上面使用macro define定义的宏，而不会删除程序代码中定义的宏。
`macro list`
显示所有通过macro define定义的宏。
除了通常在源代码中执行宏定义，还可以在编译的时候在命令行中通过‘-Dname=value’的方式定义，这样的宏也支持使用info macro命令查看，不过其行号信息显示为0。
