/*
- ���������Ŀ      ���������� 
- ��Դ              �����ű� 
- �漰֪ʶ��        ��sort������ʹ�� 

- �Ѷ����ۺ��ص�������� 
*/

#include<iostream>
#include<algorithm>
using namespace std;

int main(void){

	int n;
	int data[10000];
	int sum = 0;
	
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>data[i];
		sum += data[i];
	}

	sort(data, data+n);
	cout<<data[n-1]<<endl;
	cout<<data[0]<<endl;
	cout<<sum<<endl;
	

	return(0);
}

