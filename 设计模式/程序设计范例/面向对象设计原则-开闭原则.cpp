/* 
开闭原则:对外扩展开放, 对修改关闭, 增加功能是通过增加代码而实现的,而不是去修改源代码. 
*/

#include <iostream>
using namespace std;
// 写一个抽象类   ,抽象计算器类
class AbstractCaculat {
public:
    virtual int getResult() = 0;
    virtual void setOperatorNumber(int a, int b) = 0;
};

//加法计算器
class PlusCaculator :public AbstractCaculat {
public:
    virtual void setOperatorNumber(int a, int b) {
        this->mA = a;
        this->mB = b;
    }

    virtual int getResult() {
        return this->mA + this->mB;
    }
public:
    int mA;
    int mB;
};

//减法计算器
class MinuteCaculator :public AbstractCaculat {
public:
    virtual void setOperatorNumber(int a, int b) {
        this->mA = a;
        this->mB = b;
    }

    virtual int getResult() {
        return this->mA - this->mB;
    }
public:
    int mA;
    int mB;
};

//乘法计算器
class MultiplyCaculator :public AbstractCaculat {
public:
    virtual void setOperatorNumber(int a, int b) {
        this->mA = a;
        this->mB = b;
    }

    virtual int getResult() {
        return this->mA * this->mB;
    }
public:
    int mA;
    int mB;
};

// 取模计算器   通过增加代码来添加新功能
class ModuloCaculator :public AbstractCaculat {
public:
    virtual void setOperatorNumber(int a, int b) {
        this->mA = a;
        this->mB = b;
    }

    virtual int getResult() {
        return this->mA % this->mB;
    }
public:
    int mA;
    int mB;
};

void test01() {
    AbstractCaculat* caculator = new PlusCaculator;
    caculator->setOperatorNumber(10, 20);
    cout << "ret = " << caculator->getResult() << endl;

    delete[] caculator;

    caculator = new MinuteCaculator; 
    caculator->setOperatorNumber(10, 20);
    cout << "ret = " << caculator->getResult() << endl;

    delete[] caculator;
    caculator = NULL;
}

int main(void) {
    test01();

    system("pause");
    return 0;
}