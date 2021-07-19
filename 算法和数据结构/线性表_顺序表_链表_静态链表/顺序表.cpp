#include <iostream>
using namespace std;

#define OK    1
#define ERROR 0
#define TRUE  1
#define FALSE 0

#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

typedef struct {
    ElemType deda[MAXSIZE];
    int length;
}SqList;

Status GetElem( const SqList& L, int i, ElemType& e){
    if( L.length == 0 || i<1 || i>L.length )
        return ERROR;
    
    e = L.deda[i-1];
    return OK;
}

Status ListInsert( SqList& L, int i , ElemType e){
    int k = 0;
    if( L.length == MAXSIZE )
        return ERROR;
    if( i<1 || i> (L.length+1) )
        return ERROR;
    if( i<= L.length ){
        for( k=L.length-1; k>=i-1 ;k--){
            L.deda[k+1] = L.deda[k];
        }
    }
    L.deda[i-1] = e;
    L.length++;
    return OK;
}


Status ListDelete(SqList& L, int i, ElemType& e){
    int k = 0;
    if ( L.length == 0){
        return ERROR;
    }
    
    if( i<1 || i>L.length ){
        return ERROR;
    }
    
    e = L.deda[i-1];
    
    if( i<L.length){
        for(k=i; k<L.length ;k++){
            L.deda[k-1] = L.deda[k];
        }
    }
    L.length--;
    return OK;
}




Status ListPrint( const SqList& L){
    if( L.length == 0){
        cout << "空顺序表" << endl;
        return ERROR;
    }
    for( int i =0; i<L.length ; i++){
        cout << L.deda[i]  << " ";
    }
    cout << "list length = " << L.length << endl;
    cout <<" 结束 " << endl;
    return OK;
}





int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    SqList L = { {0}, 0 };
    for( int i = 0; i< 14 ; i++){
        ListInsert(L, i, i*2+1);
    }
    ListPrint(L);
    
    
    return 0;
}
