#include<iostream>
using namespace std;

int gcd(int a, int b);

int main(void){
	
	int count = 20;	//�趨Ҫ�Ӽ����� 
	int top = 0;
	int bottom = 0;
	bottom = 1 << (count - 1);	//ȷ��δԼ�ֵķ�ĸ 
	top = 2 * (1 << (count - 1)) - 1;	//ȷ��δԼ�ֵķ���,����ʹ�õȱ����к͹�ʽ 
	cout << (top / gcd(top, bottom)) << "/" << (bottom / gcd(top, bottom)) <<endl;	//Լ�ֲ������� 
	return(0);
}

//շת����㷨�������� 
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
