#include <iostream>
#include <map>
#include <fstream>

using namespace std;

map<string,int> M;
map<int,string> M2;

int main(){
	string id = "",user_id = "";
	ifstream myfile("fma.txt");
	string temp;
	smatch match;
	regex rgx = ("\"id\": \"\\w+\"");

	while(getline(myfile,temp)){
		if(regex_search(temp.begin(),temp.end(),match,rgx)){
			id = match[1];
			if(M.find(id) != map::end) M[id]++;
			else{
				M.insert(pair<string,int>(id,1));
			}
		}
	}

	map::iterator it = M.begin();
	int size = 0;

	for(it = M.begin();it!=M.end();it++){
		M2.insert(pair<int,string>(M[*it],(*it)));
		size++;
	}

	it = M2.begin();M.clear();
	vector<string> v;

	while(size--) it++;

	while(it!=M2.end()) v.push_back(M2[*it]);

	M2.clear();

	for(int i = v.size()-1;i>=0;i--) cout<<v[i]<<endl;

	return 0;
}