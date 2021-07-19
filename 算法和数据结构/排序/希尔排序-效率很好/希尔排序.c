/*
 希尔排序算法
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


// 希尔排序算法
void ShellSort(int arr[],int length){
    
    int increasement = length;
    int i,j,k;
    do{
        // 确定分组的增量
        increasement = increasement / 3 + 1;
        
        for(i = 0; i < increasement ; i++){
            
            for(j = i + increasement; j < length ; j+= increasement ){
                
                if(arr[j] < arr[j-increasement]){
                    int temp = arr[j];
                    
                    for( k = j - increasement; k >= 0 && temp < arr[k]; k -=increasement){
                        arr[k+increasement] = arr[k];
                    }
                    
                    arr[k+increasement] = temp;
                    
                }
            }
            
        }
        
    }while(increasement > 1);
}


int main(void){
    
    int arr[MAX];
    int arr2[MAX];
    srand((unsigned int )time(NULL));
    for (int i = 0; i < MAX ; i++){
         arr[i] = rand() % MAX;
        arr2[i] = arr[i];
    }
   
    long tshell_start = getSystemTime();
    ShellSort(arr, MAX);
    long tshell_end = getSystemTime();
    printf("希尔排序 %d 个元素, 耗时 %ld 毫秒\n",MAX,tshell_end-tshell_start);


    return 0;
}
