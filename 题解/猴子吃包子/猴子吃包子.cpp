/*
- ���������Ŀ      �����ӳ԰��� 
- ��Դ              �����ű��㷨ѵ�� 
- �漰֪ʶ��        ��������ָ���������  cout<<setiosflags(ios::fixed)<<setprecision(precision);
						
- �Ѷ����ۺ��ص������ʮ�ּ� 
*/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<iomanip> 

using namespace std;

int main(void){

	int meatBaozi, jcBaozi, emptyBaozi;
	int meatSpeed, jcSpeed, emptySpeed;
	int precision;
	
	cin>>meatSpeed>>jcSpeed>>emptySpeed>>meatBaozi>>jcBaozi>>emptyBaozi>>precision;
	
	cout<<setiosflags(ios::fixed)<<setprecision(precision);
	double result = ((double)meatBaozi/(double)meatSpeed) + ((double)jcBaozi/(double)jcSpeed) + ((double)emptyBaozi/(double)emptySpeed);
		
	cout<<result<<endl;
	

	return(0);
}







