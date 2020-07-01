#include<iostream>
#define LT_MIN 10000
#define LT_MAX 999999
using namespace std;

int sumArray(int targetArray[], int sumLength);

int main(void){
	
	int n;	//��������n
	int startNum = 10000;	//��λ����С��10000��ʼ
	int separateArray[6];	//���ڷ���5/6λ�����֣������ж�
	int separateTemp = 0;
	
	cin>>n;
	
	for(int loop = LT_MIN;loop <= LT_MAX;loop++){
		if(loop < 100000){	//��λ������� 
			separateTemp = loop;
			int fitter = 0;
			//��ȡ����λ���ֵĸ���λ����Ӧ�������� 
			while(separateTemp > 0){
				separateArray[fitter++] = separateTemp % 10;
				separateTemp /= 10;
			}
			if(sumArray(separateArray, 5) == n){
				int leftVal = separateArray[0]*10 + separateArray[1];
				int rightVal = separateArray[4]*10 + separateArray[3];
				if(leftVal == rightVal){
					cout<<loop<<endl;	//��ǰֵ����Ҫ�� 
				}
			}
		}else{	//��λ��������� 
			
			separateTemp = loop;
			int fitter = 0;
			while(separateTemp > 0){
				separateArray[fitter++] = separateTemp % 10;
				separateTemp /= 10;
			}
			if(sumArray(separateArray, 6) == n){
				int leftVal = separateArray[0]*100 + separateArray[1]*10 + separateArray[2];				
				int rightVal = separateArray[5]*100 + separateArray[4]*10 + separateArray[3];
				if(leftVal == rightVal){
					cout<<loop<<endl;	//��ǰֵ����Ҫ�� 
				}
			}
		} 
	}
	return(0);
}

int sumArray(int targetArray[], int sumLength){
	int sum = 0;
	for(int i = 0;i < sumLength;i++){
		sum += targetArray[i];
	}	
	return(sum);
}






