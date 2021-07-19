
/*
 工厂方法模式: 这里的工厂符合开闭原则,但是代码会非常多
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//抽象的水果
class AbstractFruit {
public:
    virtual void ShowName() = 0;
};

// 苹果
class Apple :public AbstractFruit {
public:
    virtual void ShowName() {
        cout << "我是苹果!" << endl;
    }
};

// 香蕉
class Banana :public AbstractFruit {
public:
    virtual void ShowName() {
        cout << "我是香蕉!" << endl;
    }
};

// 鸭梨
class Pear :public AbstractFruit {
public:
    virtual void ShowName() {
        cout << "我是鸭梨!" << endl;
    }
};


// 抽象类 水果工厂 合开闭原则
class AbstractFruitFactory {
public:
    virtual AbstractFruit* CreateFruit() = 0;   // 返回一个抽象的水果
};

// 苹果工厂
class  AppleFactory : public AbstractFruitFactory {
public:
    virtual AbstractFruit* CreateFruit() {
        return new Apple;
    }
};

// 香蕉工厂
class  BananaFactory : public AbstractFruitFactory {
public:
    virtual AbstractFruit* CreateFruit() {
        return new Banana;
    }
};

// 鸭梨工厂
class  PearFactory : public AbstractFruitFactory {
public:
    virtual AbstractFruit* CreateFruit() {
        return new Pear;
    }
};

void test01() {

    AbstractFruitFactory* factory = NULL;
    AbstractFruit* fruit = NULL;

    // 创建一个苹果工厂
    factory = new AppleFactory;
    fruit = factory->CreateFruit();  //然后创建了一个苹果
    fruit->ShowName();

    delete[] fruit;
    delete[] factory;


    // 创建一个香蕉工厂
    factory = new BananaFactory;
    fruit = factory->CreateFruit();
    fruit->ShowName();

    delete[] fruit;
    delete[] factory;


    // 创建一个香蕉工厂
    factory = new PearFactory;
    fruit = factory->CreateFruit();
    fruit->ShowName();

    delete[] fruit;
    delete[] factory;


}


int main(void) {

    test01();

    system("pause");
    return 0;
}
