#include<iostream>
using namespace std; 

int v[10];
int check(long long a){
	for(int i=0;i<=9;i++){
		v[i]=0;
	}
	int j;
	while(a){
		j=a%10;
		a/=10;
		v[j]++;
		if(v[j]>1){
			return 0;
		}
	}
	return 1;
} 

int main(){
	int f=1;
	long long x;
	for(x=99380;;x--)
	{
		if(check(x*x)){
		f=0;
		break;
		}
	}

	cout<<x<<" " ;
	cout<<x*x<<endl;
	return 0;
}


