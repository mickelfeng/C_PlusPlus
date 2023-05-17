#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;
#define SALE_DEPATMENT 1  //销售部门
#define DEVELOP_DEPATMENT 2 //研发部门
#define FINACIAL_DEPATMENT  3  //财务部门

/*
    5个员工分配进入3个部门工作.
    人员信息有: 姓名, 年龄, 电话, 工资 ,组成.
    通过 multimap 进行信息的插入 保存 显示
    分部门显示员工信息.
*/

class Worker{  //员工
public:
    string mName;
    string mTele;
    int mAge;
    int mSalary;
};

void  Create_Worker(vector<Worker>& vWorker){
    string seedName = "ABCDE";
    for(int i = 0 ; i< 5 ; i++){
        Worker worker;
        worker.mName = "员工" ;
        worker.mName += seedName[i];
        
        worker.mAge = rand() % 10 +20;
        worker.mTele = "010-888888";
        worker.mSalary = rand()% 10000+10000;
        
        // 保存员工信息.
        vWorker.push_back(worker);
    }
}

void WorkerByGroup(vector<Worker>& vWorker, multimap<int, Worker>& workerGroup){
    // 把员工随机分配到不同部门
    srand((unsigned)time(NULL));   //加一个随机种子,要不然一直都是一个数值
    for(vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++){
        int departID = rand() % 3 + 1;
        
        switch(departID){
            case SALE_DEPATMENT:
                workerGroup.insert(make_pair(SALE_DEPATMENT, *it));  //*it 表示类对象
                break;
            case DEVELOP_DEPATMENT:
                workerGroup.insert(make_pair(DEVELOP_DEPATMENT, *it));  //*it 表示类对象
                break;
            case FINACIAL_DEPATMENT:
                workerGroup.insert(make_pair(FINACIAL_DEPATMENT, *it));  //*it 表示类对象
                break;
            default:
                break;
        }
        
    }
    
}

void ShowGroupWorkers(multimap<int, Worker>& workerGroup,int departID ){
     //找当前部门总人数
    multimap<int, Worker>::iterator it = workerGroup.find(departID);
    //返回第一次部门出现的位置  迭代器
    
    unsigned long DepartCount = workerGroup.count(departID);  //找到这个部门的总人数
    unsigned long num = 0;
    for(multimap<int, Worker>::iterator pos = it; it != workerGroup.end() && num < DepartCount; pos++,num++){
        cout << "姓名 " << pos->second.mName << ",年龄 " <<pos->second.mAge << ",电话 "
        << pos->second.mTele << ",工资 " << pos->second.mSalary  << endl;
    }
}

void  PrintWorkerByGroup(multimap<int, Worker>& workerGroup){
    // 打印销售部员工的信息
    cout << " 显示销售部门" <<endl;
    ShowGroupWorkers(workerGroup,SALE_DEPATMENT);
    cout << endl;
    
    cout << " 显示开发部门" <<endl;
    ShowGroupWorkers(workerGroup,DEVELOP_DEPATMENT);
    cout << endl;
    
    cout << " 显示财务部门" <<endl;
    ShowGroupWorkers(workerGroup,FINACIAL_DEPATMENT);
    cout << endl;
}


//----------------------------------------------------------------------------------
int main(void){
    vector<Worker>vWorker;  // 存放新员工信息
//multimap 保存分组信息
    multimap<int, Worker> workerGroup;  //因为5个人其中有两个会分到一个部门,那么就需要键值相同,要用multimap
                                      // 第一个参数int 表示部门编号,第二个是员工
//创建员工
    Create_Worker(vWorker);
//员工分组
    WorkerByGroup(vWorker,workerGroup);
//打印每一部门的员工信息
    PrintWorkerByGroup(workerGroup);
    
    return 0;
}
