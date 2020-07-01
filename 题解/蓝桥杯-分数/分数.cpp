#include<iostream>
using namespace std;

int gcd(int a, int b);

int main(void){
	
	int count = 20;	//设定要加几个数 
	int top = 0;
	int bottom = 0;
	bottom = 1 << (count - 1);	//确定未约分的分母 
	top = 2 * (1 << (count - 1)) - 1;	//确定未约分的分子,这里使用等比数列和公式 
	cout << (top / gcd(top, bottom)) << "/" << (bottom / gcd(top, bottom)) <<endl;	//约分并输出结果 
	return(0);
}

//辗转相除算法函数定义 
int gcd(int a, int b){
	
	if(a < b){
		std::swap(a, b);
	}
	
	int remainder;
	while(b){
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return(a);
}
