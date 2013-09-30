#include <iostream>
#include <math.h>

using namespace std;

int gcd(long long a){
	if(!(a%10)) return 10;

	else if(!(a%5)) return 5;

	else if(!(a%2)) return 2;

	else return 1;
}

bool is_solitary(int n){
	long long count = 0,i = 1;

	while(1){
		count = pow(1,i) + pow(10,i) + pow(2,i) + pow(5,i);

		if(gcd(count) == 1) break;

		i++;
	}

	cout<<count<<" "<<i<<endl;

	return 1;
}

int main(){
	if(is_solitary(10)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
