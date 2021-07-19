//
//  冒泡怕序.c
//  cp
//
//  Created by ns on 2018/12/10.
//  Copyright © 2018年 ns. All rights reserved.
//


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/timeb.h>


#define MAX  100

long getSystemTime(void){
    struct timeb tb;
    ftime(&tb);
    return tb.time * 1000 + tb.millitm;
}

void Swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int flag = 0 ;  // 标志量   0标示没有排序好
// 冒泡排序
void BobbleSort(int arr[], int length){
    
    for(int i = 0; i < length && flag == 0 ; i++){
        flag = 1;  // 认为已经排序好了
        for( int j = i+1 ; j < length ; j++){
            if(arr[i] > arr[j]){
                flag = 0;
                Swap(&arr[i], &arr[j]);
            }
        }
    }
}

void PrintArray(int arr[] ,int length){
    for( int i = 0 ; i  < length; i++){
        printf("%d ",arr[i]);
    }
}


int main(void){
    
    int arr[MAX];
    srand((unsigned int )time(NULL));
    for (int i = 0; i < MAX ; i++){
        arr[i] = rand() % MAX;
    }
    
    printf("排序前\n");
    PrintArray(arr, MAX);
    
    long t_start = getSystemTime();
    
    BobbleSort(arr, MAX);
    
    long t_end = getSystemTime();
    
    printf("\n排序后\n");
    PrintArray(arr, MAX);
    
    printf("\n\b 排序元素个数 %d  ,时间 %ld 毫秒 \n",MAX,t_end - t_start);
    
    
    return 0;
}
