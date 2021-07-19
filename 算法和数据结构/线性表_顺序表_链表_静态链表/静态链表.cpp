#include <iostream>
using namespace std;
#define MAXSIZE 100

/*
#define ERROR 1
#define FLASE 0
#defien TRUE  1
#define OK    0
*/

typedef struct {
    int data;
    int cur;
} List , ListArray[MAXSIZE];

// 0 使用, 1 未使用
int  InitList ( ListArray& L){
    if(L == NULL)
        return -1;
    for( int i = 2; i < MAXSIZE-1 ; ++i ){
        L[i].cur = i+1;
    }
    L[0].cur  = 0;
    L[0].data = 0;
    
    L[1].cur  = 2;
    L[1].data = MAXSIZE-2;
    
    L[MAXSIZE-1].cur  = 1;
    L[MAXSIZE-1].data = -1;
    
    return 0;
}



int ListFind(const ListArray& L, const int pos, int& data){
    if( L == NULL || pos < 1  || pos > L[0].data )
        return -1;
    
    int k = 0;
    for(int i = 0; i < pos ; i++){
        k = L[k].cur;
    }
    
    data = L[k].data;
    return k;
}


int ListRevamp(ListArray& L , const int pos, const int& data){
    if( L == NULL || pos < 1 || pos > L[0].data )
        return -1;
    
    int k;
    int temp = ListFind(L, pos, k);
    L[temp].data = data;

    return 0;
}


int ListDelete(ListArray& L, const int pos, int& data){
    if( pos < 1  || L[0].data == 0 || pos > L[0].data )
        return -1;
    

    int k = 0;
    for(int i=1 ; i<pos ; ++i)
        k = L[k].cur;
    
    int j = L[k].cur;
    L[k].cur = L[j].cur;
    L[0].data--;
    
    k = L[1].cur;
    L[1].cur = j;
    L[j].cur = k;
    L[1].data++;
    data = L[j].data;
    
    return 0;
}

int PosList(ListArray& L){
    int k = L[1].cur;
    L[1].cur = L[k].cur;
    L[1].data --;
    return k;
}

int  InsertList( ListArray& L, const int pos, const int data){
    if(L == NULL || pos > L[0].data+2 || L[1].data < 2 || pos < 1)
        return -1;
    
    do{
        int k = PosList(L);
        if(k){
            L[k].data = data;
            
            int p = 0;
            for(int i =1; i<pos ; ++i)
                p = L[p].cur;
            
            L[k].cur = L[p].cur;
            L[p].cur = k;
            L[0].data ++;
            return 0;
        }
    }while(0);
    return -2;
}


int main(void){
    ListArray L;
    InitList(L);
    
    for( int i  = 1 ; i < 10 ; i++){
        InsertList(L, i , i+2);
    }
    
    int data;
    ListDelete(L, 5 , data);
    
    ListFind(L, 2, data);
    cout << data << endl;
    
    data = 1231;
    ListRevamp(L , 6 , data);
    cout << data << endl;
    
}
