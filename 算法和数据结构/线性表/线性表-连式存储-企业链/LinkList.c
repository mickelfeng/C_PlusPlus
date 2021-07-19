#include "LinkList.h"


// 初始化链表
LinkList* Init_LinkList() {

    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->head.next = NULL;
    list->size = 0;
    return list;
}

// 指定位置插入
void Insert_LinkList(LinkList* list, int pos, LinkNode* date) {
    if (list == NULL) { return; };
    if (date == NULL) { return; };
    if (pos < 0 || pos > list->size) {
        pos = list->size;
    }

    // 查找插入位置
    LinkNode* pCurrent = &(list->head);
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }

    //插入新节点
    date->next = pCurrent->next;
    pCurrent->next = date;

    list->size++;

}

// 删除指定位置的值
void Remove_LinkList(LinkList* list, int pos) {
    if (list == NULL) { return; }
    if (pos <0 || pos >= list->size) { return; }

    // 辅助指针变量
    LinkNode* pCurrent = &(list->head);  // 因为这个 head 是个具体值 不是指针,所以要取地址
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }

    pCurrent->next = pCurrent->next->next;
    list->size--;
}

// 查找  返回位置
int Find_LinkList(LinkList* list, LinkNode* date, COMPARENODE compare) {

    if (list == NULL) { return -2; }
    if (date == NULL) { return -3; }

    //辅助指针变量
    LinkNode* pCurrent = list->head.next;
    int index = 0;
    int flag = -1;
    while (pCurrent != NULL) {
        if (compare(pCurrent, date) == 0) {   // 相等返回0  , 不相等返回 -1
            
            flag = index;
            break;
        }
        pCurrent = pCurrent->next;
        index++;
    }

    return flag;
}

// 获得了链表的长度
int Size_LinkList(LinkList* list) {
    if (list == NULL) {
        return 0;
    }
    return list->size;
}

// 打印链表节点
void  Print_LinkList(LinkList* list, PRINTNODE print) {
    if (list == NULL) { return; };
    
    // 辅助指针
    LinkNode* pCurrent = list->head.next;
    while (pCurrent != NULL) {
        print(pCurrent);
        pCurrent = pCurrent->next;
    }

}

// 释放链表内存
void FreeSpace_LinkList(LinkList* list) {
    if (list == NULL) {
        return;
    }

    free(list);
    list = NULL;
}
