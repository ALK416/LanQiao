#include<iostream>
#include<string>

using namespace std;

//这里使用 long 类型也会超出范围 
bool accept(long long TESTNUM);

int main(void){

	long long testNum = 99999;
	while(!accept(testNum * testNum)){
		testNum--;
	}
	
	cout << testNum * testNum << endl;
	cout << testNum << endl;
	return(0);
}

bool accept(long long TESTNUM){
	
	string str = to_string(TESTNUM);
	int index = 0;
	int count = 0;
	while(str[index] != '\0'){
		
		count = 0;	//每次循环前都初始化count为0
		
		//判断数字是否有重复 
		for(int temp = 0; temp < str.length(); temp++){
			if(str[temp] == str[index]){
				count++;
			}
		}
		if(count != 1){
			return(false);	//检测到数字不符合要求 
		}
		index++;
	}
	
	return(true);	//数字符合要求 
}
