#include<iostream> 
#include<cmath>
#define INF 0x3f3f3f3f
using namespace std;

int num[100007];	//存储输入数据 
 
int main(void){
	
	int N;
	cin>>N;	
	for(int count=0;count<N;count++){
		cin>>num[count];
	}
	int result=1, numIter=0, depSum=0, max=-INF;
	//对每一层求和并进行比较 
	for(int depCount=1;depCount<=ceil(log(N+1)/log(2));depCount++){
		depSum=0;
		for(int temp=0;temp<pow(2,depCount-1);temp++){
			depSum+=num[numIter++];
		}
		if(depSum>max){	//更新最大权值和 
			max=depSum;
			result=depCount;
		}
	}
	cout<<result;

	return(0);
}
