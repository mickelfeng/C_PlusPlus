/* 栈的应用:  就近匹配 */#include <stdio.h>#include <string.h>#include <stdlib.h>#include "LinkStack.h"// 判断是否是数字int IsNumber(char c){    return c >= '0' && c <= '9';}// 判断是不是左括号int IsLeft(char c){    return c == '(';}// 判断是不是右括号int IsRight(char c){    return c == ')';}// 判断是不是运算符号int IsOperator(char c){    return c == '+'  ||  c == '-'  ||  c == '*'  ||  c == '/'  ||  c == '%';}// 返回运算符号的优先级int GetPrioty(char c){    if( c == '*' || c == '/'){       return  2;    }    if( c == '+' ||  c == '-'){        return 1;    }        return 0;}typedef struct MYCHAR{    LinkNode node;    char* p;}MyChar;// 创建 MyCharMyChar* CreateMyChar(char* p ){    MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));    mychar->p = p;        return mychar;}//数字操作void NumberOperate(char* c){    printf("%c",*c);}// 左括号的操作void LeftOperate(LinkStack* stack, char* p){    Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));  // 入栈}// 右括号操作void RightOperate(LinkStack* stack){        //需要从栈内弹出数据 , 首先判断栈内有没有元素    while(Size_LinkStack(stack) > 0){        MyChar* mychar = (MyChar*)Top_LinkStack(stack);                // 如果匹配到左括号 , 弹出不输出        if(IsLeft(*(mychar->p))){            Pop_LinkStack(stack);            break;        }                //输出不是左括的内容        printf("%c",*(mychar->p));        // 弹出        Pop_LinkStack(stack);        // 释放内存结点        free(mychar);    }}// 运算符号操作void  OperatorOperate(LinkStack* stack,char* p){    // 先取出栈顶符号    MyChar* mychar  = (MyChar*)Top_LinkStack(stack);        if(mychar == NULL){         Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));        return;    }        // 如果栈顶优先级 低于当前字符的优先级, 直接入栈    if( GetPrioty(*(mychar->p)) < GetPrioty(*p)){        Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));        return ;    }    // 如果优先级不低    else{                while(Size_LinkStack(stack) > 0){                        MyChar* mychar2 = (MyChar*)Top_LinkStack(stack);                        // 如果优先级低     , 当前符号入栈            if(GetPrioty(*(mychar2->p)) < GetPrioty(*p)){                Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));                break;            }                        // 输出            printf("%c",*(mychar2->p));            // 弹出            Pop_LinkStack(stack);            // 释放            free(mychar2);        }    }}int main(void){    char* str = "8+(3-1)*5";    char *p = str;        // 创建栈    LinkStack* stack = Init_LinkStack();        while( *p != '\0'){                // 如果是数字        if(IsNumber(*p)){            NumberOperate(p);        }                //如果是左括号, 直接入栈        if( IsLeft(*p)){            LeftOperate(stack, p);        }                // 如果是右括号        if(IsRight(*p)){            RightOperate(stack);        }                // 如果是运算符号        if(IsOperator(*p)){            OperatorOperate(stack,p);        }            p++;    }        while(Size_LinkStack(stack) > 0){        MyChar* mychar = (MyChar*)Top_LinkStack(stack);        printf("%c",*(mychar->p));        Pop_LinkStack(stack);        free(mychar);    }            printf("\n");    return 0;}