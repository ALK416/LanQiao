/*
- ���������Ŀ      �������ж� 
- ��Դ              �����ű���ϰ�� 
- �漰֪ʶ��        ��

- �Ѷ����ۺ��ص������
*/

#include<iostream>
using namespace std;

int main(void){

	int inputYear = 0;
	cin>>inputYear;
	
	if(inputYear%4==0 && inputYear%100!=0){
		cout<<"yes"<<endl;
	}else if(inputYear % 400 == 0){
		cout<<"yes"<<endl;
	}else{
		cout<<"no"<<endl;
	}

	return(0);
}

