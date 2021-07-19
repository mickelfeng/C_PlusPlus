/*
代理模式: 提供一种代理来控制对其他对象的访问
*/

#include <iostream>
#include <cstdlib>
using namespace std;


class AbstractCommoinInterface {
public:
    virtual void run() = 0;

};


// 我已经写好的系统
class MySystem :public AbstractCommoinInterface{
public:
    virtual void run() {
        cout << "系统启动..." << endl;
    }
};

// 必须要有权限验证,不是所有人都能来启动我的启动,提供用户名和密码.

class MySystemProxy :public AbstractCommoinInterface{
public:
    MySystemProxy(string username, string password) {
        this->mUsername = username;
        this->mPassword = password;
        pSystem = new MySystem;
    }

    bool checkUsernameAndPassoword() {
        if (mUsername == "admin" && mPassword == "admin") {
            return true;
        }
        return false;
    }

    virtual void run() {
        if (checkUsernameAndPassoword()) {
            cout << "用户名和密码验证通过" << endl;
            this->pSystem->run();
        }
        else {
            cout << "用户名或者密码错误,权限不足" << endl;
        }
    }

    ~MySystemProxy() {
        if (pSystem != NULL) {
            delete pSystem;
            pSystem = NULL;
        }
    }

public:
    MySystem* pSystem;
    string mUsername;
    string mPassword;

};

void test01() {
    MySystemProxy* proxy = new MySystemProxy("admin", "admin");
    proxy->run();


}


int main(void) {

    test01();

    system("pause");
    return 0;
}
