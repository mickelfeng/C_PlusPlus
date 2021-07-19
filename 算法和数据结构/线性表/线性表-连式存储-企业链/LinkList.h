#ifndef _LINKLIST_H
#define _LINKLIST_H
#include <stdio.h>
#include <stdlib.h>

// 链表小节点
typedef struct LINKNODE {
    struct LINKNODE* next;
}LinkNode;

// 链表结构体
typedef struct LINKLIST {
    LinkNode head;
    int size;
}LinkList;


// API

// 打印函数指针 (回调函数)
typedef void(*PRINTNODE)(LinkNode * );

// 比较的函数指针
typedef int(*COMPARENODE)(LinkNode* , LinkNode*);

// 初始化链表
LinkList* Init_LinkList();

// 指定位置插入
void Insert_LinkList(LinkList* list, int pos,LinkNode* date);

// 删除指定位置的值
void Remove_LinkList(LinkList* list, int pos);

// 查找  返回位置
int Find_LinkList(LinkList* list, LinkNode* date, COMPARENODE compare);

// 获得了链表的长度
int Size_LinkList(LinkList* list);

// 打印链表节点
void  Print_LinkList(LinkList* list, PRINTNODE print);

// 释放链表内存
void FreeSpace_LinkList(LinkList* list);


#endif