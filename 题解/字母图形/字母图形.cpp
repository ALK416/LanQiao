/*
- ���������Ŀ      ����ĸͼ�� 
- ��Դ              �����ű� 
- �漰֪ʶ��        ���ַ������� 

- �Ѷ����ۺ��ص��������Ҫ������ĸ���й���Ȼ������string�����
					������ʵ�֣����ֻ�õ���70�֣����ڴ����õ���� 
*/

#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

int main(void){

	int n,m;
	cin>>n>>m;
	string alpbet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string alpbetRev(alpbet.rbegin(), alpbet.rend());	//��ĸ������� 
	alpbetRev.erase(alpbetRev.end() - 1, alpbetRev.end());
	
	//cout<<"�����ַ��� : "<<alpbetRev<<endl;
	
	for(int i=1;i<=n;i++){
		cout<<alpbetRev.substr(25-(i-1),i-1);
		cout<<alpbet.substr(0, m - (i-1))<<endl;
	}

	return(0);
}

