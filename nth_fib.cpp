#include <iostream>

using namespace std;

long long nthfib(int n){
	long long c = 0, i = 1, j = 0;
	
	while(c<n){
		i+=j;
		j+=i;
		
		if(c == n - 1) return i;
		
		if(c == n - 2) return j; 

		c+=2;
	}

	return 0;
}

int main(){
	cout<<nthfib(100)<<endl;
	return 0;
}