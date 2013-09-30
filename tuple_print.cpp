#include <iostream>

using namespace std;

string reverse(string arg){
	string retval = "";
	
	for(int i = 0;i<arg.length();i++) retval.push_back(arg[arg.length() - i - 1]);

	return retval;
}

string strzer(int arg){
	string retval = "";
	while(arg--) retval.push_back('0');

	return retval;
}

string tobin(int arg){
	string retval = "";
	int curr = arg;
	
	while(curr>0){
		retval.push_back(curr%2 + '0');
		curr/=2;
	}

	retval = retval + strzer(3 - retval.length());

	return reverse(retval);
}

int main(){
	string str;
	cin>>str;
	char c[3];
	c[0] = str[1];
	c[1] = str[3];
	c[2] = str[5];

	for(int i = 0;i<8;i++){
		string str2 = tobin(i);
		//cout<<str2<<endl;
		for(int j = 0;j<3;j++){
			if(str2[j] - '0') str[2*j + 1] = c[j];
			else str[2*j + 1] = '*';
		}
		cout<<str<<endl;
	}

	return 0;
}
