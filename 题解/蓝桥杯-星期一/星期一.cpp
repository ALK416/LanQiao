#include<iostream> 
using namespace std;

bool isLeapYear(int YEAR);

int main(void){
	
	int count = 0;
	for(int year = 1901;year <= 2000;year++){
		if(isLeapYear(year)){
			count += 366;
		}else{
			count += 365;
		}
	}
	cout << (count / 7) << endl;
	return(0);
}

bool isLeapYear(int YEAR){
	if((YEAR % 4 == 0 && YEAR % 100 != 0) || YEAR % 400 == 0){
		return(true);		
	}else{
		return(false);
	}
}
