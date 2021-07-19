/*
二叉树: 树的深度
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

// 求二叉树高度
int CaculateTreeDepth(BinaryNode* root){
	
	if(root == NULL){
		return 0;
	}
	int depth;

	// 求左子树的高度
	int leftDepth  = CaculateTreeDepth(root->lchild);

	// 右子树高度
	int rightDepth = CaculateTreeDepth(root->rchild);
	
	// 树的高度,取最高的那个, 因为要把root 算上 所以要加1
	depth = leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;

	return depth;
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

	int depth = CaculateTreeDepth(&node1);
	printf("%d\n", depth);
}


int main(void) {
	CresteBinaryTree();


	return 0;
}