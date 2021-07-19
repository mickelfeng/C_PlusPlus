#include "CireleLinkList.h"

// API
//初始化函数
CircleLinkList* Init_CircleLinkList() {
    CircleLinkList* clist = (CircleLinkList*)malloc(sizeof(CircleLinkList));
    clist->head.next = &(clist->head);   //指向自己  玩命偷懒
    clist->size = 0;
    return clist;
}
// 插入函数
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* date) {
    if (clist == NULL || date == NULL ) { return; }
    if (pos < 0 || pos > clist->size) {
        pos = clist->size;
    }

    // 根据位置查找节点
    // 辅助指针变量
    CircleLinkNode* pCurrent = &(clist->head);
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }

    // 新数据入链表
    date->next = pCurrent->next;
    pCurrent->next = date;

    clist->size++;
}
// 获得第一个元素
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist) {
    return clist->head.next;
}
// 根据位置删除
void RempveByPos_CircleLinkList(CircleLinkList* clist, int pos) {
    if (clist == NULL) { return; }
    if (pos < 0 || pos >= clist->size) { return; }

    // 根据pos找节点
    // 辅助指针变量
    CircleLinkNode* pCurrent = &(clist->head);
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }

    CircleLinkNode* pNext = pCurrent->next;
    pCurrent->next = pNext->next;
    clist->size--;
}
// 根据值删除
void RemoveByValue_circleLinkList(CircleLinkList* clist, CircleLinkNode* date, COMPARENODE Compare) {
    if (clist == NULL) { return; }
    if (date == NULL) { return; }

    // 辅助指针变量
    CircleLinkNode* pPrev = &(clist->head);
    CircleLinkNode* pCurrent = pPrev->next;  // 第一个节点没有值
    int i = 0;
    for (i = 0; i < clist->size; i++) {
        if (Compare(pCurrent, date) == CIRCLELINKLIST_TRUE) {
            pPrev->next = pCurrent->next;
            break;
        }
        pPrev = pCurrent;
        pCurrent = pPrev->next;
    }
    clist->size--;
}
// 获得链表的长度
int Size_CircleLinkList(CircleLinkList* clist) {
    return clist->size;
}
// 判断是否为空
int IsEmpty_CircleLinkList(CircleLinkList* clist) {
    if (clist->size == CIRCLELINKLIST_FALSE) {
        return CIRCLELINKLIST_TRUE;
    }
    else {
        return  CIRCLELINKLIST_FALSE;
    }
    
}
// 根据值查找
int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* date, COMPARENODE Compare) {
    if (clist == NULL) { return -1; }
    if (date == NULL)  { return -2; }
    CircleLinkNode* pCurrent = clist->head.next;
    int flag = -1;
    for (int i = 0; i < clist->size; i++) {
        if (Compare(pCurrent, date) == CIRCLELINKLIST_TRUE) {
            flag = i;
            break;
        }
        pCurrent = pCurrent->next;
    }

    return flag;
}
// 打印节点
void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print) {
    if (clist == NULL) { return; }

    CircleLinkNode* pCurrent = clist->head.next;
    for (int i = 0; i < clist->size; i++)  {
        if (pCurrent == &(clist->head)) {
            printf("---------------\n");
            break;
        }
        print(pCurrent);
        pCurrent = pCurrent->next;
    }
}
// 释放内存
void FreeSpace_CircleLinkList(CircleLinkList* clist) {
    if (clist == NULL) {
        return;
    }
    free(clist);
}
