/*
- ���������Ŀ      �����ű�-�������� 
- ��Դ              �����ű�����ѵ�� 
- �漰֪ʶ��        ����־flag�����úͼ�� 

- �Ѷ����ۺ��ص��������, ��ʹ��map���Ľ��£��鿴Ч��������� 
*/

#include<iostream>
using namespace std;

int main(void){

	int n;
	int data[1000];
	int target;
	bool find = false;
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>data[i];
	}
	cin>>target;
	
	//��˳�����
	for(int i=0;i<n;i++){
		if(data[i] == target){
			cout<<(i+1)<<endl;
			find = true;
			break;
		}
	} 

	if(find == false){
		cout<<"-1"<<endl;
	}

	return(0);
}

