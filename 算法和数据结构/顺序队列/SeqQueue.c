//
//  SeqQueue.c
//  cp
//
//  Created by ns on 2018/12/7.
//  Copyright © 2018年 ns. All rights reserved.
//

#include "SeqQueue.h"
// API

// 初始化
SeqQueue* Init_SeqQueue(void){
    SeqQueue* queue = (SeqQueue*)malloc(sizeof(SeqQueue));
    queue->size = 0;
    for(int i = 0; i < MAX_SIZE; i++){
        queue->date[i] = NULL;
    }
    
    return queue;
}

// 入队
void  Push_SeqQueue(SeqQueue* queue,void* data){
    if(queue == NULL) { return; }
    if(data  == NULL) { return; }
    if(queue->size == MAX_SIZE) { return; }
    
    // 数组左边当作队头  0 ~ MAX
    queue->date[queue->size] = data;
    queue->size++;
}

// 返回队头元素
void* Front_SeqQueue(SeqQueue* queue){
    if(queue == NULL) { return NULL; }
    
    return queue->date[0];
}

// 出队
void Pop_SeqQueue(SeqQueue* queue){
    if(queue == NULL) { return ; }
    if(queue->size == 0) { return; }
    
    for(int i = 0; i < queue->size-1 ; i++){
        queue->date[i] = queue->date[i+1];
    }
    queue->size--;
    
}
// 返回队尾的元素
void* Back_SeqQueue(SeqQueue* queue){
    if(queue == NULL) { return NULL; }
    if(queue->size == 0 ) { return NULL; }
    return queue->date[queue->size-1];
}

// 返回队长度
int Size_SeqQueue(SeqQueue* queue){
    if(queue == NULL) { return -1; }
    return queue->size;
}
// 清空对列
void Clear_SeqQeueu(SeqQueue* queue){
    if(queue == NULL) { return; }
    
    queue->size = 0;
}
// 销毁
void FreeSpace_SeqQueue(SeqQueue* queue){
    if(queue == NULL) { return; }
    free(queue);    
}
