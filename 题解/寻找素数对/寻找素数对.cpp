/* HDU 1262 寻找素数对 */
 
#include <stdio.h>
#include <math.h>
 
int isPrime(int num);
 
/*
总体思路：
对输入的偶数取一半，若为偶数则减一，得到一个奇数
偶数减奇数必得奇数
从第一个奇数开始从大到小逐步试探，直到：
两个奇数都是素数 
*/
int main(void)
{
    int m, p;
 
 	//输入多组测试数据 
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

//素数判定算法 
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
