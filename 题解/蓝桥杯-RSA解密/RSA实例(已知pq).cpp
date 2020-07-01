#include<iostream>
using namespace std;
typedef long long LL;

const LL p = 891234941ll;
const LL q = 1123984201ll;
const LL d = 212353ll;
const LL c = 20190324ll;
const LL n = 1001733993063167141ll;
void exgcd(LL a,LL b,LL &d,LL &x,LL &y);
LL rev(LL t,LL m);
LL fastModPow(LL a,LL b,LL mod);	//快速乘改进的快速取模幂 
LL fastModMul(LL a,LL b,LL mod);	//快速乘计算 a*b

int main(void){
	
	//First Step : get e
	LL y = (p-1)*(q-1);
	LL e = rev(d, y);
	cout<<e<<endl;
	LL result = fastModPow(c, e, n);
	cout<<"Decode result : "<<result<<endl;
	
	return(0);
} 

LL rev(LL t,LL m)
{
	LL d,x,y;
	exgcd(t,m,d,x,y);
	return (x%m+m)%m;
}

void exgcd(LL a,LL b,LL &d,LL &x,LL &y)
{
	if(b==0)
	{
		d = a; x = 1; y = 0; return;
	}
	exgcd(b,a%b,d,y,x);
	y -= (a/b)*x;
}

LL fastModPow(LL a,LL b,LL mod)//快速幂
{
	LL ans = 1;
	while(b)
	{
		if(b&1) ans = fastModMul(ans,a,mod);
		a = fastModMul(a,a,mod);
		b>>=1;		
	} 
	return ans;
}

LL fastModMul(LL a,LL b,LL mod)//快速乘计算 a*b
{
	LL ans = 0;
	while(b)
	{
		if(b&1) ans = (ans+a)%mod;
		a = (a+a)%mod;
		b>>=1;
	}
	return ans;
} 
