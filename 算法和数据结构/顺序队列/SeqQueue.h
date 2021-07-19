//
//  SeqQueue.h
//  cp
//
//  Created by ns on 2018/12/7.
//  Copyright © 2018年 ns. All rights reserved.
//

#ifndef SeqQueue_h
#define SeqQueue_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// 顺序队列结构体
typedef struct SEQQUEUE{
    void* date[MAX_SIZE];
    int size;
}SeqQueue;

// API

// 初始化
SeqQueue* Init_SeqQueue(void);
// 入队
void  Push_SeqQueue(SeqQueue* queue,void* data);
// 返回队头元素
void* Front_SeqQueue(SeqQueue* queue);
// 出队
void Pop_SeqQueue(SeqQueue* queue);
// 返回队尾的元素
void* Back_SeqQueue(SeqQueue* queue);
// 返回队长度
int Size_SeqQueue(SeqQueue* queue);
// 清空对列
void Clear_SeqQeueu(SeqQueue* queue);
// 销毁
void FreeSpace_SeqQueue(SeqQueue* queue);




#endif /* SeqQueue_h */
