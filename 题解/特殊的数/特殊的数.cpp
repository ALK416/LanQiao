/*
- ���������Ŀ      �����������(ˮ�ɻ���) 
- ��Դ              �����ű�������ϰ���� 
- �漰֪ʶ��        ��pow������ʹ�� 

- �Ѷ����ۺ��ص������
	�ϼ򵥣�ֻ�趨��ѭ����Χ��Ȼ��ʹ��pow�������ݶ�����м��㼴�� 
*/

#include<iostream>
#include<cstring>
#include<math.h>
#define LT_MIN 100 
#define LT_MAX 999
using namespace std;

int main(void){
	
	int lt = LT_MIN;
	int sepaArray[3];
	memset(sepaArray, 0, sizeof(sepaArray));
	int ltTemp;
	while(lt <= LT_MAX){
		int sepaArrayIterator = 0;
		ltTemp = lt;
		while(ltTemp != 0){
			sepaArray[sepaArrayIterator++] = ltTemp % 10;
			ltTemp /= 10;
		}
		if(pow(sepaArray[0],3) + pow(sepaArray[1],3) + pow(sepaArray[2],3) == lt){
			cout<<lt<<endl;
		}
		lt++;
	}
	
	return(0);
}

