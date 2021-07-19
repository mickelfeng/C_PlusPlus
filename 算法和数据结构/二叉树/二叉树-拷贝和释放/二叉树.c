/*
二叉树: 拷贝二叉树, 释放二叉树内存
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

// 遍历二叉树
void Recursion(BinaryNode* root){
	if(root == NULL){
		return;
	}

	printf("%c ",root->ch);
	Recursion(root->lchild);
	Recursion(root->rchild);

}


// 拷贝二叉树
BinaryNode* CopyBinaryTree(BinaryNode* root){

	if(root == NULL){
		return NULL;
	}

	// 拷贝左子树
	BinaryNode* lchild = CopyBinaryTree(root->lchild);

	// 拷贝右子树
	BinaryNode* rchild = CopyBinaryTree(root->rchild);

	// 创建节点
	BinaryNode* newnode = (BinaryNode*)malloc(sizeof(BinaryNode));
	newnode->ch = root->ch;
	newnode->lchild = lchild;
	newnode->rchild = rchild;

	return newnode;
}
// 释放二叉树内存
void FreeSpace_Binary(BinaryNode* root){
	if(root == NULL){
		return;
	}
	// 释放左子树
	FreeSpace_Binary(root->lchild);

	// 释放右子树
	FreeSpace_Binary(root->rchild);

	//释放当前节点
	free(root);
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

    BinaryNode*root = CopyBinaryTree(&node1);
	Recursion(root);
	FreeSpace_Binary(root);
}


int main(void) {
	CresteBinaryTree();


	return 0;
}