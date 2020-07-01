#include<iostream>
using namespace std;

int multiply1(int N, int M);
int multiply(int N, int M);

int main(void){
	
	int runCount = 0;
	cout << "输入测试数据组数 : ";
	cin >> runCount;
	
	int N, M = 0;
	while(runCount--){
		cout << "输入 n m : ";
		cin >> N >> M;
		cout << multiply(N, M) << endl;
	}
}

/**
*  在原有公式的基础上进行简化并将乘除法交替进行
* 避免了溢出问题 
*/
int multiply(int N, int M){
	
	int result;
	if(N < M){
		result = 0;
	}else if(N == M || M == 0){
		result = 1;
	}else{
		result = 1;
		N = N - M + 1;
		for(int temp = 1;temp <= M;temp++){
			result *= N++;
			result /= temp;
		}
	}

	return(result);
}

/**
* 直接使用公式进行计算，会造成溢出的问题 
*/ 
int multiply1(int START, int LENGTH){
	
	int result = 1;
	for(int temp = LENGTH; temp > 0;temp--){
		result *= START;
		START--;
	}
	
	return(result);
}

