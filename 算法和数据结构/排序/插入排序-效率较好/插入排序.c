/*
 插入排序: 有比较好的效率
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/timeb.h>


#define MAX  10

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

// 插入排序
void InsertSort(int arr[],int length){
    
    int j  = 0;
    for ( int i = 1 ; i < length ; i++){
        
        if(arr[i] < arr[i-1]){
            int temp = arr[i];
            for( j = i -1 ; j >= 0 && temp < arr[j];j--){
                arr[j+1] = arr[j];
            }
            arr[j+1] = temp;
        }
    }
}


int main(void){
    
    int arr[MAX];
    srand((unsigned int )time(NULL));
    for (int i = 0; i < MAX ; i++){
         arr[i] = rand() % MAX;
    }
    
    
    PrintArray(arr, MAX);
    printf("\n");
    InsertSort(arr, MAX);
    PrintArray(arr, MAX);
    printf("\n");
    
    return 0;
}
