#include <iostream>
#include <string>

using namespace std;

int table[1000][1000];
int start = 0;
int maxlength = 1;

void init(){
	for(int i = 0;i<1000;i++){
		
		for(int j = 0;j<1000;j++) table[i][j] = 0;
	}
}

void dp(string str){
	int len = str.length();

	for(int i = 0;i<len;i++){
		table[i][i] = 1;
		
		if(i<len - 1 && str[i] == str[i+1]){
			table[i][i+1] = 1;
			start = i;
			maxlength = 2;
		}
	}

	for(int i = 3;i<=len;i++){
		
		for(int j = 0;j<len;j++){
			int k = j + i - 1;

			if(k<len){
				if(table[j + 1][k - 1] && str[j] == str[k]){
					table[j][k] = 1;
					
					if(i>maxlength){
						maxlength = i;
						start = j;
					}
				}
			}
		}
	}
}

int main(){
	string str;
	cin>>str;

	init();
	dp(str);

	cout<<str.substr(start,maxlength)<<endl;

	return 0;
}
