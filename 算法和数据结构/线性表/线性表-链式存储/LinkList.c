#include "LinkList.h"

// 初始化链表
LinkList* Init_LinkList() {
    
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->size = 0;
    list->head = (LinkNode*)malloc(sizeof(LinkNode));   //第一个节点不存储任何数据
    list->head->date = NULL;
    list->head->next = NULL;

    return list;
}

// 指定位置插入
void Insert_LinkList(LinkList* list, int pos, void* date) {
    if (list == NULL || date == NULL ) {
        return;
    }

    if (pos < 0 || pos > list->size) {
        pos = list->size + 1;
    }

    // 创建新的节点
    LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
    newnode->date = date;
    newnode->next = NULL;

    // 找节点
    // 辅助指针变量
    LinkNode* pCurrent = list->head;
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }

    // 新节点入链表
    newnode->next = pCurrent->next;
    pCurrent->next = newnode;
    list->size++;
}

// 删除指定位置的值
void RemoveByPos_LinkList(LinkList* list, int pos) {
    if (list == NULL || pos < 0 || pos >= list->size ) {
        return;
    }

    // 查找删除节点的前一个节点.
    LinkNode* pCurren = list->head;
    for (int i = 0; i < pos; i++) {
        pCurren = pCurren->next;
    }

    // 缓存删除的节点
    LinkNode* pDel = pCurren->next;
    pCurren->next = pDel->next;

    //删除节点
    free(pDel);

    list->size--;
}

// 获得了链表的长度
int Size_LinkList(LinkList* list) {
    return list->size;
}

// 返回第一个节点的数据
void* Front_LinkList(LinkList* list) {
    return list->head->next->date;
}

// 查找  返回位置
int Find_LinkList(LinkList* list, void* date) {
    if (list == NULL || date == NULL) {
        return -1;
    }

    //遍历查找
    LinkNode* pCurrent = list->head->next;   //第一个节点不存储任何数据
    int pos = 0;
    while (pCurrent != NULL) {
        if (pCurrent->date == date) {
            break;
        }
        pCurrent = pCurrent->next;
        pos++;
    }

    return pos;
}

// 打印链表节点
void  Print_LinkList(LinkList* list, PRINTLINKNODE print) {
    if (list == NULL) {
        return;
    }

    // 辅助指针变量
    LinkNode* pCurrent = list->head->next;
    while (pCurrent != NULL) {
        print(pCurrent->date);
        pCurrent = pCurrent->next;
    }
}


// 释放链表内存
void FreeSpace_LinkList(LinkList* list) {
    if (list == NULL) {
        return;
    }
    LinkNode* pCurrent = list->head;
    while (pCurrent != NULL) {
        LinkNode* temp = pCurrent->next;
        free(pCurrent);
        pCurrent = temp; 
    }
    free(list);
}








