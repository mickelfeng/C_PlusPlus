## 目录

- [创建计时器](#创建计时器)
- [使用计时器](#使用计时器)
- [服务器范例](#服务器范例)
- [客户端范例](#客户端范例)
- [休眠函数](#休眠函数)



## 创建计时器

> #include `<chrono>` 

- **这个计时能力是C++11标准库提供的, 可以跨平台**

- **达到微秒级计时能力**

```c++
#include <chrono>
#include <iostream>

using namespace std::chrono;      //添加命名空间, 或不添加


class CELLTime {
public:
    //得到当前的时间,  毫秒
    static time_t   getNewTimeInMilliSec(void) {
        return   duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch()).count();
    }
};



class  CELLTimestamp{
public:
    CELLTimestamp(){
        update();
    }
    ~CELLTimestamp(){}
    
    
    // 初始化时间点.
    void update(void){
        _begin = high_resolution_clock::now(); // 得到当前时间,相当于初始化
      
      /* _begin = std::chrono::high_resolution_clock::now(); 没有添加命名空间的的写法*/
    }
    
    //获得当前时间差的 秒
    double getElapsedSecond(void){
        // 将返回的微秒  扩展到 秒
        return  getElapsedTimeInMicroSec() * 0.000001;
    }
    
    //获得当前时间差的 毫秒
    double getElapsedTimeInMilliSec(void){
        // 将返回的微秒  扩展到 毫秒
        return this->getElapsedTimeInMicroSec() * 0.001;
    }
    
    //得到微秒级别的 当前时间差, 微秒
    long long  getElapsedTimeInMicroSec(){
        // 当前时间 减去曾经的一个时间点. 得到经过的时间,  单位是微秒
        return  duration_cast<microseconds>(high_resolution_clock::now() - _begin).count();

      /* retrun std::chrono::duration_cast<std::chrono::microseconds> 
             (std::chrono::high_resolution_clock::now() - _begin).count();
         没有添加命名空间的的写法
      */
    }
    
protected:
    
    // 一个时间点 <高分辨率时钟>, 分辨到微秒或纳秒级别
std::chrono::time_point<std::chrono::high_resolution_clock> _begin;  //时间点<高分辨率时钟>
  
/*  std::chrono::time_point<std::chrono::high_resolution_clock>  _begin; 
	没有添加命名空间的的写法
*/
};




int main(void)
{
    std::cout << "OK" << std::endl;
    std::chrono::milliseconds t(3000);
    std::this_thread::yield();
    std::this_thread::sleep_for(t);
//    std::this_thread::yield();
    std::cout << "OK" << std::endl;
}

```



```c++
关于c++中chrono函数的使用

　　这个库是c++11定义出来的关于处理时间的库，有了它处理时间问题就会非常方便了。我们在这里简单介绍一下这个库的一些常用方法。

　　1、duration_cast（这个主要实现的功能就是可以将单位进行转换，比如说我们获取到的系统时间可能是毫秒，但是我们要把他换算成秒怎么办，就用这个）。

　　2、system_clock::now（这个函数的主要目的就是获取到当前系统时间，注意这个时间是当前时间与1970年1月1之间的差值，单位是time_point）

　　3、time_since_porch (这个函数也是当前时间与1970年1月1日之间的差值，单位是duration)

　　4、localtime（间隔）（这个函数可以将当前时间与1970年的差值，转换成包含今天年月日的结构体，不过注意，传进去的一定是秒）

       5、strftime函数（这个函数可以将结构体指针转换成包含时间格式的字符串数组）

　　6、to_time_t（将timepoint时间转换成time_t）
```

```c++
时间函数

　　首先我们说一下，时间到底有啥用，其实我想了想，其用途无非就是两点，第一获取到当前的年月日时分秒，第二就是计算两段代码相隔的时间。所以我就着重说这两部分。

　　1、获取到当前时间的年月日

　　　　无论是什么函数，他的流程一定是这样的。获取到time_point值，然后获取到tm的值，最后获取到年月日时分秒。

　　　　1、先说第一种方法　　　

         auto now = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();  //获取到time_point的值并将其转换成秒
　　　　　 ts = localtime(&now)   //获取到当前的tm值
　　　　
         int year = ts.tm_year + 1900;
         int month = ts.tm_mon + 1;
         int day = ts.tm_mday;
          int hour = ts.tm_hour;
         int minute = ts.tm_min;
         int second = ts.tm_sec;
　　　　　获取到当前年月日时分秒的值

　　　　2、再说第二种方法
       //std::chrono::system_clock::time_point tn = std::chrono::system_clock::now();   // 获取到time_point
         auto tn = std::chrono::system_clock::now();   // 获取到time_point
         time_t now1 = std::chrono::system_clock::to_time_t(tn);  // 获取time_t的值
         ts = localtime(&now);   // 获取tm的值
         const char *fmt = "%Y-%m-%d %H:%M:%S";
         strftime(buf, sizeof(buf), fmt, ts);   // 将其转换成字符串的形式


　　　3、获取到当前程序运行的时间
　　　　
　　　　　　
auto t0 = std::chrono::system_clock::now();
    j++;
    auto time2 = std::chrono::system_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>
                   (std::chrono::system_clock::now() - t0).count()<<std::endl;

　　通过得到时间戳相减得到最终的值，另外我测的话一行代码时间58ns，所以只好设置na秒级别了。
```





# 使用计时器



```c++
#include "temp.hpp"
int main(void){
    CELLTimestamp  _tTime;     // 计时
    _tTime.update(); // 更新当前时间点.
    while(1){
        
        if (_tTime.getElapsedSecond() >= 1.0){   //大于等于1秒的时候触发
            auto t1 = _tTime.getElapsedSecond();   // 获得时间差, 秒级
            std::cout  << "time<" << t1  << std::endl;  // 输出的是秒级
            _tTime.update(); // 更新当前时间点.
        }
    }
}
```





# 服务器范例

- **`EasyTcpServer.hpp`**

  - ```c++
    #ifndef   __EASYTCPSERVER_HPP__
    #define   __EASYTCPSERVER_HPP__
    
    
    #ifdef _WIN32  //只有在Windows 下,才会定义这个宏. 出于移植考虑, 应该使用这种判别式, 以使用头文件和宏
    #define  WIN32_LEAN_AND_MEAN   //  这个宏的作用是： 会尽量避免引用早期会引起冲突的库
    #define  _WINSOCK_DEPRECATED_NO_WARNINGS
    #pragma  comment( lib, "ws2_32.lib")  //明确的指出需要一个动态链接库， 或者在项目属性页->连接器->输入->添加依赖项,将 ws2_32.lib加入进去
    
    
    #define   FD_SETSIZE  1024
    #include <WinSock2.h>
    #include <Windows.h>     // 这两个头文件的文位置不同，会造成编译失败
    
    #else    // 这个是 Unix和Linux 下才有的头文件, 也有用于方便移植的宏
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <netdb.h>
    #define  SOCKET  int       //兼容 windows ,将 socket套接字的int,变更为 SOCKET来表示,     两个平台的内容相同
    #define  INVALID_SOCKET  (SOCKET)(~0)     //取反的0, 也就是-1, 用于判别 socket套接字的创建错误
    #define  SOCKET_ERROR            (-1)     // -1, 用于判别 connect 的连接错误
    #endif
    
    #include <iostream>
    #include <string>
    #include <thread>
    #include <cstring>
    #include <vector>
    #include <algorithm>
    #include "MessageHeader.hpp"
    #include "CELLTimestamp.hpp"
    
    #define MAC_IP    "10.0.0.94"
    #define WIN_IP    "10.0.0.95"
    #define LIN_IP    "10.0.0.1"
    #define LOCAL_IP  "127.0.0.1"
    #define ALY_IP    "47.240.114.70"
    #define CONNECT_IP  LOCAL_IP      //服务器的IP
    #define  SERVER_PORT  4567
    
    
    #ifndef RECV_BUFF_SIZE
    #define RECV_BUFF_SIZE  10240   // 消息缓冲区长度
    #endif
    
    class ClientSocket {
    public:
        ClientSocket(const SOCKET _sockfd = INVALID_SOCKET) :_sockfd(_sockfd), _szMsgBuf(""), _lastPos(0) {}
    
        ~ClientSocket() {}
    
    
        SOCKET& sockfd(void) {
            return _sockfd;
        }
    
    
        char* msgBuf(void) {
            return _szMsgBuf;
        }
    
    
        int& getLastPos(void) {
            return _lastPos;
        }
    
    
        void setLastPos(const int& pos) {
            _lastPos = pos;
        }
    
    private:
        SOCKET _sockfd; // 套接字
    
         // 使用缓冲区接收数据, 接收缓冲区
     //   char  _szRecv[RECV_BUFF_SIZE];
    
        //第二缓冲区, 消息缓冲区
        char  _szMsgBuf[RECV_BUFF_SIZE * 2];
        int    _lastPos;    // 第二缓冲区 目前存在的数据长度
    
    };
    
    
    int NewScok = 0;
    
    
    class EasyTcpServer
    {
    private:
        SOCKET _sock; // 监听套接字
        std::vector<ClientSocket*> _clients; // 存储已连接的客户端 SOCK 套接字
        char  _szRecv[RECV_BUFF_SIZE];       // 消息缓冲区
        CELLTimestamp _tTime;     // 计时
        int    _recvCount;             // 计数
        
    public:
        EasyTcpServer() :_sock(INVALID_SOCKET),_tTime(),_recvCount(0) {
            _clients.clear();
        }
    
        ~EasyTcpServer() {
            Close();
        }
    
        // 初始化 Socket
        SOCKET InitSocket(void) {
    
            // 判断一下, 是否已经建立了一个套接字, 如果建立了,应该关闭它,并断开连接.
            if (_sock != INVALID_SOCKET) {
                std::cout << "< socket = " << _sock << " >"
                    << "关闭之前的套接字(或已连接的套接字),并重新建立一个新的套接字" << std::endl;
                Close();
                return this->_sock;
            }
    
    #ifdef _WIN32
            /* 建立和启动 Windows socket2.x 环境 */
            WORD ver = MAKEWORD(2, 2);   //创建版本号  2.x的版本， 2是大版本 x是小版本
            WSADATA dat;                 //数据指针
            (void)WSAStartup(ver, &dat);  // winsocket的启动函数 (版本号,  ）;  调用的是动态库，应该加入动态链接库
            // LP开头的类型，只要把LP去掉就会得到真正的类型，并传入指针即可。
    #endif
            _sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  // 需求一个 TCP的流式套接字
            if (INVALID_SOCKET == _sock) {
                std::cerr << "创建套接字错误" << std::endl;
            }
    #if 0
            else
                std::cout << "创建套接字 < " << _sock << " > 成功" << std::endl;
    #endif // #if 0
            return _sock;
        }
    
        //绑定IP和端口号
        int Bind(const char* ip, const uint16_t port) {
            if (_sock == INVALID_SOCKET) {
                InitSocket();
            }
            //  2. bind 绑定用于接收客户端连接的网络端口
            sockaddr_in  _sin = {};
            _sin.sin_family = AF_INET;
            _sin.sin_port = htons(port);
    
            // 判断IP是否传入的是空值.
            if (ip == nullptr) {
    #ifdef _WIN32
                _sin.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    #else
                _sin.sin_addr.s_addr = htonl(INADDR_ANY);
    #endif
            }
            else {
    #ifdef _WIN32
                _sin.sin_addr.S_un.S_addr = inet_addr(ip);
    #else
                inet_pton(AF_INET, ip, &_sin.sin_addr);  // INADDR_ANY
    #endif
            }
            int ret = bind(_sock, (sockaddr*)&_sin, sizeof(_sin));
            if (-1 == ret) {      // Win下特有的错误对比
                std::cout << "端口号 " << ntohs(port) << " 绑定错误" << std::endl;
                Close();
                return -1;
            }
            else
                std::cout << "端口绑定成功" << std::endl;
            return ret;
        }
    
        //监听端口号
        int Listen(const int number) {
            //  *3. listen  监听网络端口
            int ret = listen(_sock, number);
            if (SOCKET_ERROR == ret)
                std::cout << "listen Not failure" << std::endl;
            else
                std::cout << "listen success" << std::endl;
    
            return ret;
        }
    
        //接收客户端连接
        SOCKET Accept(void) {
            // *4. accept  等待接收客户端链接
            SOCKET cSock = INVALID_SOCKET;           // 该宏可以用来初始化和表示  无效的 SOCK套接字
            sockaddr_in clientAddr = {};    //接收客户端信息的结构体, 下面是长度信息.
    #ifdef _WIN32
            int clientAddrLen = sizeof(clientAddr);         //win 下是 int
    #else
            socklen_t clientAddrLen = sizeof(clientAddr);  // macos和linux是 unsigned int
    #endif
            cSock = accept(_sock, (struct sockaddr*) & clientAddr, &clientAddrLen);
            if (cSock == INVALID_SOCKET) {
                std::cout << "<socket=" << _sock << ">接收得到无效的客户端" << std::endl;
            }
    
    
            else {
                //            NewUserJoin userjoin;
                //            SendDataToALL(&userjoin);
                _clients.push_back(new ClientSocket(cSock));
    #if 0
                std::cout << "新客户端 " <<  ++NewScok <<  " 加入  < " << cSock << " >\t ";
    /*========================================================================================*/
    #ifdef _WIN32
                std::cout << "客户端的IP地址为: " << inet_ntoa(clientAddr.sin_addr); //将sin_addr
    #else
                char client_addr_arr[INET6_ADDRSTRLEN] = {};
                inet_ntop(AF_INET, &clientAddr.sin_addr, client_addr_arr, INET6_ADDRSTRLEN);
                std::cout << "客户端的IP地址为: " << client_addr_arr;
                //将sin_addr结构体转换成字符串。
    #endif
                std::cout << std::endl << "客户端的端口为: " << ntohs(clientAddr.sin_port) << std::endl;
    #endif // #if 0
            }
    
            return cSock;
        }
    
        //关闭 Socket
        void Close(void) {
            if (INVALID_SOCKET != _sock) {
                std::cout << "清理sock< " << _sock << ">  环境和结束通讯,客户端已结束" << std::endl;
                for (int n = static_cast<int>(_clients.size()) - 1; n >= 0; n--) {
    #ifdef _WIN32
                    closesocket(_clients.at(n)->sockfd());
    #else
                    shutdown(_clients.at(n)->sockfd(), SHUT_WR);
    #endif
                    delete _clients.at(n);
                }
    
    #ifdef _WIN32
                closesocket(_sock);
                /*  清除 Windows socket 环境  */
                WSACleanup(); //与WSAStartup() 相匹配， 一个是开，一个是关
    #else
                shutdown(_sock, SHUT_WR);
    #endif
                _clients.clear();
                std::cout << "结束通讯,关闭所有套接字" << std::endl;
                _sock = INVALID_SOCKET;
            }
            else
                std::cout << "Close(sock) 已经清理过了." << std::endl;
        }
    
    
        //处理网络消息
        bool OnRun() {
            if (isRun()) {
                SOCKET _maxSock = _sock;
                fd_set fdRead;
                fd_set fdWrite;
                fd_set fdExp;
                FD_ZERO(&fdRead);
                FD_ZERO(&fdWrite);
                FD_ZERO(&fdExp);
                FD_SET(_sock, &fdRead);
                FD_SET(_sock, &fdWrite);
                FD_SET(_sock, &fdExp);
    
                for (int n = static_cast<int>(_clients.size()) - 1; n >= 0; n--) {
                    FD_SET(_clients.at(n)->sockfd(), &fdRead);
                    FD_SET(_clients.at(n)->sockfd(), &fdWrite);
                    FD_SET(_clients.at(n)->sockfd(), &fdExp);
    
    #ifndef _WIN32 /* win 下 ,该代码无用, Mac 和 Linux 则至关重要*/
                    _maxSock < _clients.at(n)->sockfd() ? _maxSock = _clients.at(n)->sockfd() : _maxSock;
    #endif
                }
                timeval t = { 1,0 };
                // _In_ 代表传入参数,  _Inout 代表传入传出参数, _Inout_opt_ 传入传出操作参数
                int ret = select(_maxSock + 1, &fdRead, &fdWrite, &fdExp, &t);
                //等待描述符出现变化, 或者出错.
    
                if (ret < 0) {
                    std::cout << "select 任务结束" << std::endl;
                    Close();
                    return false;
                }
    
                //可读, 新客户端来了新链接
                if (FD_ISSET(_sock, &fdRead)) {
                    FD_CLR(_sock, &fdRead);
                    Accept();
                    return true;
                }
    
    
                //已连接客户端向服务器发送了消息
                for(size_t n = _clients.size() ,i = 0 ;  n > i  ; ++i){
                    if( FD_ISSET( _clients.at(i)->sockfd(), &fdRead ) ){
                        if( RecvData(_clients.at(i)) == -1){
                         std::cout << "通讯结束,关闭这个套接字" << _clients.at(n)->sockfd() << std::endl;
                          #ifdef _WIN32
                              closesocket(_clients.at(i)->sockfd());
                          #else
                                shutdown(_clients.at(i)->sockfd(), SHUT_WR);
                          #endif
                            auto  it = _clients.begin() + i;
                            delete (*it);
                            _clients.erase(it);
                            --i;
                            --n;
                        }
                    }
                }
                return true;
            }
            return false;
        }
    
        // 判读套接字是否在运行中, 运行中返回true , 没有运行则返回 false
        bool isRun() {
            return _sock != INVALID_SOCKET && SOCKET_ERROR != _sock;
        }
    
        //接收数据, 处理粘包, 拆分包.
        int RecvData(ClientSocket* pClient) {
            // 使用缓冲区接收数据.
    #ifdef _WIN32
            int ret;
    #else
            ssize_t ret; // ssize_t 是 long , size_t 是 unsigned long
    #endif
            ret = recv(pClient->sockfd(), _szRecv, RECV_BUFF_SIZE, 0);  // 接受客户端发送过来的数据
            if (ret <= 0) {
                std::cerr << "客户端<socket=" << pClient->sockfd() << "> 已退出, 任务结束\n" << std::endl;
                return -1;
            }
    
            // 从接收缓冲区 拷贝到 消息缓冲区. (2倍差距),有多少拷贝多少.
            memcpy(pClient->msgBuf() + pClient->getLastPos(), _szRecv, ret);
            pClient->setLastPos(pClient->getLastPos() + static_cast<int>(ret));
    
            //判断 消息缓冲区内的数据长度大于消息头, 这时就可以知道当前消息体的长度.
            while (pClient->getLastPos() >= sizeof(DataHeader)) {
                DataHeader* header = reinterpret_cast<DataHeader*>(pClient->msgBuf());
                //判断 消息缓冲区的数据长度大于消息长度
                if (pClient->getLastPos() >= header->dataLength) {
                    //剩余未处理消息缓存区数据的长度, 先行计算
                    auto nSize = header->dataLength;
                    OnNetMsg(pClient->sockfd(), header);    //处理消息
                    memcpy(pClient->msgBuf(), pClient->msgBuf() + nSize, pClient->getLastPos() - nSize); // 将第二缓存数据前移
                    pClient->setLastPos(pClient->getLastPos() - nSize);     // 需要交还给 第二缓冲区目前存在的数据长度 的数值,也就是未处理的数据
                }
                else {
                    // 消息没有发全,等待数据到达完全再来循环. 剩余数据不足一条完整的消息
                    break;
                }
            }
            return 0;
        }
    
        // 响应网络消息
        virtual void OnNetMsg(SOCKET cSock, DataHeader* header) {
            _recvCount++;
            if (_tTime.getElapsedSecond() >= 1.0){
                auto t1 = _tTime.getElapsedSecond();   // 获得时间差, 秒级
                std::cout  << "time<" << t1 << ">, socket<" << cSock
                           << ">, _recvCount<" << _recvCount << ">, connect<" << _clients.size()
                           << ">"    << std::endl;
                
                _tTime.update(); // 更新当前时间点.
                _recvCount=0;
            }
            
            switch (header->cmd) {
                case CMD_LOGIN: {
                    //                    Login* login = (Login*)header;
                    //                    std::cout << "收到客户端 < " << cSock << " >发送过来的命令:" << login->cmd << "  ,数据长度为: " << login->dataLength << "  ,Username: " << login->userName << "  ,PassWord: " << login->PassWord << std::endl;
                    //                LoginResult  ret;
                    //                SendData(cSock, &ret);
                    break;
                }
                case CMD_LOGOUT: {
                    //                  LogOut* loginout = (LogOut*)header;
                    //                    std::cout << "收到客户端< " << cSock << " >发送过来的命令:" << loginout->cmd << "  ,数据长度为: " << loginout->dataLength << "  ,Username: " << loginout->userName << std::endl;
                    
                    //                LogOutResult  ret;
                    //                SendData(cSock, &ret);
                    break;
                }
                default: {
                    std::cout << std::endl << "<soclet= " << _sock <<"> 收到服务器消息: 未定义消息 ,数据长度为" << header->dataLength << std::endl;
                    //  DataHeader err;
                    //  SendData(_cSock, &err);
                    break;
                }
            }
        }
    
        //发送给指定SOCKET客户端数据
        int SendData(SOCKET cSock, const DataHeader* header) {
            if (isRun() && header)
                return static_cast<int>(send(cSock, (const char*)header, header->dataLength, 0));
            else
                return SOCKET_ERROR;
        }
    
        // 群发消息
        void SendDataToALL(const DataHeader* header) {
            for (int n = static_cast<int>(_clients.size()) - 1; n >= 0; n--) {
                SendData(_clients.at(n)->sockfd(), header);
            }
        }
    };
    
    
    
    #endif
    ```

- **`CELLTimestamp.hpp`**

  - ```c++
    
    #ifndef __CELLTIMESTAMP_HPP__
    #define __CELLTIMESTAMP_HPP__
    
    #include <chrono>
    using namespace std::chrono;
    
    class  CELLTimestamp{
    private:
    
        
    public:
        CELLTimestamp(){
            update();
        }
        ~CELLTimestamp(){}
        
        
        // 初始化时间点.
        void update(void){
            _begin = high_resolution_clock::now(); // 得到当前时间,相当于初始化
        }
        
        //获得当前时间差的 秒
        double getElapsedSecond(void){
            // 将返回的微秒  扩展到 秒
            return  getElapsedTimeInMicroSec() * 0.000001;
        }
        
        //获得当前时间差的 毫秒
        double getElapsedTimeInMilliSec(void){
            // 将返回的微秒  扩展到 毫秒
            return this->getElapsedTimeInMicroSec() * 0.001;
        }
        
        //得到微秒级别的 当前时间差, 微秒
        long long  getElapsedTimeInMicroSec(){
            // 当前时间 减去曾经的一个时间点. 得到经过的时间,  单位是微秒
            return  duration_cast<microseconds>(high_resolution_clock::now() - _begin).count();
        }
        
    protected:
        
        // 一个时间点 <高分辨率时钟>, 分辨到微秒或纳秒级别
        time_point<high_resolution_clock>  _begin;
    };
    #endif /* __CELLTIMESTAMP_HPP__ */
    ```

- **`MessageHeader.hpp`**

  - ```c++
    #ifndef __MESSAGEHEADER_HPP__
    #define __MESSAGEHEADER_HPP__
    
    // 消息协议
    
    // 命令
    enum CMD
    {
        CMD_LOGIN,     /* 登录 */
        CMD_LOGIN_RESULT,    /* LOGIN 返回值,返回消息*/
        CMD_LOGOUT,    /* 登出 */
        CMD_LOGOUT_RESULT,  /* LOGOUT 返回值,返回消息*/
        CMD_NEW_USER_JOIN,   /* 新用户加入 */
        CMD_ERROR      /* 错误*/
    };
    
    //数据包的 包头
    struct DataHeader {
        DataHeader():dataLength(sizeof(DataHeader)),cmd(CMD_ERROR){}
        short dataLength;   //数据长度
        short cmd;          //命令, 使用 enum CMD 枚举,来执行命令
    };
    
    
    // 数据包的  包体
     /* 登录数据结构 */
    struct Login :public DataHeader
    {
        Login(){
            DataHeader::dataLength = sizeof(Login);
            DataHeader::cmd = CMD_LOGIN;
        }
        char userName[32];
        char PassWord[32];
        char data    [932];
    };
    
    /* 返回登陆是否成功的结构体 */
    struct LoginResult : public DataHeader
    {
        LoginResult() :result(0) {
            DataHeader::dataLength = sizeof(LoginResult);
            DataHeader::cmd = CMD_LOGIN_RESULT;
        }
        int result;    /* 登陆结果 */
        char data[992];
    };
    
    
    /* 退出登录的用户名 */
    struct LogOut : public DataHeader
    {
        LogOut() :userName("") {
            DataHeader::dataLength = sizeof(LogOut);
            DataHeader::cmd = CMD_LOGOUT;
        }
        char  userName[32];
    };
    
    /* 登出的结果 */
    struct LogOutResult : public DataHeader
    {
        LogOutResult() : result(0) {
            DataHeader::dataLength = sizeof(LogOutResult);
            DataHeader::cmd = CMD_LOGOUT_RESULT;
        }
        int result;
    };
    
    /* 新用户加入 */
    struct NewUserJoin : public DataHeader
    {
        NewUserJoin() : sock(0) {
            DataHeader::dataLength = sizeof(NewUserJoin);
            DataHeader::cmd = CMD_NEW_USER_JOIN;
        }
        int sock;
    };
    
    #endif
    ```

- **`main.cpp`**

  - ```c++
    #include "EasyTcpServer.hpp"
    
    bool g_bun = true;
    
    void
    cmdThread() {
        char cmdBuf[256] = {};
        while (g_bun) {
            std::cin >> cmdBuf;
            cmdBuf[strlen(cmdBuf)] = '\0';
            if (0 == strcmp(cmdBuf, "exit")) {
                std::cout << "退出 cmdThread 线程" << std::endl;
                g_bun = false;
            }
            else {
                std::cout << "不支持的命令,需要重新输入" << std::endl;
            }
            memset(cmdBuf, 0, sizeof(cmdBuf));
        }
    }
    
        
    int
    main()
    {
        EasyTcpServer server;
        server.InitSocket();
        server.Bind(nullptr, SERVER_PORT);
        server.Listen(64);
        
        std::thread t1(cmdThread);      //创建一个线程,并启动, 去执行 cmdThread 函数体的内容
        t1.detach();                             // 设置线程分离
        
        while(server.isRun() && g_bun){
            server.OnRun();
        }
        server.Close();
        std::cout << "已退出" << std::endl;
        getchar();
        return 0;
    }
    ```

    

# 客户端范例

- **`EasyTcpClient.hpp`**

  - ```c++
    	
    #ifndef   __EASYTCPCLIENT_HPP__
    #define   __EASYTCPCLIENT_HPP__
    
    
        #ifdef   _WIN32  //只有在Windows 下,才会定义这个宏. 出于移植考虑, 应该使用这种判别式, 以使用头文件和宏
        #define   WIN32_LEAN_AND_MEAN   //  这个宏的作用是： 会尽量避免引用早期会引起冲突的库
        #define  _WINSOCK_DEPRECATED_NO_WARNINGS
        #pragma  comment( lib, "ws2_32.lib")  //明确的指出需要一个动态链接库， 或者在项目属性页->连接器->输入->添加依赖项,将 ws2_32.lib加入进去
    
        #define   FD_SETSIZE  1024
        #include <WinSock2.h>
        #include <Windows.h>     // 这两个头文件的文位置不同，会造成编译失败
    
    #else    // 这个是 Unix和Linux 下才有的头文件, 也有用于方便移植的宏
        #include <unistd.h>
    
        //    #ifdef _LINUX
        #include <sys/socket.h>
        //    #else
        //        #include <socket.h>
        //    #endif
        #include <fcntl.h>
        #include <arpa/inet.h>
        #include <netinet/in.h>
        #include <netdb.h>
        #define  SOCKET  int       //兼容 windows ,将 socket套接字的int, b变更为 SOCKET来表示, 两个平台的内容相同
        #define  INVALID_SOCKET  (SOCKET)(~0)     //取反的0, 也就是-1, 用于判别 socket套接字的创建错误
        #define  SOCKET_ERROR            (-1)     // -1, 用于判别 connect 的连接错误
    #endif
    
    
    #include <iostream>
    #include <string>
    #include <thread>
    #include <cstring>
    #include "MessageHeader.hpp"
    
    #ifndef RECV_BUFF_SIZE
    #define RECV_BUFF_SIZE  10240   // 消息缓冲区长度
    #endif
    
    class EasyTcpClient {
    private:
        // 缓冲区 区域最小单元长度
        SOCKET _sock;
        // 使用缓冲区接收数据, 接收缓冲区
        char  _szRecv[RECV_BUFF_SIZE] = {};
        
        //第二缓冲区, 消息缓冲区
        char  _szMsgBuf[RECV_BUFF_SIZE * 2] = {};
        int    _lastPos;    // 第二缓冲区 目前存在的数据长度
        
    public:
        EasyTcpClient() :_sock(INVALID_SOCKET), _lastPos(0) {}
        
        // 虚析构函数
        virtual  ~EasyTcpClient()
        {
            Close();
        }
        
        /* =========================================================================== */
        //初始化 socket, 以及 SOCKET网络环境
        void initSocket()
        {
            // 判断一下, 是否已经建立了一个套接字, 如果建立了,应该关闭它,并断开连接.
            if (_sock != INVALID_SOCKET) {
                std::cout << "< socket = " << _sock << " >"
                << "关闭之前的套接字(或已连接的套接字),并重新建立一个新的套接字" << std::endl;
                this->Close();
            }
            
    #ifdef _WIN32
            /* 建立和启动 Windows socket2.x 环境 */
            WORD ver = MAKEWORD(2, 2);   //创建版本号  2.x的版本， 2是大版本 x是小版本
            WSADATA dat;                 //数据指针
            (void)WSAStartup(ver, &dat);  // winsocket的启动函数 (版本号,  ）;  调用的是动态库，应该加入动态链接库
            // LP开头的类型，只要把LP去掉就会得到真正的类型，并传入指针即可。
    #endif
            
            _sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  // 需求一个 TCP的流式套接字
            if (INVALID_SOCKET == _sock) {
                std::cerr << "创建套接字错误" << std::endl;
            }
            else
                std::cout << "创建套接字 < " << _sock << " > 成功" << std::endl;
        }
        
        /* =========================================================================== */
        
        
        //连接服务器,参数: IP地址, 网络字节序的端口号(unisgned short)
        int Connect(const char* ip, const u_short port)
        {
            if (INVALID_SOCKET == _sock) {
                std::cout << "!由于:<socket = INVALID_SOCKET> ,自动调用 initSocket() 进行初始化~! " << std::endl;
                initSocket();
            }
            sockaddr_in  _sin = {};
            _sin.sin_family = AF_INET;
            _sin.sin_port = htons(port);
            
            // 服务器IP地址
    #ifdef _WIN32
            _sin.sin_addr.S_un.S_addr = inet_addr(ip);
    #else
            inet_pton(AF_INET, ip, &_sin.sin_addr);
    #endif
            
            int ret = connect(_sock, (sockaddr*)&_sin, sizeof(_sin));
            if (SOCKET_ERROR == ret) {
                std::cerr << "!(" << _sock << ")与服务器< " << ip << " : " << port << " >连接失败~!" << std::endl;
                
    #ifdef  _WIN32
                closesocket(_sock);
    #else
                shutdown(_sock, SHUT_RDWR);
    #endif
                return (errno);
            }
    // 优化
    #if 0
            else {
    
                struct sockaddr_in local_sock;
    #ifdef _WIN32
                int  local_sock_len = sizeof(local_sock);
                getsockname(AF_INET, (sockaddr*)&local_sock, &local_sock_len);
                const char* ip_local_arr = inet_ntoa(local_sock.sin_addr);
    #else
                char ip_local_arr[INET6_ADDRSTRLEN] = {};
                socklen_t  local_sock_len = sizeof(local_sock);
                getsockname(_sock, (sockaddr*)&local_sock, &local_sock_len);
                inet_ntop(AF_INET, &local_sock.sin_addr.s_addr, ip_local_arr, INET6_ADDRSTRLEN);
    #endif
                std::cout << "\t 本地IP:" << ip_local_arr << ", 本地端口:" << ntohs(local_sock.sin_port) << std::endl;
                std::cout << "\t(" << _sock << ")与服务器< " << ip << " : " << port << " >连接成功;" << std::endl;
            }
    #endif  // #if 0
            return 0;
        }
        
        
        /* =========================================================================== */
        
        //关闭 socket, 并关闭已连接的套接字, 并且清除SOCKET 网络环境
        void Close()
        {
            if (INVALID_SOCKET != _sock) {
                std::cout << "清理sock< " << _sock << ">  环境和结束通讯,客户端已结束" << std::endl;
    #ifdef _WIN32
                closesocket(_sock);
                /*  清除 Windows socket 环境  */
                WSACleanup(); //与WSAStartup() 相匹配， 一个是开，一个是关
    #else
                shutdown(_sock, SHUT_WR);
    #endif
                _sock = INVALID_SOCKET;
            }
        }
        
        
        
        /* =========================================================================== */
        
        //处理网络消息  (应该写纯虚函数)
        virtual bool OnRun()
        {
            if (isRun()) {
                fd_set fdReads;
                fd_set fdWrites;
                fd_set fdExps;
                FD_ZERO(&fdReads);
                FD_ZERO(&fdWrites);
                FD_ZERO(&fdExps);
                FD_SET(_sock, &fdReads);
                FD_SET(_sock, &fdWrites);
                FD_SET(_sock, &fdExps);
                
                timeval t = { 0,0 };
                //macos和linux 的 select 需要的是 套接字描述符的最大值+1
                //win 的话, 无所谓, 第一个参数无用.
                int ret = select(_sock + 1, &fdReads, nullptr, nullptr, &t);
                //            std::cout << "select ret = " << ret  << " ,count = " << (++count) << std::endl;
                
                if (ret < 0 || INVALID_SOCKET == _sock || SOCKET_ERROR == _sock) {
                    std::cout << "<select = " << _sock << " > 任务结束" << std::endl;
                    Close();
                    return false;
                }
                if (FD_ISSET(_sock, &fdReads)) {
                    FD_CLR(_sock, &fdReads);
                    /*--*/
                    int ret = RecvData(_sock);
                    if (ret == -1) {
                        std::cerr << "<select = " << _sock << " >服务器出现某些错误 ,中断连接" << std::endl;
                        Close();
                        return false;
                    }
                }
                return true;
            }
            return false;
        }
        
        
        /* =========================================================================== */
        // 判读套接字是否在运行中, 运行中返回true , 没有运行则返回 false
        bool isRun()
        {
            return _sock != INVALID_SOCKET && SOCKET_ERROR != _sock;
        }
        
        
        
        /* =========================================================================== */
        // 接收数据. 收数据的时候要处理 粘包,拆分包 的问题
        int    RecvData(SOCKET Csock) {
    #ifdef _WIN32
            int ret;
    #else
            ssize_t ret;   // ssize_t  是 long 类型,  size_t 是 unsigned long
    #endif
            ret = recv(Csock, _szRecv, sizeof(_szRecv), 0);  // 接受服务器发送过来的数据
            if (ret <= 0) {
                std::cout << "<soclet= " << Csock << ">与服务器断开连接, 任务结束" << std::endl;
                return -1;
            }
            
            // 从接收缓冲区 拷贝到 消息缓冲区. (10倍差距),有多少拷贝多少.
            memcpy(_szMsgBuf + _lastPos, _szRecv, ret);
            _lastPos += ret;
            
            //判断 消息缓冲区内的数据长度大于消息头, 这时就可以知道当前消息体的长度.
            while (_lastPos >= sizeof(DataHeader)) {
                DataHeader* header = reinterpret_cast<DataHeader*>(_szMsgBuf);
                //判断 消息缓冲区的数据长度大于消息长度
                if (_lastPos >= header->dataLength) {
                    //剩余未处理消息缓存区数据的长度, 先行计算
                    auto nSize = _lastPos - header->dataLength;
                    OnNetMsg(header);    //处理消息
                    memcpy(_szMsgBuf, _szMsgBuf + header->dataLength, nSize); // 将第二缓存数据前移
                    _lastPos =this->_lastPos - nSize;     // 需要交还给 第二缓冲区目前存在的数据长度 的数值,也就是未处理的数据
                }
                else {
                    // 消息没有发全,等待数据到达完全再来循环. 剩余数据不足一条完整的消息
                    break;
                }
            }
            return 0;
        }
        
        
        
        
        
        /* =========================================================================== */
        //发送数据
        int SendData(const DataHeader* header)
        {
            if (isRun() && header)
                return static_cast<int>(send(_sock, (const char*)header, header->dataLength, 0));
            else
                return SOCKET_ERROR;
        }
        
        
        /* =========================================================================== */
        // 响应网络消息
        virtual void OnNetMsg(DataHeader* header)
        {
            
            // * 6 处理请求
            switch (header->cmd) {
                case CMD_LOGIN_RESULT: {   // 期待服务器返回登录消息
                    //                LoginResult* login = (LoginResult*)header;
                    //                std::cout << std::endl << "<soclet= " << _sock << "> 收到服务器消息: CMD_LOGIN_RESULT ,数据长度为" << login->dataLength << std::endl;
                    break;
                }
                case CMD_LOGOUT_RESULT: {   // 期待服务器返回 退出登录的消息
                    //                LogOutResult* loginout = (LogOutResult*)header;
                    //                std::cout << std::endl << "<soclet= " << _sock<< "> 收到服务器消息: CMD_LOGOUT_RESULT ,数据长度为" << loginout->dataLength << std::endl;
                    break;
                }
                case CMD_NEW_USER_JOIN: {   // 有新的连接 加入到服务器的消息
                    //                NewUserJoin* userJoin = (NewUserJoin*)header;
                    //                std::cout << std::endl << "<soclet= " << _sock << "<soclet= " << _sock << " >收到服务器消息: CMD_NEW_USER_JOIN ,数据长度为" << userJoin->dataLength << std::endl;
                    break;
                }
                case CMD_ERROR: {  // 收到了服务器错误的消息
                    DataHeader* userJoin = (DataHeader*)header;
                    std::cout << std::endl << "<soclet= " << _sock << "> 收到服务器消息: CMD_ERROR ,数据长度为" << userJoin->dataLength << std::endl;
                    break;
                }
                default: {
                    std::cout << std::endl << "<soclet= " << _sock << "> 收到服务器消息: 未定义消息 ,数据长度为" << header->dataLength << std::endl;
                    break;
                }
            }
        }
        
        SOCKET ReturnSock(void)
        {
            return _sock;
            
        }
        
    };
    
    
    
    #endif
    ```

    

- **`MessageHeader.hpp`**

  - ```c++
    
    #ifndef __MESSAGEHEADER_HPP__
    #define __MESSAGEHEADER_HPP__
    
    // 消息协议
    
    // 命令
    enum CMD
    {
        CMD_LOGIN,     /* 登录 */
        CMD_LOGIN_RESULT,    /* LOGIN 返回值,返回消息*/
        CMD_LOGOUT,    /* 登出 */
        CMD_LOGOUT_RESULT,  /* LOGOUT 返回值,返回消息*/
        CMD_NEW_USER_JOIN,   /* 新用户加入 */
        CMD_ERROR      /* 错误*/
    };
    
    //数据包的 包头
    struct DataHeader {
        DataHeader():dataLength(sizeof(DataHeader)),cmd(CMD_ERROR){}
        short dataLength;   //数据长度
        short cmd;          //命令, 使用 enum CMD 枚举,来执行命令
    };
    
    
    // 数据包的  包体
     /* 登录数据结构 */
    struct Login :public DataHeader
    {
        Login(){
            DataHeader::dataLength = sizeof(Login);
            DataHeader::cmd = CMD_LOGIN;
        }
        char userName[32];
        char PassWord[32];
        char data    [932];
    };
    
    /* 返回登陆是否成功的结构体 */
    struct LoginResult : public DataHeader
    {
        LoginResult() :result(0) {
            DataHeader::dataLength = sizeof(LoginResult);
            DataHeader::cmd = CMD_LOGIN_RESULT;
        }
        int result;    /* 登陆结果 */
        char data[992];
    };
    
    
    /* 退出登录的用户名 */
    struct LogOut : public DataHeader
    {
        LogOut() :userName("") {
            DataHeader::dataLength = sizeof(LogOut);
            DataHeader::cmd = CMD_LOGOUT;
        }
        char  userName[32];
    };
    
    /* 登出的结果 */
    struct LogOutResult : public DataHeader
    {
        LogOutResult() : result(0) {
            DataHeader::dataLength = sizeof(LogOutResult);
            DataHeader::cmd = CMD_LOGOUT_RESULT;
        }
        int result;
    };
    
    /* 新用户加入 */
    struct NewUserJoin : public DataHeader
    {
        NewUserJoin() : sock(0) {
            DataHeader::dataLength = sizeof(NewUserJoin);
            DataHeader::cmd = CMD_NEW_USER_JOIN;
        }
        int sock;
    };
    
    #endif
    
    ```

    

- **`main.cpp`**

  - ```c++
    #include "EasyTcpClient.hpp"
    #include <limits>
    #include <istream>
    #include <cstring>
    #include <stdio.h>
    
        
    #define MAC_IP    "10.0.0.94"
    #define WIN_IP    "10.0.0.95"
    #define LIN_IP    "10.0.0.1"
    #define LOCAL_IP  "127.0.0.1"
    #define ALY_IP    "47.240.114.70"
    #define CONNECT_IP  LOCAL_IP      //服务器的IP
    #define  SERVER_PORT  4567
    
    
    
    bool g_bun = true;
    
    void
    cmdThread() {
        char cmdBuf[10] = {};
        while (g_bun) {
            std::cin >> cmdBuf;
            cmdBuf[strlen(cmdBuf)] = '\0';
            if (0 == strcmp(cmdBuf, "exit")) {
                std::cout << "退出 cmdThread 线程" << std::endl;
                g_bun = false;
            }
            else {
                std::cout << "不支持的命令,需要重新输入" << std::endl;
            }
            memset(cmdBuf, 0, sizeof(cmdBuf));
        }
    }
        
    int
    main()
    {
    #ifdef _WIN32
        const int cCount = FD_SETSIZE-1;  //win 下有64个.实际可用 63个
    #else
        const int cCount = FD_SETSIZE-5; // linux 下有1024 ,减去 0,1,2,3 和监听.实际可用 1024-5=1019.(以服务器为准.)
    #endif
        EasyTcpClient* client = new EasyTcpClient[cCount];
        int n = 0;
        for (; n < cCount ; n++){
            if (!g_bun){
                return 0;
            }
            client[n].initSocket();
            client[n].Connect(CONNECT_IP, SERVER_PORT);
        }
        
        std::cout << "CONNECT <" << n <<  ">" << std::endl;
        std::thread t1(cmdThread);      //创建一个线程,并启动, 去执行 cmdThread 函数体的内容
        t1.detach();                             // 设置线程分离
        
        Login login;
    #ifdef _WIN32
        strcpy_s(login.userName, sizeof(login.userName), "lyb");
        strcpy_s(login.PassWord, sizeof(login.userName), "lybpasswd");
    
    #else
        strncpy(login.userName, "lyb", sizeof(login.userName));
        strncpy(login.PassWord, "lybpasswd", sizeof(login.PassWord));
    #endif
        
        while (g_bun){
            for (int n =0; n < cCount && g_bun ;n++){
                client[n].SendData(&login);
    //            client[n].OnRun();
            }
        }
    
        for (int n =0; n < cCount ;n++){
            client[n].Close();
        }
        delete[] client;
        return 0;
    }
    ```






# 休眠函数

> `<chrono>` 和 `<thread>`

- **C++提供的毫秒级休眠函数和对象**
- 声明一个休眠时间,也就是100毫秒:`std::chrono::milliseconds t(100);`
- 启动一个休眠:`std::this_thread::sleep_for(t);`

```c++
#include <thread>
#include <chrono>
// 声明一个休眠的时间, 毫秒单位
std::chrono::milliseconds t(100);
// 启动一个休眠, c++ 提供的, 休眠 毫秒
std::this_thread::sleep_for(t);
//当前线程放弃执行，操作系统调度另一线程继续执行
std::this_thread::yield();

std::this_thread::yield：　当前线程放弃执行，操作系统调度另一线程继续执行。即当前线程将未使用完的“CPU时间片”让给其他线程使用，等其他线程使用完后再与其他线程一起竞争"CPU"。调用线程放弃执行，回到准备状态，重新分配cpu资源。所以调用该方法后，可能执行其他线程，也可能还是执行该线程
  
std::this_thread::sleep_for：　表示当前线程休眠一段时间，休眠期间不与其他线程竞争CPU，根据线程需求，等待若干时间。

  
  
关于sleep_for，sleep以及yield函数三者的区别 
	关于sleep_for，它还有一个类似的函数，叫yield，他的作用域，参数和sleep_for是一样的，它的函数原型是这样的：
		std::this_thread::yield：　当前线程放弃执行，操作系统调度另一线程继续执行。即当前线程将未使用完的“CPU时间片”让给其他线程使用，等其他线程使用完后再与其他线程一起竞争"CPU"。
	另外我们在系统中还有一个阻塞函数sleep函数，所以我们说一说三者的区别。
	我们先来说sleep函数，我们有两点要说明：
			1、sleep函数是系统函数，换句话说它不需要c++11支持，只要有编译器就能找到这个函数。
  		2、sleep函数是进程阻塞函数，换句话说一旦调用这个函数，当前进程当中所有的线程全部阻塞。
  
 
  
#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>

int main(void)
{
    std::cout << "OK" << std::endl;
    std::chrono::milliseconds t(3000);
    t+= t;
    std::this_thread::sleep_for(t);
//    std::this_thread::yield();
    std::cout << "OK" << std::endl;
}

```





