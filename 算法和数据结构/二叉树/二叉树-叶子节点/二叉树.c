/*
二叉树: 基础递归遍历方式
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 二叉树节点
typedef struct BINARYNODE {
	char ch;

	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;

int num = 0;
void reat(BinaryNode* root){
	
	if (root == NULL) {
		return ;
	}
	if (root->lchild == NULL && root->rchild == NULL) {
		num++;
		return ;
	}
	else {
		reat(root->lchild);
		reat(root->rchild);
		return ;
	}
}



void CresteBinaryTree() {
	//创建节点
	BinaryNode node1 = { 'A',NULL,NULL };
	BinaryNode node2 = { 'B',NULL,NULL };
	BinaryNode node3 = { 'C',NULL,NULL };
	BinaryNode node4 = { 'D',NULL,NULL };
	BinaryNode node5 = { 'E',NULL,NULL };
	BinaryNode node6 = { 'F',NULL,NULL };
	BinaryNode node7 = { 'G',NULL,NULL };
	BinaryNode node8 = { 'H',NULL,NULL };

	
	// 建立节点关系
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;

	reat(&node1);
	printf("%d\n", num);
}


int main(void) {
	CresteBinaryTree();


	return 0;
}