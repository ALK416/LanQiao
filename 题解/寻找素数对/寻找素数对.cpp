/* HDU 1262 Ѱ�������� */
 
#include <stdio.h>
#include <math.h>
 
int isPrime(int num);
 
/*
����˼·��
�������ż��ȡһ�룬��Ϊż�����һ���õ�һ������
ż���������ص�����
�ӵ�һ��������ʼ�Ӵ�С����̽��ֱ����
���������������� 
*/
int main(void)
{
    int m, p;
 
 	//�������������� 
    while(scanf("%d",&m)!=EOF) {
    	
        p = m / 2;
        if(p % 2 == 0)
            p--;
 
        for(;;) {
            if(p <= 2)
                break;
            if(!isPrime(p)) {
                p -= 2;
                continue;
            }
            if(isPrime(m - p)) {
                printf("%d %d\n\n", p, m-p);
                break;
            }
 
            p -= 2;
        }
    }
 
    return 0;
} 

//�����ж��㷨 
int isPrime(int num){
		if(num==2 || num==3) {
			return 1;
		}
		
		if(num%6!=1 && num%6!=5) {
			return 0;
		}
		
		int tmp = (int)sqrt(num);
		
		for(int i=5; i<=tmp; i+=6) {
			if(num%i==0 || num%(i+2)==0) {
				return 0;
			}
		}
		
		return 1;
}
