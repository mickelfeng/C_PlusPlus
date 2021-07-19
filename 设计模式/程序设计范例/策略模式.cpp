/*
 策略模式: 定义了一系列的算法,并将每个算法封装起来, 而且使他们还可以相互替换
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 抽象武器  武器策略
class WeaponStrate{
public:
    virtual void UseWeapon() = 0;
};

// 匕首
class Knife:public WeaponStrate{
public:
    virtual void UseWeapon(){
        cout << "使用匕首" << endl;
    }
};

// AK47
class AK47:public WeaponStrate{
public:
    virtual void UseWeapon(){
        cout << "使用AK47" << endl;
    }
};


//角色
class Character{
public:
    void setWeapon(WeaponStrate* weapon){
        this->pWeapon = weapon;
    }
   void ThrowWeapon(){
       this->pWeapon->UseWeapon();
    }
public:
    WeaponStrate* pWeapon;
};


void test01(){
    //创建角色
    Character* charachter = new Character;
    
    //武器策略
    WeaponStrate* knife = new Knife;
    WeaponStrate* ak47 = new AK47;
    
    charachter->setWeapon(knife);
    charachter->ThrowWeapon();
    
    charachter->setWeapon(ak47);
    charachter->ThrowWeapon();
    
    delete[] ak47;
    delete[] knife;
    delete[] charachter;
}

int main(void){
    test01();
    return 0;
}
