#ifndef _CIRELELINKLIST_H
#define _CIRELELINKLIST_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 链表的小节点
typedef struct CIRCLELINKNODE {
	struct CIRCLELINKNODE* next;
}CircleLinkNode;

// 链表结构体
typedef struct CIRCIELINKLIST {
	CircleLinkNode  head;
	int size;
}CircleLinkList;

#define CIRCLELINKLIST_TRUE  1
#define CIRCLELINKLIST_FALSE 0


// 查找 比较 回调
typedef int(*COMPARENODE)(CircleLinkNode*, CircleLinkNode*);
// 打印回调
typedef void(*PRINTNODE)(CircleLinkNode*);


// API
//初始化函数
CircleLinkList* Init_CircleLinkList();
// 插入函数
void Insert_CircleLinkList(CircleLinkList* clist ,int pos,CircleLinkNode* date);
// 获得第一个元素
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist);
// 根据位置删除
void RempveByPos_CircleLinkList(CircleLinkList* clist, int pos);
// 根据值删除
void RemoveByValue_circleLinkList(CircleLinkList* clist, CircleLinkNode* date, COMPARENODE Compare);
// 获得链表的长度
int Size_CircleLinkList(CircleLinkList* clist);
// 判断是否为空
int IsEmpty_CircleLinkList(CircleLinkList* clist);
// 根据值查找
int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* date, COMPARENODE Compare);
// 打印节点
void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print);
// 释放内存
void FreeSpace_CircleLinkList(CircleLinkList* clist);


#endif