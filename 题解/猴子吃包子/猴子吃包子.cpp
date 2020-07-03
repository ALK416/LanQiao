/*
- 程序设计题目      ：猴子吃包子 
- 来源              ：蓝桥杯算法训练 
- 涉及知识点        ：浮点数指定精度输出  cout<<setiosflags(ios::fixed)<<setprecision(precision);
						
- 难度评价和重点分析：十分简单 
*/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<iomanip> 

using namespace std;

int main(void){

	int meatBaozi, jcBaozi, emptyBaozi;
	int meatSpeed, jcSpeed, emptySpeed;
	int precision;
	
	cin>>meatSpeed>>jcSpeed>>emptySpeed>>meatBaozi>>jcBaozi>>emptyBaozi>>precision;
	
	cout<<setiosflags(ios::fixed)<<setprecision(precision);
	double result = ((double)meatBaozi/(double)meatSpeed) + ((double)jcBaozi/(double)jcSpeed) + ((double)emptyBaozi/(double)emptySpeed);
		
	cout<<result<<endl;
	

	return(0);
}







