#include <iostream>

using namespace std;

long long A[5001];

void init(){
	for(int i = 0;i<5001;i++) A[i] = 0;
}

void dp(string str){
	init();

	A[str.length()] = 1;
	if(str[str.length() - 1] != '0') A[str.length() - 1] = 1;
	for(int i = str.length() - 2;i>=0;i--){
		if(str[i] == '0'){
			A[i] = 0;
			continue;
		}
		A[i] = A[i+1];
		if((str[i] - '0')*10 + (str[i+1] - '0') <= 26 && (str[i] - '0')*10 + (str[i+1] - '0') >= 10) A[i] += A[i+2];
	}

}

int main(){
	string str;

	while(cin>>str){
		if(str == "0") break;

		dp(str);
		cout<<A[0]<<endl;
	}
}
