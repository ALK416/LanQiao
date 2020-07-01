#include<iostream>
using namespace std;

int main(void){
	
	int resultContainer[4] = {1, 1, 1, 3};
	int temp1, temp2, temp3;
	long long temp4;
	
	for(int count = 1;count <= 20190320;count++){
		temp1 = resultContainer[1];
		temp2 = resultContainer[2];
		temp3 = resultContainer[3];
		temp4 = (temp1 + temp2 + temp3) % 10000;
		resultContainer[0] = temp1;
		resultContainer[1] = temp2;
		resultContainer[2] = temp3;
		resultContainer[3] = temp4;	
	}
	cout << "The result is : " << resultContainer[3];
} 

/*
²âÊÔÓï¾ä£º 
cout << resultContainer[0] << " " << resultContainer[1] << " " << resultContainer[3] << " " << resultContainer[3] << endl;


*/
