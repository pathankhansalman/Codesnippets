#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<char,int> M;

void init(){
	char c = 'a';
	int ind = (int)c;
	for(int i = 0;i<26;i++){
		M.insert(pair<char,int>((char)(ind + i), 0));
	}
}

char second_most(string str){
	char c = ' ';
	if(str == "") return c;
	map<char,int>::iterator it;
	
	for(int i = 0;i<str.length();i++){
		it = M.find(str[i]);
		(*it).second++;
	}

	map<int,vector<char> > M2;
	vector<char> v;

	for(it = M.begin();it!=M.end();it++) M2.insert(pair<int,vector<char> >((*it).second,v));

	map<int,vector<char> >::iterator it2;

	for(it2 = M2.begin();it2!=M2.end();it2++){
		int val = (*it2).first;
		
		for(it = M.begin();it!=M.end();it++){
			if((*it).second == val) v.push_back((*it).first);
		}

		(*it2).second = v;
		v.clear();
	}

	it2 = M2.end();
	it2--;
	if(it2!=M2.begin()) it2--;
	return (*it2).second[0];
}

int main(){
	init();
	string str;
	cin>>str;
	cout<<second_most(str)<<endl;
	return 0;
}
