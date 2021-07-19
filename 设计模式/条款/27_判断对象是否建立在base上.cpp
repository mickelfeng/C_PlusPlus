#include <iostream>			    
#include <string>
#include <list>
#include <memory>
#include <complex>
using namespace std;

/*
条款27, 继承这个 基类, 重写析构函数,通过list 容器来判别 派生类是否定义在 heap, 把这个类比喻成 flag 就好了
 
  但是不能使用在内建类型身上, 因为内建类型有的并没有 this 指针和释放之类的操作
 
 
*/


// base class
class HeapTracked{
public:
    class MissingAddress{};    // throw exception
    
    virtual ~HeapTracked() = 0;   // destructor is abstract virtual
    static void* operator new(size_t size);
    static void  operator delete(void* ptr);
    bool isOnHeap() const ;
private:
    typedef const void* RawAddress;
    static list<RawAddress>addresses;
};


// static class memory
list< HeapTracked::RawAddress >HeapTracked::addresses;

// this is destructor for HeapTracked base class
HeapTracked::~HeapTracked() {}

void* HeapTracked::operator new(size_t size){
    void* memPtr = ::operator new (size);   // call define global new
    addresses.push_front(memPtr);    // address
    return memPtr;
}

void HeapTracked::operator delete(void* ptr){
    list<RawAddress>::iterator it = find(addresses.begin(),addresses.end(),ptr);
    
    if( it != addresses.end() ){
        addresses.erase(it);
        ::operator delete(ptr);  // free memory  , delete for global
    }else{
        throw MissingAddress();   // throw exception
    }
}

bool HeapTracked::isOnHeap()const {
    const void* rawAddress = dynamic_cast< const void* > ( this );
    list<RawAddress>::iterator it = find(addresses.begin(),addresses.end(),rawAddress);
    return it != addresses.end();
}


// derived class inherit  base Heapracked
// if Asset in (   -> heap   else -> stack )
class Asset : public HeapTracked {
private:
    char*  value;
};


void inventoryAsset(const Asset* ap){
/*
    if( ap->isOnHeap ){
 
 ap is a heapp-based asset - inventory it as such;   // ap is for heap
 
    } else {
 ap is a non-heap-basecd asset - record it that way; // ap is for non-heap
 }
 
*/
}



int main(void){
    
    
    return 0;
}
