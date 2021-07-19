
/*
    堆排序
*/
#include <iostream>
using namespace std;

void PrintArray(int arr[], int len){

    for(int i = 0; i < len ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void MySwap(int arr[],int a, int b){
    int temp = arr[a];
    arr[a]   = arr[b];
    arr[b]   = temp  ;
}


/*
    @param myArr 待调整的数组(二叉树)
    @param index 待调整的节点的下标
    @param len   数组的长度
*/
void HeapAdjust(int arr[], int index, int len){

    // 现保存当前结点的下标( 父节点)
    int max = index;
    //保存左右孩子的数组下标
    int lChild = index * 2 + 1;
    int rChild = index * 2 + 2;

    if(lChild < len && arr[lChild] > arr[max]){
        max = lChild;
    }
    if(rChild < len && arr[rChild] > arr[max]){
        max = rChild;
    }

    if(max != index){
        // 交换两个结点
        MySwap(arr,max,index);   // max 和 index 都是下标, 交换arr 内两个下标内的值
        HeapAdjust(arr,max,len);
    }
}

// 堆排序
void HeapSort(int myArr[],int len){

    // 初始化堆
    for(int i = len / 2 -1; i >= 0; i--){
        HeapAdjust(myArr,i,len);
    }

    // 交换堆顶元素和最后一个元素
    for(int i = len -1 ; i >= 0 ; i--){
        MySwap(myArr,0,i);
        HeapAdjust(myArr,0,i);
    }
}

int main(void){

    int myArr[] = {4,2,8,0,5,7,1,3,9};
    int len = sizeof(myArr)/sizeof(int);
    PrintArray(myArr,len);

    // 堆排序
    HeapSort(myArr,len);

    PrintArray(myArr,len);


    return 0;
}