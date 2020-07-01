/*
- 程序设计题目      ：01字符串 
- 来源              ：蓝桥杯基础练习 
- 涉及知识点        ：bitset的使用，二进制输出 

- 难度评价和重点分析：
*/

#include<iostream>
#include<bitset>

using namespace std;

int main(void){

	
	bitset<5> binaryConverter(0);
	for(int count=0;count<=31;count++){
		
		binaryConverter = count;
		cout<<binaryConverter<<endl;
		
	}

	return(0);
}

