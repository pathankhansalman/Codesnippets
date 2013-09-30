#include <iostream>
#include <vector>

using namespace std;

int ispalin[1000][1000];

void init(){
	for(int i = 0;i<1000;i++){
		for(int j = 0;j<1000;j++) ispalin[i][j] = 0;
	}
}

void dp(string str){
	int len = str.length();

	for(int i = 0;i<len;i++){
		ispalin[i][i] = 1;
		if(i < len - 1 && str[i] == str[i+1]) ispalin[i][i+1] = 1;
	}

	for(int i = 3;i<=len;i++){
		for(int j = 0;j<len;j++){
			int k = j+i - 1;
			if(k<len && (str[j] == str[k] && ispalin[j+1][k-1])){
				ispalin[j][k] = 1;
			}
		}
	} 
}

vector<vector<string> > allpalins(string str,int start){
	int len = str.length();
	vector<vector<string> > retval,retval_h2;
	if(start>=len) return retval;

	vector<string> retval_h,retval_h3;

	for(int i = start;i<str.length();i++){
		if(ispalin[start][i]){
			retval_h.push_back(str.substr(start,i-start+1));
			retval_h2 = allpalins(str,i+1);
			for(int j = 0;j<retval_h2.size();j++){
				retval_h3 = retval_h;
				for(int k = 0;k<retval_h2[j].size();k++) retval_h3.push_back(retval_h2[j][k]);
				retval.push_back(retval_h3);
			}
		}
	}

	return retval;
}

int main(){
	string str;
	cin>>str;
	init();
	dp(str);
	int siz = 0;
	//cout<<ispalin[0][str.length() - 1]<<endl;
	vector<vector<string> > result = allpalins(str,0);
	int min = 10000000;

	for(int i = 0;i<result.size();i++){
		
		if(siz = result[i].size() < min) min = siz;
		
		for(int j = 0;j<siz;j++){
			cout<<result[i][j]<<" ";
		}
		
		cout<<endl;
	}

	return 0;
}