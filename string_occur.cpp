#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>

using namespace std;

vector<string> tokenizer(string str){
	vector<string> retval;
	string curr = "";
	int flag = 0;
	//cout<<str<<":"<<str.length()<<endl;
	for(int i = 0;i<str.length();i++){
		//cout<<str[i]<<endl;
		if(!flag && str[i] == ' '){
			flag = 1;
			retval.push_back(curr);
			//cout<<curr<<endl;
			curr = "";
		}

		else{
			flag = 0;
			curr.push_back(str[i]);
		}

	}

	if(curr!="") retval.push_back(curr);
	//cout<<retval.size()<<endl;
	return retval;
}

int flag = 0;

bool valid(string str){
	
	if(!flag && str[0] == '0') return 0;
	
	flag = 1;
	char c = '0';
	
	if(str[0] - c > 9) return 0;
	
	if(str.length() == 1) return 1;
	
	return valid(str.substr(1));
}

int main(){
	string arg;
	getline(cin,arg);
	vector<string> v = tokenizer(arg);
	map<int,int> m;
	map<int,int>::iterator it;
	//cout<<v.size()<<endl;
	for(int i = 0;i<v.size();i++){
		
		if(valid(v[i])){
			int M = atoi(v[i].c_str());
			it = m.find(M);
			
			if(it != m.end()) (*it).second++;
			
			else m.insert(pair<int,int>(M,1));
		}
	}

	for(it = m.begin();it!=m.end();it++) cout<<(*it).first<<":"<<(*it).second<<endl;

	return 0;
}
