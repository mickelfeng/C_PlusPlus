/*
线性表; 链式存储,
*/
#include <stdio.h>
#include <windows.h>
#include "LinkList.h"

//自定义一个数据类型
typedef struct PERSON {
    char name[64];
    int age;
    int score;
}Person;

// 打印回调函数
void Myprint(void *date) {
    Person* p = (Person*)date;
    printf("Name: %s  ,Age: %d , Score: %d \n", p->name, p->age, p->score);
}

void test01() {

    // 创建链表
    LinkList* list = Init_LinkList();

    //创建数据
    Person p1 = { "aaa",18,100 };
    Person p2 = { "bbb",19,99 };
    Person p3 = { "ccc",20,101 };
    Person p4 = { "ddd",17,97 };
    Person p5 = { "eee",16,59 };

    //数据插入链表
    Insert_LinkList(list, 0, &p1);
    Insert_LinkList(list, 0, &p2);
    Insert_LinkList(list, 0, &p3);
    Insert_LinkList(list, 0, &p4);
    Insert_LinkList(list, 0, &p5);

    // 打印
    Print_LinkList(list, Myprint);

    //删除3
    RemoveByPos_LinkList(list, 3);

     // 打印
    printf("--------------------\n");
    Print_LinkList(list, Myprint);


    printf("--------------------\n");
    Person* pt = (Person*)Front_LinkList(list);
    printf("Name: %s  ,Age: %d , Score: %d \n", pt->name, pt->age, pt->score);


    //销毁
    FreeSpace_LinkList(list);

}


int main(void) {
    test01();



    system("pause");
    return 0;
}