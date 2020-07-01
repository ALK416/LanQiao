/*
- 程序设计题目      ：数列特征 
- 来源              ：蓝桥杯 
- 涉及知识点        ：sort函数的使用 

- 难度评价和重点分析：简单 
*/

#include<iostream>
#include<algorithm>
using namespace std;

int main(void){

	int n;
	int data[10000];
	int sum = 0;
	
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>data[i];
		sum += data[i];
	}

	sort(data, data+n);
	cout<<data[n-1]<<endl;
	cout<<data[0]<<endl;
	cout<<sum<<endl;
	

	return(0);
}

