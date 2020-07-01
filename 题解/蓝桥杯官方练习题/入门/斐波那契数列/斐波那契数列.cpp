#include<iostream> 
using namespace std;
// 1 1 2 3 5 8 13
int main(void){
	
	int n;
	cin>>n;
	int p1, p2, p3;
	int tempArray[3]={1,1,2};
	p1=p2=1;
	p3=2;
	int temp;
	
	if(n<=3){
		cout<<tempArray[n-1];
	}else{
		for(int i=4;i<=n;i++){
		temp=p2+p3;
		p2=p3;
		p1=p2;
		p3=temp%10007;	//µÃµ½ fib_i		
	}
	cout<<p3;
	}

	return(0);
}
