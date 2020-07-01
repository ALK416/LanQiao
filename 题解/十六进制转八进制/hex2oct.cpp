#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
 
int main(void){
	
	int count;
	string hexInputs[10];
	string temp = "";
	string octOutput;
	cin>>count;
	for(int temp=0;temp<count;temp++){
		cin>>hexInputs[temp];
	}

	for(int i=0;i<count;i++){
		temp = "";	//每次循环开始前清除
		string hexInput = hexInputs[i];
		int length = hexInput.length();	//获取字符串的长度 
		for(int j=0;j<length;j++){
			switch(hexInput[j]){
				case '1':
					temp = temp + "0001";
					break;
				case '2':
					temp = temp + "0010";
					break;
				case '3':
					temp = temp + "0011";
					break;
				case '4':
					temp = temp + "0100";
					break;
				case '5':
					temp = temp + "0101";
					break;
				case '6':
					temp = temp + "0110";
					break;
				case '7':
					temp = temp + "0111";
					break;
				case '8':
					temp = temp + "1000";
					break;
				case '9':
					temp = temp + "1001";
					break;
				case 'A':
					temp = temp + "1010";
					break;
				case 'B':
					temp = temp + "1011";
					break;
				case 'C':
					temp = temp + "1100";
					break;	
				case 'D':
					temp = temp + "1101";
					break;
				case 'E':
					temp = temp + "1110";
					break;
				case 'F':
					temp = temp + "1111";
					break;
			}
		}
		//16进制转化为2进制之后，开始转化为8进制
		if(temp.size() % 3 == 1){
			temp.insert(0, "00");
		}else if(temp.size() % 3 == 2){
			temp.insert(0, "0");
		}
		//cout<<"当前处理的数据: "<<hexInput<<endl;
		//cout<<"2进制转化结果："<<temp<<endl;
		octOutput = "";
		for(int temp2=0;temp2<(temp.size()/3);temp2++){
			string partialConverter = temp.substr(3*temp2, 3);
			//cout<<"当前处理三位数据 : "<<partialConverter<<endl;
			//cout<<"当前三位数据转化"<<atoi(partialConverter.c_str())<<endl;
			switch(atoi(partialConverter.c_str())){
				case 0:
					octOutput = octOutput + "0"; 
					break;
				case 1:
					octOutput = octOutput + "1";
					break;
				case 10:
					octOutput = octOutput + "2"; 
					break;
				case 11:
					octOutput = octOutput + "3";
					break;
				case 100:
					octOutput = octOutput + "4";
					break;
				case 101:
					octOutput = octOutput + "5"; 
					break;
				case 110:
					octOutput = octOutput + "6";
					break;
				case 111:
					octOutput = octOutput + "7";
					break;
			}
		}
		//8进制转换完毕，检查是否有前置0
		if(octOutput[0] == '0'){
			octOutput.erase(0,1);
		}
		//输出结果
		cout<<octOutput<<endl; 
	}
	return(0);
}
