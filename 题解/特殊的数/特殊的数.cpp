/*
- 程序设计题目      ：特殊的数字(水仙花数) 
- 来源              ：蓝桥杯基础练习部分 
- 涉及知识点        ：pow函数的使用 

- 难度评价和重点分析：
	较简单，只需定义循环范围，然后使用pow函数根据定义进行计算即可 
*/

#include<iostream>
#include<cstring>
#include<math.h>
#define LT_MIN 100 
#define LT_MAX 999
using namespace std;

int main(void){
	
	int lt = LT_MIN;
	int sepaArray[3];
	memset(sepaArray, 0, sizeof(sepaArray));
	int ltTemp;
	while(lt <= LT_MAX){
		int sepaArrayIterator = 0;
		ltTemp = lt;
		while(ltTemp != 0){
			sepaArray[sepaArrayIterator++] = ltTemp % 10;
			ltTemp /= 10;
		}
		if(pow(sepaArray[0],3) + pow(sepaArray[1],3) + pow(sepaArray[2],3) == lt){
			cout<<lt<<endl;
		}
		lt++;
	}
	
	return(0);
}

