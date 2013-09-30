#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int A[1000001];
vector<int> primes;

void init(){
	for(long long i = 0;i<1000001;i++) A[i] = 0;

	A[0] = A[1] = 1;

	for(long long i = 2;i<1000001;i++) if(!A[i]) for(long long j = i*i;j<1000001;j+=i) A[j] = 1;

	for(int i = 0;i<1000001;i++) if(!A[i]) primes.push_back(i);
}

int main(){
	int A,B,j = 1;
	init();
	
	while(cin>>A>>B){
		if(A == 0 && B == 0) break;
		int num = 0,count = 0,count1,count2;
		for(int i = 0;i<primes.size();i++){
			count1 = count2 = 0;
			if(A == 1 && B == 1) break;
			int factor = primes[i];
			if(A%factor && B%factor) continue;
			//cout<<primes[i]<<A%factor<<B%factor<<endl;
			while(!(A%factor)){
				if(!count1) num++;
				count1++;
				A/=factor;
			}
			while(!(B%factor)){
				if(!count1 && !count2) num++;
				count2++;
				B/=factor;
			}
			//cout<<count1<<" "<<count2<<endl;
			count+=fabs(count1 - count2);
		}
		cout<<j<<". "<<num<<":"<<count<<endl;
		j++;
	}

	return 0;
}