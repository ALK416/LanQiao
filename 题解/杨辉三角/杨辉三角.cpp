/*
- 程序设计题目      ：杨辉三角 
- 来源              ：蓝桥杯基础练习 
- 涉及知识点        ：杨辉三角的规律 

- 难度评价和重点分析：一般，掌握规律很好做 
*/

#include<iostream>
#include<cstring>

using namespace std;

int main(void){

	int result[34][34];
	memset(result, 0, sizeof(result));
	int count = 0;
	cin>>count;	//输入杨辉三角的层数
	
	for(int i=0;i<count;i++){	//逐行生成 
	
		if(i==0){	//特殊处理第一行和第二行 
			result[i][0] = 1;
			continue;
		}else if(i==1){
			result[i][0] = 1;
			result[i][1] = 1;
			continue;
		}	
		
		for(int j=0;j<=i;j++){	//一行中的数据 
		
			//正常处理中间的行 
			if(j==0){
				result[i][j] = 1;
			}else if(j==i){
				result[i][j] = 1;
			}else{
				result[i][j] = result[i-1][j-1] + result[i-1][j];
			}
			
		}
		
	}
	
	for(int i=0;i<count;i++){
		for(int j=0;j<=i;j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	} 

	return(0);
}

