#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int gcd(int a, int b);

/**
	���⣺�������������������ǻ�Ϊһ�����ķ���
	
	˼·������ͬ�֣���Ϊһ�������ķ�����Ȼ���ҳ����ӷ�ĸ�����Լ�� K (շת�����)
	������ ( ���� / K ) / ( ��ĸ / K ) ��Ϊ������ 
	 
*/
int main(){
	
	int runCount = 0;
	cout << "�������д��� �� "; 
	cin >> runCount;
	
	int a, b, c, d;
	int num1, num2;
	int k;
	
	while( runCount-- ){
		cout << "�ֱ����� a b c d : ";
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
