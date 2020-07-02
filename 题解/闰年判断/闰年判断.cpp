/*
- 程序设计题目      ：闰年判断 
- 来源              ：蓝桥杯练习题 
- 涉及知识点        ：

- 难度评价和重点分析：
*/

#include<iostream>
using namespace std;

int main(void){

	int inputYear = 0;
	cin>>inputYear;
	
	if(inputYear%4==0 && inputYear%100!=0){
		cout<<"yes"<<endl;
	}else if(inputYear % 400 == 0){
		cout<<"yes"<<endl;
	}else{
		cout<<"no"<<endl;
	}

	return(0);
}

