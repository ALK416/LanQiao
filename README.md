## 外卖店优先级：



#### 问题描述：

> “饱了么”外卖系统中维护着 N 家外卖店，编号 1 ∼ N。每家外卖店都有
> 一个优先级，初始时 (0 时刻) 优先级都为 0。
> 每经过 1 个时间单位，如果外卖店没有订单，则优先级会减少 1，最低减
> 到 0；而如果外卖店有订单，则优先级不减反加，每有一单优先级加 2。
> 如果某家外卖店某时刻优先级大于 5，则会被系统加入优先缓存中；如果
> 优先级小于等于 3，则会被清除出优先缓存。
> 给定 T 时刻以内的 M 条订单信息，请你计算 T 时刻时有多少外卖店在优
> 先缓存中。



#### 思路

**思路1：**

把所有订单按照时间顺序进行排序，然后逐单按照时间顺序进行处理，相当把实际的情况模拟一遍。在处理过程中进行优先级的检测。由于要对M个订单进行排序，每个订单又要对所有店铺进行遍历，所以复杂度为：O(MN)

**思路2：**

分别处理每家店，枚举每一家店的所有订单，然后计算出这家店在t时刻是否在优先缓存中。依次处理每一家店，最后得到结果。相当于跳过了过程，直接计算结果。

> 在0~T时间内，假设接到了3个订单 M1, M2, M3，那么显然在接到订单1之前优先级为0，所以T1时刻的优先级+2, 从T1~T2首先减去时间差(T2-T1)，如果时间差为负，则直接置为0。按照这种方法处理所有的订单，即可针对一家店得到最后是否在优先缓存中。



#### 实现代码：

思路1：

```c++
#include <iostream>
#include<queue> 
using namespace std;
#define X 100001

struct order{
	int ts,td;
	order (int t,int d){
		ts=t;
		td=d;
	}
	bool operator<(const order &a)const{
		return a.ts<ts;
	}
};
int sumt[X],book[X]; //sumt存优先级，book[i]=1表示在优先缓存中； 
int main()
{
	int N,M,T,t,id;
	cin>>N>>M>>T;
	
	priority_queue<order>q;
	while(M--){
		cin>>t>>id;
		q.push(order(t,id));
	}
	int a=0;
	while(!q.empty()){
		order temp=q.top();
		q.pop();
		id=temp.td;	//当前处理订单的店家号 
		
		for(int i=1;i<=N;i++){
			if(i==id) continue;
			if(sumt[i]>0) sumt[i]--;
			if(book[i]&&sumt[i]<=3){
				book[i]=0;
				a--;
			}
		}
		sumt[id]+=2;	//给当前外卖店优先级+2 
		if(!book[id]&&sumt[id]>5){	//考虑是否加入优先缓存 
			book[id]=1;
			a++;
		}
	}
	cout<<a<<endl;
	return 0;
}
```

