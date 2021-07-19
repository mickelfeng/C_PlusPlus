//
//  LinkStack.h
//  cp
//
//  Created by ns on 2018/12/7.
//  Copyright © 2018年 ns. All rights reserved.
//

#ifndef LinkStack_h
#define LinkStack_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//链式栈的节点
typedef struct LINKNODE{
    struct LINKNODE* next;
}LinkNode;

// 链式栈
typedef struct LINKSTACK{
    LinkNode head;
    int size;
}LinkStack;

// API

// 初始化函数
LinkStack* Init_LinkStack(void);
// 入栈
void Push_LinkStack(LinkStack* stack,LinkNode* data);
// 出栈
void Pop_LinkStack(LinkStack* stack);
// 返回栈顶元素
LinkNode* Top_LinkStack(LinkStack* stack);
// 返回栈元素的个数
int Size_LinkStack(LinkStack* stack);
// 清空栈
void Clear_LinkStack(LinkStack* stack);
// 销毁栈
void Free_LinkStack(LinkStack* stack);



#endif /* LinkStack_h */
