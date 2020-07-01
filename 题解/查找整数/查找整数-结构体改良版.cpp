/*
- 程序设计题目      ：查找整数 
- 来源              ：蓝桥杯 
- 涉及知识点        ：stable_sort和sort的使用方法、二分查找算法 

- 难度评价和重点分析：本题不适合使用二分查找，因为存在重复数字时，要的是最先出现的数字，二分查找不能保证这一点 
*/

#include<iostream>
#include<algorithm>
using namespace std;

struct singleVal{
	int index;
	int val;
};

singleVal data[1000];
bool cmp(const singleVal &x, const singleVal &y);

int main(void){

	int n;
	cin>>n;
	int valTemp;
	for(int i=0;i<n;i++){	//输入数据到结构体中 
		cin>>valTemp;
		data[i].index = (i + 1);
		data[i].val = valTemp;
	}

	int target;
	cin>>target;	//输入目标搜索值 

	stable_sort(data, data + n, cmp);
	
	//二分搜索目标数值
	int left = 0;
	int right = n-1;
	int mid;
	int searchResult = -1;
	while(left <= right){
		mid = (left + right) / 2;
		if(data[mid].val == target){	//找到目标数值 
			searchResult = data[mid].index;	//返回目标数值的索引 
			break;
		}else if(data[mid].val < target){
			left = mid + 1;
		}else if(data[mid].val > target){
			right = mid - 1;
		}
		//cout<<"left:"<<left<<" ,right:"<<right<<endl;
	}
	
	cout<<searchResult<<endl;
	
	return(0);
}

bool cmp(const singleVal &x,const singleVal &y){
	return(x.val < y.val);
}

