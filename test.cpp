#include <iostream>
#include <string>

using namespace std;

int main(){
	string str1 = "\"hello,good\"";
	string str2 = "llo";
	if(str1.find(str2)!=string::npos) cout<<str2<<endl;
	return 0;
}