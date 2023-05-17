/*
    STL 总和案例
 1) 演讲比赛(speech_contest): 24人参加, 比赛分三轮, 前两轮为淘汰赛, 第三轮决赛.
 2) 比赛方式: 分组比赛,每组6个人; 选手每次随机分组,进行比赛:
        第一轮分为4个小组,每组6个人. 比如 100 - 105 分为一组, 106 - 111 分为第二组,以此类推.
        每人分别按照抽签(draw)顺序演讲. 当小组演讲完后,淘汰组内排名最后的三位选手,然后继续下一个小组的比赛.
 
        第二轮分为2个小组,每组6人. 比赛完毕,淘汰组内排名最后的三个选手,然后继续下一个小组的比赛.
 
        第三轮只剩下6个人, 本轮为决赛,选出前三名.
 3) 比赛评分: 10个评委打分,去除最低,最高分,求平均分.
        每个选手演讲由10个评委分别打分. 该选手的最终得分是去掉一个最高分和一个最低分,求得剩下的8个成绩的平均分.
        选手的名次按得分降序列,若得分一样,按参号升序排名.
 
 用STL 编程, 求解这个问题
 1)请打印出所有选手的名字与参赛号,并以参赛号的升序排列.
 2)打印每一轮比赛后,小组比赛成绩和小组晋级名单.
 3)打印决赛前三名,选手名称、成绩.
 
 
 需求分析:
 // 产生选手 (ABCDEFGHIJKLMNOPQRSTUVWXYZ) 姓名,得分:选手编号
 // 第1轮 选手抽签, 选手比赛 查看比赛结果 (晋级名单)
 // 第2轮 选手抽签, 选手比赛 查看比赛结果 (晋级名单)
 // 第3轮 选手抽签, 选手比赛 查看比赛结果  (前三名)
 
 
 // 第一步创建24个学生 , 因为每个学生都有参赛编号,而且参赛编号是唯一的, 放到map中 ,key是编号,value是选手对象
 // vector<int> v1 第一轮参赛的编号列表 map[编号], random_shuffle 抽签,打乱顺序
 // 第一轮比赛的晋级名单 vector<int> v2; 作为第二轮的参赛编号名单.
 // 第二轮比赛的晋级名单 放到 vector<int> v3;
 // 第三轮参赛名单 v3 参赛, 结果前三名放到vector<int>v4 ;
 // map 只是用来存储信息,不需要执行更改,
 // vector 的对象内容会反复交接和输出.

 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>
#include <map>
#include <numeric>
#include <functional>
#include <deque>
#include <ctime>
using namespace std;

class Player{
public:
    string mName;  // 选手的名字
    int Mscore[3];  // 选手的分数, 如果他参加了三轮,那么他就应该有三个分数.
};

void Create_Player(map<int,Player>& mPlist, vector<int>& v1 ){  //创建选手
    string seedName = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0; i < 24 ; i++){
        Player p;
        p.mName = "选手";
        p.mName += seedName[i];
        
        for(int j = 0; j < 3 ;j++){
            p.Mscore[j] = 0;
        }
        
        int uID = 100 + i;  // 生成一个唯一编号
        mPlist.insert(make_pair(uID, p));  // 保存选手个人信息, 使用make_pair 来插入到mPlist中
        v1.push_back(uID);  // 保存选手编号   // 通过选手编号来从 mPlist 内找选手信息 key
    }
}

void Set_Random(vector<int>& v){  // 选手抽签
    random_shuffle(v.begin(), v.end());  // 随机算法来进行排序,模拟抽签
}


void Set_Score(int index, vector<int>& vIn, map<int,Player>& mPlist, vector<int>& vOut){ // 比赛
    srand((unsigned int)time(NULL));   // 打分随机数生成种子
    
    // 第一个int 是分数,第二个int 是编号 . 根据分数自动排序
    multimap<int,int,greater<int>>mGroup;
    int groupIndex = 0;
    
    for(vector<int>::iterator it = vIn.begin(); it != vIn.end(); it++){
        
        // 打分
        deque<int>dScore;
        for(int i = 0; i < 10; i++){
            int score = rand() % 40 + 60; //通过随机数来打分 60 ~ 99
            dScore.push_back(score);
        }
        
        // 把分数排序
        sort(dScore.begin(),dScore.end());
        
        // 去除最高和最低分
        dScore.pop_front();
        dScore.pop_back();
        
        //求平均分
        int totaoScore = accumulate(dScore.begin(), dScore.end(),0);  // 返回一个总分数.
        int avgScore = totaoScore / dScore.size();   // 求打分的平均分
        mPlist[*it].Mscore[index - 1] = avgScore;   // 把平均分 赋值送入map容器中
        // [*it] 相等于通过key查找到内容,  .Mscore是个数组, [index -1 ] 访问数组 ,然后写入数据.
        
        //把当前选手编号放到Mgroup  中
        mGroup.insert(make_pair(avgScore, *it));
        groupIndex++;
        if(groupIndex % 6 == 0){
            
            int numIndex = 0;   // 用来判别容器 mGroup 内是否已经有了3个元素,也就是一组的前三名
            for(multimap<int, int>::iterator mit = mGroup.begin(); mit != mGroup.end();mit++){
                if(numIndex >= 3){
                    break;
                }
                
                // 把前三名选手的编号,放到输出容器内
                vOut.push_back(mit->second); // 要第二个参数的选手的编号, 不需要第一个参数的分数
                numIndex++;
            }
            mGroup.clear();  // 清空容器内的元素,不能留下上一组 6 个人的信息.
            
        }
    }
}

void Show_Good_Player( int index, vector<int>& v,map< int, Player >& mPlist){  // 打印晋级名单
    cout << "第" << index << "轮晋级名单:" << endl;
    for(vector<int>::iterator it = v.begin(); it != v.end() ; it++){
        cout << "姓名: " << mPlist[*it].mName <<" 分数: " << mPlist[*it].Mscore[index - 1] << endl;
    }
    cout << endl;
}


int main(void){
    
    // 定义 map 容器根据编号保存选手信息.
    map< int, Player > mPlist;

    // 第一轮比赛的参赛列表 24人 晋级12人
    vector<int>v1;
    
    // 第二轮比赛参赛列表 12人 晋级 6人
    vector<int>v2;
    
    // 第三轮比赛的参赛列表 6人 晋级 3人
    vector<int>v3;
    
    // 最终前三名
    vector<int>v4;
    
    //创建选手
    Create_Player(mPlist,v1);

    // 第一轮比赛
    Set_Random(v1);  // 抽签
    Set_Score(1,v1,mPlist,v2);   // 打分 比赛
    Show_Good_Player(1,v2,mPlist);  // 打印晋级名单
    
    
    // 第二轮比赛
    Set_Random(v2);  // 抽签
    Set_Score(2,v2,mPlist,v3);   // 打分 比赛
    Show_Good_Player(2,v3,mPlist);  // 打印晋级名单
    
    
    // 第三轮比赛
    Set_Random(v3);  // 抽签
    Set_Score(3,v3,mPlist,v4);   // 打分 比赛
    Show_Good_Player(3,v4,mPlist);  // 打印晋级名单

    cout << "比赛结束" << endl;
    return 0;
}

