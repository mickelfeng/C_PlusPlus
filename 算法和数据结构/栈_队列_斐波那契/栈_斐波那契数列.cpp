//
//  main.cpp
//  stack
//
//  Created by ns on 2019/3/11.
//  Copyright © 2019 ns. All rights reserved.
//

#include <iostream>
using namespace std;
#define ERROR 0
#define OK    1
#define TRUE  1
#define FALSE 0

#define MAXSIZE  10
typedef int Status;
typedef int SElemType;

/////////////////////////////////////////////////////////////
// 顺序单项栈

typedef struct{
    SElemType data[MAXSIZE];
    int top;
}SqStack;



// 入栈操作
Status  Push(SqStack* S, SElemType e){
    if(S->top == MAXSIZE -1){    // 栈满
        return ERROR;
    }
    S->top++;
    S->data[S->top] = e;
    return OK;
}


// 出栈
Status Pop( SqStack* S, SElemType* e){
    if(S->top == -1)
        return ERROR;
    *e = S->data[S->top];   // 将要删除的栈顶元素给e
    S->top--;       // 栈顶指针减1
    return OK;
}

/////////////////////////////////////////////////////////////////////////
// 顺序双向栈

typedef struct{
    SElemType data[MAXSIZE];
    int top1;   // 栈1 的栈顶指针
    int top2;   // 栈2 的栈顶指针
}SqDoubleStack;

// 入栈2
Status  Push(SqDoubleStack* S, SElemType e, int stackNumber){
    if(S->top1+1 == S->top2)    // 栈满了  不能在添加新元素了
        return ERROR;
    
    if(stackNumber == 1){        //  栈1 有元素进栈
        S->top1++;
        S->data[S->top1] = e;    // 给数组元素赋值
    }
    else if( stackNumber == 2){   // 栈2 有元素进栈
        S->top2--;
        S->data[S->top2] = e;
    }
    
    return OK;
}


// 出栈2
Status Pop(SqDoubleStack* S, SElemType* e, int stackNumber){
    if(stackNumber == 1){
        if(S->top1 == -1)
            return ERROR;
        S->top1--;
        *e = S->data[ S->top1 ];
    }
    else if(stackNumber == 2){
        if(S->top2 == MAXSIZE)
            return ERROR;
        S->top2++;
        *e = S->data[S->top2];
    }
    return OK;
}


////////////////////////////////////////////////////////////////
// 链栈

typedef struct StackNode{
    SElemType data;
    struct StackNode* next;
}StackNode, *LinkStackPtr;


typedef struct LinkStack{
    LinkStackPtr top;    // 这是个指针 , 指向上面的结构体, 栈顶指针
    int count;          // 栈的深度
}LinkStack;     // 栈顶

Status StackEmpty(LinkStack S){
    return S.count == -1 ? TRUE : FALSE;
}


//插入元素e 为新元素
Status Push(LinkStack* S, SElemType e){
    LinkStackPtr s= new StackNode;
    s->data = e;
    s->next = S->top;       // 把当前的栈顶元素赋值给新的节点的直接后继
    
    S->top = s;      // 将新的节点s 赋值给你栈顶指针
    S->count++;
    return OK;
}

// 出栈
Status Pop(LinkStack* S, SElemType* e){
    LinkStackPtr p;
    if(StackEmpty(*S))   // 检查是不是空的,  空的话返回1, 非空返回0
        return ERROR;
    
    *e = S->top->data;
    p = S->top;     // 将栈顶指针下移一位.
    S->top = S->top->next;  //  使得栈顶指针下移一位, 指向后一节点
    delete[] p;
    S->count--;
    return OK;
}


///////////////////////////////////////////////////////////////////////
//  斐波那契数列递归形式
long long  Fbi(long long  i){
    if( i < 2)
        return i;
    return Fbi(i-1) + Fbi(i-2);
    
}

int main(int argc, const char * argv[]) {
    long long i = 1;
    for(; i< 40 ; i++){
        printf(" i = %lld \n ",Fbi(i));
    }
    
    cout << " " << endl;
    return 0;
}
