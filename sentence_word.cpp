#include <iostream>
#include <set>
#include <string>

using namespace std;

int f[1000];

void init(){
	f[0] = 0;

	for(int i = 1;i<1000;i++) f[i] = -1;
}

void dp(string str, set<string> s){

	for(int i = 1;i<=str.length();i++){

		for(int j = 0;j<i;j++){
			
			if(f[j] != -1){
				string pot_word = str.substr(j,i-j);
				
				if(s.count(pot_word)){
					f[i] = j;
					break;
				}
			}
		}
	}
}

void print(string str, int f[]){
	if(str != ""){
		int len = str.length();
		cout<<f[len]<<endl;
		
		print(str.substr(0,f[len]),f);

		string word = str.substr(f[len],len - f[len]);

		if(!f[len]) cout<<word;

		else cout<<' '<<word;
	}
}

int main(){
	string str;
	cin>>str;
	set<string> words;

	words.insert("Back");
	words.insert("in");
	words.insert("Black");

	dp(str,words);

	if(f[str.size() - 1] == -1) cout<<"no answer"<<endl;

	else print(str,f);

	return 0;
}
