#include<iostream> 
#include<cmath>
#define INF 0x3f3f3f3f
using namespace std;

int num[100007];	//�洢�������� 
 
int main(void){
	
	int N;
	cin>>N;	
	for(int count=0;count<N;count++){
		cin>>num[count];
	}
	int result=1, numIter=0, depSum=0, max=-INF;
	//��ÿһ����Ͳ����бȽ� 
	for(int depCount=1;depCount<=ceil(log(N+1)/log(2));depCount++){
		depSum=0;
		for(int temp=0;temp<pow(2,depCount-1);temp++){
			depSum+=num[numIter++];
		}
		if(depSum>max){	//�������Ȩֵ�� 
			max=depSum;
			result=depCount;
		}
	}
	cout<<result;

	return(0);
}
