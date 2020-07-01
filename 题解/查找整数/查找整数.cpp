/*
- 程序设计题目      ：蓝桥杯-查找整数 
- 来源              ：蓝桥杯基础训练 
- 涉及知识点        ：标志flag的设置和检测 

- 难度评价和重点分析：简单, 可使用map来改进下，查看效率有无提高 
*/

#include<iostream>
using namespace std;

int main(void){

	int n;
	int data[1000];
	int target;
	bool find = false;
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>data[i];
	}
	cin>>target;
	
	//简单顺序查找
	for(int i=0;i<n;i++){
		if(data[i] == target){
			cout<<(i+1)<<endl;
			find = true;
			break;
		}
	} 

	if(find == false){
		cout<<"-1"<<endl;
	}

	return(0);
}

