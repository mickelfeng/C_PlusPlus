#ifndef _DYNAMIC_ARRAY_H
#define _DYNAMIC_ARRAY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 动态增长内存,策略,将存放数据的内存放到堆上
// 动态数据, 申请内存 拷贝数据 释放原内存
// 容量 capacity 表示我这块内存空间一共可以存放多少元素.
// size 概念, 记录当前数组中具体的元素个数

// 动态数据结构体
typedef struct DYNAMICARRAY {
    int* pAddr;  // 具体存放数据的地址
    int  size;   // 当前有多少个元素
    int  capacity;  // 容量,我容器当前最大能容纳多少个元素
}Dynamic_Array;


// 写一系列的相关对 DYNAMICARRAY 结构体操作的函数
// 初始化
Dynamic_Array* Init_Array(void);
//插入
void PushBack_ArrAy(Dynamic_Array* arr, int value);
//删除  根据位置删除
void Remove_Array(Dynamic_Array* arr, int pos);
//根据值删除
void RemoveByValue_Array(Dynamic_Array* arr, int value);
//查找
int Find_Array(Dynamic_Array* arr, int value);
//打印,遍历
void Print_Array(Dynamic_Array* arr);
//释放动态数据的内存
void FreeSpace_Array(Dynamic_Array* arr);
// 清空数组
void Clear_Array(Dynamic_Array* arr);
//获得动态数组容量
int Capacity_Array(Dynamic_Array* arr);
//获得动态数组当前元素的个数
int Size_Array(Dynamic_Array* arr);
//根据位置获得某个位置的元素
int At_Array(Dynamic_Array* arr,int pos);

#endif