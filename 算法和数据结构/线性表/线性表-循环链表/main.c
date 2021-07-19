/*
循环单向链表
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CireleLinkList.h"

typedef struct POERSON {
	CircleLinkNode node;
	char name[64];
	int age;
	int score;
}Person;

int MyCompare(CircleLinkNode* date1, CircleLinkNode* date2) {
	Person* p1 = (Person*)date1;
	Person* p2 = (Person*)date2;

	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age && p1->score == p2->score) {
		return CIRCLELINKLIST_TRUE;
	}
	else {
		return CIRCLELINKLIST_FALSE;
	}

}

void MyPrint(CircleLinkNode* date) {
	Person* p = (Person*)date;
	printf("Name: %s, Age: %d, Score: %d \n", p->name, p->age, p->score);
}

int main(void) {

	// 创建循环链表
	CircleLinkList* clist = Init_CircleLinkList();

	// 创建数据
	Person p1, p2, p3, p4, p5;
	strcpy(p1.name, "aaa");
	strcpy(p2.name, "bbb");
	strcpy(p3.name, "ccc");
	strcpy(p4.name, "ddd");
	strcpy(p5.name, "eee");

	p1.age = 10;
	p2.age = 20;
	p3.age = 30;
	p4.age = 40;
	p5.age = 50;

	p1.score = 50;
	p2.score = 60;
	p3.score = 70;
	p4.score = 80;
	p5.score = 90;

	// 数据入链表
	Insert_CircleLinkList(clist, 100, (CircleLinkNode*)&p1);
	Insert_CircleLinkList(clist, 100, (CircleLinkNode*)&p2);
	Insert_CircleLinkList(clist, 100, (CircleLinkNode*)&p3);
	Insert_CircleLinkList(clist, 100, (CircleLinkNode*)&p4);
	Insert_CircleLinkList(clist, 100, (CircleLinkNode*)&p5);

	// 打印
	Print_CircleLinkList(clist, MyPrint);

	Person pDel;
	strcpy(pDel.name, "ccc");
	pDel.age = 30;
	pDel.score = 70;

	// 根据值删除
	RemoveByValue_circleLinkList(clist, (CircleLinkNode*)&pDel, MyCompare);

	// 打印
	printf("----------------------------\n");
	Print_CircleLinkList(clist, MyPrint);



	FreeSpace_CircleLinkList(clist);
	system("pause");
	return 0;
}