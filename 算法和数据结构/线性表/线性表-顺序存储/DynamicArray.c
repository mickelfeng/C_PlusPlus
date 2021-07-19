#include "DynamicArray.h"
#include <stdio.h>

// 初始化
Dynamic_Array* Init_Array(void) {
    Dynamic_Array* myArray = (Dynamic_Array*)malloc(sizeof(Dynamic_Array));
    if (myArray == NULL) {
        printf("对象内存申请失败.退出");
        system("pause");
        exit(-1);
    }

    myArray->size = 0;
    myArray->capacity = 20;  
    myArray->pAddr = (int*)malloc(sizeof(int) * myArray->capacity);
    if (myArray->pAddr == NULL) {
        printf("数组内存申请失败.退出");
        system("pause");
        exit(-2);
    }

    return myArray;
}

//插入
void PushBack_ArrAy(Dynamic_Array* arr, int value) {
    if (arr == NULL || arr->pAddr == NULL) {
        return;
    }
    if (arr->capacity == arr->size ) {   // 因为每次插入 只是一个元素,所以不用太过于判断
        // 如果进入了这里, 那么表示容器内存不够用了 ,需要重新申请一块内存

        int* newSpace = (int*)malloc(sizeof(int) * arr->size * 2);

        // 拷贝数据到新的空间     这里拷贝的是字节的, 不是int的类型数据
        memcpy(newSpace, arr->pAddr, arr->capacity * sizeof(int));

        free(arr->pAddr);     // 释放旧空间
        arr->pAddr = newSpace;
        arr->capacity = arr->capacity * 2;
    }
    // 插入新元素

    arr->pAddr[arr->size] = value;
    arr->size++;
}

//删除  根据位置删除
void Remove_Array(Dynamic_Array* arr, int pos) {
    if (arr == NULL || arr->pAddr == NULL) {
        return;
    }

    if (pos < 0 || pos >= arr->size) {
        printf("访问越界 %d  \n", pos);
        return;
    }

    for (int temp = pos; temp < (arr->size - 1); temp++) {
        arr->pAddr[temp] = arr->pAddr[temp + 1];
    }
    arr->size--;
}

//根据值删除
void RemoveByValue_Array(Dynamic_Array* arr, int value) {
    if (arr == NULL || arr->pAddr == NULL) {
        return;
    }
    // 删除value值第一次出现在容器的位置, 而不是全部删除
    int i =  Find_Array(arr, value);
    if (i >= 0) {
        Remove_Array(arr, i);
    }
}

//查找
int Find_Array(Dynamic_Array* arr,int value) {
    if (arr == NULL || arr->pAddr == NULL) {
        return -1;
    }

    int pos = -1;

    for (int i = 0; i < arr->size; i++) {
        if (arr->pAddr[i] == value) {
            pos = i;
            break;
        }
    }

    return pos;
}

//打印,遍历
void Print_Array(Dynamic_Array* arr) {
    if (arr == NULL || arr->pAddr == NULL) {
        return;
    }
    for (int i = 0; i < (arr->size); i++) {
        printf("%d ", (arr->pAddr[i]));
    }
    printf("\n");
}

//释放动态数据的内存
void FreeSpace_Array(Dynamic_Array* arr) {
    if (arr == NULL || arr->pAddr == NULL) {
        return;
    }

    if (arr->pAddr != NULL) {
        free(arr->pAddr);
        arr->pAddr = NULL;
    }
    free(arr);
    arr = NULL;
}

// 清空数组
void Clear_Array(Dynamic_Array* arr) {
    if (arr == NULL || arr->pAddr == NULL) {
        return;
    }
    arr->size = 0;
}

//获得动态数组容量
int Capacity_Array(Dynamic_Array* arr) {
    if (arr == NULL || arr->pAddr == NULL) {
        return 0;
    }
    return arr->capacity; 
}

//获得动态数组当前元素的个数
int Size_Array(Dynamic_Array* arr) {
    if (arr == NULL || arr->pAddr == NULL) {
        return 0 ;
    }
    return arr->size;
}

//根据位置获得某个位置的元素
int At_Array(Dynamic_Array* arr, int pos) {   
    return arr->pAddr[pos];   // 当数组访问越界的时候 直接抛出异常
}