//
//  根据后缀表达式求解.c
//  cp
//
//  Created by ns on 2018/12/8.
//  Copyright © 2018年 ns. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkStack.h"

int IsNumber(char c ){
    return c >= '0' && c <= '9';
}

typedef struct MYNUM{
    LinkNode node;
    int val;
}MyNum;

int Caculate(int left, int right ,char c){
    
    int ret = 0;
    
    switch (c) {
        case '+':
            ret = left + right;
            break;
            
        case '-':
            ret = left - right;
            break;
            
        case '*':
            ret = left * right;
            break;
            
        case '/':
            ret = left / right;
            break;
            
        default:
            break;
    }
    return ret;
}


int main(void){
    
    // 后缀表达式
    char* str = "831-5*+";
    char* p   = str;
    
    // 创建栈容器
    LinkStack* stack = Init_LinkStack();
    
    while(*p != '\0'){
        // p 只能是 数字或者是运算符 , 不可以是括号
        
        // 如果是数字  直接入栈
        if(IsNumber(*p)){
            MyNum* num = (MyNum*)malloc(sizeof(MyNum));
            num->val = (*p) - '0';
            Push_LinkStack(stack,(LinkNode*)num);
        }else{
            // 先从栈中弹出右操作数
            MyNum* right = (MyNum*)Top_LinkStack(stack);
            int rightNum = right->val;
            Pop_LinkStack(stack);
            free(right);
            
            // 取出左操作数
            MyNum* left = (MyNum*)Top_LinkStack(stack);
            int leftNum =  left->val;
            Pop_LinkStack(stack);
            free(left);
            
            
            int ret = Caculate(leftNum,rightNum,*p);
            MyNum* num = (MyNum*)malloc(sizeof(MyNum));
            num->val = ret;
            Push_LinkStack(stack, (LinkNode*)num);
        }
        p++;
    }
    
    if(Size_LinkStack(stack) == 1){
        MyNum* num = (MyNum*)Top_LinkStack(stack);
        printf("运算结果是: %d \n",num->val);
        Pop_LinkStack(stack);
        free(num);
    }
    
    // 释放栈
    Free_LinkStack(stack);
    printf("\n");
    return 0;
}
