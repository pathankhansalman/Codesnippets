#include <iostream>
#include <stack>

using namespace std;

void reverse(string str, stack<char> s){
	string retval = "";

	for(int i = 0;i<str.length();i++){
		
		if(str[i] == ' '){

			while(!s.empty()){
				retval.push_back(s.top());
				s.pop();
			}

			retval.push_back(str[i]);
		}

		else s.push(str[i]);
	}

	if(s.empty()) cout<<retval<<endl;

	else{

		while(!s.empty()){
				retval.push_back(s.top());
				s.pop();
		}

		cout<<retval<<endl;
	}

}

int main(){
	string str;
	getline(cin,str);
	stack<char> s;

	reverse(str,s);

	return 0;
}
