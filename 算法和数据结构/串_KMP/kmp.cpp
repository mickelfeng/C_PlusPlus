#include <iostream>
#include <string>
using namespace std;


void initArray( const char* T, int next[], int Tlen){
	next[0] = 0;
	int i  = 0;   // 代表的字符串和下标
	int j  = 1;	  // 代表的数组
	
	while(Tlen > i){
		if(i == 0 || T[i] == T[j]){
			next[j] = j;

		}

	}
}


int mycmp(const char* S, const char* T){
	int next[19] = 0;
	initArray( T, next, strlen(T));


}


int main(void){
	const char* S = "aabbccaaddaaeeffgg";
	const char* T = "aaddaa";

	cout << mycmp(S, T) << endl;


	return 0;
}
