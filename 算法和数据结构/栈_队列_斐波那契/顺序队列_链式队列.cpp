//
//  main.cpp
//  stack
//
//  Created by ns on 2019/3/11.
//  Copyright © 2019 ns. All rights reserved.
//
///    说白了  全都是线性表

#include <iostream>
#include <string>
using namespace std;
#define ERROR -1
#define OK    1
#define TRUE  1
#define FALSE 0

#define MAXSIZE  20
typedef int Status;
typedef int QElemType;



////////////////////////////////////////////////////////
// 队列顺序存储
typedef struct {
    QElemType data[MAXSIZE];
    int front;    // 头指针
    int rear;     // 尾指针   , 若队列不空, 指向队列尾元素的下一个位置
} SqQueue;





// 初始化一个空队列
Status InitQueue(SqQueue* Q){
    Q->front = 0;
    Q->rear  = 0;
    return OK;
}


//返回Q的元素个数, 也就是队列的当前长度
int QueueLength(SqQueue Q){
    return (Q.rear - Q.front +MAXSIZE)% MAXSIZE;
}

// 若队列未满, 则插入元素e 为Q 新的队尾元素
Status EnQueue(SqQueue* Q, QElemType e){
    if(Q->front == Q->rear)
        return ERROR;
    
    Q->data[Q->rear] = e;                 // 将元素e 赋值给队尾
    Q->rear = (Q->rear+1)% MAXSIZE;       // rear 指针向后移 一个位置,
                                          // 如果到了最后 则转到数组头部
    return OK;
}


// 若队列不空, 则删除Q中队头元素  , 用e 返回其值
Status DeQueue(SqQueue* Q, QElemType* e){
    if(Q->front == Q->rear)
        return ERROR;
    *e = Q->data[Q->front];         // 将对头元素付给e
    Q->front = (Q->front+1)% MAXSIZE;    // front  指针向后移动一位置
                                        // 若到最后 则转到数组头部
    return OK;
}



////////////////////////////////////////////////////////
// 队列链式存储

/* typedef int QElemType; */

typedef struct QNode{
    QElemType data;
    struct QNode* next;
} QNode , *QueuePtr;

typedef struct{
    QueuePtr front;
    QueuePtr rear;  // 对头 , 队尾 指针
}LinkQueue;


// 入栈2
Status EnQueue(LinkQueue* Q, QElemType e){
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if(!s)
        exit(EOVERFLOW);
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;      // 把拥有元素e 新节点s 赋值给原队尾节点的后继
    Q->rear = s;            // 把当前的 s 设置为队尾节点, rear 指向 s
    return OK;
}

// 出栈2
Status DeQueue(LinkQueue* Q, QElemType* e){
    QueuePtr p;
    if(Q->front == Q->rear)
        return ERROR;
    
    p = Q->front->next;         // 将欲删除的对头节点 暂存给p
    *e = p->data;               // 将欲删除的对头节点的值赋值给e
    Q->front->next = p->next;    // 将原对头节点后继 p->next 赋值给头节点后继
    
    if(Q->rear == p)            // 若队头是队尾, 则删除后将rear 指向头节点
        Q->rear = Q->front;
    free(p);
    return OK;
}


int main(void){
 
    
    return 0;
}
