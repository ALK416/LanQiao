/* POJ1182 食物链 */

#include <iostream>
#include <stdio.h>
 
using namespace std;

const int N = 50000;	//限制最多有50000个动物 

/*
	对每一个动物来说，其他动物(X)可以分为三种:
	1.X与自己是同类	(第一个50000存储自己) 
	2.自己吃掉X	(第二个50000对应存储被自己吃掉的)
	3.自己被X吃掉	(第三个50000对应存储吃自己的)
*/


int f[N * 3 + 1], cnt;
void initF(int n);
int find(int root);
void unionOperation(int root1, int root2);

int main()
{
    int n, k, d, x, y, ans;
 	cout<<"分别输入动物的数量和断言个数：";
    scanf("%d%d", &n, &k);
    initF(n * 3);
    ans = 0;
    cout<<"接下来输入"<<k<<"行，每一行代表一个断言 "<<endl; 
    for(int i=1; i<=k; i++) {
        scanf("%d%d%d", &d, &x, &y);
 
        if(x > n || y > n || (d == 2 && x == y)) {
            ans++;
            continue;
        }
 
        if(d == 1) {
        	//    x 吃 y					x 被 y 吃 
            if(find(n + x) == find(y) || find(n * 2 + x) == find(y)) {
                ans++;
                continue;
            }
            
            unionOperation(x, y);	//设置 x y的上级一样(x 或 y) 
            unionOperation(n + x, n + y);	// x,y 吃一样的动物 
            unionOperation(n * 2 + x, n * 2 + y);	// x,y 被一样的动物吃
			 
        } else if(d == 2) {
        	
        	//		x y是同类			y 吃 x 
            if(find(x) == find(y) || find(n * 2 + x) == find(y)) {
                ans++;
                continue;
            }
            
            unionOperation(x, n * 2 + y);	//设置 x 吃 y 
            unionOperation(n + x, y);
            unionOperation(n * 2 + x, n + y);
        }
    }
 	
 	cout<<"假话的个数 : "<<ans<<endl;
 
    return 0;
} 


void initF(int n)
{
    for(int i = 1; i <=n; i++)
        f[i] = i;
    cnt = n;
}
 
//并查集 查函数 
int find(int root) //查找根结点
{
	int son, tmp;
	son = root;
	while(root != f[root]) //我的上级不是掌门
		root = f[root];
	
	//这里进行了路径压缩 
	while(son != root)
	{
		tmp = f[son];
		f[son] = root;
		son = tmp;
	}
	
	return root; //掌门驾到~~
}
 

//并查集 并函数 
void unionOperation(int root1, int root2) //将 root1和root2的上级并到一起 
{
	int x, y;
	x = find(root1);//我老大是玄慈
	y = find(root2);//我老大是灭绝
	if(x != y) 
		f[x] = y; //打一仗，谁赢就当对方老大
}
