//
//  SeqStack.c
//  cp
//
//  Created by ns on 2018/12/7.
//  Copyright © 2018年 ns. All rights reserved.
//
#include"SeqStack.h"

// API

// 初始化
SeqStack* Init_SeqStack(void){
    SeqStack* stack = (SeqStack*)malloc(sizeof(SeqStack));
    stack->size = 0;
    
    for(int i = 0; i < MAX_SIZE; i++){
        stack->data[i] = NULL;
    }
    
    return stack;
}
// 入栈操作
void Push_SeqStack(SeqStack* stack,void* data){
    if(stack == NULL) {return;}
    if(data  == NULL) {return;}
    
    if(stack->size == MAX_SIZE){
        return;
    }
    
    stack->data[stack->size] = data;
    stack->size++;
}
// 返回栈顶元素
void* Top_SeqStack(SeqStack* stack){
    if(stack == NULL)     {return NULL;}
    if(stack->size ==  0) {return NULL;}
    
    return stack->data[stack->size-1];
}
// 出栈
void Pop_SeqStack(SeqStack* stack){
    if(stack == NULL)    { return; }
    if(stack->size == 0) { return; }
    
    stack->data[stack->size-1] = NULL;   // 这步有没有无所谓, 也没什么必要
    stack->size--;
}
// 判断是否为空
int IsEmpty(SeqStack* stack){
    if(stack == NULL) { return -1; }
    if(stack->size == 0) { return SEQSTACK_TRUE; }
    
    return SEQSTACK_FALSE;
}
// 返回栈中元素的个数
int Size_SeqStack(SeqStack* stack){
    if(stack == NULL) { return -1; }
    return stack->size;
}
// 清空栈
void Clear_SeqStack(SeqStack* stack){
    if(stack == NULL) { return ; }

/*  这步有没有都无所谓的
    for(int i = 0; i < stack->size ; i++){
        stack->data[i] = NULL;
    }
*/
    stack->size = 0;
}
// 销毁栈
void FreeSpace_SeqStack(SeqStack* stack){
    if(stack == NULL){
        return;
    }
    free(stack);
    stack = NULL;
}
