/*
 合成复用原则 :继承和组合,有限选用组合
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//抽象类 车
class AbstractCar {
public:
    virtual void run() = 0;
};

//大众车
class Dazhong : public AbstractCar {
public:
    virtual void run() {
        cout << "大众车 启动..." << endl;
    }
};

// 拖拉机
class Tuolaji :public AbstractCar {
public:
    virtual void run() {
        cout << "拖拉机 启动..." << endl;
    }
};
#if 0   //不应该使用继承
class Person :public Tuolaji {
public:
    void Doufeng() {
        run();
    }
};
#endif

// 可以使用组合
class Person {
public:
    void setCar(AbstractCar* car) {
        this->car = car;
    }
    void Doufeng() {
        this->car->run();
        if (this->car != NULL) {
            delete[] car;
            this->car = NULL;
        }
    }
    ~Person(){
        if (this->car != NULL) {
            delete[] car;
            car = NULL;
        }
    }
public:
    AbstractCar* car;
};

void test02(){
    Person* p = new Person;
    p->setCar(new Dazhong);
    p->Doufeng();
    
    p->setCar(new Tuolaji);
    p->Doufeng();
    
    delete p;
}

// 继承和组合, 优先选用组合
int main(void) {
    test02();
    
    
    system("pause");
    return 0;
}
