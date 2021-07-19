
/*
 简单工厂模式: 这里的工厂并不符合开闭原则,只是一个对象生成器
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


// 水果 工厂  不符合开闭原则

class FruitFactory {
public:
    static AbstractFruit* CreateFruit(string flag) {
        if (flag == "Apple") {
            return new Apple;
        }
        else if (flag == "Banana") {
            return new Banana;
        }
        else if (flag == "Pear") {
            return new Pear;
        }
        else {
            return NULL;
        }
    }
};

void test01() {

    //创建过程不需要关系, 直接拿来用就好了
    FruitFactory* factory = new FruitFactory;
    AbstractFruit* fruit = factory->CreateFruit("Apple");
    fruit->ShowName();
    delete[] fruit;

    fruit = factory->CreateFruit("Pear");
    fruit->ShowName();
    delete[] fruit;

    fruit = factory->CreateFruit("Banana");
    fruit->ShowName();
    delete[] fruit;

    delete[] factory;
}

int main(void) {
 
    test01();

    system("pause");
    return 0;
}
