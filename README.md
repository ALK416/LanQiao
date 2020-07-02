### 蓝桥杯程序设计经验与总结：

[TOC]





<hr/>
##### 1. 辗转相除法：

辗转相除法求两个数字的`最大公约数`

算法思想：

> 假设 a > b ,现在要求 a b 的最大公约数:
>
> while(b){	//当小数为0时，大数即为最大公约数
>
> c = a % b	//大数对小数取余
>
> a = b			//小数给大数
>
> b = c;			//余数给小数
>
> }

代码：

```C++
int gcd(int a, int b){
	
	if(a < b){
		std::swap(a, b);
	}
	
	int remainder;
	while(b){
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return(a);
}
```



对应题型：

`ICPC - a/b + c/d`

<hr/>
##### 2. sort库函数+自定义排序

包含头文件 `algorithm` 

sort(data, data+range, cmp);

- data指的是数组的指针
- data+range指的是指向数组尾部的指针
- cmp是一个自定义的函数，用于规定排序规则(升序/降序)

```c++
bool cmp(int x, int y){		//返回 x>y，则表示升序
	return(x>y);
}
int main(void){
	int array[200];
	sort(array,array+200,cmp);
	return(0);
}
```



<hr/>
##### 3. memset函数的使用以及重要性:

在头文件`cstring`中，用于将一个数组初始化一个值

```c++
int data[10];
/*将 data 数组全部初始化为 0 */
memset(data, 0, sizeof(data));
```

在C语言中，申请一个数组如果不手动初始化的话，数组中会是脏数据，即随机的数据。

<hr/>
##### 4. 组合计算问题：

在组合计算时会出现溢出的问题，数字的增长是剧烈的：

> **即便是 long long 类型，到了 21 的阶乘也会溢出**
>
> 0! 1
> 1! 1
> 2! 2
> 3! 6
> 4! 24
> 5! 120
> 6! 720
> 7! 5040
> 8! 40320
> 9! 362880
> 10! 3628800
> 11! 39916800
> 12! 479001600
> 13! 6227020800
> 14! 87178291200
> 15! 1307674368000
> 16! 20922789888000
> 17! 355687428096000
> 18! 6402373705728000
> 19! 121645100408832000
> 20! 2432902008176640000
> 21! -4249290049419214848



组合计算的公式：`C(n,m)=n!/(n-m)!*m!`

可以采用的技巧：

- 首先对公式进行简化 : `x / m!`，这里的 `x`指的是将 `n!`与`(n-m)!`合并之后得到的结果
- 对于`x / m!` ，可以使用循环来使乘除法交替进行，这样可以避免溢出。



改进的算法具体代码:

```c++
/**
*  在原有公式的基础上进行简化并将乘除法交替进行
* 避免了溢出问题 
*/
int multiply(int N, int M){
	
	int result;
	if(N < M){
		result = 0;
	}else if(N == M || M == 0){
		result = 1;
	}else{
		result = 1;
		N = N - M + 1;	//这里修改之后的 N，实际上就是计算 X 的部分
		for(int temp = 1;temp <= M;temp++){
			result *= N++;
			result /= temp;
		}
	}

	return(result);
}
```



对应例题：`新生晚会`



<hr/>
##### 5. 数组排序 `Java`

```java
Arrays.sort(data);	//对int等基本类型数据数组进行排序

//正常升序排序
Collections.sort(integers);

//指明降序排序
Collections.sort(integers, Collections.<Integer>reverseOrder());

```



##### 5.2 (结构体)数组排序 `C++`

- 普通数组排序：

  - ```c++
    sort(array, array + (sizeof(array) / sizeof(array[0])));
    //注意这里使用 sizeof(array) / sizeof(array[0]) 来表示数组的长度
    //注意有时数组并没有全用，所以还是得用 n ，而不直接用这个
    ```

- 结构体数组排序：

  - 结构体数组排序时，需要设定根据哪个属性来排序：

  - ```c++
    bool cmp(const structType &x,const structType &y){
    	return(x.sortVal < y.sortVal);
    }
    ```

  - ```c++
    stable_sort(data, data + n, cmp);
    sort(data, data + n, cmp)
    ```

  - 



<hr/>
##### 6. 对象数组排序(Java)

把一个包含对象的`ArrayList`根据某一属性进行排序：

**排序所需要的工具类:**

```java
import java.util.Comparator;

public class UserOrder implements Comparator<User> {
    @Override
    public int compare(User o1, User o2) {
        return(o2.getUserId() - o1.getUserId());
    }
}
```



**排序实例:**

```java
  		ArrayList<User> users = new ArrayList<User>();
        users.add(new User(5, "User5"));
        users.add(new User(4, "User4"));
        users.add(new User(6, "User6"));
        users.add(new User(1, "User1"));
        users.add(new User(3, "User3"));

        for(User temp : users){
            System.out.println(temp.getUserName() + " : " + temp.getUserId());
        }

        Collections.sort(users, new UserOrder());

        for(User temp : users){
            System.out.println(temp.getUserName() + " : " + temp.getUserId());
```



<hr/>
##### 7. 浮点数控制输出位数&Math类的平方和开方方法:

```java
        double result = Math.sqrt( Math.pow(Xa - Xb, 2) + Math.pow(Ya - Yb, 2));

        System.out.println(String.format("%.2f", result));	//C语言方式

        DecimalFormat df = new DecimalFormat(".00");	//使用DecimalFormat

        System.out.println(df.format(result));
```



<hr/>
##### 8. 并查集:

>  例题: 食物链

```java
/* POJ1182 食物链 */
 
#include <iostream>
#include <stdio.h>
 
using namespace std;
 
const int N = 50000;
int f[N * 3 + 1], cnt;
 
void UFInit(int n)
{
    for(int i = 1; i <=n; i++)
        f[i] = i;
    cnt = n;
}

int Find(int root) //查找根结点
{
	int son, tmp;
	son = root;
	while(root != f[root]) //我的上级不是掌门
		root = f[root];
	while(son != root) //我就找他的上级，直到掌门出现
	{
		tmp = f[son];
		f[son] = root;
		son = tmp;
	}
	return root; //掌门驾到~~
}
 

void Union(int root1, int root2) //虚竹和周芷若做朋友
{
	int x, y;
	x = Find(root1);//我老大是玄慈
	y = Find(root2);//我老大是灭绝
	if(x != y) 
		f[x] = y; //打一仗，谁赢就当对方老大
}
 
 
int main()
{
    int n, k, d, x, y, ans;
 
    scanf("%d%d", &n, &k);
    UFInit(n * 3);
    ans = 0;
    for(int i=1; i<=k; i++) {
        scanf("%d%d%d", &d, &x, &y);
 
        if(x > n || y > n || (d == 2 && x == y)) {
            ans++;
            continue;
        }
 
        if(d == 1) {
            if(Find(n + x) == Find(y) || Find(n * 2 + x) == Find(y)) {
                ans++;
                continue;
            }
            Union(x, y);
            Union(n + x, n + y);
            Union(n * 2 + x, n * 2 + y);
        } else if(d == 2) {
            if(Find(x) == Find(y) || Find(n * 2 + x) == Find(y)) {
                ans++;
                continue;
            }
            Union(x, n * 2 + y);
            Union(n + x, y);
            Union(n * 2 + x, n + y);
        }
    }
 
    printf("%d\n", ans);
 
    return 0;
}
```



<hr/>
##### 9. 改进的素数检测算法：

1.常规算法：

> 素数是指除了这个数本身以及1没有能够整除的这样的数

从2到这个数字，检测中间是否有数字可以整除这个数，如果有则立即判断这个数不是素数.

2.改进后：

质数分布规律：

> - 大于等于5的质数一定和6或者6的倍数相邻。
>
> - 小于5的质数只有 2 ， 3
> - 对于大于等于5的数字
>   - 不与6或者6的倍数相邻，则一定不是质数
>   - 与6或者6的倍数相邻，也不一定是质数

```c++
//优化后的 质数判定算法
int isPrime(int num){
		if(num==2 || num==3) {
			return 1;
		}
		
		if(num%6!=1 && num%6!=5) {
			return 0;
		}
		
		int tmp = (int)sqrt(num);
		
    	//检测这个数是否会被多个 与6或6的倍数相邻的数字 整除
		for(int i=5; i<=tmp; i+=6) {
			if(num%i==0 || num%(i+2)==0) {
				return 0;
			}
		}
		
		return 1;
}
```



<hr/>
##### 10. C++ string 类:

string 是由 STL 中的 basic_string 模板实例化得到的模板类

常用方法1：

```c++
//构造方法
string s1("normal Constructor");	//规律构造
string s3(4, 'K');	//单字符构造
string s4(s1, 1, 5);	//基于已有字符串构造0

string testString = "987654321";	//初始化并输出
cout << testString << endl;

//为string类型变量赋值(和使用等号等效)
string str("normal constructor");
str.assign("normal constructor renamed");

//截取子串
//pos代表起始位置从0开始，size表示截取几个
testString.substr(pos, size);

//交换内容
string str1 = "123";
string str2 = "321";
str2.swap(str1);	//将str1, str2内容互换

//获取长度, 两种方法等效
cout << str.length() << endl;
cout << str.size() << endl;

//将string逆序,利用反向迭代器
string alpbetRev(alpbet.rbegin(), alpbet.rend());

//去掉最后一个字符
alpbetRev.erase(alpbetRev.end() - 1, alpbetRev.end());
```



解决devcpp不支持C++11的问题：

> 在编译选项中，在编译时加入以下命令区域加入：
>
> -std=c++11
>
> 勾选对勾，点击确定即可。



常用方法2：

```c++
//数值类型转化为字符串类型
//可转化：int, long, long long, float, double, long double 

long testNum = 987654321;
string convertString = to_string(testNum);
cout << convertString.substr(0, 3);
```



<hr/>
##### 11. C++各种整数类型的表示范围:

> short   -32768~+32767
>
> unsigned   int   0～42 9496 7295  
> int   -2147483648～21 4748 3647
> unsigned long 0～42 9496 7295
> long   -2147483648～21 4748 3647
> long long的最大值：922 3372 0368 5477 5807
> long long的最小值：-922 3372 0368 5477 5808
> unsigned long long的最大值：1844 6744 0737 0955 1615



有关题目：`蓝桥杯 平方十位数`



<hr/>
##### 12. C++简单移位：

左移可以实现 乘2的效果

```c++
2 * (1 << 2) = 8;
```



有关题目：`蓝桥杯 分数` , 在等比数列和的计算中使用移位运算(等比2)。 



<hr/>
##### 13. 两个数互质

两个数互质即意味着：这两个数的最大公约数 = 1

对于一个分数来说，如果分子分母互质，那么：**该分数最简**



<hr/>
##### 14. 闰年判断:

> 闰年判断规则：
>
> 被4整除，且不被100整除 或者 被400整除

闰年有 366天，平年有365天



相关题目 `蓝桥杯 星期一`

<hr/>
##### 15.针对整数的逐位检测算法：

> 在许多有关数字性质判断的题目中，需要对数字进行逐位检测，可以利用取余来完成。使用while循环，使得算法整体能够比较简洁。

```c++
bool judge(int VAL){
	int n = 0;
	while(VAL != 0){
		n = VAL % 10;	//检查最低位 
		if(/*检测是否满足条件*/)
		VAL /= 10;
	}
	return(false);	//所有位都不符合条件，显然数整体不符号条件 
}
```

 相关题目 `蓝桥杯 '2019'平方和`



<hr/>
##### 16.蓝桥杯中经常出现大数

> 遇到可能出现的大数情形时，使用 long 或 long long 类型来存储，可以仅仅在需要的地方使用大数类型，int可以向 long long 类型转换。



处理大数的方法：

- 定义范围更大的类型

- 采取某种转化，转大数为小数

  > 例如：`蓝桥杯 数列求值` 中，答案要求给出第 20190324 个单元的数值的最后四位，所以在每次计算时将结果对10000取余即可将所有大数转化为小数。
  >
  > **但是这种方法中可能需要定义一个 long long 类型的变量，作为转化的中介。**



相关题目 `蓝桥杯 '2019'平方和  ` `蓝桥杯 数列求值`



<hr/>
##### 17.手写分析和数学分析的重要性

> 蓝桥杯中有很多题，结合手写分析和数学分析后，可以很大程度上简化问题。	

例题 `蓝桥杯 降雨量`：

```javascript
由于沙之国长年干旱，法师小明准备施展自己的一个神秘法术来求雨。
这个法术需要用到他手中的 49 张法术符，上面分别写着 1 至 49 这 49 个
数字。法术一共持续 7 周，每天小明都要使用一张法术符，法术符不能重复使用。
每周，小明施展法术产生的能量为这周 7 张法术符上数字的中位数。法术
施展完 7 周后，求雨将获得成功，降雨量为 7 周能量的中位数。
由于干旱太久，小明希望这次求雨的降雨量尽可能大，请大最大值是多少？
-------------------------------------------------
将七周画出来(每一周的法术符值从小到大排列)：
(并把七周根据各个周星期四的法术符值排序，从上到下降序)
x x x x14 x x x 
x x x x24 x x x 
x x x x34 x x x 
x x x x44 x x x 
x x x x45 x x x 
x x x x46 x x x 
x x x x47 x x x 

`显然x44即为最终降雨量的值，而容易看出比x44大的只有x44右下方的所有，共计15个。所以x44最大为: 49 - 15 = 34`
```

对于这种题型，经过适当的数学分析，能起到事半功倍的效果。所以以后对于题目，要先尝试数学的分析,不可着急上手。



<hr/>
##### 18.位运算实现快速幂

使用累乘的方法实现幂运算 x^y^ 的时间复杂度是 `O(n)`，而使用快速幂改进之后可以达到 `O(logn)`。

**原理:**

> 将 y 展开为二进制形式，则可得 二进制代码长度为 log~2~n
>
> 例如：假设 y = 10, 则 y = 1010~2~ ，第i位的位权是 2^i-1^，计算过程为：
>
> 从最低位向高位遍历：
> | 从低位到高位 | 数值 | 结果累乘操作 |
| ------------ | ---- | ------------ |
| 最低位       | 0    | 不乘 x^1^    |
| 第二位       | 1    | 乘以 x^2^    |
| 第三位       | 0    | 不乘 x^4^    |
| 第四位       | 1    | 乘以 x^8^    |



**代码实现：**

```c++
int fastPow(int X, int Y){
	int result = 1;
	int x = X;
	int y = Y;
	//循环移位累乘
	while(y){
		if(y & 1)	result *= x;
		x *= x;
		y = y >> 1;
	}
	return(result);
}
```



<hr/>
##### 19.扩展欧几里得算法：

由欧几里得算法可以得到：
$$
gcd(a,b)=gcd(b,a\%b)
$$
**定理**：对于两个整数 a,b 必有整数 x y 使得：
$$
ax+by=gcd(a,b)
$$
则由上面两式可得：
$$
ax_{1}+by_{1}=bx_{2}+(a\%b)y_{2}\\
即\\
ax_{1}+by_{1}=bx_{2}+(a-(\frac{a}{b})b)y_{2}\\
即\\
ax_{1}+by_{1}=ay_{2}+b(x_{2}-(\frac{a}{b})y_{2})
$$
由于a,b为常数且等式成立，可以得到：
$$
x_{1}=y_{2}\\y_{1}=x_{2}-(\frac{a}{b})y_{2}
$$

---

显然利用:
$$
gcd(b,a\%b)=gcd(a\%b,b\%(a\%b))
$$
可以继续得到 $x_{2},y_{2}$和 $x_{3},y_{3}$ 的关系，这种关系可以一直保持下去。

但是由于辗转相除法是有穷的，所以$x_{i},y_{i}$之间的迭代也是有穷的，$x_{max},y_{max}$ 显然在辗转相除法中是当 $b=0$ 时的情形，所以 $b=0$ 是递归基。



实现代码：

```c++
void extgcd(int a,int b,int &x,int &y){
    if(b==0){
        x = 1;
        y = 0;
        return;
    }
    extgcd(b,a%b,x,y);
    //从这里开始往回倒,最后求出x,y
    int x1 = x,y1 = y;
    x = y1;
    y = x1 - (a/b) * y1;
}
```



<hr/>
##### 20.模反元素：

定理：

> 如果两个正整数a n互质，那么一定可以找到一个整数 b ，使得 ab被n除的余数是1，b称为a的模反元素，即：
>
> $ab\equiv1(mod\ n)$
>
> 例：7 模 11 的逆元
>
> $7*8=11*5+1$
>
> 所以 7 模 11 的逆元为 8



求一个整数的模反元素：

```c++
int modReverse(int a,int n)//ax=1(mod n) 求a的逆元x 
{
    int d,x,y;
    d=ex_gcd(a,n,x,y);
    if(d==1)
        return (x%n+n)%n;
    else
        return -1;
}
```



<hr/>
##### 21.位运算实现快速乘：

两个数字 a b 相乘可以等效成 b 个 a 相加。

那么将 b 转化为二进制代码，逐位进行判断相加，即为快速乘算法：

```c++
//快速乘算法 
int fastMul(int a,int b)
{
    int ans=0;
    while(b)
    {	//始终比较 a 的最低为，为1则加上对应的数
        if(b&1) ans=(ans+a);
        a<<=1;	//a乘2，以进行下一位的运算
        b>>=1;	//b右移一位，检测下一位
    }
    return ans;
}
```



<hr/>
##### 22.快速乘改进的快速取模幂：

快速乘的时间复杂度是 O(logn)，付出这个时间代价可以防止累加时溢出：

**快速取模乘：**

```c++
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
```



**使用快速取模幂来改进：**

```c++
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
```



快速幂用于在防止溢出的前提下计算(计算过程中不断模n)：

$result=x^{y}\ mod \ n$



<hr/>
##### 23.RSA加密算法：

RSA加密算法是一种非对称加密算法，在当今被广泛使用。于1977年被提出，经过了时间的考验，一直截止到2017年被普遍认为是最优秀的公钥方案之一。

**原理：**

> 首先选定两个大素数:  $ p,q $
>
> -  $n=p*q$  
>
> 然后找到一个数 $d$，使得：
>
> - $d$ 与 $(p-1)(q-1)$ 互质
>
> 接下来找到数 $e$ ，使得：
>
> - $de\equiv1(mod\ ((p-1)*(q-1)))$
>
> $e$ 是 $d$ 模 $(p-1)*(q-1)$ 的逆元(模反元素)

则有：

- $n,e$ 组成了私钥

- $n,d$ 组成了公钥 



**加密与解密方法**

设密文原文为 X：

- 加密：$C=X^{d} \ mod\ n$
- 解密：$X=C^{e}\ mod\ n$



**破解方法**

由于 RSA 中**公钥 (n,d) 是公开的**，所以：

- 通过对 $n$ 分解质因数可以得到很多 $p, q $
- 检测 $p, q $与 $d$ 是否互质
- 由扩展欧几里得算法根据 $p,q,d$ 得到 $e$

- 得到加密的C后，可以根据 $e,n$ 来破解得到密文



**RSA算法的可靠性：**

> 对极大的整数进行因数分解的难度决定了RSA算法是可靠的。

**唯一分解定理：**

> 对于任意一个大于1的自然数N，如果N不是质数，则N可以唯一分解为有限个质数的乘积



<hr/>
##### 24.RSA解密算法实现：

对密文进行解密有两步：

- 由 $n,d$ 得出 $p,q$
- 根据 $de\equiv1(mod\ ((p-1)*(q-1)))$ ，使用扩展欧几里得算法求出 e
- 利用 $X=C^{e}\ mod\ n $ 得到解密后的密文



**第一步：分解质因数**

```c++
p = 891234941ll;
q = 1123984201ll;
```



**第二步：扩展欧几里得算法的 e**

```c++
m = (p - 1) * (q - 1);
e = modReverse(d, m);
//Result : 823816093931522017
```

```c++
LL modReverse(LL t,LL m)
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
```



**第三步：利用公式解密**

```c++
n = p * q;
result = fastModPow(c, e, n);
//Result : 579706994112328949
```

```c++
LL fastModPow(LL a,LL b,LL mod)	//快速取模幂
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
```



<hr/>
##### 25.质因数分解(暴力)：

```c++
LL target;
cout<<"Input target number : ";
cin>>target;
	cout<<target<<" = ";
for(LL i = 1;i < target;i += 2){
	if(target % i == 0){
		cout<<i<<" * ";
		target /= i;
	}
}
cout<<target<<endl;
```



<hr/>
##### 26.对数换底公式：

在二叉树中，如果有n个结点，那么深度为: $ceil(log_{2}(n+1))$, 第 i 层有 $2^{i-1}$ 个结点。

在C++中，`log`函数其实是以 e 为底的，所以要计算以2为底的对数时，需要使用换底公式：
$$
log_{a}b=\frac{log_{c}b}{log_{c}a}
$$
因而可得：
$$
log_{2}x=\frac{lnx}{ln2}
$$
在代码中即为：

```c++
(log(x) / log(2))
```




<hr/>
##### 27.INT-INF之 0x3f3f3f3f

当我们需要设置一个int类型的最大值以用于某种功能时，首先我们能够想到使用： `0x7f ff ff ff ` (4字节int类型的最大值)，这个值为：`2147483647`。

但是使用这个INF的时候，仅仅做一点运算便会造成溢出。因为为了给INF腾出一点运算的空间：

- 能够乘2倍不溢出
- 和`0x7f ff ff ff` 一个数量级

所以使用：`0x3f 3f 3f 3f` ，也是一个十位数`1061109567`，乘2也刚好不会溢出。

**所以，可以利用 0x3f3f3f3f 来设置一个很大的量，作为界限值或者近似无穷来使用。**

> 例题：**蓝桥杯-完全二叉树的估值**
>
> 情景：要选择出最小的每一层求和，所以最开始要设置一个比所有可能的和都要小的 **Negative-INF**



<hr/
##### 28.C++优先队列的用法:

优先队列是一种数据结构，是在先进先出的基础上保证队列中的元素始终按照指定的排序规则进行排列。



**配合结构体使用的方法：**

- 建立一个结构体
- 在结构体中重载 < 运算符
  - 要实现从队列头到队列尾升序的话：return(target.age < age);
  - 要实现降序的话，return(target.age > age);
- 使用 priority_queue<Student>testQueue; 建立即可使用

```c++
#include<iostream> 
#include<queue>
#include<stdlib.h>	//这个头文件是 system("pause")的对应头文件
using namespace std;

struct Student{
	int age, grade;
	Student(int AGE, int GRADE){
		age = AGE;
		grade = GRADE;
	}
	bool operator<(const Student &target) const{
		return(target.age < age);
	}
};

int main(void){
	
	priority_queue<Student>testQueue;
	int count = 5;
	
	testQueue.push(Student(5,90));
	testQueue.push(Student(20,993));
	testQueue.push(Student(7,91));
	
	Student test = testQueue.top();
	testQueue.pop();
	Student test2 = testQueue.top();
	return(0);
}
```



**priority_queue的函数详解：**

- bool empty() const
  - 若队列为空，则返回 true
  - 若队列不为空，返回 false
  - 复杂度：常数
- size_type size() const
  - size_type 为 unsigned integral 类型
  - 返回元素的个数
- value_type& top() const
  - 返回队列头元素的 常量引用
- void pop()
  - **不返回队列头元素** :star:
  - 弹出队列头元素
- void push (const value_type& val)
  - 不返回任何参数
  - 向队列尾插入一个元素
- 还有两个函数，但是都是C++11标准的，所以这里就不写了

<hr/>
##### 29.C++设置输出精度：

输出浮点数，需要规定输出的小数位数时，使用：

- setiosflags(ios:fixed)
- setprecision(n)

这两个来设置为固定精度的输出，需要包含头文件 `#include<iomanip>`

**使用这种固定精度时，会自动四舍五入**



实例：圆的面积输出(7位小数精度限制)

```c++
#include<iostream> 
#include<queue>
#include<stdlib.h>
#include<math.h> 
#include<iomanip> 
using namespace std;

int main(void){
	int r;
	cin>>r;
	cout<<setiosflags(ios::fixed)<<setprecision(7);
	double result = (atan(1.0)*4)*r*r;
	cout<<result<<endl;
	return(0);
}
```



<hr/>
##### 30.C++如何精确表示Π

$$
\pi =arctan(1.0)*4
$$
arctan函数需要使用 math.h 头文件

```c++
atan(1.0)*4
```

<hr/>
##### 31.隐藏在题目中的陷阱

不论是简单的题目还是复杂的题目，尤其是在简单的题目中，常常会隐藏着整性溢出的陷阱，如果使用了int类型而没有检查是否会溢出，则多半会溢出，在这种情况下，**往往只能拿到一半的分数**

例如：序列求和

> 1+2+3+4+....+n
>
> int类型的范围大概到 21个亿，当n=100000时就会溢出

在看一个题目的时候，首先审视下避免溢出需要使用什么数据类型。

<hr/>
##### 32.回文的一个简单处理思路：

回文就是左右对称的数字，在求符合某种规律的回文时，可以注意：

- 方法是遍历搜索
- 找到搜索的下限值和上限值(根据题目给出的条件)
- 对于一个数字，使用%10拆开各个位，进行判断
- 符合则输出

> 例题：蓝桥杯-特殊回文

<hr/>

##### 33.bitset：二进制数组

bitset是一种类似于数组的数据结构，它的每一个元素只能是0或1，因而可以用于二进制数字的处理。

构造方法：

```c++
#include<bitset>
...
    
bitset<4> bitset1;　　//无参构造，长度为４，默认每一位为０

bitset<8> bitset2(12);　　//长度为８，二进制保存，前面用０补充

/*还可以用string和字符数组来构造bitset*/
string s = "100101";
bitset<10> bitset3(s);　　//长度为10，前面用０补充

char s2[] = "10101";
bitset<13> bitset4(s2);　　//长度为13，前面用０补充
```

使用字符串和字符数组来构造bitset时，要注意只能包含0和1，否则会错误



可以通过等号来对bitset进行赋值，例如：

```c++
bitset<5> temp(0);
temp = 8;
```



通过cout语句即可将bitset的各个位输出：

```c++
bitset<5> binaryConverter(31);
count<<binaryConverter<<endl;
```



例子：蓝桥杯01字符串

(输出从00000~11111这32个五位的字符串)

```c++
#include<iostream>
#include<bitset>
using namespace std;
int main(void){
	bitset<5> binaryConverter(0);	//声明5位的bitset
	for(int count=0;count<=31;count++){
		binaryConverter = count;
		cout<<binaryConverter<<endl;
	}
	return(0);
}
```



<hr/>

##### 34.杨辉三角：

杨辉三角的排列规则如下，只要掌握规则，生成便比较容易：

![](K:\GitWorkplace\LanQiao\笔记图片资源\杨辉三角.png)

- 对于1、2行，进行一下特别处理，直接输出全1
- 对于其他行：
  - 首位元素都输出1
  - 中间元素值为两肩上元素的和



(详细代码参考题解中的源代码)

<hr/>