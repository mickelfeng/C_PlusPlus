/*
 依赖倒转原则: 依赖抽象类,依赖多态,底层实现和抽象类挂钩,业务和抽象类挂钩,但是业务和底层之间没有太大的代码关联.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#if 0
// 银行工作人员
class BankWorker{
public:
    void saveService(){
        cout << "办理存款业务..." << endl;
    }
    void payService(){
        cout << "办理支付业务..."  << endl;
    }
    void tranferService(){
        cout << "办理转账业务..."  << endl;
    }
};

// 中层模块
void doSaveBussiness(BankWorker* worker){
    worker->saveService();
}
void doPayBussiness(BankWorker* worker){
    worker->payService();
}
void doTranferBussiness(BankWorker* worker){
    worker->tranferService();
}

//业务模块
void test01(){    // 这种设计不好
    BankWorker* worker = new BankWorker;
    doSaveBussiness(worker);   // 办理存款业务
    doPayBussiness(worker);   // 办理支付业务
    doTranferBussiness(worker);   // 办理转账业务
}
#endif

// 银行工作人员 抽象类
class AbstractWorker{
public:
    virtual void doBussiness() = 0;
};

// 专门负责办理 存款业务的工作人员
class SaveBankWorker : public AbstractWorker{
    virtual void doBussiness(){
        cout << "办理存款业务..." << endl;
    }
};

// 专门负责办理 支付业务的工作人员
class PayBankWorker: public AbstractWorker{
    virtual void doBussiness(){
        cout << "办理支付业务..." << endl;
    }
};

// 专门负责办理 转账业务的工作人员
class TransferBankWorker: public AbstractWorker{
    virtual void doBussiness(){
        cout << "办理转账业务..." << endl;
    }
};

// 中层业务
void doNewBusiness(AbstractWorker* worker){
    worker->doBussiness();
    delete[] worker;
}


void test02(){
    doNewBusiness(new TransferBankWorker);
    doNewBusiness(new PayBankWorker);
    doNewBusiness(new SaveBankWorker);
    
}

int main(void) {
    
    test02();
    
   
    return 0;
}
