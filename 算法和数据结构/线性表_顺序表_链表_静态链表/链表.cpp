#include <iostream>
using namespace std;

#define OK    1
#define ERROR 0
#define TRUE  1
#define FALSE 0
#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node* next;
}Node;

typedef struct Node* LinkList;


Status GetElem( const LinkList L, int i, ElemType& e){
    int j = 0;
    LinkList p;
    p = L->next;
    j = 1;
    while( p && j<i){
        p = p->next;
        ++j;
    }
    if( !p || j>i){
        return ERROR;
    }
    e = p->data;
    return OK;
}

Status ListInsert( LinkList* L, int i , ElemType e){
    int j = 0;
    LinkList p;
    p = *L;
    j = 1;
    while ( p  && j<i){
        p = p->next;
        ++j;
    }
    
    if( !p || j>i){
        return ERROR;
    }
    
    Node* s = new Node;
    
    s->data = e;
    s->next = p->next;
    p->next = s;
    
    return OK;
}


Status ListDelete(LinkList& L, int i, ElemType& e){
    int j;
    LinkList p, q;
    p = L;
    j = 1;
    while( p->next && j<i ){
        p = p->next;
        ++j;
    }
    
    if( !(p->next) || j>i )
        return ERROR;
    
    q = p->next;
    p->next = q->next;   /* p->next = p->next->next; */
    e = q->data;
    delete q ;
    
    return OK;
}



void CreateListHead (LinkList& L, int n){       /* 头插法 */
    LinkList p;
    int i = 0;
    srand( static_cast<unsigned>(time(0)) );
    L = new Node;
    L->next = NULL;
    for(; i<n ; ++i ){
        p = new Node;
        p->data = rand() %100 +1;
        p->next = L->next;
        L->next = p;            /*每次都会把 p 挤走, 抢占第一个位置*/
    }
}


void CreateListTail(LinkList& L, int n){   /*  尾插法 */
    LinkList p , r;
    int i  = 0;
    srand( static_cast<unsigned>(time(0)));
    L = new Node;
    r = L;
    for ( ; i<n ; ++i ){
        p = new Node;
        p->data = rand() %100 +1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}


void ClearList( LinkList& L){
    LinkList p,q;
    p = L->next;
    while(p){
        q = p->next;
        delete[] p;
        p = q;
    }
    L->next = NULL;
}




int main(int argc, const char * argv[]) {
    // insert code here...

    LinkList p;
    CreateListHead(p, 10);
    return 0;
}
