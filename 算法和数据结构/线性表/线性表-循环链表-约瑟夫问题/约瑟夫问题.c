/*
循环单向链表: 约瑟夫问题
	m 个人围成一圈,首先第 1 人从 1 开始 一个人一个人顺时针报数,报到第 n 个人,
  令其出列.然后再从下一个人开始 从1顺时针报数,报道第 n 个人,在令其出列,......
  如此下去,求出列顺序?
	
	假设  m = 8   n = 3
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CireleLinkList.h"

#define M 8    // 8个人
#define N 3    // 数到 3 就出列

typedef struct MYNUM {
	CircleLinkNode node;
	int val;
}MyNum;

void MyPrint(CircleLinkNode* date) {
	MyNum* num = (MyNum*)date;
	printf("%d  ", num->val);
}

int MyCompare(CircleLinkNode* date1, CircleLinkNode* date2) {
	MyNum* num1 = (MyNum*)date1;
	MyNum* num2 = (MyNum*)date2;

	if (num1->val == num2->val) {
		return CIRCLELINKLIST_TRUE;
	}
	else {
		return CIRCLELINKLIST_FALSE;
	}
}

int main(void) {
	
	// 创建循环列表
	CircleLinkList* clist = Init_CircleLinkList();

	// 链表插入数据
	MyNum num[M];
	
	for (int i = 0; i < M; i++) {
		num[i].val = i + 1;
		Insert_CircleLinkList(clist, i, (CircleLinkNode*)&num[i]);
	}

	// 打印
	Print_CircleLinkList(clist, MyPrint);
	printf("\n");

	int index = 1;
	// 辅助指针
	CircleLinkNode* pCurrent = clist->head.next;
	while (Size_CircleLinkList(clist) > 1) {
		if (index == N) {
			MyNum* temNum = (MyNum*)pCurrent;
			printf(" %d temNum \n", temNum->val);

			//缓存待删除节点的下一个节点
			CircleLinkNode* pNext = pCurrent->next;
			// 根据值去删除
			RemoveByValue_circleLinkList(clist, pCurrent, MyCompare);
			pCurrent = pNext;
			if (pCurrent == &(clist->head)) {
				pCurrent = pCurrent->next;
			}
			index = 1;
		}

		pCurrent = pCurrent->next;
		if (pCurrent == &(clist->head)) {
			pCurrent = pCurrent->next;
		}
		index++;
	}

	if (Size_CircleLinkList(clist) == 1) {
		MyNum* tempNum = (MyNum*)Front_CircleLinkList(clist);
		printf("\n val %d \n",tempNum->val);
	}
	else {
		printf("\n出错\n");
	}

	//释放内存
	FreeSpace_CircleLinkList(clist);

	printf("\n");
	system("pause");
	return 0;
}