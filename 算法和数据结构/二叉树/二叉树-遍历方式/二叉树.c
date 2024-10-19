//
//  treeForch.cpp
//  math
//
//  Created by ns on 2024/10/17.
//

#include <iostream>
#include <stdio.h>
// 二叉树节点
typedef struct BINARYNODE {
    char ch;

    struct BINARYNODE* lchild;
    struct BINARYNODE* rchild;
}BinaryNode;

// 递归遍历
void Recursion(BinaryNode* root) {

    if (root == NULL) {
        return;
    }

    // 先访问根节点

//    printf("%c ", root->ch);   // 先序遍历  5 3 2 1 4 7 6 8
 
    // 再遍历左子树
    Recursion(root->lchild);
    printf("%c ", root->ch);   // 中序遍历   1 2 3 4 5 6 7 8 

    // 再遍历右子树
    Recursion(root->rchild);
    //printf("%c ", root->ch);   // 后序遍历      1 2 4 3 6 8 7 5
}

void CresteBinaryTree() {
    /**
                    5
               3          7
            2    4     6     8
        1
     */
    //创建节点
    BinaryNode node1 = { '1',NULL,NULL };
    BinaryNode node2 = { '2',NULL,NULL };
    BinaryNode node3 = { '3',NULL,NULL };
    BinaryNode node4 = { '4',NULL,NULL };
    BinaryNode node5 = { '5',NULL,NULL };
    BinaryNode node6 = { '6',NULL,NULL };
    BinaryNode node7 = { '7',NULL,NULL };
    BinaryNode node8 = { '8',NULL,NULL };

    
    // 建立节点关系
    node5.lchild = &node3;  // root
    node5.rchild = &node7;  // root
    node3.lchild = &node2;
    node3.rchild = &node4;
    node2.lchild = &node1;
    node7.lchild = &node6;
    node7.rchild = &node8;

    // 递归遍历
    Recursion(&node5);
    printf("\n");
}


int main(int argc, char* argv[]){
    CresteBinaryTree();

}
