/*
- ���������Ŀ      ��01�ַ��� 
- ��Դ              �����ű�������ϰ 
- �漰֪ʶ��        ��bitset��ʹ�ã���������� 

- �Ѷ����ۺ��ص������
*/

#include<iostream>
#include<bitset>

using namespace std;

int main(void){

	
	bitset<5> binaryConverter(0);
	for(int count=0;count<=31;count++){
		
		binaryConverter = count;
		cout<<binaryConverter<<endl;
		
	}

	return(0);
}

