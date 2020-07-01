#include<iostream>
#define LT_MIN 1000
#define LT_MAX 9999
using namespace std;

int main(void){
	
	int lt = LT_MIN;
	int ltTemp;
	int separator[4];
	
	while(lt <= LT_MAX){	//1000~9999ÔÚ·¶Î§ÄÚÖð¸ö¼ì²â 
		ltTemp = lt;
		int sepaIterator = 0;
		while(ltTemp > 0){
			separator[sepaIterator++] = ltTemp % 10;
			ltTemp /= 10;
		}
		if((separator[0]*10 + separator[1]) == (separator[3]*10 + separator[2])){
			cout<<lt<<endl;
		}
		lt++;
	}
	
	return(0);
}


