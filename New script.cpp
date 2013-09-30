#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string Genre[19];

void init(){
	Genre[0] = "Action";
	Genre[1] = "Adventure";
	Genre[2] = "Sci";
	Genre[3] = "Drama";
	Genre[4] = "Romance";
	Genre[5] = "Comedy";
	Genre[6] = "Animation";
	Genre[7] = "Biography";
	Genre[8] = "Crime";
	Genre[9] = "Documentary";
	Genre[10] = "Family";
	Genre[11] = "Fantasy";
	Genre[12] = "History";
	Genre[13] = "Horror";
	Genre[14] = "Music";
	Genre[15] = "Mystery";
	Genre[16] = "Sport";
	Genre[17] = "Thriller";
	Genre[18] = "War";
}

int counts(string arg1, string arg2){
	int retval = 0;
	int i = 0;

	if((i=arg1.find(arg2)) != string::npos){
		retval++;
		retval += counts(arg1.substr(i + arg2.length()),arg2);
	}

	return retval;
}

string recommendation(string arg){
	string retval = "";
	int countnow = 0,count = 0,maxin = 0, max = 5;
	vector<string> retvals;

	for(int i = 0;i<19;i++){
		if((countnow = counts(arg,Genre[i])) >= count){
			maxin = i;
			count = countnow;
			if(countnow >= 5) retvals.push_back(Genre[maxin]);
		}
	}

	if(retvals.size() > 1){
		for(int i = 0;i<retvals.size();i++) cout<<retvals[i]<<endl;
	}

	else{
		if(count<=3) retval = "fuck you";
		else retval = Genre[maxin];
	}

	return retval;
}

int main(){
	init();
	ifstream myfile("fb data mohit.txt");
	string arg = "", arg2;

	while(getline(myfile,arg2)) arg = arg + arg2;

	cout<<recommendation(arg)<<endl;

	return 0;
}