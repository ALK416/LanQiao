#include<iostream> 
using namespace std;

bool judge(int VAL);

int main(void){
	long long result = 0;
	for(int count = 1;count <= 2019;count++){
		if(judge(count)){
			result += count * count;
		}
	}
	cout << "The result is : " << result << endl;
}

//Ӧ���������������λ����㷨 (����������С��Ϊ�������)
bool judge(int VAL){
	
	int n = 0;
	while(VAL != 0){
		n = VAL % 10;	//������λ 
		if( n == 2 || n == 0 || n == 1 || n == 9){
			return(true);
		}
		VAL /= 10;
	}
	return(false);	//����λ����������������Ȼ�����岻�������� 
}
