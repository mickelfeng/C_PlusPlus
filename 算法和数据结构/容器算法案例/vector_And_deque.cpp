#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

//选手类
class Player{
public:
    Player(){}
    Player(string name,int score):mName(name),mScoer(score){}
public:
    string mName; //名字
    int mScoer; //分数
};

//创建选手
void Create_Player(vector<Player>& v){
    string nameSeed = "ABCDE";
    for(int i = 0; i< 5; i++){
        Player p;
        p.mName = "选手";
        p.mName += nameSeed.at(i);
        p.mScoer = 0;
        
        v.push_back(p);
    }
}

void Print(int val){
    cout << val  <<  " ";
}

//打分
void Set_Score(vector<Player>& v){
    
    for(vector<Player>::iterator it = v.begin(); it != v.end();it++){
        deque<int>dScore;
        
        for(int ji = 0 ; ji< 10; ji++){
            int secore = rand() % 41 + 60;  // 60是及格分线  加上比较好
            dScore.push_back(secore);
        }
        
        sort(dScore.begin(),dScore.end());
//        for_each(dScore.begin(), dScore.end(), Print);
//        cout << endl;
        //去除最高分
        dScore.pop_front();
        
        //去除最低分
        dScore.pop_back();
    
        int totalScore = 0;
        for(deque<int>::iterator dit = dScore.begin(); dit != dScore.end(); dit++){
            totalScore += (*dit);
        }
        
        int avgScore = totalScore/dScore.size();
        
        (*it).mScoer = avgScore;
    }
    
}


bool mycompare(Player& p1, Player& p2){
    return p1.mScoer > p2.mScoer;
}

//根据选手分数排序
void Print_Rank(vector<Player>& v){
    sort(v.begin(),v.end(),mycompare);
    
    for(vector<Player>::iterator it = v.begin(); it != v.end(); it++){
        cout << "name " << (*it).mName << ", mScoer " << (*it).mScoer  << endl ;
    }
    cout << endl;
}


int main(void){
    
    vector<Player>vPlist;
    Create_Player(vPlist);
    Set_Score(vPlist);
    Print_Rank(vPlist);
    
    
    return 0;
};
