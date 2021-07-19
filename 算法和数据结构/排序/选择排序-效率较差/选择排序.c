/*
 选择排序:  比冒泡排序减少了交换次数
 
  和冒泡做对比
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/timeb.h>


#define MAX  10000

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

void PrintArray(int arr[] ,int length){
    for( int i = 0 ; i  < length; i++){
        printf("%d ",arr[i]);
    }
}

// 选择排序
void SelectSort(int arr[], int length ){
    
   // 减少了交换次数 , 仅此而已
    for(int i = 0; i < length ; i++ ){
        int min  = i;  // 记录下标
        
        for(int j = i+1; j < length ; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        
        if(min != i){  // 内层循环结束后,min会得到整个数组内的最小值的下标
            Swap(&arr[min], &arr[i]);
        }
        
    }
}


// 冒泡排序
void BobbleSort(int arr[], int length){
    int flag = 0 ;  // 标志量   0标示没有排序好
    
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

int main(void){
    
    int arr[MAX];
    int arr2[MAX];
    srand((unsigned int )time(NULL));
    for (int i = 0; i < MAX ; i++){
         arr[i] = rand() % MAX;
        arr2[i] = arr[i];
    }
    
    // 冒泡排序和所用时间
    long tbubble_start = getSystemTime();
    BobbleSort(arr,MAX);
    long tbubble_end = getSystemTime();
    
    printf("冒泡排序 %d 元素,所需时间%ld \n",MAX,tbubble_end - tbubble_start);
    
    
    // 选择排序和所用时间
    long tselect_start =  getSystemTime();
    SelectSort(arr2,MAX);
    long tseletc_end = getSystemTime();
    
    printf("选择排序 %d 元素,所需时间%ld \n",MAX,tseletc_end - tselect_start);
    
    
    return 0;
}
