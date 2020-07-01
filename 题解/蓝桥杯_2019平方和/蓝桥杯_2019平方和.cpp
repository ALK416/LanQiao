#include<iostream> 
using namespace std;

bool judge(int VAL);

int main(void){
	long long result = 0;
	for(int count = 1;count <= 2019;count++){
		if(judge(count)){
			result += count * count;
		}
	}
	cout << "The result is : " << result << endl;
}

//应用了针对整数的逐位检查算法 (利用整数变小数为零的特征)
bool judge(int VAL){
	
	int n = 0;
	while(VAL != 0){
		n = VAL % 10;	//检查最低位 
		if( n == 2 || n == 0 || n == 1 || n == 9){
			return(true);
		}
		VAL /= 10;
	}
	return(false);	//所有位都不符合条件，显然数整体不符号条件 
}
