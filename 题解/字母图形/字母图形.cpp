/*
- 程序设计题目      ：字母图形 
- 来源              ：蓝桥杯 
- 涉及知识点        ：字符串处理 

- 难度评价和重点分析：需要分析字母排列规则，然后利用string的相关
					函数来实现，最后只拿到了70分，存在处理不好的情况 
*/

#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

int main(void){

	int n,m;
	cin>>n>>m;
	string alpbet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string alpbetRev(alpbet.rbegin(), alpbet.rend());	//字母表的逆序 
	alpbetRev.erase(alpbetRev.end() - 1, alpbetRev.end());
	
	//cout<<"逆序字符串 : "<<alpbetRev<<endl;
	
	for(int i=1;i<=n;i++){
		cout<<alpbetRev.substr(25-(i-1),i-1);
		cout<<alpbet.substr(0, m - (i-1))<<endl;
	}

	return(0);
}

