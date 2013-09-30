#include <iostream>

using namespace std;

int A[1000001];

void init(){
	for(int i = 0;i<=1000000;i++) A[i] = 0;
}

void dp(){
	A[0] = 0;
	A[1] = 1;

	for(int i = 1;i<=1000000;i++){
		int j = 2*i;
		if(j<=1000000){
			if(!A[j]){
				A[j] = A[i] + 1;
			}
		}

		if(i%2 == 0 && (i-1)%3 == 0){
			j = (i - 1)/3;
			if(!A[j] && j){
				A[j] = A[i] + 1;
			}
		}
	}
}

int main(){
	init();
	dp();
	int a,b;
	while(cin>>a>>b){
		int max = 0;
		for(int i = a;i<=b;i++){
			cout<<A[i]<<endl;
			if(A[i]>max) max = A[i];
		}
		cout<<max<<endl;
	}
	return 0;
}
