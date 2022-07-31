## 目录

- [关键字](#关键字)
- [STL简单介绍](#STL简单介绍)
  - [STL容器的种类](#STL容器的种类)
  - [STL头文件](#STL头文件)
  - [迭代器的简单描述](#迭代器的简单描述)
  - [STL中的算法](#STL中的算法)
    - [一些算法常用函数](#一些算法常用函数)
  - [容器的使用空间](#容器的使用空间)
- [容器STL基本概念](#容器STL基本概念)
  - [每种容器的算法特点](#每种容器的算法特点)
  - [STL容器共性机制](#STL容器共性机制)
  - [STL容器使用时机](#STL容器使用时机)
  - [STL容器的使用场景](#STL容器的使用场景)
- [string](#string)
  - [常见的初始化对象的方法和规范写法](#常见的初始化对象的方法和规范写法)
  - [string拼接操作的API](#string拼接操作的API)
  - [string查找和替换的API](#string查找和替换的API)
  - [string比较操作API](#string比较操作API)
  - [string字串操作API-重要](#string字串操作API-重要)
  - [string插入和删除操作API](#string插入和删除操作API)
  - [string数据存储操作API](#string数据存储操作API)
- [vector](#vector)
  - [vector初始化方式API](#vector初始化方式API)
  - [vector常用赋值操作API](#vector常用赋值操作API)
  - [使用swap缩减空间](#使用swap缩减空间)
  - [vector大小操作API](#vector大小操作API)
  - [vector数据存储操作API](#vector数据存储操作API)
  - [vector插入和删除操作API](#vector插入和删除操作API)
  - [vector基本语法和应用](#vector基本语法和应用)
    - [一种元素排序方式](#一种元素排序方式)
- [deque](#deque)
  - [deque构造函数API](#deque构造函数API)
  - [deque赋值操作API](#deque赋值操作API)
  - [deque大小操作API](#deque大小操作API)
  - [deque双端插入和删除操作API](#deque双端插入和删除操作API)
  - [deque数据存储API](#deque数据存储API)
  - [deque应用范例](#deque应用范例)
- [stack](#stack)
  - [stack构造函数API](#stack构造函数API)
  - [stack赋值操作API](#stack赋值操作API)
  - [stack大小操作API](#stack大小操作API)
- [queue](#queue)
  - [queue构造函数API](#queue构造函数API)
  - [queue存取,插入和删除操作API](#queue存取,插入和删除操作API)
  - [queue赋值操作API](#queue赋值操作API)
  - [queue大小操作API](#queue大小操作API)
- [list](#list)
  - [list构造函数API](#list构造函数API)
  - [list数据元素插入和删除操作API](#list数据元素插入和删除操作API)
    - [list大小操作API](#list大小操作API)
    - [list反转排序API](#list反转排序API)
    - [list基本范例和应用](#list基本范例和应用)
- [set/multiset](#set/multiset)
  - [set/multiset构造函数API](#set/multiset构造函数API)
  - [set/multiset赋值操作API](#set/multiset赋值操作API)
  - [set/multiset大小操作API](#set/multiset大小操作API)
  - [set/multiset插入和删除操作API](#set/multiset插入和删除操作API)
  - [set/multiset查找操作API](#set/multiset查找操作API)
  - [set/multiset使用和应用范例](#set/multiset使用和应用范例)
  - [set/multiset高级应用范例](#set/multiset高级应用范例)
- [pair](#pair)
  - [pair构造函数API](#pair构造函数API)
  - [pair数据查看和修改API](#pair数据查看和修改API)
  - [pair的构造方法](#pair的构造方法)
- [map/multimap](#map/multimap)
  - [map/multimap构造函数API](#map/multimap构造函数API)
  - [map/multimap赋值操作API](#map/multimap赋值操作API)
  - [map/multimap大小操作API](#map/multimap大小操作API)
  - [map/multimap插入数据元素操作API](#map/multimap插入数据元素操作API)
  - [map/multimap删除操作API](#map/multimap删除操作API)
  - [map/multimap查找操作API](#map/multimap查找操作API)
  - [map/multimap修改数据实值API](#map/multimap修改数据实值API)
  - [map/multimap使用范例](#map/multimap使用范例)
  - [map/multimap经典查找范例](#map/multimap经典查找范例)
  - [map/multimap排序范例:重要](#map/multimap排序范例:重要)
- [函数对象-仿函数](#函数对象-仿函数)
  - [谓词](#谓词)
  - [函数对象适配器](#函数对象适配器)
    - [函数对象适配器范式-仿函数适配器bind1st,bind2nd绑定适配器](#函数对象适配器范式-仿函数适配器bind1st,bind2nd绑定适配器)
    - [函数对象适配器范式-伪函数适配器not1,not2取反适配器,bool是返回值](#函数对象适配器范式-伪函数适配器not1,not2取反适配器,bool是返回值)
    - [函数对象适配器范式-把普通函数适配成函数对象bind2nd和ptr_fun](#函数对象适配器范式-把普通函数适配成函数对象bind2nd和ptr_fun)
    - [函数对象适配器范式-调用类自己提供的打印函数](#函数对象适配器范式-调用类自己提供的打印函数)
- [查找算法](#查找算法)
  - [常用遍历算法](#常用遍历算法)
  - [常用排序算法](#常用排序算法)
  - [常用拷贝和替换算法](#常用拷贝和替换算法)
  - [常用算数生成算法](#常用算数生成算法)
  - [常用集合算法](#常用集合算法)
  - [一键替换字符串中的字符](#一键替换字符串中的字符)
  - 











- **[beg,end):   中括号表示 '包括' ,小括号表示 '不包括',  beg会放入数据,但是end 可能会放入也可能不会放入.**

- 

### 关键字

```c++
<algorithm>, <vector> , <string> , <stack>  , < deque> , <queue>, <list>,    <set>    
 算法头文件 , vector   ,  string  ,stack栈容器,   deque  ,  queue ,  list ,set/multiset

vector<type>::iterator   t ; /* 迭代器类型 */
  pair<type, type>       p ; /* 也是迭代器类型 *

```

## STL简单介绍

- **STL 标准模板库, 基于模板实现的.**
- ==**STL 从广义上分为: `容器(container), 算法(algorithm), 迭代器(iterator).`**==
  - ==**容器和算法之间通过迭代器进行无缝连接.**==
- **仿函数就是类,只不过他重载了函数调用符号()括号,**
  - **`class Myfun{  public: bool operator()(int a){ return a} };`**

> **STL的一个重要特点就是 `数据结构和 算法 分离`**



### STL头文件

**在c++ 标准中,STL 被组织成以下13个头文件**

```c++
<algorithm> , <deque>,   <functional>,  <iterator>, <vector>,  <list>,
<map>,       <memory>,  <numeric>,     <stack> ,   <utility>
```



### STL容器的种类

1. **STL中 容器分为两种:   `(容器就是数据结构)`**
   1. **序列式容器:**
      1. **容器中的元素的位置是由进入容器的时机和地点来决定的.`<vector>,<stack>,<deque>,<queue>,<list>.`**
   2. **关联式容器, 容器已经有规则,进入容器的元素的位置不是由时机和地点决定.`<set>`**



### 迭代器的简单描述

- **STL中 迭代器 可以理解为指针,对指针的操作基本都可以对迭代器操作.而且迭代器是容器提供的**
  - **可以对迭代器使用* 操作符,来得到它所指向的数据内容.**
- ==**实际上迭代器就是一个类, 这个类封装一个指针.(也就是重载了很多操作符).**==



### STL中的算法

> **STL中 算法 通过有限的步骤,解决具体问题.(他或大或小,或多或少解决程序中遇到的问题).**

```c++
for_each(迭代器,迭代器,回调参数);  
    // 循环输出两个迭代器之间的所有内容. 需要算法头文件< alogorithm>
    // 返回一个回调函数的类型.(可以是伪函数也可以是普通函数).

[beg,end):   中括号表示 '包括' ,小括号表示 '不包括',  beg会放入数据,但是end 可能会放入也可能不会放入.
```

- **排序算法也就是`<algorithm>`头文件中的`sort()`函数, 不支持不带随机访问的容器**,也就是说`list`这个容器就无法使用他,但是 `list` 这个容器自带 `sort()` 这个排序算法,并不依赖于 外部的排序算法.
- ==**有的容器需要提供自定义类型的排序方法**,比如`<map>,<set>`,那么需要伪函数,在重载()小括号的时候要注意,**`不要使用引用参数`**==
  - **使用普通的参数就好了,要不然会出现权限问题,(如果担心的话,可以在函数结尾添加一个const).**



## 一些算法常用函数

```c++
    deque<int>de;
    vector<int>ve;

    void Print(int val){      //需要我们自己提供回调函数,用于循环打印输出
        cout << val << " ";
    }

    sort(ve.begin(),ve.end());  // 排序算法,只需要提供迭代器,这里如果不指定规则那么他会从小到大来排序
    sort(de.begin(),de.end());  

    for_each(ve.begin(),ve.end(),Print);  // 循环调用了回调函数来实现容器内的数据输出打印.
    for_each(de.begin(),de.end(),Print);  // 迭代器两个, 一个回调函数, 主要作用是输出容器内的数据.
```



### 容器的使用空间

- **`vector` 和 `deque` 在堆上创建空间.**
- **`stack`  在栈上创建空间.**



# 容器STL基本概念

1. **对象元素必须能够被拷贝.**
2. **容器都是值寓意, 而非引用寓意. 向容器中放入元素,都是放入的元素的拷贝份.**
3. **如果元素的成员有指针,注意深拷贝的浅拷贝问题.**
4. **支持 [ ] 中括号下标访问的,基本上都支持随机访问.**
5. **不支持随机访问的容器,就只能 `v.begin() + 1`  绝对不能 `v.begin()+2`   . **



## 每种容器的算法特点

- **`deque` 双端数组:**
  - **操作特点:** 
    - **在两端插入和删除效率都比较高,在指定位置插入的效率相对于vector好一些.也会引起数据元素移动.**
  - **`deque`是分段连续的内存空间,支持随机访问,支持迭代器, 但是用的比较少 `<deque>`**

- **`stack` 栈容器:**
  - **规则:先进后出**
  - ==**只能访问栈顶的最后一个被压入的元素, 不支持遍历,不提供迭代器,也不支持随即访问.**==
  -  **如果想把容器中的内容全部都打印一遍,只能从栈顶.`top()`一个一个往外弹出.`pop();`**
- ==**`vector` 单端数组, 动态数组  可变数组:**==
  - **最常用**
  - **单口容器.从末端插入和删除元素,如果删除头元素,那么所有的元素都要向前移动.**
  - **支持随机访问, 支持 [] 中括号下标访问的,基本上都支持 随机访问**
  - **当vector添加元素,他会自动增长,但是你删除元素的时候,不会自动减少`(使用resize()  缩小空间也是这样)`**
  - **使用 `.swap();` 来巧妙的缩减空间:  具体步骤在 常用赋值操作 API那里.**
- **`queueq` 队列容器:**
  - **规则: 先进先出, 头部插入和删除**
  - ==**不能遍历,不提供迭代器,也不支持随机访问**==
  - **常用函数:**
    - `empty() 容器是否为空.  front()头元素,  back()尾元素,  push() 添加一个元素, pop() 删除队头第一个元素.`

- ==**`list` 双向链表:**==
  - **非常 常用**
  - **在任何位置插入和删除效率都非常好.因为插入和删除相对于链表来说不需要移动元素**
  - **缺点是:** 
    - ==**`不支持随机访问,因为非连续内存空间,所以要保存节点和节点之间的前驱后继的关系. list自己提供了 sort() 来进行排序,但是却不能使用算法文件<algorithm>中的sort(). 因为他不支持随机访问.`**==
  - **优点:**
    - **最大的优点是 find() 查找方法,使用的时候你要清楚 `查找的基础数据类型,查找对象,提供回调(条件).`**

- **`pair` 对组容器:**
  - **将两个值合并成一个值,但是他需要两个参数类型来初始化,一般都是使用调用它的函数,就是`make_pair(key,Elem);`**
    - **第一个存储的是键值,使用 `.first` 来访问, 实值则需要 `.second` 来访问,因为他们两个都返回的是存入的对象或者实值.**

- **`set/multiset` 是依靠二叉树来实现的:**
  - **在初始化和插入元素的时候会自动进行排序,但却不能随意修改元素的值,只能通过删除某个元素,然后再把新的元素插入进来实现修改元素的目的.**
  - **提供只能访问元素的迭代器,支持不可修改的随机访问.**
  - ==**不能存储两个相同的值.**==
  - ==**`multiset`   和 `set` 的唯一区别是 `multiset`可以存储两个key 相同的值(键值);**==

- **`map/multimap`:**
  - **和set基本相同,没什么太大的区别,只是查找的方式略有区别和增强.**
  - **`multimap`和 `map` 的唯一区别是 `multimap`可以存储两个key 相同的值(键值);**



> **vector 与 deque 的比较:**
>
> 1. **`vector.at()` 比 `deque.at()`  效率高,比如`vector.at(0)` 是固定的,`deque` 的开始位置却不固定.**
>    1. **`.at` 提供的是每个元素的访问**
> 2. **如果有大量释放操作的话,`vector` 花的时间更少,这跟二者的内部实现有关.**
> 3. **deque 支持头部的快速插入与删除, 这个deque的优点.**



## STL容器共性机制

- **STL 容器所提供的都是值(value)寓意,而非引用(reference)寓意**
  - **也就是说当我们个容器中插入元素的时候,容器内部实施拷贝动作,将我们要插入的元素再另行拷贝一份放入容器中,而不是将原数据直接放进容器中**
    - ==**也就是说 "我们提供的元素必须能够被拷贝".**==



> - ==**除了 `queue`  和 `stack` 之外, 每个容器都提供可返回迭代器的函数,运用返回的迭代器就可以访问元素.**==
>
> - **通常 STL 不会抛出异常,需要使用者传入正确参数.**
> - **每个容器都提供了一个默认的构造函数和默认的拷贝构造函数.**
> - **大小相关的函数方法:**  
>   - **`.size()` 返回容器中元素的个数,**
>   - **`.empty()` 判断容器是否为空.**



### STL容器使用时机

| 动作 \ 容器  |  vector  |  queue   |   list   |  set   | multiset |     map      |   multimap   |
| :----------: | :------: | :------: | :------: | :----: | :------: | :----------: | :----------: |
| 典型内存结构 | 单端数组 | 双端数组 | 双向链表 | 二叉树 |  二叉树  |    二叉树    |    二叉树    |
|  可随机存取  |    是    |    是    |    否    |   否   |    否    | 对Key而言:是 |      否      |
| 元素搜寻速度 |    慢    |    慢    |  非常慢  |   快   |    快    | 对Key而言:快 | 对Key而言:快 |
| 元素安插移除 |   尾端   | 头尾两端 | 任何位置 | 不支持 |  不支持  |    不支持    |    不支持    |

**因为是二叉树,所以最后一项没有,都不支持随机位置插入和删除**



### STL容器的使用场景

- **`vector`**
  - **比如软件历史操作记录的存储,我们经常要查看历史记录,比如上一次的记录,上上次的记录,但是不会去删除记录,因为记录是事实的描述.**
  - **或者是尾部添加和删除的场景**
- **`deque`**
  - **比如排队购票系统,对排队者的存储可以采用deque ,支持头端的快速移除,尾端的快速添加.如果用vector,则头端移除时会移动大量的数据,速度慢.**

- **`list`**
  - **比如公交车乘客的存储,随时可能有乘客下车,支持频繁的不确实位置元素的移除插入.**
- **`set`**
  - **比如对手机游戏的个人得分记录的存储,存储要求从高分到低分的顺序排列.**
- **`map`**
  - **比如按ID 号存储十万个用户,想要快速通过ID 查找对应的用户.`(二叉树的查找速度是最快的)`**
  - **二叉查找树的查找效率就体现出来了,如果是 vector 容器,最坏的情况下可能要遍历完整个容器,才能找到该用户.**





# string

> **`string  : <string>`**

**重要的区别: char* 是一个指针,string 是一个类.**

==**string 原型是 `typedef basic_string<char> string`**==

- **string**
  - **string 封装了很多实用的成员方法:**
    - ==**查找`find`, 拷贝`copy`,删除`delete`,替换`replace`,插入`insert`,转换成c串 `c_str().`**==
    - **string 不需要考虑内存释放和越界**
    - ==**string 转换 char* 通过 string 提供的 c_str() 方法来实现.**==
    - **注意深拷贝和浅拷贝.**
    - **string 占用的内存 会根据他目前所存储的字符串自动调整,添加就增长,削弱就减小.**
    - **`string` 也提供迭代器 `.begin()` 指向第一个元素的位置, `.end()`指向最后一个元素的下一个空位置.**

- ==**要使用 `.at(数字)` 来访问和修改 `string`中某个位置的元素.**==



#### 常见的初始化对象的方法和规范写法

```c++
#include <string>
/* 初始化 */
	string s1;  
	string s2(10,'a');         // 存在10个 a  结尾有个\0 , 也就是说真正的数组长度是 11
	string s3("sadnnjasd");    // 字符串初始化
	string s4(s3);             // 对象初始化

/* 赋值 */
    s2 = "asssd";         //覆盖了原先s2 内的数值.也调整了所占用的内存长度,由10变成了5
    s2 = s3;              //还是覆盖,然后调整内存长度
    s2.assign("asdqew");  //通过成员方法也可以赋值

for(int a = 0; i< 10; i++){
  cout << s2[i];    // 重载了[] 操作符,可以像数组一样来使用,一旦越界程序会崩, 不建议使用
  cout << s2.at(i); //成员方法 .at() 提供字符串每个字符的访问. 一旦越界则会抛出异常 out_of_ranges.
}                   // 可以捕获和处理这个异常, 建议使用
```



### string拼接操作的API

```c++
一般都是这样调用的 string s;  s.append("kasd"); //把 kasd 添加到 s 的结尾.

/*  将字符串链接到结尾的操作 */
string& operator+=(const string& std);     //重载 += 操作符,对象参数
string& operator+=(const char* str);    //重载 += 操作符, c字符串参数
string& operator+=(const char c);       // 重载 += 操作符, 一个字符参数

/*  将字符串链接到结尾的操作 */
string& append(const char* s);      //把字符串 s 链接到当前字符串结尾
string& append(const char* s, int n);   // 把字符串 s 的前 n 个字符连接到当前字符串结尾
string& append(const string& s);        // 与 += 操作相同
string& append(const string& s,int pos,int n);  //把对象 s 中从 pos 开始的 n 个字符串连接到结尾.
string& append(int n ,char c);        // 在当前字符串结尾添加 n 个字符 c 
```



### string查找和替换的API

```c++
一般都是这样调用的 string s; s.find("aa",10);  //在s中查找 aa,从s的第十个位置开始, 返回位置下标,从0开始
// 如果没找到, 那么就会返回一个 0xFF FF FF FF FF FF FF FF  ,也就是 (2^64)-1


/*  从前向后查找操作 */
int find(const sting& str, int pos = 0)const;  // 查找str第一次出现位置,从 pos 位置开始查找.
int find(const char* s, int pos = 0)const;   // 查找s 第一次出现位置,从 pos 位置开始查找.
int find(const char* s, int pos, int n)const:   // 从pos 位置查找 s 的前n个字符第一次出现的位置.
int find(const char  c, int pos = 0)const;   // 查找字符 c 第一次出现的位置.

/*  从后向前查找操作 */
int rfind(const string& str, int pos = npos)const;  // 查找str最后一次出现的位置,从pos位置开始查找
int rfind(const char* s,int pos=npos)const;   // 查找 s 最后一次出现的位置,从 pos位置开始查找
int rfind(const char* s,int pos ,int n)const;    // 从pos处查找 s 的前 n 个字符最后一次的位置.
int rfind(const char  c,int pos = 0)const;     // 查找 字符 c 最后一次出现的位置

/*  替换操作 */
string& replace(int pos, int n, const string& str);  //替换从pos开始 n 个字符为字符串 str
string& replace(int pos, int n, const char* s);    //替换从pos 开始的 n 个字符为字符串 s  
```

- **`find` 和 `rfind` 的区别:** 
  - ==**`find` 是从前向后走, `rfind` 是从后往前走. 但返回值永远是从前向后数.末尾不会变成开头.**==

- ==**他们的返回值是出现的位置,是从0 开始的,和字符数组一样的计数方式.**==
- ==**`npos` 是字符串结尾的最后一个位置, `pos` 是字符串的开始位置.**==



### string比较操作API

```c++
int compare(const string& s)const;  // 与对象 s 比较
int compare(const char* s)const;  // 与字符串 s 比较
```

- **`compare` 函数在  `this > s 时返回 正数` , ` this < s 时返回 负数`, `this = s 时返回0;`**
- **比较区分大小写,比较时参考字典顺序,排在前面的最小.比较 ascii码**
- **大写的A 比小写的a 要小. ascii码**
- **一般都是用来判别两个字符串是否相等的, 一旦用来判断大小的话,则会非常混乱.**
- **对比的方式都是按照同位置上的字符来比较的,如果相等则对比下一个位置,一旦出现不相等,则后面不会再进行比较,然后返回结果.**



### string字串操作API-重要

```c++
string substr(int pos = 0, int n = npos)const; // 截取返回 从 [pos 位置开始到第 n) 个位置的字符串

范例: 
string s1 = "abcde";
string s2;
s2 = s1.substr(1,3);   
    // 返回第1个位置后3个字符,在后面添加\0
    //  s2 = bcd\0
    //  [1, 3)   包括1  但不包括3
```



### string插入和删除操作API

```c++
/*  插入操作 */
string& insert(int pos, const char* s);      // 在 pos 位置 插入字符串
string& insert(int pos, const string& str);  // 在pos位置 插入 str对象中存储的字符串
string& insert(int pos, int n, char c);      // 在pos 位置插入 n 个字符 c

/*  删除操作 */
string& erase(int pos, int n = npos);        // 删除从 pos 开始的 n 个字符
```



### string数据存储操作API

```c++
char& at(size_t pos); 
       // 返回pos位置的字符, 如果访问越界,则会抛出抛出 out_of_range 异常,(这个最安全最好).

char& operator[](size_t pos);   // 返回pos位置的字符, 如果访问越界,程序直接崩,不会抛出异常.
```

==**要使用 at(数字) 来访问和修改 string中某个位置的元素.**==





# vector

> **`vector` :   ( 动态数组  可变数组 )    需要头文件 `< vector >`   `<algorithm>`**

- **`vector`容器,是单口容器.**
  - **从末端插入和删除元素,如果删除头元素,那么所有的元素都要向前移动.**

- **`vector` 也提供迭代器 `.begin()` 指向第一个元素的位置, `.end()`指向最后一个元素的下一个空位置.**



> ==**vector 动态内存增长原理:**==
>
> **`当插入新元素的时候,如果原来的空间不足,那么 vector 会重新申请一块更大的内存空间(一般情况下是原先的2倍),将原空间数据拷贝到新空间,然后释放旧空间的数据和内存. 再把新元素插入到新空间.`**



> ==**vector 支持随机访问.**==
>
> - **调用 `v.at(2);`  可以访问到 v.begin() +2 的元素.**
> - **但是其他的不支持随机访问的容器,就只能 v.begin() + 1  绝对不能 v.begin()+2   . 而且支持 [] 中括号下标访问的,基本上都支持随机访问.**



**当向 `vector` 添加元素,他会自动增长,但是删除元素的时候,不会自动减少.(使用resize()  缩小空间也是这样).**

==**使用`swap();`缩减空间来巧妙的缩减空间:  具体步骤在 [使用swap缩减空间](#使用swap缩减空间) 内有介绍.**==

```c++
vector<int>v;

int* vp1 = &v[0];       //得到了元素首地址( 这个很有用 );
int* vp2 =  reinterpret_cast<int*>(&v);  // 得到对象的首地址(注意区分);

vector<int>::iterator it = v.begin();    // it 是迭代器类型.指针

typedef typeof(v) v_i;
v_i::iterator it = ve.begin();
```



### vector初始化方式API

```c++
vector<int>v;

vector(v.begin(),v.end());   // 构造函数 将v[begin(),end()] 区间中的元素拷贝给本身. _这个最常用_
vector(int* arrBegin, int arrLen);  // 构造函数,使用数组初始化, 后面是数组元素的个数
vector( n ,elem);            // 构造函数 将 n 个 elem元素 拷贝给本身.  
vector(const vector &vec);   // 拷贝构造函数
clear(无参数);                // 清空容器内所有的元素和数据
```



### vector常用赋值操作API

```c++
assign(beg,end);       
/* 将 [ beg,end ) 区间中的数据保留下来, 并清除多余的内容
 * 例如  vector<int> a(5, 9);   //将5个9 赋值给a , a.size = 5;
 *       a.assign( a.begin(),  a.begin()+3 );  // 只保留 3个元素, 其余的都清除,并设置 end()
 */ 

assign( n , elem); //将 n 个 elem元素 拷贝赋值给自身
vector& operator= (const vector& vec);    // 重载等号操作符

swap(vec);  
 //将 vec 与本身的指向存储数据的内存空间的指针进行了交换,并没有改动任何内存中的数据,仅仅修改了指针.
```

**当vector添加元素,他会自动增长,但是你删除元素的时候,不会自动减少.`(使用resize()  缩小空间也是这样).`**



### 使用swap缩减空间

```c++
vector<int> v;
for(int i = 0; i < 1000 ; i++){
  v.push_back(i);     // 向容器中添加1000个元素
}

cout << v.capacity() << endl;    //会输出 1024, 代表容器可容纳1024个元素
v.resize(10);   //把元素缩减到10个.抛弃后面所有超出的元素, 但是内存空间不会释放.还存在1000个元素

cout << v.capacity() << endl;    //会输出 1024, 也就是说 ,resize没什么用.

vector<int>(v).swap(v);   
/* 详解:  vector<int> (v)  表示定义一个匿名对象,使用v来进行初始化, 
*        然后  .swap(v); 表示和 v 交换内存空间,这个时候 v就得到用v初始化的匿名对象的空间指针,
*        匿名对象得到了 原先v的内存空间指针指向. 而且这个匿名空间会自动销毁,然后回收内存.
*/
typedef typeof(v)  v_i;
v_i (v).swap(v);

cout << v.capacity() << endl;    //会输出 10, 这样才是真正的释放掉了空间
```





### vector大小操作API

```c++
size(无参数);    // 返回容器中已存在的元素的个数.
empty(无参数);   // 判断容器是否为空, 如果是空 则返回 真 true ,不空则返回 假 false

resize(int num);/* 重新指定容器当前容纳元素的长度为num ,若容器变长,则以默认值填充新位置,如果容器变短,
                 *  则末尾超出容器长度的元素将被删除.(num就表示修改后的容器内会有num个元素)
                 */
resize(int num, elem);
        /* 重新指定容器当前容纳元素的长度为num ,若容器变长,则以 elem 值填充新位置,
         * 如果容器变短, 则末尾超出容器长度的元素将被删除.(num就表示修改后的容器内会有num个元素)
         */

reserve(int len); // 容器预留 len 个元素长度,预留位置不初始化,元素不可访问.

capacity(无参数); 
 /* 返回容器的容量,就是容器目前指向的内存一共可以容纳多少个元素
  *(capacity()永远大于或等于 size() ,返回的是容器内存最多存储的元素个数(如果达到上限还能扩充),
  * 不是目前存在的元素个数.
  */
```

- **在使用 `resize() ;` 缩小容器中存储的元素的时候, 虽然元素个数缩少了,但是内存却保持原样,(没缩小之前的与样子).**
- **`reserve()` 和 `resize()` 的区别:**
  - **`reserve` 是容器预留空间, 但在空间内不真正创建元素对象,所以在没有添加新的对象之前,不能引用容器内的元素.**
  - **`resize`  是改变容器的大小,再创建对象,并初始化, 因此调用这个函数之后,就可以引用容器对象了.**

- **如果你知道容器大概要存储的元素个数, 那么你可以使用 `reserve` 预留空间,以提高效率.**
- **如果使用`resize` 来减少容器的容量,那么减少后应该使用 `swap` 来和一个匿名对象进行初始化和交换内存指针,来释放内存.**



### vector数据存储操作API

```c++
at(int idx);   //返回索引 idx 所指向的数据, 如果 idx越界, 抛出 out_of_range 异常. (应该使用这个)
operator[](size_t pos);   // 返回索引 idx 所指向的数据,越界时 程序直接崩溃,不会抛出任何异常.
front(无参数);   // 返回容器中的第一个数据元素.
back(无参数);    // 返回容器中的最后一个数据元素.

或者使用 迭代器
```

- ==**索引和访问应该使用 at() 来进行.**==



### vector插入和删除操作API

```c++
/* 插入操作 */
insert(const iterator pos, int count, elem );  //迭代器指向位置pos 插入 count个元素 elem.
insert(const iterator pos, ele); //迭代器指向位置pos 插入一个 ele 元素
push_back(一个参数);  // 在末尾压入(插入)一个数据元素

/* 删除操作 */
pop_back(无参数); //弹出在末尾最后一个数据元素(也就是删除最后一个元素)
erase(const iterator start, const iterator end); // 删除迭代器从 [start 到 end) 之间的元素
erase(const iterator pos);  // 删除迭代器指向的一个元素, 并返回下一个元素的迭代器指针
clear(无参数);  // 删除容器中的所有元素
```

- **这些API 都是没有返回值的,所以无法判断删除了哪个元素.**
  - 要使用 `auto a = v.back();`  来获取最后一个元素,然后决定是否删除
- **在删除元素之前 还是尽量确定后再进行删除.**
- **在使用迭代器循环检测和删除的时候,要这么来更新迭代器:**
    - ==**`item  = ver.erase(item);`  // 删除迭代器指向的数据, 然后得到下个元素的迭代器**==



### vector基本语法和应用

```c++
//
//  main.cpp
//  effectiveC
//
//  Created by lq on 2021/5/29.
//

#include "main.hpp"
#include <iostream>
#include  <vector>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

inline void Pint(const int n)
 {
     cout << n << endl;
     
 }

class Person{
    public:
        Person(const int _id = 0, const int _age = 0):id(_id),age(_age) {}
        int id;
        int age;
};


int main(void){
    vector<int> v  ;   // v 是个容器,存放的元素类型是 int
    int arr[] = {1,23,4,5,6,7,8};
    vector<int>v1(arr, arr+sizeof(arr)/sizeof(int));  // 使用第一个构造函数,用int数组初始化,元素个数
    //这里要注意,arr+1 只能走4个字节, arr+7 会走7个四个字节(上面sizeof计算会得到7)

    vector<int>v2(v1.begin(),v1.end());  //和上面差不多
    
    v.push_back(10);   // 向容器中放入一个int 类型的元素 10
    v.push_back(20);   // 再向容器中压入一个int类型的元素 20
    
    vector<int>::iterator pBegin = v.begin();   //得到v的迭代器      可以把这个看成指针
    vector<int>::iterator pEnd = v.end();   //一个开始位置一个结尾位置  可以实现++ 和-- *运算

    
    for_each(vector<int>::iterator(v1.begin()), vector<int>::iterator(v1.end()), Pint);
    for_each(pBegin,pEnd,Pint);
/* inline void Pint(int n){   cout << n; }    //这个是我们自定义的回调函数
 * 参数结构:  容器头,容器尾,自定义的回调函数.  这个是容器算法,在<algorithm>中
 * 尽量不要使用v.begin()和v.end() 来代替, 或者匿名迭代器.
 * 容器中可能存放基础的数据类型,也可能存放自定义数据类型
 * 这个函数并不是直接可以打印容器内的内容,而是调用我们自定义的回调函数来输出和打印的.
 * 这是使用算法进行遍历 ,  这个算法的主要功能也就是遍历.
 */
    
    
/* 另一种初始化和遍历算法 */
    vector<Person*> P;           // 一个Person指针的容器 ,容器里面存放的是指向 Persion对象的指针.
    Person *l1 = new Person (10, 20),
           *l2 = new Person (30, 40),
           *l3 = new Person (50, 60);
    P.push_back(l1);    // 压入数据
    P.push_back(l2);
    P.push_back(l3);

    
    //第二种遍历方法,不使用算法的.
    for (vector<Person*>::iterator it = P.begin(); it != P.end(); it++) {
        cout << (*it)->age << " " << (*it)->id << endl;
/* (*it) 表示取出迭代器所指向的对象,和指针一样的操作,拿到的是对象或指针 ,可以. 或 -> 成员和函数 */
    }
    std::cout << endl;
    
    // 遍历 带删除的方法
    for( vector<Person*>::iterator it = P.begin(); it != P.end() ; ){
        cout << (*it) ->age << "  " << (*it)->id << endl;
        delete *it;
        *it = nullptr;
        it = P.erase(it);
    }
    
    return 0;
}

```

#### 一种元素排序方式

```c++
#include <iostream>
#include  <vector>
#include <algorithm>
using namespace std;

class Plar{
    public:
        Plar(int a =0) : mPlar(a){}
        int mPlar;
};  //这个类中就有一个int 的公有成员数据

bool Mycompare ( Plar& p1,Plar& p2){
  return p1.mPlar < p2.mPlar;  //返回假则交换.从小到大排序,
}

int main(void){
    vector<Plar> vp;     // Plar类型的容器.  把它当成已经拥有 很多类元素的值
    Plar a(1);
    Plar b(2);
    Plar c(3);
    Plar d(4);
    Plar e(5);
    Plar f(6);
    Plar g(7);
    
    vp.push_back(c);
    vp.push_back(d);
    vp.push_back(a);
    vp.push_back(g);
    vp.push_back(f);
    vp.push_back(e);
    vp.push_back(c);
    vp.push_back(b);
    
    vector<Plar>::iterator vit = vp.begin();   // 得到第一个元素的迭代器.指针
    (*vit).mPlar = 10;   // 通过新定一个迭代器类型,可以这样来给类中的内容赋值,和调用成员函数(只能是公有)
    sort(vp.begin(),vp.end(),Mycompare);       //自定义排序方式,会将容器的两个相邻的内容传递给回调函数.
    for (vector<Plar>::iterator it = vp.begin() ; it != vp.end() ; it++){
        cout <<  it->mPlar << endl;
    }
}

```





# deque

> **deque:  双端数组 ,需要头文件<deque>**

- ==**`deque` 在两端频繁插入删除的时候可以选用这种容器.**==



- **`deque` 是双口容器, 可以在开头插入和删除元素,尾部也可以插入和删除元素.**

- **`push_front()`,`pop_front()` 开头插入和删除元素**
- **`push_back()`,`pos_back()` 尾部元素插入和删除元素**
- ==**`deque` 也提供迭代器 `.begin()` 指向第一个元素的位置, `.end()`指向最后一个元素的下一个空位置.**==

- **`deque` 也提供 `.front()`访问第一个元素, `.back()` 访问最后一个元素.**

- ==**`deque` 的实现相当于数组与链表的组合, 他和`vector` 的最大区别就是:**==
  - **它是由很多不连续的内存空间组合起来的,相当于一个表格的存在.**
  - **每块空间都很大, 然后让这几个空间来组合成一个链表表格**
- **`deque` 的内存是自己进行管理的,不需要我们手动来释放空间`(比如 vector<type>(v).swap(v) 来赋值和交换).`**

- `deque<type>::iterator it = v.begin();    // it 是迭代器类型.指针`
- **`deque` 的原理是 有个中控器里面 存储和管理 节点,节点连接缓冲区(就是开辟的内存空间指针),进而操纵内存.**



> ==**deque的特性:**==
>
> 1. **双端插入和删除元素效率较高.**
> 2. **指定位置插入也会导致数据元素移动,降低效率.  (也就是修改表的排序).**
> 3. **可随机存取,效率高.也就是说可以通过[] 下标来访问.  (毕竟是查表嘛).**
> 4. **不用担心内存不足.  (因为每次添加都是一次内存申请和表格的数据添加).**
> 5. ==**排序效率非常低下!.  ( 应该把`deque`的内容拷贝给`vector`,排序完成后再拷贝回来).**==



- `::iterator`  是迭代器的类型.

```c++
deque<int>d1;  
d1.push_back(10);

deque<int>::iterator it = d1.begin();  // it 得到了d1 的迭代器所指向的第一元素的位置.
cout << *it << endl;        //  *it 会得到迭代器所指的元素内容.(也就是 int 类型的数据)
int i =0;
cout << d1.at(i) << endl;  //这样也可以得到容器中的元素内容.(也就是int类型的数据)
```



### deque构造函数API

```c++
deque<int> deqT;     // 默认构造函数格式.   deqT 是一个对象.
deque<int> deqT(beg,end);    // 构造函数将[beg,end) 区间中的元素拷贝给本身.
/* [beg,end):   中括号表示 '包括' ,小括号表示 '不包括',  beg会放入数据,但是end 可能会放入也可能不会放入. */

deque<int> deqT(n,elem);     // 构造函数将 n 个 elem 拷贝给本身.
deque<int> deqT(const deque& deq);  // 拷贝构造函数, 使用deque对象来初始化一个新对象.
```



### deque赋值操作API

```c++
assign(beg,end);     // 将[beg,end)区间中的数据拷贝赋值给本身;
assign(n, elem);     // 将 n 个 elem 拷贝赋值给本身.
deque& operator= (const deque& deq); // 等号操作符重载
swap(deq);          // 将deq 和本身的元素互换 .
```



### deque大小操作API

```c++
deque.size(无参数);  //返回容器中元素的个数

deque.empty(无参数); // 判断容器是否为空, 空返回 true  ,非空返回 false

deque.resize(num);  //重新制定容器的长度为num,容器变长,则使用默认值填充新位置,容器变短,则末尾元素被删除.
deque.resize(num,elem) ;  // 同上, 只不过使用 elem 来填充新位置.
```



### deque双端插入和删除操作API

```c++
push_back(elem);  // 在容器尾部添加一个数据
push_front(elem); // 在容器头部插入一个数据

pop_back(无参数);  // 在容器尾部删除一个数据
pop_front(无参数); // 在容器头部删除一个数据
```

- **这些API 都是没有返回值的,所以无法判断删除了哪个元素.**
  - **`要使用 auto a = d1.front(); 来获取元素,然后决定是否删除`**
- **在删除元素之前 还是尽量确定十分要进行删除.**



### deque数据存储API

```c++
at(idx);          // 返回索引 idx 所指的数据,如果 idx 越界,抛出 out_of_range.
operator[](idx);  // 返回索引 idx 所指的数据,如果 idx 越界, 不抛出异常,直接出错.
front(无参数);     // 返回第一个数据
back(无参数);      // 返回最后一个数据
```

- **删除和插入随机位置的效率都不高**



### deque应用范例

```c++
#include <deque>
#include <iostream>
using namespace std;

class Plar{ public:  int mPlar; };  //这个类中就有一个int 的公有成员数据
bool Mycompare ( Plar& p1,Plar& p2){ return p1.mPlar < p2.mPlar; }  //返回假则交换.从小到大排序,
int main(void){

      deque<int>d4(10,3);   // 使用 10个3 来初始化 d4
      int i =0;

    // 循环输出数据的基本案例:
      for(deque<int>::iterator it = d4.begin(); it != d4.end();it++,i++){
          cout <<  d4.at(i) <<endl;   // 循环遍历,这样比较安全,也可以使用下标
          cout << *it << endl;  // 遍历 和d4.at(i); 效果相同.
      }



      
      deque<Plar> dp;     // Plar类型的容器.  把它当成已经拥有 很多类元素的值
      deque<Plar>::iterator dit = dp.begin();   // 得到第一个元素的迭代器.指针
      (*dit).mPlar = 10;   // 通过新定一个迭代器类型,可以这样来给类中的内容赋值,和调用成员函数(只能是公有)
      
      sort(dp.begin(),dp.end(),Mycompare);       //自定义排序方式,会将容器的两个相邻的内容传递给回调函数.
}
```







## stack

> **stack 栈 容器: 需要头文件 `<stack>`**    

- **这个容器规则是 先进后出 `(first in last out, FILO)`的数据结构.**
- ==**该容器只有一个出口,`stack` 只允许 `在栈顶新增元素,移除元素,获得顶端元素`,但是除了顶端之外,其他地方不允许存储元素,只有栈顶元素可以被外界使用.**==

- ==**stack 不具有遍历行为,不支持随机存取,没有迭代器. 只能通过 `.top`从栈顶获取元素.以及删除元素.**==

- **由栈顶压入`.push 压栈`  ,`.pop 出栈` , `.top(); 可以返回栈顶的元素(也就是最后一个压入的元素)`.**

- **如果想读取 `stack` 容器中的某个元素内容,那么必须把这个元素和栈顶之间的元素全部弹出,才能访问这个元素.**

> **一个栈的入栈顺序是: a b c d e , 则出栈的顺序是 e d c b a .**



### stack构造函数API

```c++
stack<T> stKT;           //stack 采用模版类实现
stack(const stack& stk); //拷贝构造函数
```



### stack赋值操作API

```c++
stack& operator=(const stack& stk);   //重载等号操作符
```



### stack大小操作API

```c++
empty(无参数);  // 判断堆栈是否为空, 空则返回 true  ,非空则返回 false
size(无参数);   // 返回堆栈的大小
```

> **一般来说使用 `.empty()` 来判断是否达到容器结尾,因为这种容器必须弹出一个才能访问下一个,一旦容器内没有任何内容了,  就判断到底了,也就停止了继续向下的循环.(使用.size() > 0  也可以,但是效率会略微减少)**





## queue

> **queue 队列容器 : 需要头文件 `< queue >`**



- **不要和 deque 弄混了.`deque 是双端数组`.**
- ==**这个容器的规则是: `先进先出, 一端插入 另一端 删除. 而且不能进行遍历. 不支持随机访问. 不提供迭代器`**==

- ==**元素只能从队尾插入,从队头来进行删除.**==

- **通过 `.push()` 向队尾插入元素,`.pop()` 来删除队头的第一个元素.**

- **通过 `.back()` 来查看队尾最后一个元素, `.front()` 来查看队头的第一个元素.**

- **这个容器仅仅支持 从队尾插入和 队头删除操作,而且没有遍历,也没有迭代器.更没有两端同时删除的操作API.**



### queue构造函数API

```c++
queue<T> queT;   // queue 采用模版类实现, queue 对象的默认构造形式.
queue(const queue& que);  // 拷贝构造
```



### queue存取,插入和删除操作API

```c++
push(elem);  // 往队尾添加元素
pop(无参数);  // 从队头移除第一个元素

back(无参数); // 返回最后一个元素的内容
front(无参数);// 返回队头的第一个元素的内容
```



### queue赋值操作API

```c++
queue& operator= (const queue& que);  // 重载等号操作符
```



### queue大小操作API

```c++
empty(无参数);  // 判断队列是否为空,空时返回 true , 非空 返回 false
size(无参数);  // 返回队列大小,就是有多少个元素
```

>  **一般来说使用 .empty() 来判断是否达到容器结尾,因为这种容器必须弹出一个才能访问下一个,一旦容器内没有任何内容了, 就判断到底了,也就停止了继续向下的循环.(使用.size() > 0  也可以,但是效率会略微减少)**





## list

>  **list 链表容器 : 头文件 `<list>`**

==**可以把list 看成是链表,支持头插入和尾插入,支持迭代器. 但是不支持随机访问.**==

- **链表是由一系列的节点组成, 节点包涵两个域,一个数据域,一个指针域.**

- **链表内存是非连续的.**
  - **非连续内存,添加删除元素 时间复杂度都是常数项, 不需要移动元素, 比数组添加删除效率高.**
  - **链表只有在需要的时候 才会分配内存空间.**
  - ==**链表需要额外的空间保存节点关系,前驱 后继关系.**==
  - **链表只要你拿到第一个节点,就相当于拿到了整个链表.**



### list构造函数API

```c++
list<T> lstT; // list采用类模版类实现,对象的默认构造函数形式.
list(beg,end); 
      //构造函数将(beg,end) 区间中的元素拷贝给本身.(如果是链表实现的话,这么拷贝可能会出现浅复制问题)

list(n,elem); // 构造函数将 n 个lelm 拷贝给自身.
list(const list& lst);  // 拷贝构造函数.
```



### list数据元素插入和删除操作API

```c++
assign(num, elem);   //将num 个 elem元素插入到容器中, 默认在结尾插入.

push_back(elem); // 在容器尾部添加一个数据
push_front(elem); // 在容器头部插入一个数据

pop_back(无参数);  // 在容器尾部删除一个数据
pop_front(无参数); // 在容器头部删除一个数据

insert(pos,elem);    // 在pos 位置插入 elem 元素的拷贝,返回新数据的位置.
insert(pos,n,elem);  // 在pos 位置插入 n 个 elem 数据, 无返回值.
insert(pos,beg,end);  // 在pos 位置插入 [beg,end) 区间的数据, 无返回值.

clear(无参数);  //删除容器的所有数据.
erase(beg,end);  // 删除 [beg,end) 区间的数据, 返回下一个数据的位置
erase(pos) ;   // 删除 pos 位置的数据, 返回下一个数据的位置.
remove(elem);  // 将容器中所有与 elem 值匹配的元素,移动到末尾
```



### list大小操作API

```c++
size(无参数);  // 返回容器中元素的个数.
empty(无参数);  // 判断容器是否为空, 空时 true ,非空 false
resize(num);  // 重新制定容器的长度为 num ,若比原长度长,则使用默认值填充,若短,则删除超出部分.
```



### list反转排序API

```c++
reverse(无参数); 
         // 反转链表, 比如lst 包含 1,3,5,7  这三个元素, 运行此方法后, lst就包含 7,5,3,1 元素. 

sort(无参数或 回调函数);   
         // list 排序 ,默认的排序是由小到大. 也可以自定义回调函数,(自定义类型必须回调函数).
```

- **`sort()` 这个排序算法是属于这个 list 容器的,并不是其他的算法.**
- **`sort()` 回调函数必须是 bool 类型的返回值, 他会把两个容器容纳的两个相邻的类型的元素传入给回调函数,通过返回值来确认时候调换.**
  - 例如: `list<int> lis;  sort(compare);  bool compare(int a, int b){}   //这就是回调函数格式`

- **因为外部的 `sort()` 算法并不支持 不带随机访问的容器的, 所以 list 这个容器只能自带一套算法了.**



### list基本范例和应用

```c++
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

bool mycompare02(int a, int b){  // 自定义回调函数,排序要调用, 由到大小
    return a > b;
}


int main(void)
{
    // 初始化和赋值操作
    {
        list<int>mlist1;
        mlist1.assign(10,5);  // 将10个5 拷贝赋值给 mlist1
        list<int>mlist2(10,10);
        list<int>mlist3(mlist2);
        list<int>mlist4(mlist2.begin(),mlist2.end());
        
        for(list<int>::iterator it = mlist4.begin();it != mlist4.end();it++){
            cout << *it << " " ;
        }
        cout << endl;
        
    }
    
    {
        //插入
        list<int> mlist;
        
        mlist.push_back(100);
        mlist.push_front(200);
        
        mlist.insert(mlist.begin(),300);
        mlist.insert(mlist.end(), 400);
        // 300 , 200 ,100, 400
        list<int>::iterator itm = mlist.begin();  //300
        itm++; //200
        itm++; //100
        mlist.insert(itm,500);  // 300 , 200 ,100, 500 ,400
        mlist.insert(mlist.end(),200);  // 300 , 200 ,500, 100 ,400, 200
                                       //插入迭代器指向的位置上, 本身指向的元素向后移动
        
        for(list<int>::iterator its = mlist.begin();its != mlist.end();its++){
            cout << *its << " " ;
        }
        cout << endl;
        
        //删除
        mlist.pop_back(); // 300 , 200 ,500, 100 ,400
        mlist.pop_front();    // 200 ,500, 100 ,400
         
        //    mlist.erase(mlist.begin(),mlist.end());  //相当于调用 mlist.clear();
        mlist.remove(200);  // 删除所有匹配的200
                            // 500, 100 ,400
        for(list<int>::iterator its = mlist.begin();its != mlist.end();its++){
            cout << *its << " " ;
        }
        cout << endl;
    }
    
    {
        // 赋值操作和swap 内存指针交换
        list<int>mlist;
        mlist.assign(10,10);
        
        list<int>mlist2;
        mlist2 =  mlist;  // 深拷贝
         
        mlist2.swap(mlist);  // 双方内存指针交换
    }
    
    {
        //反转
        list<int>mlist;
        for(int i = 0; i < 10 ; i++){
            mlist.push_back(i);
        }
        // 0 , 1, 2, 3, 4,5 ,6 , 7, 8, 9
        
        for(list<int>::iterator it = mlist.begin(); it != mlist.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
        
        
        mlist.reverse();    // 容器y元素反转, 倒序.
        for(list<int>::iterator it = mlist.begin(); it != mlist.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
    
    {
        // 排序
        list<int> mlist;
        mlist.push_back(2);
        mlist.push_back(1);
        mlist.push_back(7);
        mlist.push_back(4);
        mlist.push_back(8);
        mlist.push_back(5);
        
        mlist.sort();       //默认排序
        
        for(list<int>::iterator it = mlist.begin(); it != mlist.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
        mlist.sort(mycompare02);   // 调用回调函数来排列顺序, 他接受一个 函数, 函数需要接受两个值
        for(list<int>::iterator it = mlist.begin(); it != mlist.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
}
```





## set/multiset

> **set/multiset  容器 :  他们同用一个同头文件 `<set>`    ,multiset:表示多重集合,多重映射,多重对应**

- ==**set 和 multiset 是两个容器 ,他们所有的内容全部相同,只有元素的重复不同**==
  - **set不能出现重复的键值,multiset却可以重复.**
- ==**两种容器最大的区别是: **==
  - ==**set 容器中不允许出现重复的元素. multiset 允许出现重复元素.**==

- **set/multiset 的特性:**
  - **所有元素会根据元素的值自动进行排序(如果是对象的话,那么我要提供对象的排序条件).**

- **set 是以 `RB-tree(红黑树 red black tree,平衡二叉树的一种) `为底层机制,其查找效率非常好.**
  - **目前主流是非平衡数**

- **set是提供迭代器的,但是不允许使用迭代器来修改元素的值.**
  - ==**如果想要修改那么就 删除 想要 修改 的元素,然后添加新元素.**==
- **set 的默认排序是从小到大的,也可以是依靠 ASCII 码来进行.**
- **set 改变默认排序的方法:**
  - **需要仿函数**

- ==**set 的遍历有三种方法: 先序遍历,中序遍历,后续遍历.**==



### set/multiset构造函数API

```c++
set<T> st;             // set 默认构造
mulitset<T> mst;       // multiset 默认构造
set( const set&  st);  //拷贝构造


//类参数和排序参数 以及类查找  . 这里面的参数需要写全,尤其是it迭代器那里,一定要写全.
class Person{    // 容器内存储的对象
public: Person(int age,int id):age(age),id(id){}
      int id;
      int age;
};

class mome{   // 伪函数 类.
public:  bool operator()(Person a,Person b)const{
             return a.id > b.id;         // 排序所依赖的方式.
          }
};

set<Person,mome> sp;      //指定一类型, 并且设置自定义的排序伪函数 .
set<Person,mome>::iterator ti1 = sp.begin();     // 对应的 迭代器
set<Person,mome>::iterator ti2 = sp.find(Person(1,4));   // 查找匹配 一个匿名对象 ,返回迭代器
```



### set/multiset赋值操作API

```c++
set& operator=(const set& st);   //重载等号操作符
swap(st);   //交换两个集合容器
```



### set/multiset大小操作API

```c++
size(无参数);  //返回容器中元素的数目
empty(无参数);  //判断元素是否为空. 空 返回true ,非空 返回 false
```



### set/multiset插入和删除操作API

```c++
insert(elem);  //在容器中插入元素.

clear(无参数);  //清除容器内所有的元素.
erase(pos);    //删除 pos 迭代器所指的元素, 返回下一个元素的迭代器.
erase(beg,end);  // 删除区间 [beg,end) 的所有元素, 返回下一个元素的迭代器.
erase(elem);  // 删除容器中值为elem 的元素. (set的话仅仅只是删除一个元素,因为他不能存储两个相同的元素)
```



### set/multiset查找操作API

```c++
find(Elem); //查找元素是否存在,若存在,返回该元素的迭代器,若不存在,返回.end()迭代器; key就是elem.

lower_bound(keyElem);  //返回第一个 key  >= keyElem 键值元素的迭代器.
upper_bound(keyElem);  //返回第一个 key  >  keyElem 键值元素的迭代器.
equal_range(keyElem);  //返回容器中 key 与 keyElem 相等的上下限的两个迭代器.(需要pair容器来接收)

pair<set<int>::iterator,set<int>::iterator>myret = s1.equal_range(2);
//需要这样写来接受 equal_range() 返回的两个迭代器,因为他返回的是有两个参数的两个类模板,pair是对组容器
// 在s1 中寻找 2 这个元素, 返回上下限的两个迭代器.
	myret.first;  // 这个返回值是第一个返回的参数,就是 lower_bound 值;
	myret.second; // 这个返回值是第二个返回的参数,就是 upper_bound 值;
```

- 查找是非常重要的操作,因为是以二叉树来实现的,而二叉树的基本使用方式就是用来查找数据的.
- **返回的 .end()  ,指向了结尾后的位置, 所以可以使用尾迭代器 来进行比对,来确认是否找到了需要的key值.**



### set/multiset使用和应用范例

```c++
#include <iostream>
#include <set>
using namespace std;

class Myfun{
public:
    bool operator()(int a,int b){
        return a > b;       // 返回 a>b  表示由大到小排序
    }
};

int
main(void){
    {
        // set 的 自动排序
        set<int> s1;
        s1.insert(7);
        s1.insert(2);
        s1.insert(8);
        s1.insert(1);
        s1.insert(3);
        // 这样胡乱插入元素后 , 内部依然是进行排序的, 一般是从小到大
        for(set<int>::iterator it = s1.begin(); it != s1.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
    
    {
        //改变默认排序方式的范例:
        set<int,Myfun> s1;      //可以传入两个参数来进行排序,在初始化的时候他会调用这个伪函数,来创建一个对象
        s1.insert(7);           //  进行调用,来排序.使用完成后,这个对象不会析构,可以定义析构和构造来进行查看
        s1.insert(2);           // 当set 对象的生命周期结束后,仿函数才会析构.
        s1.insert(5);
        s1.insert(3);
        s1.insert(1);
        s1.insert(4);
        for(set<int>::iterator it = s1.begin(); it != s1.end(); it++){
            cout << *it << " ";         // 这里的迭代器只需要一个 int 就可以了,无视那个Myfun,但是对象的话不行
        }                               // 如果这里报错了, 那么就把 Myfun 加上.
        cout << endl;
        
    }
    
    {
        // 查找操作.:这步最重要(二叉树)
        set<int> s1;
        s1.insert(7);
        s1.insert(2);
        s1.insert(5);
        s1.insert(3);
        s1.insert(1);
        s1.insert(4);
        
        set<int>::iterator ret = s1.find(4);   // 返回迭代器   find();
        if(ret == s1.end()){            // 没找到就返回 .end()
            cout << "没找到" <<endl;
        }else{                          // 找到返回匹配值的迭代器
            cout << "ret: " << *ret << endl;
        }
        
        // lower_bound();   找到 大于等于 key 的第一个值的迭代器.
        ret = s1.lower_bound(2);    //查找2  如果找到2则返回2的迭代器, 如果没找到2 则返回大于2的第一个值迭代器.
        
        if(ret == s1.end()){        // 如果没有找到则返回大于2的第一个值的迭代器
            cout << "没找到" <<endl;
        }else{                      // 找到了2 就直接返回了指向 2的迭代器
            cout << "ret: " << *ret << endl;
        }
        
        // upper_bound(keyElem);  // 找到大于 kyeElem 的第一个值, 不包括相等的值
        ret = s1.upper_bound(2);
        
        if(ret == s1.end()){
            cout << "没找到" <<endl;
        }else{              // 返回大于2 的值的第一个值的迭代器.
            cout << "ret: " << *ret << endl;
        }
        
        // equal_range();  // 他返回两个迭代器, 需要apir来接收.  一个是lower_bound, 一个是upper_bound
        pair<set<int>::iterator,set<int>::iterator > myret = s1.equal_range(3);
        if(myret.first == s1.end()){        // 查看第一个是否返回了与3相等或大于他的值 的迭代器.
            cout << "没找到" <<endl;
        }else{
            cout << "找到了" << *(myret.first) <<endl;
        }
        
        if(myret.second == s1.end()){       // 查看第二个是否返回了 比3 大的值 的迭代器.
            cout << "没找到" <<endl;
        }else{
            cout << "找到了" << *(myret.second) <<endl;
        }
    }
}
```



### set/multiset高级应用范例

```c++

//类参数和排序参数 以及类查找  . 这里面的参数需要写全,尤其是it迭代器那里,一定要写全.
class Person{    // 容器内存储的对象
public:
    Person(int age,int id):age(age),id(id){}
public:
    int id;
    int age;
};

class mome{   // 伪函数 类.
public:
    bool operator()(Person a,Person b)const{
        return a.id > b.id;         // 排序所依赖的方式.
    }
};

void test03(){

    set<Person,mome>sp;

    Person p1(10,20),p2(30,40),p3(50,60);
    sp.insert(p1);
    sp.insert(p2);
    sp.insert(p3);
    for(set<Person,mome>::iterator it = sp.begin(); it != sp.end(); it++){
        cout << (*it).age << " "  << (*it).id << endl;
    }


    // 查找    p4 并没有在容器内, 但是容器会根据排序类 mome 中的id 进行查找,其他的参数是不会看的.
    Person p4(10,30);
    
    set<Person,mome>::iterator ti2 = sp.find(p4);   // 这里查找的是 id 的值,跟   对象名和age没关系,
    if(ti2 == sp.end()){
        cout << "没找到"  << endl;
    }else{
        cout << "找到了 " << (*ti2).id<< " "<< (*ti2).age << endl;
    }
}
```

```c++
#include <iostream>
#include <set>
#include <algorithm>
void Dispset(std::set<int> &myset)
{
    std::set<int>::iterator it;
    for (it=myset.begin(); it!=myset.end(); ++it) {
        printf("%d ",*it);
    }
    printf("\n");
}


int main(int argc, const char * argv[]) {

    std::set<int> set1, set2, set3;
    int a[] = {4, 1, 2, 6};
    int n = sizeof(a)/sizeof(a[0]);
    set1.insert(a, a+n);
    
    int b[] = {1, 5, 3, 2, 4};
    int m = sizeof(b)/sizeof(b[0]);
    set2.insert(b, b+m);
    
    std::set<int>::iterator it3;
    printf("set1: ");Dispset(set1);
    printf("set2: ");Dispset(set2);
    std::insert_iterator< std::set<int> > insert_it (set3, set3.begin()); // 插入迭代器
    std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), insert_it);
    printf("并集: "); Dispset(set3);
    set3.clear();
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), insert_it);
    printf("交集: "); Dispset(set3);
    set3.clear();
    
    std::set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), insert_it);
    printf("差集: "); Dispset(set3);
    set3.clear();
    return 0;
}

```





## pair

> **`pair`  对组 :  包含在头文件 `< iostream >`**

- **对组将一对值组合成一个值,这一对值可以具有不同的数据类型,两个值可以分别用 `pair` 容器提供的两个公有函数 `first` 和`second` 访问.**
- ==**pair的第一元素被成为键值,第二元素被称为实值**==
- **`类模板 template<class T1,class T2> struct pair;  //原型`**
- **一般是配合 `set` 的查找方式的返回值来进行使用的, 也就是接收 `set.equal_range()`的返回值**
- **支持下标访问`[];`**



### pair构造函数API

```c++
pair<T1,T2>paiT;   //默认构造函数
pair<T1,T2>paiT = pair2;  // 拷贝构造     
pair<T1,T2>pairT = make_pair(T1 elem,T2 elem);  
```



### pair数据查看和修改API

```c++
first(无参数);   //返回 T1 这个键值
second(无参数);  //返回 T2 这个实值
```



### pair的构造方法

```c++
pair<int,int>pair1(10,20);
cout << pair1.first << " " << pair1.second << endl;

pair<int,string>pair2 = make_pair(10,"aaa");
cout << pair2.first << " " << pair2.second << endl;

pair<int ,string>pair3 = pair2; 
```





## map/multimap

> **`map/multimap` 容器: `<map>`  `multimap`:表示多重集合,多重映射,多重对应**



- **map 和 multimap 是两个容器 ,他们所有的内容全部相同,只有key 键值不同**
  - **map不能出现重复的键值,multimap却可以重复.**
  - **map是不允许出现键值相同的元素的,但是实值没问题,(multimap,可以出现相同的键值和实值).**
    - ==**可以把键值当成一个唯一标识来看,比如 SQL .**==
- **特性:**
  - **map相对与 set区别,map 具有键值和实值, 所有元素根据 `键值` 自动排序.**
    - **pair的第一元素被称为键值,第二元素被称为实值**
- ==**在map中, Key值重复就无法插入, 就算 实值不同也不行,绝对无法插入**==
- **map 也是以红黑树为底层实现机制.**
- **因为是红黑树原理,所以传入参数会进行自动排序( 默认顺序是从小到大, 如果是自定义类型,那么要提供排序方法类或伪函数).**
  - ==**map既然是红黑树原理,那么就不可以更改`键值`,却可以更改实值.(multimap ,也不可以修改键值).**==
- ==**要把数据封装成 pair 然后在放入 map 里面去.**==



### map/multimap构造函数API

```c++
pair<Key,Elem> tp;   // Key 键值,  Elem 实值,可以用来初始化 map容器

map<Key, Elem> mapT;  // 默认构造函数
map<Key, Elem> mapTp(tp);
map<Key, Elem> mapTp( pair<Key, Elem>(键值, 实值));  

map(const map& mp);  // 拷贝构造函数
```



### map/multimap赋值操作API

```c++
map& operator=(const map& mp);  //重载等号操作符
swap(mp);  // 交换两个集和容器
```



### map/multimap大小操作API

```c++
size(无参数);  // 返回容器中的元素的个数.
empty(无参数);   // 判断容器是否为空 , 空true  ,非空返回 false
```



### map/multimap插入数据元素操作API

```c++
man.insert(...);  //往容器插入元素,返回 pair<iterator,bool> 
map<int,string>mapStu;   // 正常初始化一个对象

mapStu.insert(pair<int,string>(3,"小张")); // 第一种 通过pair的方式插入对象.
mapStu.insert(make_pair(4,"老李"));   // 第二种方式, 通过 make_pair 的方式插入对象.
mapStu.insert(map<int,string>::value_type(1,"小可"));//第三种方式,通过 value_type 的方式插入对象.
																										// 和第一种一样只不过是改了个名
mapStu[3] = "小六";   //第四种方式,通过数组的方式插入对象.
```

- **`make_pair` 接受两个元素.**



### map/multimap删除操作API

```c++
clear(无参数);  //删除所有元素

erase(pos);   //删除pos迭代器所指的元素,返回下一个元素的迭代器.
erase(beg,end);  //删除区间 [beg,end) 的所有元素,返回下一个元素的迭代器.
erase(keyElem);   //删除容器中key 为 keyElem的对组.(就是找到存有 keyElem数值的键值)
```



### map/multimap查找操作API

```c++
find(key);  //查找key 是否存在,若存在,返回该键值的元素的迭代器, 若不存在,返回map.end();

count(keyElem);  //返回容器中key 为 Elem 的对组的个数. 对map 来说,要么是0,要么是1,对于multimap来说
                 // 值可能大于1.

lower_bound(keyElem);  //返回第一个 key  >= keyElem 键值元素的迭代器.
upper_bound(keyElem);  //返回第一个 key  >  keyElem 键值元素的迭代器.
equal_range(keyElem); // 返回容器中key 与 keyElem 相等 或大  的两个迭代器.


map<int,char> ppt;
pair< map<int,char>::iterator, map<int,char>::inerator > eret = ppt.equal_range(7);
    
  eret.first->first    这一层是拿到上一层返回的第一个迭代器 lower_bound() 中的 key 键值, (int)
  eret.first->second   这一层是拿到上一层返回的第一个迭代器 upper_bound() 中的 Elem 实值,(char)
  
  eret.second->first    这一层是拿到上一层返回的第二个迭代器 lower_bound() 中的 key 键值, (int)
  eret.second->second   这一层是拿到上一层返回的第二个迭代器 upper_bound() 中的 Elem 实值,(char)


```

- `.count()` 最常用



### map/multimap修改数据实值API

```c++
map[num] = value ;  
/* 在容器中查找 num 这个 key 值,如果没找到就添加一个key和value,
 * 如过在容器中找了 num 的 key , 就修改他的实值 变成 value;
 */


// 通过数组下标的方式,不光能删除和插入,还能访问其中的元素, 直接可以用来输出
map<int,int> m1;
m1[1] = 2;   // 这里表示,没有找到 1 这个 key 的键值,就直接添加进去了,然后初始化为2
cout << m1[1] << endl;   // 这里会输出 2
m1[1] = 3;   // 键值1 代表的实值修改为了  3
```

- **通过数组下标的方式,能够在不删除元素的情况下修改元素内的值,也可以插入一个值.**
- **通过数组下标的方式,不光能删除和插入,还能访问其中的元素, 直接可以用来输出.**



### map/multimap使用范例

```c++
void
map_init()
{
//初始化
   map<int,int> mymap;  // 第一个是key类型 ,第二个是value类型,键值与实值
    
    //插入数据   pair 第一个是 pair.first key值, piar.second  value值,
    mymap.insert(pair<int,int>(10,10));  // 第一种方式,放入匿名对象
    mymap.insert(make_pair(20,20));  // 第二种是函数返回值放入,这个是右值引用,可以看下源代码.
    mymap.insert(map<int,int>::value_type(30,30)); //第三种,和第一种一样只不过是改了个名

//通过下标来访问和初始化,以及修改实值.
    mymap[40] = 40;   //第四种,数组的方式,如果40这个key 不存在那么就插入到容器中
    mymap[10] = 20;   // 如果他发现10 这个key 存在容器中, 那么就修改 value 变成20.

//验证
    pair< map<int,int>::iterator , bool> ret = mymap.insert(pair<int, int>(50,50));
    // 这种插入可以用来验证插入的数据有没有进入到容器中, 使用bool来判断.
    // insert() 会返回一个迭代器(如果插入成功,就返回已经插入数据的迭代器) 和一个bool值,用了判断是否插入了.
    if(ret.second){ // bool变成了 实值,ret 的第二个参数就是用来接受insert()的返回值的
        cout << "插入数据成功" <<endl;        // 返回真值,就表示插入成功了.
    }else{
        cout << "插入失败"  << endl;     // 返回 false 就是失败了  这个值被丢弃了.
    }
    cout << "---------------------" << endl;  //分割线
    ret = mymap.insert(pair<int, int>(50,60));  // 这里要插入的数据和上面的key冲突了,所以这个会失败.
    
    if(ret.second){ // bool变成了 实值,ret 的第二个参数就是用来接受insert()的返回值的
        cout << "插入数据成功" <<endl;        // 返回真值,就表示插入成功了.
    }else{
        cout << "插入失败"  << endl;     // 返回 false 就是失败了  这个值被丢弃了.
    }
    
//打印
    for(map<int,int>::iterator it = mymap.begin(); it!= mymap.end(); it++){
         // *it 取出来的是一个 pair
        cout << "key " <<(*it).first << ", value " << it->second << endl;
    }   // first 和 second 是pair中的, first表示的是键值,second 是实值, 对应第一个值和第二个值
    
//通过下标能够直接读取到实值
    cout << "mymap[60]  " << mymap[60] << endl;
     //因为我没有插入过60这个key,所以他自动给添加了一个 key 就是60,而且我没有给初始化数据,那么他就给了默认值0.
    // 这个默认值如果是类的话就另说了,(应该是默认构造), 假如有 60这个键值,那么就会输出 60 键值后面的实值.
}
```



### map/multimap经典查找范例

```c++
// 查找进阶范例: 超级典型
void test04() {
    map<int, int> mymap;
    mymap.insert(make_pair(3, 30));
    mymap.insert(make_pair(1, 10));
    mymap.insert(make_pair(5, 50));
    mymap.insert(make_pair(7, 70));
    mymap.insert(make_pair(9, 90));
    
    map<int,int>::iterator lret = mymap.lower_bound(4);
    // 寻找键值 大于等于 4 的元素, 并返回其键值 指向的实值
    // 应该输出 找到lower-bound! 50
    if ( lret  != mymap.end() ) {
        cout << "找到lower-bound! " << lret->second << endl;   //重点解释 放在下面
    }
    else {
        cout << "没找到" << endl;
    }

    map<int,int>::iterator uret = mymap.upper_bound(5);
     //  寻找键值 大于 5 的元素, 并返回其键值 指向的实值
     //  应该输出 找到upper_bound! 70
    if ( uret  != mymap.end() ) {
        cout << "找到upper_bound! " << uret->second << endl;   //重点解释 放在下面
    }
    else {
        cout << "没找到" << endl;
    }

    pair < map<int, int>::iterator, map<int, int>::iterator> eret = mymap.equal_range(5);
    	//如果成功则会有:  大于等于5的 键值的实值的迭代器(50), 和一个 大于5的键值的实值的迭代器(70).
        // 如果失败,则是 空的指针.
       // 参数为9 时,eret.first->second=90; eret.second = nullptr; , 一个找得到,一个找不到
    
    if (eret.first  != mymap.end() ) {
        cout << "找到lower-bound! " << eret.first->second << endl;   //重点解释 放在下面
    }
    else {
        cout << "没找到" << endl;
    }

    if (eret.second  != mymap.end()) {
        cout << "找到upper-bound! " << eret.second->second << endl;  //重点解释 放在下面
    }
    else {
        cout << "没找到" << endl;
    }
}


/* ================================================================================ */

!重点解释取* 和解说范围.
  pair < map<int, int>::iterator, map<int, int>::iterator> eret = mymap.equal_range(5);
  // ret  就是两个迭代器, pair 是能容纳两个迭代器的容器.

  eret.first  这一层是  pair < map<int, int>::iterator, map<int, int>::iterator >
          拿到左边的key 值的迭代器.
              就是  mymap.lower_bound(5); 的返回值.找到和 5 相同或者大于5 的键值中的实值.
  
  eret.second 这一层是  pair < map<int, int>::iterator, map<int, int>::iterator >
          拿到右边的Elem 值的迭代器
             就是,mymap.upper_bound(5);的返回值.找到大于 5的键值中的实值.(但是不会理会2 这个键值).

    
  eret.first->first    这一层是拿到上一层返回的第一个迭代器 lower_bound() 中的 key 键值,(是个int,)
  eret.first->second   这一层是拿到上一层返回的第一个迭代器 lower_bound() 中的 Elem 实值,(是个int)
  
  eret.second->first    这一层是拿到上一层返回的第二个迭代器 upper_bound() 中的 key 键值,(是个int,)
  eret.second->second   这一层是拿到上一层返回的第二个迭代器 upper_bound() 中的 Elem 实值,(是个int)
```



### map/multimap排序范例:重要

```c++
#include <iostream>
#include <set>
#include <map>
using namespace std;

// 排序范例和一些要注意的事项.: 重要章节
class MyKey {
public:
    MyKey() { cout << "默认构造" << endl; }
    MyKey(int index, int id) :mIndex(index), mID(id) {
        cout << "MyKey(int,int..." << endl;
    }
    MyKey(const MyKey& t):mIndex(t.mIndex),mID(t.mID){  cout << "拷贝构造" << endl; }
    
    ~MyKey() { cout << "析构"  << endl; }
    
    int mIndex;
    int mID;
};

struct mycompare {
    bool operator()(MyKey k1, MyKey k2)const {
        return k1.mIndex < k2.mIndex;
    }
};

void test02() {
    map<MyKey, int , mycompare>mymap;  //自动排序,自定义数据类型必须提供一个排序方法.
    // 可以把这个方法当成第三个初始化,第三个参数也就是排序规则.
    
    mymap.insert(make_pair(MyKey(1, 2),10));
    cout << endl;
    mymap.insert(make_pair(MyKey(4, 5),20));
    
    for (map<MyKey, int, mycompare>::iterator it = mymap.begin(); it != mymap.end(); it++) {
        cout << "mID : " << it->first.mID << ", mIndex : " << (*it).first.mIndex << endl
        << "keyElem" << it->second << endl;
    }
    // first 代表的是 key键值, second 代表的 int 才是实值
    // 都是以 pair 模式存储的, make_pair()第一个参数是key键值,第二个就是实值
}


int
main(void){
    test02();    
}

```







## 函数对象-仿函数

> **函数对象:  就是仿函数  `(重载了()小括号的类)`    这个不是容器, 是标准库中的内容.**



- **如果`operator()(参数列表);`**  
  - **`参数列表中,有一个参数就叫 一元仿函数, 两个参数就是 二元仿函数.....`**

- **函数对象可以像普通函数一样调用.**

- **函数对象可以像普通函数那样接受参数.**
- **函数对象超出了函数的概念,函数对象可以保存函数调用的状态.**

```c++
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <arpa/inet.h>
using namespace std;

struct MyPrint {
    MyPrint() {
        nNum = 0;
        cout << "正在进行默认构造" << endl;
    }
    
    MyPrint(const MyPrint& t){
        nNum = t.nNum;
        cout << "正在进行拷贝构造"  << "t = " << t.nNum << endl;
    }
    
    ~MyPrint(){
        cout << "正在进行析构" << endl;
    }
    
    void operator()(int val) {
        this->nNum++;
        cout << val  << "  nNum :" << nNum << endl;
    }
    int nNum;
};
int num = 0;

void
MyPrint02(int val) {
    num++;
    cout << val << endl;
}

void
test01() {
    MyPrint print;
    print(20);
}

void
test02() {
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
#if 0
    MyPrint02(10);
    MyPrint02(20);
    cout << num << endl;

    MyPrint print;

    print(10);
    print(20);
    cout << print.nNum << endl;
#endif
    MyPrint print_1;
    MyPrint print_2 = for_each(v.begin(), v.end(), print_1);
  // 如果这样调用需要第二个对象来接受正确的返回值,
  // 实际上是在使用 print_1, 然后进行拷贝 构造出来print_2, 毕竟 for_each() 返回一个伪函数对象.
        
    cout << "print_1调用次数" << print_1.nNum << endl;   //这个是0
    cout << "print_2调用次数" << print_2.nNum << endl;  // 这个是正确的
}

int main(void){
        test02();
}
```





## 谓词

>  **谓词是指 普通函数或 重载operator() 的返回值是 bool 类型的函数对象(仿函数).**

- **如果operaor() 接受一个参数,那么叫做一元谓词, 如果接受两个参数,那么叫做二元谓词.**
- **谓词可作为一个判别式.**



- **内建函数对象:  ` <functional>`**
  - **STL 内建了一些函数对象, 分为:**
    - **算术类函数对象**
    - **关系运算类对象**
    - **逻辑运算类仿函数**
  - **这些仿函数产生的对象,用法和一般函数完全相同,当然我们还可以产生无名的临时对象来履行函数功能.**
  - **使用内建对象需要引用头文件 `<functional>`**

```c++
 6 个算数类函数对象, 除了negate是一元运算,其他都是二元运算.
    template<class T> T plus<T,T>   //加法仿函数
    template<class T> T minute<T,T>  //减法仿函数
    template<class T> T multiplies<T,T>  //乘法仿函数
    template<class T> T divides<T,T>  // 除法仿函数
    template<class T> T modulus<T,T>  // 取模仿函数
    template<class T> T negate<T>  // 取反仿函数
--------------------
 6 个关系运算类函数对象,每一种都是二元运算:
    template<class T> bool equal_to<T,T>  //等于
    template<class T> bool not_equal_to <T,T> // 不等于
    template<class T> bool greater<T,T> // 大于
    template<class T> bool greater_equal<T,T>  // 大于等于
    template<class T> bool less<T,T> //小于
    template<class T> bool less_equal<T,T>  //小于等于
--------------------
 3 个逻辑运算类运算函数,not 为一元运算,其余为二元运算.
    template<class T> bool logical_and<T,T>  //逻辑与
    template<class T> bool logical_or<T,T>  //逻辑或
    template<class T> bool logical_not<T,T>  //逻辑非
--------------------


 用法: 
 	plus<int>myplus;
	cout << myplus(10,20) << endl;
            // 会输出 30 
```

- **跟自己自定义的函数对象一样,该怎么用就怎么用**





## 函数对象适配器

- 函数对象适配器是完成一些配接工作
  - **这些配接包括绑定(bind), 否定(negate), 以及对 一般函数 或  成员函数 的 修饰,使其成为 函数对象**
- **重点掌握函数对象适配器.**

```c++
    bind1st : 将参数绑定为函数对象的第一个参数
    bind2nd : 将参数绑定为函数对象的第二个参数
    not1   : 对一元函数对象取反
    not2   : 对二元函数对象取反
    ptr_fun : 将普通函数修饰成函数对象
    mem_fun : 修饰成员函数
    mem_fun_ref : 修饰成员函数

  预定以函数对象
    仿函数适配器 bind1st , bind2nd
    仿函数适配器 not1 not2
    仿函数适配器 ptr_fun
    成员函数适配器 mem_fun , mem_fun_ref
      
    // bind1st bind2nd 区别是:
    // bind1st : 将addNum 绑定为函数对象的第一个参数.
    // bind2nd : 将addNum 绑定为函数对象的第二个参数.
```

**有的时候使用需要继承 `binary_function` 这个基类. 也可能会继承其他的基类, 一切看范式.**



### 函数对象适配器范式-仿函数适配器bind1st,bind2nd绑定适配器

```c++
//---------------------------------------------------------------------
// 这里继承了一个父类   , 这个父类是模板,给了他三个参数 ,二元的使用binary_function
struct MyPrint :public binary_function<int, int,void> { //int,int,void 两个参数,一个返回值
    void operator()(int v, int t)const {
        cout << "v " << v << ", t" << t << endl;
        cout << "v + t  " << v + t << endl;
    }
};

// 仿函数适配器 bind1st  bind2nd  绑定适配器
void test01() {
    vector<int > v;
    for (int i = 0; i < 10; i++) {  //循环赋值,压入容器
        v.push_back(i);
    }
    int addNum = 200;
    for_each(v.begin(), v.end(), bind2nd(MyPrint(), addNum));
    for_each(v.begin(), v.end(), bind1st(MyPrint(), addNum));
    // 绑定适配器  将一个二元的函数对象,转变成一元的函数对象.
    // 因为for_each()需要回调函数有一个参数,但是MyPrint 有两个参数
    // bind1st 把这个函数变成了一元函数,来给for_each()调用,
    // 然后把bind1st内的第二个值在传入到函数内,变成第二个参数.
    // 随后函数就会正常的被调用.

    // bind1st bind2nd 区别是:
    // bind1st : 将addNum 绑定为函数对象的第一个参数.
    // bind2nd : 将addNum 绑定为函数对象的第二个参数.
}
```





### 函数对象适配器范式-伪函数适配器not1,not2取反适配器,bool是返回值

```c++
// 伪函数适配器  not1  not2 取反适配器   , bool 是返回值

class Myprint02 {
public:
    void operator()(int v) {
        cout << v << " ";
    }
};

class Mycompare :public binary_function<int, int, bool> { //int,int,bool 两个参数,一个返回值
public:
    bool operator()(int v1, int v2)const {  //也可以叫二元谓词,因为返回值是布尔
        return v1 > v2;                 // 凡是涉及到排序 全都是返回布尔类型
    }
};

struct MyGreter5 : public unary_function<int, bool> { //一元的使用unary_function
    bool operator()(int v)const {
        return v > 5;
    }
};

//---------------------------------------------------------------------
// 伪函数适配器  not1  not2 取反适配器
void test02() {
    srand((unsigned) time(nullptr)); //初始化随机种子
    vector<int > v;
    for (int i = 0; i < 10; i++) {  //循环赋值,压入容器
        v.push_back(rand() % 100 + 1);
    }
    for_each(v.begin(), v.end(), Myprint02());  // 排序之前 打印一次
    cout << endl;
    sort(v.begin(), v.end(), not2(Mycompare()));  //使用匿名类对象来排序, 伪函数
    for_each(v.begin(), v.end(), Myprint02());  // 排序之后 打印一次
    cout << endl;

    // not1  not2
    // 如果对二元谓词取反, 用not2
    // 如果对一元谓词取反, 用not1

    vector<int>::iterator it = find_if(v.begin(), v.end(), not1(MyGreter5()));
    //从迭代器区间查找大于5的值,但是取反了,就只能查找小于等于 5的值, 返回一个迭代器

    if (it == v.end()) {
        cout << "没有找到" << endl;
    }
    else {
        cout << *it << endl;
    }

   // cout << *it << endl;

}
```



### 函数对象适配器范式-把普通函数适配成函数对象bind2nd和ptr_fun

```C++
void MyPrint03(int val, int val2) {   //函数也可以用来打印和回调函数,但是无法进行绑定
    cout << "vla2 :  " << val2 << ", val :" << val << " ";
    cout << endl;
}

void test03() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    // 把普通函数适配成函数对象
    for_each(v.begin(), v.end(), bind2nd(ptr_fun(MyPrint03), 10));
    // 普通函数是无法使用 bind2nd 这个函数对象的,必须要经过 ptr_fun来转化
}
```



### 函数对象适配器范式-调用类自己提供的打印函数

```c++
// 如果容器中存放的 对象 或者 对象指针, 我们for_each 算法打印的时候,调用类自己提供的打印函数.
class Persion {
public:
    Persion() {}
    Persion(int age, int id) :age(age), id(id) {}
    void show() {
        cout << "age: " << age << ", id " << id << " aaa " << endl;
    }
public:
    int age;
    int id;
};

void test04() {
    vector<Persion> v;
    Persion p1(10, 20), p2(30, 40), p3(50, 60);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    // 格式: &类名::函数名
    for_each(v.begin(), v.end(), mem_fun_ref(&Persion::show)); //调用了类中函数来进行输出

    vector<Persion*> v1;
    v1.push_back(&p1);
    v1.push_back(&p2);
    v1.push_back(&p3);


    for_each(v1.begin(), v1.end(), mem_fun(&Persion::show)); // 指针和 普通对象是不同的格式

    // mem_fun_ref  和 mem_fun 的区别是:
    //  如果存放的是对象指针则 使用 mem_fun
    //  如果使用的是对象  使用mem_fun_ref
    //  除了这两个不同外, 括号内的 内容完全不变
}
```









# 查找算法

> **常用的查找算法: `<algorithm>`** 

- **`find()` 返回一个迭代器,找到则返回找到的, 没有找到就返回`.end();`**

- **`find_if()`  会根据我们的条件(函数), 返回第一个满足条件的元素的迭代器;需要我们来自定义查找的范围和查找的回调函数,他会返回一个bool值.**

- **`binary_search()`  二分查找法,它只会返回一个bool值 ,告诉你有还是没有(只支持自带排序和带排序算法的容器)**

- **`adjacent_find()` 查找相邻重复的元素, 比如 1 2 2 3 4 3 , 他会把 第二个2 的迭代器返回,4 后面的 3 不符合相邻重复的条件.**

- **`count count_if()` 查找元素出现比 第三个参数大的元素的个数.只不过一个需要提供回调函数而已**

  

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
// find  最常用的一种
void test02(){
    vector<int >v1;
    for(int i = 0 ; i < 10 ; i++){
        v1.push_back(i);
    }
    
    vector<int>::iterator vitBegin = v1.begin();
    vector<int>::iterator vitEnd   = v1.end();
     
    // find() 返回一个迭代器,找到则返回找到的, 没有找到就返回end();
    vector<int>::iterator ret = find(vitBegin,vitEnd ,5);
    if(ret != v1.end()){
        cout << "找到了 " << *ret  << endl;
    }else{
        cout << "没找到" << endl;
    }
}


/*=====================================================================================*/

class Person{
public:
    Person(int age,int id):age(age),id(id){}
    bool operator==(const Person& p)const{   // 返回的是bool 类型 , 为什么这么写,去看find()源代码
        return p.id == this->id && p.age == this->age;  // 这里是判断条件, 多多注意 const
    }
public:
    int id ;
    int age;
};

void test03(){
    vector<Person>v1;
    Person p1(10,20),p2(30,40);
    
    v1.push_back(p1);
    v1.push_back(p2);
    
    vector<Person>::iterator vitBegin = v1.begin();
    vector<Person>::iterator vitEnd   = v1.end();
    
    vector<Person>::iterator ret = find(vitBegin,vitEnd,p1);
                              // find(1,2,3); 在1和2的范围内找到3这个元素
    if(ret != v1.end()){
        cout << "找到了"   << endl;
    }else{
        cout << "没找到"  << endl;
    }
    
}

/*=====================================================================================*/


//find_if的回调函数,他每次都会把值仍到这里来,
bool MySearch(int val){
    return val > 5;  //只要我们给他返回true,那么他就认为找到了
};

//这个是 count_if 的回调函数,统计大于5的元素的个数, 返回的是bool
bool MySearch2(int val){
    return val > 5;
}

// binary_search  二分查找法,它只会返回一个bool值 ,告诉你有还是没有(只支持自带排序和带排序算法的容器)
// adjacent_find 查找相邻重复的元素, 比如 1 2 2 3 4 3 , 他会把 第二个2 的迭代器返回,4 后面的 3 不符合条件.
// find_if  需要我们来自定义查找的范围和查找的回调函数,他会返回一个bool
// count 和 count_if
void test04(){
    vector<int >v1;
    for(int i = 0 ; i < 10 ; i++){
        v1.push_back(i);
        if (i==5)
            v1.push_back(i);
    }
    v1.push_back(5);  // 特意多添加了一个5的值
    
    vector<int>::iterator  itBegin = v1.begin();
    vector<int>::iterator  itEnd   = v1.end();
    
    bool ret = binary_search(itBegin, itEnd, 6);
         // 在 itBegin和 itEnd 范围内寻找 6这个元素. 找到返回 true ,否则 false
    
    if(ret){
        cout << "找到了"  << endl;
    }else{
        cout << "没找到" << endl;
    }
    
// 上面的 迭代器不应该继续使用, 应该重新进行初始化,binary_search() 会修改它们的值
    itBegin = v1.begin();
    itEnd   = v1.end();
    
    vector<int>::iterator pos = adjacent_find(itBegin, itEnd); // 这里不需要第三个值
    // 只是查找相邻的,  如果两个数值相等, 但是他们不相邻,那么就不回返回他们的迭代器
    // 例如 , 1, 2, 4, 5, 5, 6   .那么返回的是 第一个5, 上个元素是4, 下个元素是第二个5
    
    if(pos != v1.end()){
        cout << "找到了相邻重复元素!  " << *pos <<" -- " << *(pos-1) << "  ++ " << *(pos+1) <<endl;
    }else{
        cout << "没找到相邻重复元素" << endl;
    }
    
// 上面的 迭代器不应该继续使用, 应该重新进行初始化,adjacent_find() 会修改它们的值
    itBegin = v1.begin();
    itEnd   = v1.end();
    
    
// find_if  会根据我们的条件(函数), 返回第一个满足条件的元素的迭代器, 也就是函数设定的大于5的值.
    vector<int>::iterator it = find_if( itBegin, itEnd ,MySearch);
    if(it  != v1.end()){
        cout << "找到了"  << *it <<  endl;  //这里回返回指向元素6的迭代器,因为我的回调函数写的是大于5的数
    }else{
        cout << "没找到"  << endl;
    }

// 上面的 迭代器不应该继续使用, 应该重新进行初始化,adjacent_find() 会修改它们的值
    itBegin = v1.begin();
    itEnd   = v1.end();
    
// count , count_if 都是查找元素出现比 第三个参数大的元素的个数.只不过一个需要提供回调函数而已
    long num = count(itBegin, itEnd, 9);
    cout <<"9出现的次数 : "  << num << endl;
    
// 上面的 迭代器不应该继续使用, 应该重新进行初始化,adjacent_find() 会修改它们的值
    itBegin = v1.begin();
    itEnd   = v1.end();
    num = 0;
    
    //统计大于5的 元素的总个数
    num = count_if (itBegin, itEnd, MySearch2);
    cout << "大于5的元素出现的个数" << num << endl;
}

int
main(void){
    test04();
}
```





## 常用遍历算法

> **常用的遍历算法: `<algorithm>`**

- **`for_each(迭代器,迭代器,回调函数) ;  // 都写烂了`**
- **`transform( 迭代器, 迭代器, 迭代器,回调函数);   // 把两个迭代器之间的内容全部搬运到另一个容器中,注意这里是不会给目标容器分配内存空间的, 所以我们要提前分配好内存.  他会返回目标容器的迭代器`**



```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


struct MyPlus{
    int operator()(int val){  // 因为 vector 这个容器的类型是 int 那么这里也要写int
        return val;   // 搬运容器,传入的是 v1的内容, 返回值是给 v2的,而且这里还可以进行修改
    }
};

void MyPrint(int val){ // 用来给for_each 打印的
    cout << val << " ";
}

//transform  将一个容器的元素 搬运到 另一个容器中
void test01(){
    vector<int> v1;
    vector<int> v2;
    v2.resize(100);  // 这里必须用reszie扩张空间,等待存储v1的元素,如果缺少这步,则会出现内存崩溃.
                    // 绝对不能使用reserve ,因为使用之后只能通过 push_back 来添加新值
    
    //将 v1 进行赋值和添加元素
    for(int i = 0 ; i< 10 ; i++){
        v1.push_back(i);
    }
    
    // 原容器的迭代器,目标容器的迭代器,后面的是伪函数,用来搬运的
    transform(v1.begin(), v1.end(), v2.begin(),MyPlus());
    
    for_each(v2.begin(), v2.end(), MyPrint);
    cout << endl;
}

int
main(){
    test01();
}
```





## 常用排序算法

> 常用的排序算法  容器 `<algorithm>`

- **`sort(iterator beg,iterator end,_callback);`**
  - **`//对指定范围内的元素进行排序,默认是由小到大, 两个迭代器,  一个回调谓词函数(返回bool类型的函数对象). (要求容器必须支持随机访问,否则无法使用)`**

- **`random_shuffle(iterator beg,iterator end);`**   该算法 在C++17中 被删除了
  - **`//对指定范围内的元素随机调整次序,两个迭代器 (就算是自定义类型,也不需要另外的排序函数),仅仅只需要迭代器 (要求容器必须支持随机访问,否则无法使用`**

- **`reverse(iterator beg, iterator end);`**
  - **`//反转指定范围的元素. 两个迭代器,就算是自定义类型,也不需要另外的排序函数,(要求容器必须支持随机访问,否则无法使用)`**

- **`merge(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);`**
  - **`//两个容器元素合并放入到另一个容器中.`**
  - **`// 前面四个迭代器代表两个容器,而且这两个容器必须是有序的(比如map,set),  一定要把第五个接受元素的迭代器 使用 resize() 来重新划分空间.`**
  - **`不支持随机访问的容器也可以使用这个算法,但是要先排序,比如 list.sort();`**

- ==**如果想让 `list` 容器来实现反转指定元素和随机排序之类的时候,那就只能自己写算法来解决了.**==



```c++
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;
//merge 算法 整合两个容器的元素,排序后放入第三个容器中 和 sort 算法范例: (虽然都写烂了)
struct MyPrint01{
    void operator()(int v){
        cout << v << " ";
    }
};
struct MyCompare01{  //排序 sort 时,想自定义排序元素的时候使用的自定义伪函数
    bool operator()(int v1,int v2){
        return v1 > v2;
    }
};

void test01(){
    vector<int>v1;     // 支持随机访问可以用
    vector<int>v2;
    list<int>l3;    // 不支持随机访问的容器
    
    srand((unsigned int)time(nullptr)); //随机数初始化的种子,用的是时间
    for(int i = 0; i< 10 ; i++){
        v1.push_back(rand()% 10);  // 都使用随机数来进行初始化
        //   v2.push_back(rand()% 10);
        l3.push_back(rand()% 10);
    }

    sort(v1.begin(),v1.end(),MyCompare01());  //进行普通排序, (也可以使用自定的第三个参数来实现逆向排序)
  //  sort(v2.begin(),v2.end(),MyCompare01());
        
    l3.sort(MyCompare01());                  // list自带排序函数
    
    for_each(l3.begin(),l3.end(),MyPrint01()); //输出
        cout << endl;
    vector<int> v3;  // 准备把v1和v2的数据放入这个 v3 中
//    v3.resize(v1.size() + v2.size()); //开辟空间,并且初始化
    v3.resize(v1.size() + l3.size());
    
  //  merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin(),MyCompare01());
    merge(v1.begin(),v1.end(),l3.begin(),l3.end(),v3.begin(),MyCompare01());
     //算法 merge.把v1和v2的数据都给v3 , 默认是从小到大排序, 最后一个参数是修改默认排序的一个伪函数.
    
    for_each(v3.begin(),v3.end(),MyPrint01());  //通过上面自定义的伪函数实现输出和打印
    cout << endl;
}
//------------------------------------------------------------------------

// random_shuffle 将元素进行随机排序, 只需要迭代器,不考虑类型
void test02(){
    vector<int>v;
   // list<int>v;
    for(int i = 0; i < 9 ; i++){
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),MyPrint01());  // 第一次打印
        cout << endl;
    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end();
    random_shuffle(itBegin, itEnd);   // 进行随机排序
        cout << endl;
    for_each(v.begin(),v.end(),MyPrint01());  // 第二次打印
        cout << endl;
}
//------------------------------------------------------------------------

// reverse  反转指定范围的元素
void test03(){
    vector<int>v;
    for(int i = 0; i < 9 ; i++){
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),MyPrint01());  // 第一次打印
    cout << endl;
    reverse(v.begin(), v.end());  // 反转指定范围的元素 也只是需要迭代器
    for_each(v.begin(),v.end(),MyPrint01());  // 第二次打印
}


int
    main(void){
        test03();
    }
```





## 常用拷贝和替换算法

> **常用拷贝和替换算法: `<algorithm>`**

- **`copy(iterator beg, iterator end, iterator dest);`**
  - **`// 将容器内指定范围的元素拷贝到另一容器中.两个迭代器, dest 是新容器的begin迭代器, (要保证这个新容器有足够的空间,resize());`**
- **`replace(iterator beg, iterator end, oldvalue , newvalue);`**
  - **`将容器内指定范围的某个旧元素修改为新元素,两个迭代器,  okdvalue 旧元素 , newvalue 新元素.`**

- **`replace_if(iterator beg, iterator end, _callback, newvalue);`**
  - **`将容器内指定范围满足条件的元素替换成新元素,两个迭代器, _callback 函数回调或者谓词(返回bool类型的函数对象), newvalue 新元素`**
- **`swap(container c1, container c2);`**
  - **`互换两个容器的元素, c1 容器1 , c2 容器 2`**

```c++
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;


struct MyPrint01{
    void operator()(int val){
        cout << val <<  " ";
    }
};

// copy swap
void test01(){
    vector<int> v1;
    srand((unsigned int)time(NULL));
    for(int i = 0; i< 10 ; i++){
        v1.push_back(rand()% 10);
    }
    
    for_each(v1.begin(),v1.end(),MyPrint01());cout << endl;
    
    vector<int> v2;
    v2.resize(v1.size());
    copy(v1.begin(),v1.end(),v2.begin());  // 使用了v1的两个迭代器 ,使用了v2的begin 一个迭代器
    
    cout << endl;
    for_each(v2.begin(),v2.end(),MyPrint01());cout << endl;
    
// swap
    vector<int>v3;
    for(int i = 0; i< 10; i++){
        v3.push_back(rand()%10);
    }
    cout << endl << " -------交换前----- " << endl;
    for_each(v3.begin(), v3.end(), MyPrint01());cout <<endl;
    for_each(v2.begin(), v2.end(), MyPrint01());cout <<endl;
    swap(v2,v3);    // 简单的交换
    cout << " -------交换后----- " << endl;
    
    for_each(v3.begin(), v3.end(), MyPrint01());cout <<endl;
    for_each(v2.begin(), v2.end(), MyPrint01());cout <<endl;
}
//------------------------------------------------------------------

// repace replace_if
struct MyConmpare02{
    bool operator()(int val){
        return val > 5;  // 如果传入的参数大于5 就替换他
    }
};

void test02(){
    vector<int> v1;
    srand((unsigned int)time(NULL));
    for(int i = 0; i< 10 ; i++){
        v1.push_back(i);
    }
    for_each(v1.begin(),v1.end(),MyPrint01());cout << endl;
    replace(v1.begin(), v1.end(), 5, 100);  // 寻找 v1.begin 到 v1.end 之间的元素 5 全部修改成100
                                          // 找不到就不替换
    for_each(v1.begin(),v1.end(),MyPrint01());cout << endl;
    
    replace_if(v1.begin(), v1.end(), MyConmpare02(), 200);  // 自定义条件替换,把大于5的数替换成200
    for_each(v1.begin(),v1.end(),MyPrint01());cout << endl;
    
}
```







## 常用算数生成算法

> **常用算数生成算法:  `<numeric>`**

- **`accumlate(iterator beg, iterator end , value);`**
  - **`计算容器中所有元素的累加总和. 两个迭代器,value 累加值或偏移值 (写0就好了),如果写的是10, 那么累加完成后会多加这个10`**
- **`fill(iterator beg, iterator end, value);`**
  - **`将容器中所有元素全部变成 value (也包含有空间但未初始化的). 两个迭代器, value 填充元素, (如果是新容器,那么应该使用resize() 来扩充容器).`**

```c++

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <numeric>
using namespace std;
// accumulate  计算容器内元素相加的总值   , fill
struct MyPrint01{
    void operator()(int val){
        cout << val << " ";
    }
};
        
void test01(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(9);   // 这些元素相加等于15
    
    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd   = v.end();
        
    int ret = accumulate(itBegin, itEnd, 0);  // 计算容器内所有元素的累加值,在加上后面的0
    cout << "ret " << ret << endl;  // 这里输出的是15, 如果累加值的0 变了,那么他就要加上这个累加值

// fill  用 value 来覆盖容器中所有的元素,也就是把容器中所有的内容全部替换成 value
    vector<int>v2;
    v2.push_back(1);
    v2.resize(10);      //扩容
    
    itBegin = v.begin();
    itEnd   = v.end();
    
    fill(v2.begin(), v2.end(), 10);
    for_each(v2.begin(), v2.end(), MyPrint01());
}
```





## 常用集合算法

> **常用集合算法:  交集 并集 子集 差集 `<algorithm>`** 

- **`set_intersection(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);`**
  - **`求 两个 set 集合的交集  ( 两个集合必须是有序 序列)`**
  - **`两个容器的  四个迭代器`**
  - **`dest 目标容器迭代器 (begin())`**
  - **`这个算法的返回值是 dest目标容器的最后一个元素的迭代器地址.end()`**
  - 如果是自定义类型,那么会在最后一个多传入一个 回调伪函数;
- **`set_union(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest)`**
  - **`两个集合的交集, 不会出现重复元素.(重复元素只显示一次)`**
  - **`将两个容器的值的交集 结果传入给 第三个容器, 第三个容器的容量选前两个容器的容量最小值即可`**
  - 自定义类型的话,也需要一个回调伪函数
- **`set_difference(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest)`**
  - **`两个集合的差集`**
  - 和上面两个相同.

```c++
#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>
#include <numeric>

using namespace std;
// accumulate  计算容器内元素相加的总值   , fill
struct MyPrint01{
    void operator()(int val){
        cout << val << " ";
    }
};

// set_intersection  交集
void test02(){
    vector<int> v1;
    vector<int> v2;
    
    for(int i = 0; i < 10 ; i++){
        v1.push_back(i);
         v2.push_back(i+5);
    }

    vector<int>v3;
    v3.resize(min(v1.size(),v2.size()));  //min 返回两个值中较小的那个
    // 给v3开辟空间,  并且把多余的空间全部初始化为0  (其他类型则不固定)
    
        vector<int>::iterator itBegin_1 = v1.begin();
        vector<int>::iterator itBegin_2 = v2.begin();
        vector<int>::iterator itBegin_3 = v3.begin();
        vector<int>::iterator itEnd_1 = v1.end();
        vector<int>::iterator itEnd_2 = v2.end();
        
    vector<int>::iterator it =  set_intersection(itBegin_1,itEnd_1,itBegin_2,itEnd_2,itBegin_3);
      // 计算 v1 和 v2 的交集,并把内容写入v3 (如果容器中是自定义类型,那么还需要添加一个回调函数参数).
      // 该算法返回一个迭代器,这个迭代器指向最后添加到v3容器中的元素的下一个元素, it就指向 9 后面的0,
      // 第二种调用: set_intersection(迭代器1-1,迭代器1-2,迭代器2-1,迭代器2-2,迭代器3-1,回调函数);

    // 打印结果
    for_each(v1.begin(), v1.end(), MyPrint01()); cout << endl; // 0 ~ 9
    for_each(v2.begin(), v2.end(), MyPrint01()); cout << endl; // 5 ~ 14
    for_each(v3.begin(), it, MyPrint01()); cout << endl;   // 5 6 7 8 9
    
    cout << *it << endl;  // it指向 9 后面的 0
    cout << endl << "------------------------------------" << endl;
    
// set_union 并集 , 并集就是把两个集合相加,重复的部分只显示一次,(因为集合不能有重复元素)
    vector<int> v4;
    v4.resize(v1.size()+v2.size());  // 开辟空间,10+10 = 20
    it = set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v4.begin());
     // 计算 v1 和 v2 的并集 , 并把内容写入 v4 (自定义还需要特殊化)
    // 该算法返回一个迭代器,这个迭代器指向最后添加到v4容器中的元素的下一个元素, it就指向 14 后面的0, 也就是 v4.end()
    
    // 打印结果
    for_each(v4.begin(), it, MyPrint01()); cout << endl; //输出 0 ~ 14
    cout << endl << "------------------------------------" << endl;
    
// set_difference 差集 ,
    vector<int> v5;  // 保存 v1 差 v2 的集合值
    vector<int> v6;  // 保存 v2 差 v1 的集合值
    v5.resize( min(v1.size(),v2.size()) );  // 申请内存空间, 差集不可能会大于 v1
    v6.resize( min(v1.size(),v2.size()) );  // 差集不可能会大于 v2
        
    it = set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),v5.begin());
    for_each(v5.begin(), it, MyPrint01()); cout << endl; //输出 0 1 2 3 4
    it = set_difference(v2.begin(),v2.end(),v1.begin(),v1.end(),v6.begin());
    for_each(v6.begin(), it, MyPrint01()); cout << endl; //输出 10 11 12 13 14
    
    
    cout <<  "v5.capcaity() " << v5.capacity();
}


int main(void){
    test02();
}

```



### 一键替换字符串中的字符

## 使用 `std::replace` 功能

推荐的解决方案是使用标准算法 `std::replace` 来自 `<algorithm>` 标题。它对字符串进行一次线性扫描，然后 到位 替换所有匹配的字符。

```c++
#include <iostream>
#include <algorithm>
#include <string>
 
int main()
{
    std::string s = "C**";
    const char x = '*';
    const char y = '+';
 
    std::replace(s.begin(), s.end(), x, y);
    std::cout << s;
 
    return 0;
}
```

