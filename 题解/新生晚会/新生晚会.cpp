#include<iostream>
using namespace std;

int multiply1(int N, int M);
int multiply(int N, int M);

int main(void){
	
	int runCount = 0;
	cout << "��������������� : ";
	cin >> runCount;
	
	int N, M = 0;
	while(runCount--){
		cout << "���� n m : ";
		cin >> N >> M;
		cout << multiply(N, M) << endl;
	}
}

/**
*  ��ԭ�й�ʽ�Ļ����Ͻ��м򻯲����˳����������
* ������������� 
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
* ֱ��ʹ�ù�ʽ���м��㣬�������������� 
*/ 
int multiply1(int START, int LENGTH){
	
	int result = 1;
	for(int temp = LENGTH; temp > 0;temp--){
		result *= START;
		START--;
	}
	
	return(result);
}

