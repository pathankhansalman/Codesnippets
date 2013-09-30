#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> digits(int num){
	vector<int> retval;
	
	while(num>0){
		retval.push_back(num%10);
		num/=10;
	}

	return retval;
}

set<int> s;

int oneornot(int num){
	vector<int>v = digits(num);
	int square = 0;

	for(int i = 0;i<v.size();i++) square+=(v[i]*v[i]);

	if(square == 1) return 1;

	if(s.count(square)) return 0;

	s.insert(square);

	return oneornot(square);
}

int main(){
	int num;
	cin>>num;
	cout<<oneornot(num)<<endl;

	return 0;
}
