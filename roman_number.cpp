#include <iostream>

using namespace std;

int getcharval(char c){
	if(c == 'I') return 1;
	if(c == 'V') return 5;
	if(c == 'X') return 10;
	if(c == 'L') return 50;
	if(c == 'C') return 100;
	if(c == 'D') return 500;
	if(c == 'M') return 1000;
}

int getdecimal(string str){
	int retval = 0;
	char last = str[str.length() - 1];

	for(int i = str.length() - 1;i>=0;i--){
		char curr1 = last;
		char curr2 = str[i];
		if(getcharval(curr1)>getcharval(curr2)) retval-=getcharval(curr2);
		else{
			retval+=getcharval(curr2);
			last = str[i];
		}
	}

	return retval;
}

int main(){
	string str;
	cin>>str;
	cout<<getdecimal(str)<<endl;
	return 0;
}
