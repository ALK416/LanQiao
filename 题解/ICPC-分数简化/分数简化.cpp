#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int gcd(int a, int b);

/**
	问题：输入两个分数，将他们化为一个最简的分数
	
	思路：首先同分，化为一个初步的分数，然后找出分子分母的最大公约数 K (辗转相除法)
	最后输出 ( 分子 / K ) / ( 分母 / K ) 即为最简分数 
	 
*/
int main(){
	
	int runCount = 0;
	cout << "输入运行次数 ： "; 
	cin >> runCount;
	
	int a, b, c, d;
	int num1, num2;
	int k;
	
	while( runCount-- ){
		cout << "分别输入 a b c d : ";
		cin >> a >> b >> c >> d;
		num1 = a * d + b * c;
		num2 = b * d;
		k = gcd(num1, num2);
		cout << num1 / k << " " << num2 / k << endl;
	}
	
	return(0);
}

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
