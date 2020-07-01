/* POJ1182 ʳ���� */

#include <iostream>
#include <stdio.h>
 
using namespace std;

const int N = 50000;	//���������50000������ 

/*
	��ÿһ��������˵����������(X)���Է�Ϊ����:
	1.X���Լ���ͬ��	(��һ��50000�洢�Լ�) 
	2.�Լ��Ե�X	(�ڶ���50000��Ӧ�洢���Լ��Ե���)
	3.�Լ���X�Ե�	(������50000��Ӧ�洢���Լ���)
*/


int f[N * 3 + 1], cnt;
void initF(int n);
int find(int root);
void unionOperation(int root1, int root2);

int main()
{
    int n, k, d, x, y, ans;
 	cout<<"�ֱ����붯��������Ͷ��Ը�����";
    scanf("%d%d", &n, &k);
    initF(n * 3);
    ans = 0;
    cout<<"����������"<<k<<"�У�ÿһ�д���һ������ "<<endl; 
    for(int i=1; i<=k; i++) {
        scanf("%d%d%d", &d, &x, &y);
 
        if(x > n || y > n || (d == 2 && x == y)) {
            ans++;
            continue;
        }
 
        if(d == 1) {
        	//    x �� y					x �� y �� 
            if(find(n + x) == find(y) || find(n * 2 + x) == find(y)) {
                ans++;
                continue;
            }
            
            unionOperation(x, y);	//���� x y���ϼ�һ��(x �� y) 
            unionOperation(n + x, n + y);	// x,y ��һ���Ķ��� 
            unionOperation(n * 2 + x, n * 2 + y);	// x,y ��һ���Ķ����
			 
        } else if(d == 2) {
        	
        	//		x y��ͬ��			y �� x 
            if(find(x) == find(y) || find(n * 2 + x) == find(y)) {
                ans++;
                continue;
            }
            
            unionOperation(x, n * 2 + y);	//���� x �� y 
            unionOperation(n + x, y);
            unionOperation(n * 2 + x, n + y);
        }
    }
 	
 	cout<<"�ٻ��ĸ��� : "<<ans<<endl;
 
    return 0;
} 


void initF(int n)
{
    for(int i = 1; i <=n; i++)
        f[i] = i;
    cnt = n;
}
 
//���鼯 �麯�� 
int find(int root) //���Ҹ����
{
	int son, tmp;
	son = root;
	while(root != f[root]) //�ҵ��ϼ���������
		root = f[root];
	
	//���������·��ѹ�� 
	while(son != root)
	{
		tmp = f[son];
		f[son] = root;
		son = tmp;
	}
	
	return root; //���żݵ�~~
}
 

//���鼯 ������ 
void unionOperation(int root1, int root2) //�� root1��root2���ϼ�����һ�� 
{
	int x, y;
	x = find(root1);//���ϴ�������
	y = find(root2);//���ϴ������
	if(x != y) 
		f[x] = y; //��һ�̣�˭Ӯ�͵��Է��ϴ�
}
