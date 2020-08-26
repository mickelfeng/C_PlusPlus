## 目录

- [多线程基础](#多线程基础)
  - [查看本地CPU核心数和线程数](#查看本地CPU核心数和线程数)
  - [不同平台下的线程](#不同平台下的线程)
  - [多线程容易造成数据混乱](#多线程容易造成数据混乱)
- [线程同步思想](#线程同步思想)
  - [线程同步实现](#线程同步实现)
  - [线程同步范例-生产者与消费者模型](#线程同步范例-生产者与消费者模型)
- [信号量线程同步](#信号量线程同步)
  - [信号量线程同步范例-生产者消费者模型](#信号量线程同步范例-生产者消费者模型)
- [互斥量-互斥锁](#互斥量-互斥锁)
  - [互斥锁的相关函数](#互斥锁的相关函数)
  - [原子操作和死锁](#原子操作和死锁)
- [读写锁](#读写锁)
  - [读写锁主要操作函数](#读写锁主要操作函数)
  - [读写锁范例](#读写锁范例)
- [在C中的多线程](#在C中的多线程)
  - [C中的创建线程函数原型pthread_create](#C中的创建线程函数原型pthread_create)
  - [C-获得当前线程的ID号  pthread_self](#C-获得当前线程的ID号pthread_self)
  - [C-获得当前线程返回值的错误号和输出错误信息 strerror](#C-获得当前线程返回值的错误号和输出错误信息strerror)
  - [C-单个线程退出,而且不影响其他线程的函数 pthread_exit](#C-单个线程退出,而且不影响其他线程的函数pthread_exit)
  - [C-杀死或取消线程  ptherad_cancel](#C-杀死或取消线程ptherad_cancel)
  - [C-回收子线程资源阻塞等待线程退出,获取线程退出状态  pthread_join](#C-回收子线程资源阻塞等待线程退出,获取线程退出状态pthread_join)
  - [C-设置线程分离 ptherad_detach](#C-设置线程分离ptherad_detach)
  - [C-线程属性](#C-线程属性)
- [在Cpp中的多线程](#在Cpp中的多线程)
  - [C++中的创建线程和头文件](#C++中的创建线程和头文件)
  - [C++中的互斥锁](#C++中的互斥锁)
  - [C++中的原子操作-原子锁](#C++中的原子操作-原子锁)
  - [C++中的自解锁](#C++中的自解锁)
  - [C++信号量锁](#C++信号量锁)
  - 







- `restrict`，C语言中的一种类型限定符（Type Qualifiers），用于告诉编译器，对象已经被指针所引用, 不能通过除该指针外所有其他直接或间接的方式修改该对象的内容。





**使用的是C++标准库提供的多线程.**

==**编译代码命令: `g++ a.cpp -std=c++11   -pthread`**==

## 多线程基础

> **线程和进程的相同点和不同点:**
>
> - 函数调用成功返回0 , 失败返回错误号.(和 errno 没关系 ,不能使用perror来打印错误信息)
> - 如果父线程比子线程提前结束,那么子线程会被直接结束, 因为他们使用的是同一个pid.
> - 子线程只会执行参数内的函数, 不会向下执行,不会回到创建出他的位置.
>
> 
>
> ==**多线程和多进程的区别:**==
>
> - **多进程:**
>   - **始终共享的资源 : 代码.  文件描述符.  内存映射区--mmap  , 可以通过这些内容实现多个进程间的通信**
> - **多线程:**
>   - **堆 , 全局变量**
>   - **线程比进程更加节省资源. 而且也不会减少抢到cpu 的时间碎片个数.  (内核和Cpu 只认pcb无论进程和线程)**





> **查看指定线程的 LWP 号** 
>
> - 线程号和线程ID 是有区别的.
> - 线程号是给内核看的.
>   - 查看方式:
>     - 找到程序的进程ID (首先要找到进程的pid, 然后把下面的pid 替换)
>     - **`ps -Lf pid` 使用这个命令来查询**

- **线程:**
  - **一个单独的进程可以看作是一个 单独的一个线程**
  - ==**创建线程之后, 地址空间没有变化.**==
  - **进程退化成了线程 - 主线程.**
  - ==**创建出的子线程 和主线程 共用地址空间.(但是每个线程之间的栈空间地址是独立的,不相同,不相通,其他的相通)**==
  - **父线程结束后,如果子线程没有设置分离,那么他也会跟着结束.(如果分离了,那么就不会影响到子线程).**
  - **主线程和子线程都有各自独立的pcb.**
    - **子线程的 pcb 是从主线程拷贝来的.**

- ==**主线程和子进程之间通信是靠 全局变量 和 堆.**==



> **主线程和子线程共享的内容**
>
> - **`.text  ,  .bss  ,  .data  ,  堆区  ,  动态库加载区  ,  环境变量  ,  命令行参数`**
>
> **不共享的内容:**
>
> - **栈区  ,  栈区内存储的数据的地址  (每个线程都是独立的)**
> - **如果一个进程有5个线程, 那么栈区会被平均分为5份.**



```c++
注意事项:
- 多线程传参数时,绝对不要使用栈区的内容,一定要使用堆上的内容,因为每个线程的栈区地址不相同.每个线程都是独有的栈区.
- 父线程要回收没有分离的子线程的pcb.
```





### 查看本地CPU核心数和线程数

- **Macos: `sysctl -n machdep.cpu.core_count machdep.cpu.thread_count      #显示核心数和线程数`**
- **Linux: `lscpu`**







### 不同平台下的线程

- 在Linux 下
  - 线程就是进程 - 轻量级的进程. 
  - 对于内核来说, 线程就是进程,  (毕竟是使用进程当模型,修改出来的一个类似进程的版本)
  - **在底层实现上和 windows 是有本质的区别的. 千万不要混为一谈.**
- 在windows 下
  - **线程就是线程, 进程就是进程, 线程的CPU使用率比进程高, 所以大部分都是用线程.**



==**编译代码命令: `g++ a.cpp -std=c++11   -pthread`**==



### 多线程容易造成数据混乱

- **数据混乱的原因:**
  - **操作了共享资源**
  - **cpu 调度出现问题**
- **解决方法:**
  - **线程同步**
    - **协同步调,按照先后顺序执行操作**
  - **数据加锁**





## 线程同步思想

- **线程同步思想**
  - 给共享资源上锁.
    - 然后每个线程都要判断这个锁的状态.然后确定访问权.
    - 如果没有拿到访问权,那么这个线程就会被阻塞,等待解锁.然后再去抢夺锁的拥有权.
  - **通过加锁的机制,将线程的 并行 变更为了 串行.**



### 线程同步实现

- ==**通过这个条件变量和 互斥锁可以实现 线程同步.**==
  - **条件变量 :  这个本质不是锁. 但是条件变量能够阻塞线程.**



> - **条件变量 + 互斥量(锁) 能够完成线程同步, 但是单一的话是不可以的.需要两个组合使用**
>   - **互斥量(锁) :  保护一块共享数据**
>   - **条件变量 : 引起阻塞**

- **条件变量的两个动作是:**
  - **条件不满足, 阻塞线程** 
  - **当条件满足, 通知阻塞的线程开始工作**
- **条件变量的类型是: `pthread_cond_t ;`**

```c

主要函数:
	条件变量的类型是: pthread_cond_t cond;

初始化一个条件变量
  	int pthread_cond_init(
        pthread_cond_t* restrict cond,        //条件变量
       const pthread_condattr_t* restrict attr);    // 第二个参数是属性, 给NULL就好了 不需要设置

销毁一个条件变量
  int pthread_cond_destroy( pthread_cond_t* cond );

阻塞等待一个条件变量
  int pthread_cond_wait( pthread_cond_t* restrict cond,   // 条件变量的类型
                    pthread_mutex_t* restrict mutex);       // 这个是互斥锁的指针.
// 这个函数 会阻塞线程, 然后将已经上锁的 mutex 这个互斥锁解锁. 
//  当这个函数解除阻塞的时候, 会对互斥锁加锁.

唤醒至少一个 阻塞在条件变量上的线程:  { 到底唤醒几个 不确定 }
int pthread_cond_signal( pthread_cond_t* cond);

唤醒全部 阻塞在条件变量上的线程: { 全部都要醒 }
int pthread_cond_broadcast( pthread_cond_t* cond);

限时等待一个条件变量
 int pthread_cond_timedwait( pthread_cond_t* restrict cond,   // 条件变量的类型
                         pthread_mutex_t* restrict mutex,            // 互斥锁
                         const struct timespec* restrict abstime);   // 一个结构体,内部保存着需要设定的时间,需要自定义

```



### 线程同步范例-生产者与消费者模型

```c
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
// 简单线程同步范例

// 创建节点结构
typedef struct node{
    int data;
    struct node* next;
}Node;

// 永远指向链表头部的指针
Node* head = NULL;

//线程同步 需要一个互斥锁
pthread_mutex_t mutex;

//阻塞线程 ,条件变量类型的变量
pthread_cond_t cond;

// 生产者
void* producer(void* arg){
    while(1){
        // 创建一个链表的节点
        Node* pnew = (Node*)malloc(sizeof(Node));
        pnew->data = rand() % 1000;  // 范围 0-999

        pthread_mutex_lock( &mutex);
        pnew->next = head;
        head = pnew;
        printf("==== produce: %lu, %d\n",pthread_self(),head->data);
        pthread_mutex_unlock( &mutex);

        // 通知消费者线程 解除阻塞
        pthread_cond_signal( &cond);
     //   sleep(rand() % 3);
    }
    return NULL;
}
void* customer(void* arg){
    while(1){
        pthread_mutex_lock( &mutex);
        if( head == NULL){
            pthread_cond_wait( &cond, &mutex ); // 阻塞,互斥锁解锁
          // 等待pthread_cond_signal(); 函数的通知, 然后解除阻塞, 互斥锁上锁
        }
        Node* pdel = head;
        head = head->next;
        printf("----- customer: %lu, %d\n",pthread_self(), pdel->data);
        free(pdel);
        pthread_mutex_unlock( &mutex);
    }
    return NULL;
}


int main(int argc, char* argv[]){
    pthread_t p1,p2;
    // 初始化互斥锁和条件变量类型
    pthread_mutex_init( &mutex, NULL );
    pthread_cond_init( &cond,  NULL);


    
    //生产者线程
    pthread_create( &p1, NULL, producer, NULL);
    //消费者线程
    pthread_create( &p2, NULL, customer, NULL);
    
    // 阻塞 回收子线程
    pthread_join( p1, NULL);
    pthread_join( p2, NULL);
    
    // 销毁互斥锁和条件变量
    pthread_mutex_unlock( &mutex);
    pthread_cond_destroy( &cond);

    return 0;
}


```



## 信号量线程同步

> `<semaphore.h>`  也是一种同步方式:   信号量

- **信号量 (信号灯) : 是锁   而且是并行的**
  - **他和 互斥锁的区别就是 资源大小, 互斥锁只能是1 ,而他却可以大于1. 能够实现线程并行处理.互斥锁是串行.**

- **信号量类型: `sem_t sem;     // 就是一个加强版的 互斥锁.`**

```c
#include <semaphore.h>

信号量类型:   
    sem_t sem;     // 就是一个加强版的 互斥锁.

主要函数:
    初始化信号量
        sem_init(sem_t* sem, int pshared, unsigned int value);
            
            pshared 参数 : 0 - 线程同步
                          1 - 进程同步
            value   参数:  最多有几个线程 同时 操作共享数据

    销毁信号量
        sem_destroy(sem_t* sem);

    加锁
        sem_wait(sem_t* sem);
            调用一次相当于对 sem 初始化的value 做了 --(自减) 操作
            如果sem值为0, 线程会阻塞.

    尝试加锁
        sem_trywait(sem_t* sem)
            sem == 0 , 加锁失败, 不阻塞, 直接返回
              
    解锁
        sem_post(sem_t* sem);
            对 sem 初始化的 value 做 ++ (自增) 操作, 不能大于value的上限.
```



### 信号量线程同步范例-生产者消费者模型

```c
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <signal.h>
#include <stdlib.h>
#include <pthread.h>


//范例  这是个线程的,   也可以修改成进程的, 但是需要 mmap 内存映射区 来通信


sem_t  produce_sem ;
sem_t  custom_sem  ;

// 创建节点结构
typedef struct node{
    int data;
    struct node* next;
}Node;

// 永远指向链表头部的指针
Node* head = NULL;


// 生产者
void* producer(void* arg){
    while(1){
        sem_wait( &produce_sem);  // pro --  == 0 ,阻塞
        // 创建一个链表的节点
        Node* pnew = (Node*)malloc(sizeof(Node));
        pnew->data = rand() % 1000;  // 范围 0-999
        pnew->next = head;
        head = pnew;
        printf("==== produce: %lu, %d\n",pthread_self(),head->data);
        
        sem_post( &custom_sem ); // custom ++

        sleep(rand() % 3);
    }
    return NULL;
}

void* customer(void* arg){
    while(1){
        sem_wait(&custom_sem);
        if ( head != NULL ){
            Node* pdel = head;
            head = head->next;
            printf("----- customer: %lu, %d\n",pthread_self(), pdel->data);
            free(pdel);
        }
        sem_post( &produce_sem);

        sleep(rand() %4);

    }
    return NULL;
}


int main(int argc, char* argv[]){
    pthread_t p1,p2;
    // 初始化互斥锁和条件变量类型

    sem_init(&produce_sem, 0 ,100);
    sem_init(&custom_sem, 0 ,0 );

    
    //生产者线程
    pthread_create( &p1, NULL, producer, NULL);
    //消费者线程
    pthread_create( &p2, NULL, customer, NULL);
    
    // 阻塞 回收子线程
    pthread_join( p1, NULL);
    pthread_join( p2, NULL);

    sem_destroy(&produce_sem);
    sem_destroy(&custom_sem);
    
    return 0;
}
```





## 互斥量-互斥锁

> **互斥量 (互斥锁) { 如果一个线程加锁, 那么所有线程全部都要加锁 ,而且还是同一把锁 }**
>
> **一个资源一把锁, 而不是一个线程一把锁.**

- **互斥锁类型 :**
  - **创建一把锁  `pthread_mutex_t mutex;`**

- ==**每个共享资源 都会拥有一把只属于自己的锁, 就是说 有多少共享资源, 就会有多少把锁.**==



**互斥锁的特点:**

- **多个线程访问共享数据的时候是串行的操作.**

**互斥锁的缺点:**

- **效率过低.**



> 互斥锁的使用步骤:
>
> 1. **创建互斥锁:  `pthread_mutex_t mutex;`**
> 2. **初始化这把锁 : `pthread_mutex_init(&mutex, NULL);`**
> 3. **寻找共享资源 :**
>    1. **操作共享资源之前加锁: `pthread_mutex_lock(&mutex);    //上锁后操作共享资源 ...`**
>    2. **操作共享资源结束后解锁: `pthread_mutex_unlock(&mutex);`**
> 4. **加锁和解锁中间的操作被称作 临界区 . 这个临界区越小越好, 加锁解锁非常频繁,这个是很正常的.**



### 互斥锁的相关函数

```c
#include <pthread.h>

创建一把互斥锁:  
      pthread_mutex_t mutex;

初始化锁:   
    int pthread_mutex_init(pthread_mutex_t* mutex, const pthread_mutexattr_t* attr);
        参数:  mutex : 锁 
              attr  : 锁的属性, 一般给NULL 就好了, 我们不关心

销毁互斥锁:
    int pthread_mutex_destroy(pthread_mutex_t* mutex);
        参数:   mutex : 锁

加锁:  { 有阻塞 } 
   int  pthread_mutex_lock(pthread_mutex_t* mutex);
        参数:   mutex : 锁
        [ 没有上锁, 当前线程会将这把锁 锁上. ]
        [ 被锁上了:  当前进程阻塞.   ]
            [ 锁被打开之后, 线程解除阻塞 ]

加锁: { 无阻塞 }
   int pthread_mutex_trylock(pthread_mutex_t* mutex);
        没有锁上: 当前进程会给这把锁 加锁.
        如果锁上了: 不会阻塞, 会返回一个非0 的错误号. (char* strerror(number) 来打印)
        使用该函数时,必须使用if 判断返回值是否为0 ,而且必须填写 else 语句的错误处理.
     例: 
        if( pthread_mutex_trylock( &mutex) == 0){
            // 尝试加锁, 并且成功了
            // 访问共享资源操作
        } else {
            // 错误处理.  或者等一会再次尝试加锁
        }

解锁:
   int pthread_mutex_unlock(pthread_mutex_t* mutex);
        参数:   mutex: 锁  { 无论有无阻塞都可以解锁 }
```



### 原子操作和死锁

> **原子操作 : cpu 处理一个指令, 线程/进程 在处理完这个指令之前是不会失去cpu的.**
>
> **死锁  : 所有线程都阻塞了. (忘记解锁, 或多重上锁,或访问一个锁的时候再去访问另一个锁). {说白了是自己作死}**



## 读写锁

> **一个资源一把锁, 而不是一个线程一把锁.**

- **读写锁 :  { 这是一个锁, 他的名字是 读写锁 }** 
  - **`pthread_relock_t  lock;    // 读写锁的变量,他拥有读属性和写属性`**



- ==**读写锁的类型:**==
  - **读锁  - 对内存做读操作**
  - **写锁  - 对内存做写操作** 



- **读写锁的特性:**

  - **程A 加 `读锁` 成功, 又来了三个线程,做 `读操作`, 可以操作成功.**
    - 读共享  . 并行处理
  - **线程A 加 `写锁` 成功, 又来了三个线程,做 `读操作`, 三个线程阻塞.**
    - 写独占
  - **线程A 加 `读锁` 成功, 又来了B 线程加 `写锁`  B线程阻塞, 又来了C 线程加`读锁` 阻塞.**
    - **读写不能同时操作.**
    - ==**写的优先级高.(无论先来后到)**==

  

- **读写执行场景:**

  - **线程A 加 `写锁`成功, 线程B 请求`读锁`.**
    - **线程B 阻塞. 写独占**
  - **线程A 持有`读锁`, 线程B 请求写锁.**
    - **线程B 阻塞. 读写不能同时操作**
  - ==**线程A拥有`读锁`, 线程B请求`读锁`.**==
    - ==**线程B 加锁成功. 可以访问**==
  - **线程A 持有`读锁`, 然后线程B 请求 `写锁`, 然后线程C 请求`读锁`.**
    - **B阻塞, C阻塞 , 写的优先级高**
    - ==**A 解锁, B 加写锁成功. C 继续阻塞.**==
    - ==**B 解锁, C 加读锁成功.**==
  - **线程A 持有`写锁`, 然后线程B 请求`读锁`, 然后线程C 请求`写锁`.**
    - **B阻塞, C阻塞**
    - ==**A解锁, C加写锁成功, B 继续阻塞   写的优先级高.(无论先来后到)**==
    - **C解锁, B加写读成功**



- **读写锁的使用场景:**
  - **读写锁:**
    - 读 - 并行 (一起走)
    - 写 - 串行 (一个接一个)
  - **程序中的 读操作的个数远大于 写操作的时候.**



### 读写锁主要操作函数

```c
#include <pthread>


restrict，C语言中的一种类型限定符（Type Qualifiers），用于告诉编译器，对象已经被指针所引用，不能通过除该指针外所有其他直接或间接的方式修改该对象的内容。


 0. 创建一把锁
      pthread_relock_t  lock;    // 读写锁的变量,他拥有读属性和写属性

 a.初始化读写锁
      int pthread_rwlock_init(
            pthread_rwlock_t* restrict rwlock,      // pthread_relock_t 锁的变量地址
            const pthread_rwlock_t* restrict attr   // 锁的属性, 给 NULL 就好了
            );

  b.销毁读写锁
      int pthread_rwlock_destroy(pthread_rwlock_t* rwlock);

  c.加读锁
      int pthread_rwlock_rdlock(pthread_rwlock_t* rwlock);
            // 阻塞: 之前这把锁加的是写锁的操作.

  d.尝试加读锁
      int pthread_rwlock_tryrdlock(pthread_rwlock_t* rwlock);
            // 加锁成功: 返回0     失败返回:错误号 (strerror(number))
  e.加写锁
      int pthread_rwlock_wrlock(pthread_rwlock_t* rwlock);
            // 阻塞: 1. 上一次加的是写锁, 还没解锁的时候
            //      2.  上次加的是读锁, 还没解锁的时候

  f.尝试加写锁
      int pthread_rwlock_trywrlock(pthread_rwlock_t* rwlcok);
            // 加锁成功: 返回0      失败返回:错误号 (strerror(number))

  g.解锁
      int pthread_rwlock_unlock(pthread_rwlock_t* rwlock);
            // 无论读锁还是写锁,都是用这个, 毕竟两种锁不能同时生效.
```



### 读写锁范例

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// 读写锁范例   8个线程 其中5个读 number  剩下3个写number
int number = 0;
pthread_rwlock_t lock;

void* write_func(void* arg){
    // 循环写
    while(1){
        pthread_rwlock_wrlock( &lock );
        number++;
        printf("== write:%d , %d\n", *((int*)arg), number);
        pthread_rwlock_unlock( &lock );
        usleep(100000);
    }
    return NULL;
}

void* read_func(void* arg){
    while(1){
        
        pthread_rwlock_rdlock( &lock );
        printf("== read:%d ,%d\n",*((int*)arg),number);
        pthread_rwlock_unlock( &lock );
        usleep(100000);
    }
    return NULL;
}

int main(int argc, char* argv[]){
    //初始化读写锁
    int* t = (int*)malloc(sizeof(int) * 8);
    for(int n =0; n < 8 ;n++){
        t[n] = n;
    }
    
    pthread_rwlock_init(&lock, NULL);
    pthread_t p[8];
    // 循环创建三个写线程
    // 创建五个读线程
    for(int i=0; i<3; ++i){
        pthread_create( &p[i], NULL, write_func, &t[i]);
    }
    for(int i=3; i<8; ++i){
        pthread_create( &p[i], NULL, read_func, &t[i]);
    }
    //回收子线程pcb
    for(int i=0; i<8 ;++i){
        pthread_join(p[i], NULL);
    }
    //释放读写锁资源
    pthread_rwlock_unlock(&lock);
    return 0;
}
```









## 在C中的多线程

> **线程头文件 `<thread.h>`**

- **函数调用成功返回0 , 失败返回错误号.(和 errno 没关系 ,不能使用perror来打印错误信息)**
- **如果父线程比子线程提前结束,那么子线程会被直接结束, 因为他们使用的是同一个pid.**

- **子线程只会执行参数内的函数, 不会向下执行,不会回到创建出他的位置.**



### C中的创建线程函数原型pthread_create

```c
#include <thread.h>

int pthread_create( 
            pthread_t* pthread,      // 线程ID = 无符号长整型  pthread_t
            const pthread_attr_t* attr,     // 线程属性 ,NULL
            void* (*start_routine)(void*),  // 线程处理函数
            void* arg           // 线程处理函数参数
            );

参数:    thread: 传出参数, 线程创建成功之后,会被设置一个合适的值
          attr: 默认传NULL,也可以传递进程分离参数 ,但是需要自己定义一个,然后使用函数初始化在传递过来.
 start_routine: 子进程的处理函数
           arg: 回调函数的参数 (小心地址传递和值传递,有必要的话 可以上锁).

返回值:
     成功返回0 ,失败返回错误号.(这是进程独有的错误号,不能和其他标准库的混为一谈)

/****************************************/
范例: 
void* myfunc(void* no){  
  printf("当前线程的 线程ID %ld \n, 传入参数 %d \n", pthread_self(), *a);
  /*自定义回调函数, 这里的内容省略 */ 
}

int main(){
	pthread_t pthid;
	int* a = 10;
	int ret = pthread_create(&pthid, NULL, myfunc, (void*)a);
	if(ret != 0 ){
 	 printf("error number %d , : %s",ret , strerror(ret));
	}
}
```



### C-获得当前线程的ID号pthread_self

- **虽然可以获得线程ID号,但是无法进行打印出来.**

```c
#include <pthread.h>

pthread_t pthread_self(void);

返回值 : 使用这个函数的返回值可以用来进行线程分离.

pthread_detach(pthread_self());     //将当前线程进行 线程分离.
```



### C-获得当前线程返回值的错误号和输出错误信息strerror

- **创建线程时, 如果失败,就会返回错误号.**
- **如果想获得进程的错误信息, 那么必须使用`strerror()`这个函数, 其他的都不行.**

```c
<string.h>
<stdio.h>
<pthread.h>

因为 pthread_create() 函数返回的是错误号,而且不能是perror来打印错误信息.

错误输出信息的函数原型:
char* strerror(int errnum);   
   errnum 参数:  他接受错误码,然后读取这个错误码,输出错误码信息, 也就是 pthread_create() 返回值

    返回值:  就是错误码对应的信息.

如果想获得进程的错误信息, 那么必须使用这个函数, 其他的都不行.
```



### C-单个线程退出,而且不影响其他线程的函数pthread_exit

- **结束一个线程, 但是无法释放自己的pcb .需要父线程来释放. 而且该线程退出后,它本身的栈区就会被销毁.**
- **就是结束当前线程**

```c
void pthread_exit(void *retval);

    retval  参数: 可以NULL, 也可以给主线程返回一个信息. 但是主线程需要使用pthread_join来接收.
                   但是需要注意返回值必须是 堆 或全局变量 ,需要保证数据还存在.
```



### C-杀死或取消线程ptherad_cancel

- **注意事项:**
  - **子进程被杀死前,必须进行过一次系统调用(printf,read,write,都会进行系统调用).**
    - **如果实在不确定子线程有没有调用系统函数. 那么给子进程函数中设置一个 `ptherad_testcancel()`; 这个函数也可以.**
    - **`ptherad_testcancel();` 这个函数没有任何意义,就是为了插入一个断点,让父线程可以杀掉这个子线程的一个位置.**

```c
int pthread_cancel(pthread_t thread);

	  pthread 参数: 需要杀死的线程ID

范例:
 void Pth(void){
 	pthread_testcancel();    //开始就调用了.
	while(1);  // 死循环,什么都不做, 也不会自动退出  
}
int main(void){
  pthread_t pt ;
  int ret = pthread_create( &pt, NULL, Pth, NULL);
  if ( 0 != ret ){
    printf("error number %d , : %s",ret , strerror(ret));
    return -1; 
  }
  else{
  	sleep(20);  //等待一下子线程,让他开始运行
    ptherad_detach(pt);   // 线程分离
    pthread_cancel(pt);   // 手动杀死这个子线程.
  }
  return 0;
}
```





### C-回收子线程资源阻塞等待线程退出,获取线程退出状态pthread_join

- **如果是线程分离,那么就不能使用这个函数了**
- ==**这个函数会阻塞主线程, 直到子线程结束.**==

```c
int pthread_join(pthread_t thread, void** retval);

	thread  参数: 要回收的子线程的线程id
  retval  参数: 读取线程退出的时候携带的状态信息. 
                 这是一个传出参数.
                 和 pthread_exit 中的 retval参数指向内存地址相同.

返回值:  如果成功返回 0 ;
        如果失败返回 返回错误编号, 需要使用 strerror 来读取.


/*****************************************************/
范例:  void* ptr;     // 用来存放退出线程所携带的信息
      pthread_join(pthread,&ptr);   // 阻塞主线程,等待子线程退出 ,然后把信息写入 ptr

```



### C-设置线程分离ptherad_detach

- **一旦设置了线程分离, 那么它就会自动回收子线程的pcb**
- **分离之后,子线程会自己回收本身的pcb, 不需要父进程的参与回收.**

```c
int ptherad_detach(pthread_t pthread);
	
	 pthread 参数 : 需要分离的线程ID

/* ******************************************************* */
直接设置线程分离的例子:
        pthread_t pthid;
        pthread_create(pthid, NULL, myfunc, NULL);
        ptherad_detach(pthid);
        // 完成 线程分离了 , 不需要设置属性
```





### C-线程属性

- **线程属性:**
  - ==**这种设置 一般用在创建线程之前,然后使用这个设置去创建线程**==

- **通过线程属性设置线程的分离:**
  - 线程属性类型 : `ptherad_attr_t attr;  // 这种设置的好处显而易见, 子线程可以独立释放pcb ,防止僵尸进程.`

```c
线程属性类型 : 
       ptherad_attr_t   attr;  //这个attr是线程属性,初始化他,然后传给 pthread_create().第二个参数

线程属性操作函数:
   - 对线程属性变量的初始化
        int pthread_attr_init(pthread_attr_t* attr);
   - 设置线程分离属性
        int ptherad_attr_setdetachstate( pthread_attr_t* attr, int detachstate);
         参数:   attr :  线程属性 
          detachstate : PTHREAD_CREATE_DETACHED (分离)
                        PTHREAD_CREATE_JOJINABLE (非分离)


   - 释放线程属性资源函数:
        int pthread_attr_destroy(pthread_attr_t* attr);
                    // 上面的attr 使用完后需要用这个回收


/*************************************************************************************/

    范例:
		void myfunc(void) {}  // 空函数

    // 创建一个子线程
    pthread_t pthid;
    
    pthread_attr_t attr;        // 声明一个线程属性变量
    pthread_attr_init(&attr);     // 将这个变量初始化
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);  // 将属性设置为 分离

    int ret = pthread_create(&pthid, &attr, myfunc, NULL); // 创建线程,并将属性传入,分离

    if( ret != 0){                                  // 判断是否创建成功
        printf("error number: %d\n",ret);
        printf("%s\n",strerror(ret));
        exit(1);
    }
    
    printf("parent thread id: %ld\n",pthread_self());   // 输出当前线程的id 号

    sleep(2);
    pthread_attr_destroy(&attr);        // 释放线程属性变量占用的空间.
```





## 在Cpp中的多线程

> **线程头文件 `<thread>`**

- **c++提供的多线程有两个阶段, 一个是创建线程, 一个是启动线程.**
  - **一个线程必须要先创建, 然后再启动,才算的上是一个完整的流程**
  - **应该使用`t.detach()` 来启动线程, 这样会自动设置线程分离, 以免出现资源回收之类的诸多麻烦.**



### C++中的创建线程和头文件

> **线程头文件 `<thread>`**

- **使用 `std::thread t(函数指针);` 这样来创建线程**
  - **`std::thread t(函数指针, 参数1, 参数2, 参数3 );` 这样来传递线程函数需要的参数**
    - ==**`t.detach();` 可以启动线程并设置线程分离,否则会返回 `SIGABRT` 信号**==
      - **如果创建了 数组对象.那么执行一次 `.detach()` 就会把数组内的所有线程全部开启, 也就是说, 重复调用是无效的.但是可以解决删除问题.**
        - ==**但是, 没有执行 `.detach() 或 .join()` 的 存在于堆或栈上的线程对象, 是不能够执行`delete`的, 必须全部调用, **==
    - **`t.join();` 会启动一个或多个线程,并等待该线程执行结束之后,继续执行主线程**
      - **多个线程指的是数组, 里面都是线程对象, 当数组中的某个对象调用 `.join()` 时, 数组内的所有对象全部都会启动, 也就是某个时间点一起并行执行.**
- **使用`std::thread t(函数指针);` 来创建线程,但不调用 `.detach() 和 join()` 的任何一个,那么线程会直接启动, 但是父进程结束前会收到一个信号 `SIGABRT` . 这个是没有调用`.detach() 和 join()` 引发的.**
  - **如果使用 `std::thread t(函数指针);` 创建线程,并且调用了  `.detach() 或 join()` .那么线程会在`.detach() 或 join()` 调用处启动, 不会在创建函数之后就直接运行子线程.**.
- **可以让线程去执行某个类内的函数**
    - `std::thread t(std::mem_fn(&PP::OnRun), this);`
        - **`std::mem_fn(类内成员函数地址, 参数);` 可以将类成员函数 转换成普通函数来交给线程去执行**

```c++
#include <iostream>
#include <thread>

void 
cmdThread(int a, char b){
  std::cout << "第二线程" << std::endl;
}
int
main2(void){
 std::thread t1(cmdThread, 1, 'c');  //如果只是这么写, 不设置.join和.detach,那么线程会直接启动
 std::thread* t2 = new std::thread(cmdThread, 1, 'c');  // 和上面一样.
  // 如果这么写, 那么在主线程结束前,会出现一个信号 SIGABRT,这个信号给 t1和t2调用 detach即可解决.
}

int 
main(void){
  std::thread t1(cmdThread, 1, 'c');  //创建线程. 并准备好了需要传递的参数
  t1.detach();                    //启动线程 并 设置线程分离
  
  std::thread t2(cmdThread, 1, 'c');  //创建线程. 并准备好了需要传递的参数
  t2.join();                      // 启动线程,并等待该线程结束,然后主线程继续向下执行
    
  
  thread t3[3];       //创建线程数组. 不用给初始化.
  for (int i =0; i< 3; i++){
    t3[i] = thread(workFun, 1 , 'b' );     // 循环进行初始化,但是使用的是 匿名对象深拷贝.(效率低)
    t3[i].join();      // 进程挨个启动, 因为是挨个创建的, 如果创建全部之后再调用也行, 但是必须全部调用
  }
  
  
  thread* t4[4];       //创建线程数组. 不用给初始化.
  for (int i =0; i< 4; i++){
    t4[i] = new thread(workFun, 1 , 'b' );     // 循环进行初始化,但是使用的是 堆空间.
  }
  t4[0]->detach();       //启动t4 数组内全部的子线程, 但会造成 delete 失败. 应该全部手动调用
  t4[1]->detach();
  t4[2]->detach();
  t4[3]->detach();   //虽然这里调用了, 但是什么都不会发生. 如果不这么做, 会无法删除没有调用.detach()
                     // 的对象, 哪怕对象存在于栈空间也一样, 否则 主线程绝对报错. 
}



//让线程去执行某个类内的函数.
class PP{
    void OnRun(){  }
    
    void Start() {
    // 启动一个线程,去执行工作函数
    // 将类成员函数转化成普通函数指针, 以供线程使用, 这样可以避免非常多的问题. 也是规范写法
    std::thread t(std::mem_fn(&PP::OnRun), this);  //后面的这个this 是非常重要的, 类成员函数的隐藏参数
    t.detach();   //线程分离
}
}

```



## C++中的互斥锁

> **需要头文件 `<mutex>`**

- 需要一个变量(应该是全局的)  `mutex m;` , 互斥锁(`每个资源一把锁,所有线程共享同一把锁`).
  - `m.lock();`  上锁. 应该给临界区上锁.但不应该加在循环上.
  - `m.unlock();` 解锁.
  - **自解锁和自上锁`(可以解决异常)`**:
    - **`lock_guard<mutex> lg(m);`, 找个对象就是一个对 mutex的封装. 构造是 `m.lock();` ,析构是 `m.unlock();`**
    - ==该类型存在于作用域之中,让他自动析构来达到解锁的目的,可以避免一些异常而导致无法解锁的发生==

 

## C++中的原子操作-原子锁

> **需要头文件 `<atomic>`**

- **适用于多线程, 效率非常可观,比 `mutex`要好**
- C++提供了一个原子操作的类型. `atomic<类型> Name;` 
  - 可以将需要共享以及加锁的元素声明为该模版类型.
- **这个原子操作,内部的实现也是锁. 当普通的锁来用即可.**

```C++
#include <mutex>
#include <atomic>
class test{
    // 空的
};

atomic<test>  tTest; // 可以放入对象.
atomic_int sum(0);   // typdef定义的, 原型是, atomic<int> sum(0);
const int tCount = 4; //线程的数量.

void workFun(int index){
	for( int i =0; i< 1000; i++)
	  sum++;
}

int main(int argc, const char * argv[]) {    
  thread* t[tCount] = {};
  for (int i =0; i< tCount; i++){
    t[i] =  new thread(workFun, i);  
  }
  for (int i =0; i< tCount; i++){
    t[i]->detach();
  }
  
  for (int i =0; i< tCount; i++){
    delete t[i];  
  }
}

/* 结论: 线程数4, 每个循环执行 1000次 sum++,  程序结束后 sum = 4000; ,没有任何明面加锁操作. */
```





## C++中的自解锁

> 头文件 `<mutex>`

- **自解锁和自上锁`(可以解决异常)`**:
    - **`std::lock_guard<std::mutex> lg(m);`, 找个对象就是一个对 mutex的封装. 构造是 `m.lock();` ,析构是 `m.unlock();`**
        - m是 `std::mutex m;`
    - ==该类型存在于作用域之中,让他自动析构来达到解锁的目的,可以避免一些异常而导致无法解锁的发生==
- **`std::unique_lock<std::mutex> ug(m);`  这个也是自解锁, 只不过功能更多而已**
    - 可以进行尝试加锁, 循环尝试加锁, 手动解锁等.
    - 还可以提供给信号量锁 去使用

```c++
#include <mutex>
std::mutex  lock;
std::lock_guard <std::mutex> lg(lock);   // 必须用一个 互斥锁


std::unique_lock<std::mutex> ug(lock);  
ug.lock();   // 加锁
ug.try_lock() ;  //尝试加锁
ug.unlock();   //解锁
ug.owns_lock();   // 当前线程是否拥有锁
ug.release();    //释放锁
```







## C++信号量锁

> 头文件 `<condition_variable>` , 翻译过来就是 支持阻塞等待的条件变量

- 陷入阻塞, 等待唤醒
- 但要注意虚假唤醒, 会造成死锁
    - 就是当前没有阻塞线程, 却调用了一次唤醒函数, 随后线程进入了阻塞, 但无法得到唤醒了.

```c++
#include <condition_variable>
#include <mutex>
//使用之前,需要 互斥锁和自解锁 
std::mutex _mutex;     //互斥锁
std::unique_lock<std::mutex> ug(_mutex);   //自解锁, (互斥锁), 这个应该写在局部作用域内, 随时释放.

std::condition_variable  _cv;   //定义信号量锁
_cv.wait(ug);    // 陷入阻塞, 等待其他线程调用唤醒函数 .notify_one() 或 .notify_all()
_cv.wait(ug,[=]()->bool{      /* 陷入阻塞. 当lambda表达式满足某些要求时, 就进行唤醒,而不是继续等待 */
    return true;              
});

_cv.notify_one();   //唤醒一个陷入阻塞的线程
_cv.notify_all();   //唤醒全部陷入阻塞的线程

```

```c++
/*  一个信号量锁的模版 */
#ifndef __CELLSEMAPHORE_HPP__
#define __CELLSEMAPHORE_HPP__
//信号量 类型
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>   //信号量 锁

class CELLSemaphore
{
public:
	CELLSemaphore():_wait(false), _wakeup(0){}
	~CELLSemaphore() {}

	//进入阻塞
	void wait() {
		std::unique_lock<std::mutex> ug(_mutex);
		_wait--;
		if ( 0 > _wait) {
			_cv.wait(ug, [this]()->bool {
				return this->_wakeup > 0;
				});
			_wakeup --;
		}
	}

	//解除阻塞
	void wakeup() {
		std::lock_guard<std::mutex> lg(_mutex);
		_wait++;
		if ( 0 >= _wait) {
			++_wakeup; 
			_cv.notify_one();
		}
	}
private:
	std::mutex _mutex;
	std::condition_variable  _cv;
	int _wait;    //等待计数
	int _wakeup;  //唤醒计数
};
#endif
```













