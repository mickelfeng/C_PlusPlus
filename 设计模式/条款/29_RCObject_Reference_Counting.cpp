#include <iostream>
#include <string>
using namespace std;

/*
 自动操作 引用次数
*/
 
void strcpys(char* ls1, const char* ls2) {
	char* temp = const_cast<char*>(ls2);
	
	do{
		*ls1 = *temp;
		ls1++; temp++;
	} while (*temp);

	*ls1 = '\0';
}



// base reference-Counting
class RCObject{             // base class , 用于 reference-counted objects.
public:
    void addReference();
    void removeReference();
    void markUnshareable();
    bool isShareable()const ;
    bool isShared() const ;

protected:
    RCObject();
    RCObject(const RCObject& rhs);
    RCObject& operator=(const RCObject& rhs);
    virtual ~RCObject() = 0;
    
private:
    int  refCount;
    bool shareable;
};

RCObject::RCObject()
:refCount(0), shareable(true)
{}

RCObject::RCObject(const RCObject& rhs)
:refCount(0), shareable(true)
{}

RCObject& RCObject::operator=(const RCObject& rhs){
    return *this;
}

RCObject::~RCObject(){}   // 纯虚成员函数 析构

void RCObject::addReference(){
    ++refCount;
}

void RCObject::removeReference(){
    if(--refCount == 0)
        delete this;
}

void RCObject::markUnshareable(){
    shareable = false;
}

bool RCObject::isShareable() const {
    return shareable;
}

bool RCObject::isShared() const {
    return refCount > 1;
}








// smart pointers base
template<class T>       // template class , 用来产生 smartpointers-to-T objects;
class RCPtr{            // T 必须继承自 RCObject.
public:
    RCPtr(T* realPtr = 0);
    RCPtr(const RCPtr& rhs);
    ~RCPtr();
    
    RCPtr& operator=(const RCPtr& rhs);
    
    T* operator->() const ;
    T& operator* () const;
    
private:
    T* pointee;    // dumb ptr
    void init();   // 共同的初始化动作
};


template<class T>
RCPtr<T>::RCPtr(T* realPtr)
: pointee(realPtr)
{
    init();
}

template<class T>
RCPtr<T>::RCPtr(const RCPtr& rhs)
: pointee(rhs.pointee)
{
    init();
}

template <class T>
void RCPtr<T>::init(){
    if(pointee == 0){       // 如果 dumb pointer 是null
        return ;            // 那么 smart pointer 也是
    }
    if(pointee->isShareable() == false){    // 如果其值不可共享.
        pointee = new T(*pointee);          // 就复制一份
    }
    pointee->addReference();        // 注意 现在有了一个针对实值的新接口
}

template<class T>
RCPtr<T>& RCPtr<T>::operator=(const RCPtr& rhs){
    if(pointee != rhs.pointee){
        if(pointee){
            pointee->removeReference();
        }
        pointee = rhs.pointee;
        init();
    }
    return *this;
}

template<class T>
RCPtr<T>::~RCPtr(){
    if(pointee)
        pointee->removeReference();
}

template<class T>
T* RCPtr<T>::operator->() const {
    return pointee;
}

template<class T>
T& RCPtr<T>::operator*() const {
    return *pointee;
}






class String {          // 应用性 class, 这是应用程序开发人员接触的层面
public:
    String(const char* initValue = "");

    const char& operator[](int index) const;
    char& operator[](int index);

private:
    
    struct StringValue:public RCObject {
        char* data;
        
        StringValue(const char* initValue);
        StringValue(const StringValue& rhs);
        void init(const char* initValue);
        ~StringValue();
    };
    
    RCPtr<StringValue> value;
};



void String::StringValue::init(const char* initValue){
    data = new char[strlen(initValue) +1];
    strcpys(data, initValue);
}

String::StringValue::StringValue(const StringValue& rhs){
    init(rhs.data);
}

String::StringValue::StringValue(const char* initValue){
    init(initValue);
}

String::StringValue::~StringValue() {
    delete[] data;
}



String::String(const char* initValue)
:value(new StringValue(initValue))
{}

const char& String::operator[](int index) const {
    return value->data[index];
}

char& String::operator[](int index) {
    if(value->isShared()){
        value = new StringValue(value->data);
    }
    value->markUnshareable();
    return value->data[index];
}





int main(void) {


	return 0;
}
