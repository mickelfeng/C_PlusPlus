/*
线性表; 顺序存储, 问题多多 不完美  ,  可以进行优化
*/
#include <stdio.h>
#include <windows.h>
#include "DynamicArray.h"

void  test01(){
    Dynamic_Array* myArray = Init_Array();

   // 打印容量
    printf("数组容量%d \n", Capacity_Array(myArray));
    printf("数组大小%d \n", Size_Array(myArray));
    // 插入元素
    for (int i = 0; i < 30; i++) {
        PushBack_ArrAy(myArray,i);
    }
    // 打印容量
    printf("数组容量%d \n", Capacity_Array(myArray));
    printf("数组大小%d \n", Size_Array(myArray));
    // 打印
    Print_Array(myArray);

    //删除
    Remove_Array(myArray, 0);
    RemoveByValue_Array(myArray, 27);

    // 打印
    Print_Array(myArray);
    
    // 查找
    int pos =  Find_Array(myArray, 5);
    printf("5查找到: pos : %d    value: %d",pos, At_Array(myArray, pos));


    //销毁
    FreeSpace_Array(myArray);

}


int main(void) {

    test01();

    system("pause");
    return 0;
}