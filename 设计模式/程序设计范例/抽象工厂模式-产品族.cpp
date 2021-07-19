/*
 抽象工厂模式:针对产品族, 而不是产品等级.
 */

#include <iostream>
#include <string>
using namespace std;

// 抽象苹果类
class AbstracApple{
public:
    virtual void ShowName() = 0;
};

// 中国苹果
class ChinaApple:public AbstracApple{
public:
    virtual void ShowName(){
        cout << "中国苹果" << endl;
    }
};

//美国苹果
class USAApple:public AbstracApple{
public:
    virtual void ShowName(){
        cout << "美国苹果" << endl;
    }
};

//日本苹果
class JapanApple:public AbstracApple{
public:
    virtual void ShowName(){
        cout << "日本苹果" << endl;
    }
};

// 抽象香蕉类
class AbstracBanana{
public:
    virtual void ShowName() = 0;
};

// 中国的香蕉
class ChinaBanana:public AbstracBanana{
public:
    virtual void ShowName(){
        cout << "中国的香蕉" << endl;
    }
};

// 美国的香蕉
class USABanana:public AbstracBanana{
public:
    virtual void ShowName(){
        cout << "美国的香蕉" << endl;
    }
};

// 日本的香蕉
class JapanBanana:public AbstracBanana{
public:
    virtual void ShowName(){
        cout << "日本的香蕉" << endl;
    }
};

// 抽象鸭梨类
class AbstractPear{
public:
    virtual void ShowName() = 0;
};

class ChinaPear:public AbstractPear{
public:
    virtual void ShowName(){
        cout << "中国的鸭梨" << endl;
    }
};

class USAPear:public AbstractPear{
public:
    virtual void ShowName(){
        cout << "美国的鸭梨" << endl;
    }
};

class JapanPear:public AbstractPear{
public:
    virtual void ShowName(){
        cout << "日本的鸭梨" << endl;
    }
};


// 抽象工厂   针对产品族
class AbstracFactory{
public:
    virtual AbstracApple* CreateApple() = 0;
    virtual AbstracBanana* CreateBanana() = 0;
    virtual AbstractPear* CreatePear() = 0;
};

// 中国工厂
class ChinaFactory: public AbstracFactory{
public:
    virtual AbstracApple* CreateApple(){
        return new ChinaApple;
    }
    virtual AbstracBanana* CreateBanana(){
        return new ChinaBanana;
    }
    virtual AbstractPear* CreatePear(){
        return new ChinaPear;
    }
};

// 美国工厂
class USAFactory: public AbstracFactory{
public:
    virtual AbstracApple* CreateApple(){
        return new USAApple;
    }
    virtual AbstracBanana* CreateBanana(){
        return new USABanana;
    }
    virtual AbstractPear* CreatePear(){
        return new USAPear;
    }
};

// 日本工厂
class JapanFactory: public AbstracFactory{
public:
    virtual AbstracApple* CreateApple(){
        return new JapanApple;
    }
    virtual AbstracBanana* CreateBanana(){
        return new JapanBanana;
    }
    virtual AbstractPear* CreatePear(){
        return new JapanPear;
    }
};

void test01(){
    
    AbstracFactory* factory = NULL;  // 工厂的抽象类
    AbstracApple* apple = NULL;
    AbstracBanana* banana = NULL;
    AbstractPear* pear = NULL;
    
    // 中国工厂
    factory = new ChinaFactory;
    apple = factory->CreateApple();
    banana = factory->CreateBanana();
    pear = factory->CreatePear();
    
    apple->ShowName();
    banana->ShowName();
    pear->ShowName();
    delete pear;
    delete banana;
    delete apple;
    delete factory;
}


int main(void){
    
    
    test01();
    return 0;
}
