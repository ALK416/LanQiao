/*
- ���������Ŀ      ���������� 
- ��Դ              �����ű� 
- �漰֪ʶ��        ��stable_sort��sort��ʹ�÷��������ֲ����㷨 

- �Ѷ����ۺ��ص���������ⲻ�ʺ�ʹ�ö��ֲ��ң���Ϊ�����ظ�����ʱ��Ҫ�������ȳ��ֵ����֣����ֲ��Ҳ��ܱ�֤��һ�� 
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
	for(int i=0;i<n;i++){	//�������ݵ��ṹ���� 
		cin>>valTemp;
		data[i].index = (i + 1);
		data[i].val = valTemp;
	}

	int target;
	cin>>target;	//����Ŀ������ֵ 

	stable_sort(data, data + n, cmp);
	
	//��������Ŀ����ֵ
	int left = 0;
	int right = n-1;
	int mid;
	int searchResult = -1;
	while(left <= right){
		mid = (left + right) / 2;
		if(data[mid].val == target){	//�ҵ�Ŀ����ֵ 
			searchResult = data[mid].index;	//����Ŀ����ֵ������ 
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

