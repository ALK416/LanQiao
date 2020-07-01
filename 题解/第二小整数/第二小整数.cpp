#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void){
	int runCount = 0;
	cin >> runCount;
	int data[10];
	
	while( runCount-- ){
		memset(data, 0, sizeof(data));
		int readCount;
		cin >> readCount;
		
		for(int temp = 0; temp < readCount; temp++){
			cin >> data[temp];
		}
		sort(data, data + readCount);
		cout << data[1] << endl;
	}
	
}
