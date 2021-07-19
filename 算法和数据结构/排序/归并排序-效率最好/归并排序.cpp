/*
 归并排序算法  ; 两个部分, 一个是分组 一个是合并
*/

#include <iostream>
#include <string>
#include <ctime>
#include <sys/timeb.h>
using namespace std;

#define MAX 100000

long getSystemTime(){
    struct timeb tb;
    ftime(&tb);
    return tb.time * 1000 + tb.millitm;
}


// 打印
void PrintArray(int arr[],int len){
    for(int i =0 ; i< len ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 创建数组
int* CreateArray(){
    
    srand((unsigned int)time(NULL));
    int* arr = (int*)malloc(sizeof(int)*MAX);
    for(int i =  0 ; i < MAX; i++){
        arr[i] = rand() % MAX;
    }
    
    return arr;
}

// 合并算法  从小到大
void Merge(int arr[], int start, int end, int mid, int* temp){
    int i_start = start;
    int i_end = mid;
    int j_start = mid +1;
    int j_end = end;
    
    int length = 0;  // 表示辅助空间有多少个元素
    
    // 合并两个有序序列
    while(i_start <= i_end && j_start <= j_end){
        
        if(arr[i_start] < arr[j_start]){
            temp[length] = arr[i_start];
            length++;
            i_start++;
        }else{
            temp[length] = arr[j_start];
            length++;
            j_start++;
        }
        
    }
    
    // i 这个序列
    while(i_start <= i_end){
        temp[length] = arr[i_start];
        i_start++;
        length++;
    }
    
    // j 这个序列
    while(j_start <= j_end){
        temp[length] = arr[j_start];
        j_start++;
        length++;
    }
    
    // 把辅助空间的内容覆盖到原空间
    for(int i = 0; i< length ; i++){
        arr[start+i] = temp[i];
    }
}

// 归并排序 中的分组
void MergeSort(int arr[],int start, int end,int* temp){
 
    if(start >= end){
        return;
    }
    
    int mid = (start + end) / 2;   //拿到数组中元素个数的半数
    
    // 开始分组
    
    // 左半边
    MergeSort(arr, start, mid, temp);
    
    //右半边
    MergeSort(arr, mid+1, end, temp);
    
    // 合并
    Merge(arr, start, end, mid,temp);
    
}

int main(void){
    
    int* myArr = CreateArray();

    // 辅助空间
    int* temp = (int*)malloc(sizeof(int)*MAX);
    
    long t_start = getSystemTime();
    MergeSort(myArr, 0, MAX-1, temp);
    long t_end = getSystemTime();
    printf("归并算法 排序%d 个 , 用时 %ld 毫秒\n",MAX, t_end - t_start);
    
    
    
    
    free(temp);
    free(myArr);
    return 0;
}
