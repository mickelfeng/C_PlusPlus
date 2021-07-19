//
//  LinkStack.c
//  cp
//
//  Created by ns on 2018/12/7.
//  Copyright © 2018年 ns. All rights reserved.
//

#include "LinkStack.h"

// API

// 初始化函数
LinkStack* Init_LinkStack(void){
    LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
    stack->head.next = NULL;
    stack->size = 0;
    return stack;
}

// 入栈
void Push_LinkStack(LinkStack* stack,LinkNode* data){
    if(stack == NULL) { return ; }
    if( data == NULL) { return ; }
    
    data->next = stack->head.next;
    stack->head.next = data;
    stack->size++;
}

// 出栈
void Pop_LinkStack(LinkStack* stack){
    if(stack == NULL) { return ; }
    if(stack->size == 0 ) { return ; }
    
    // 第一个有效结点
    LinkNode* pNext = stack->head.next;
    stack->head.next = pNext->next;
    stack->size--;
}

// 返回栈顶元素
LinkNode* Top_LinkStack(LinkStack* stack){
    if(stack == NULL) { return NULL; }
    if(stack->size == 0 ) { return NULL; }
    
    return stack->head.next;
}

// 返回栈元素的个数
int Size_LinkStack(LinkStack* stack){
    if(stack == NULL) { return -1; }

    return stack->size;
}

// 清空栈
void Clear_LinkStack(LinkStack* stack){
    if(stack == NULL) { return ; }
    stack->size = 0;
    stack->head.next= NULL;
}

// 销毁栈
void Free_LinkStack(LinkStack* stack){
    if(stack == NULL) { return ; }
    
    stack->size = 0;
    free(stack);
}


