/*
- ���������Ŀ      ��������� 
- ��Դ              �����ű�������ϰ 
- �漰֪ʶ��        ��������ǵĹ��� 

- �Ѷ����ۺ��ص������һ�㣬���չ��ɺܺ��� 
*/

#include<iostream>
#include<cstring>

using namespace std;

int main(void){

	int result[34][34];
	memset(result, 0, sizeof(result));
	int count = 0;
	cin>>count;	//����������ǵĲ���
	
	for(int i=0;i<count;i++){	//�������� 
	
		if(i==0){	//���⴦���һ�к͵ڶ��� 
			result[i][0] = 1;
			continue;
		}else if(i==1){
			result[i][0] = 1;
			result[i][1] = 1;
			continue;
		}	
		
		for(int j=0;j<=i;j++){	//һ���е����� 
		
			//���������м���� 
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

