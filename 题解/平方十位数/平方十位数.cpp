#include<iostream>
#include<string>

using namespace std;

//����ʹ�� long ����Ҳ�ᳬ����Χ 
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
		
		count = 0;	//ÿ��ѭ��ǰ����ʼ��countΪ0
		
		//�ж������Ƿ����ظ� 
		for(int temp = 0; temp < str.length(); temp++){
			if(str[temp] == str[index]){
				count++;
			}
		}
		if(count != 1){
			return(false);	//��⵽���ֲ�����Ҫ�� 
		}
		index++;
	}
	
	return(true);	//���ַ���Ҫ�� 
}
