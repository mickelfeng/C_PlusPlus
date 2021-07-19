//
//  二叉树的#号创建法.c
//  cp
//
//  Created by ns on 2018/12/9.
//  Copyright © 2018年 ns. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 二叉树节点
typedef struct BINARYNODE {
    char ch;
    struct BINARYNODE* lchild;
    struct BINARYNODE* rchild;
}BinaryNode;


void Recursion(BinaryNode* root){
    if(root == NULL){
        return ;
    }

    printf("%c ",root->ch);
    
    Recursion(root->lchild);
    Recursion(root->rchild);
    
}


// 返回一个二叉树的结点
BinaryNode* CreatBinaryTree(void){
    
    
  //  fflush(stdin);  // 清空缓冲区
    
    char ch ;
    scanf("%c",&ch);
    
    while(getchar() != '\n'){
        continue;
    }
    
    BinaryNode* node   = NULL;

    if(ch == '#'){
        node = NULL;
        
    }else{

        node = (BinaryNode*)malloc(sizeof(BinaryNode));
        node->ch = ch;
        node->lchild = CreatBinaryTree();
        node->rchild = CreatBinaryTree();
    }
    
    return node;
}


int main(void){
    
    //创建树
    BinaryNode* root =  CreatBinaryTree();
    
    //打印树
    Recursion(root);
    
    return 0;
}
