#include<iostream>
#define LT_MIN 10000
#define LT_MAX 999999
using namespace std;

int sumArray(int targetArray[], int sumLength);

int main(void){
	
	int n;	//接收输入n
	int startNum = 10000;	//五位数最小从10000开始
	int separateArray[6];	//用于分离5/6位的数字，进行判断
	int separateTemp = 0;
	
	cin>>n;
	
	for(int loop = LT_MIN;loop <= LT_MAX;loop++){
		if(loop < 100000){	//五位数情况下 
			separateTemp = loop;
			int fitter = 0;
			//提取出五位数字的各个位到对应的数组中 
			while(separateTemp > 0){
				separateArray[fitter++] = separateTemp % 10;
				separateTemp /= 10;
			}
			if(sumArray(separateArray, 5) == n){
				int leftVal = separateArray[0]*10 + separateArray[1];
				int rightVal = separateArray[4]*10 + separateArray[3];
				if(leftVal == rightVal){
					cout<<loop<<endl;	//当前值符合要求 
				}
			}
		}else{	//六位数的情况下 
			
			separateTemp = loop;
			int fitter = 0;
			while(separateTemp > 0){
				separateArray[fitter++] = separateTemp % 10;
				separateTemp /= 10;
			}
			if(sumArray(separateArray, 6) == n){
				int leftVal = separateArray[0]*100 + separateArray[1]*10 + separateArray[2];				
				int rightVal = separateArray[5]*100 + separateArray[4]*10 + separateArray[3];
				if(leftVal == rightVal){
					cout<<loop<<endl;	//当前值符合要求 
				}
			}
		} 
	}
	return(0);
}

int sumArray(int targetArray[], int sumLength){
	int sum = 0;
	for(int i = 0;i < sumLength;i++){
		sum += targetArray[i];
	}	
	return(sum);
}






