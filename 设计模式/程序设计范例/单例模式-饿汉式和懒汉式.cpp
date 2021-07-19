/*
 单例模式:控制某个类型的对象个数,单例模式中,系统只有一个对象.
    单例模式分为 懒汉式 和 饿汉式
 因为单例模式在程序中只存在一个对象,所以不需要考虑内存泄露问题,而且不需要提供析构函数.

 
 实现单例步骤:
  1.构造函数私有化.
  2.增加静态私有的当前类的指针变量.
  3.提供一个静态对外接口,可以让用户获得单例对象.
*/

#include <iostream>
#include <string>
using namespace std;

class A{   // 经典范例
private:
    A(){
        a = new A;   // 必须在这里 new 一个内存
    }
public:
    static A* getInstace(){  // 对外接口,可以让用户访问到对象指针
        return a;
    }
    
private:
    static A* a;   // 私有的静态指针, 静态成员的属性是 所有这个类的对象都共享同一个数值,一个变化,全部变化.
};
A* A::a = NULL;     // 类外初始化是必须的
//  使用 A::getInstace();   来获得指针,但是却无法实例化的拿到.


// 单例模式  懒汉式
class Singleton_lazy{
private:
    Singleton_lazy(){cout << "懒汉式构造"<< endl;}
public:
    static Singleton_lazy* getInsetance(){      //这里多个一步判断
        if(pSingleton == NULL){
            pSingleton = new Singleton_lazy;
        }
        return pSingleton;
    }
private:
    static Singleton_lazy* pSingleton;
};
Singleton_lazy* Singleton_lazy::pSingleton = NULL;   // 类外初始化成了 null
// 这个类会在需要的时候创建


// 单例模式 饿汉式
class Singleton_hungry{
private:
    Singleton_hungry(){cout << "饿汉式构造"<< endl;}
public:
    static Singleton_hungry* getInsetance(){        // 这里直接返回了 ,没有进行判断
        return pSingleton;
    }
    
private:
    static Singleton_hungry* pSingleton;
};
Singleton_hungry* Singleton_hungry::pSingleton = new Singleton_hungry; //饿汉式在这里new初始化
// 这个类会在 main() 函数 开始之前就构造了


void test01(){
    
   Singleton_lazy* p1 =  Singleton_lazy::getInsetance();
   Singleton_lazy* p2 =  Singleton_lazy::getInsetance();
    if(p1 == p2){
        cout <<"指向同一块内存空间, 是单例" << endl;
    }else{
        cout << "不是单例" << endl;
    }
    
    Singleton_hungry* p3 = Singleton_hungry::getInsetance();
    Singleton_hungry* p4 = Singleton_hungry::getInsetance();
    
    if(p3 == p4){
        cout <<"指向同一块内存空间, 是单例" << endl;
    }else{
        cout << "不是单例" << endl;
    }
}


int main(void){
    cout << "main 函数开始" << endl;
     // 运行的时候 饿汉式会比 main 先创建类对象
    
    test01();
    
    return 0;
}
