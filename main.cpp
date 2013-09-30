#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctype.h>
#include <algorithm>
#define DEBUG 1

using namespace std;

map<string,int> M;
multimap<int,string> M2;

vector<string> mytokenize(string arg, char c){
	vector<string> retval;
	string str="";

	for(int i = 0;i<arg.length();i++){
		if(arg[i] != c) str.push_back(arg[i]);
		if(arg[i] == c){
			//cout<<str<<endl;
			retval.push_back(str);
			str = "";
		}
	}

	//cout<<str<<endl;
	retval.push_back(str);
	//cout<<retval.size()<<endl;
	return retval;
}

string filter(string arg){
	string retval = arg;
	if(retval[0] == ' '){
		retval = retval.substr(1);
		retval = filter(retval);
	}
	int len = retval.length();
	if(retval[len - 1] == ' '){
		retval = retval.substr(0,len - 1);
		retval = filter(retval);
	}
	
	return retval;
}

string convert_tolower(string arg){
	string retval = "";

	for(int i = 0;i<arg.length();i++){
		retval.push_back(tolower(arg[i]));
	}

	return retval;
}

int main(){

	// Start of close friends list
	ifstream myfilenow("friendlists.txt");
	string id,temp = "",user_id = "722088650\"";
	int is_close = 0,is_data = 0;
	vector<string> v1;

	while(getline(myfilenow,temp)){
		//cout<<"here"<<endl;
		if(temp.find("\"Close Friends\"") != string::npos){
			is_close = 1;
			//cout<<"here"<<endl;
		}
		if(is_close && temp.find("\"data\"")!=string::npos) is_data = 1;
		if(is_data && temp.find("],")!=string::npos) is_data = 0;

		if(is_data && temp.find("\"id\":") != string::npos){
			temp = filter(temp);

			int len = temp.length();
			if(temp[len - 1] == ',') temp = temp.substr(0,len - 1);
			len = temp.length();
			//cout<<"here"<<endl;
			temp = temp.substr(0,len - 1);

			id = temp.substr(7);
			len = id.length();
			if(id!=user_id){
				//cout<<id<<endl;
				v1.push_back(id.substr(0,len - 3));
			}
		}
	}
	// End of close friends list

	// Start of likes and comments
	ifstream myfile("fma.txt");
	int is_application = 0,is_comment = 0;
	is_data = 0;

	while(getline(myfile,temp)){
		if(temp.find("\"application\":") != string::npos) is_application = 1;
		if(is_application && temp.find("},")!=string::npos) is_application = 0; 
		if(temp.find("\"comments\":")!=string::npos) is_comment = 3;
		if(temp.find("\"data\":")!=string::npos) is_data = 1;
		if(is_data && temp.find("],")!=string::npos) is_data = 0;
		if(is_comment && temp.find("},")!=string::npos && !is_data) is_comment = 0;
		if(temp.find("\"id\": \"") != string::npos){
			temp = filter(temp);
			//if(DEBUG) cout<<temp<<endl;
			int len = temp.length();
			if(temp[len - 1] == ',') temp = temp.substr(0,len - 1);
			len = temp.length();

			temp = temp.substr(0,len - 1);

			id = temp.substr(7);

			if(M.find(id) == M.end() && id!=user_id && !is_application) M.insert(pair<string,int>(id,1+is_comment));

			else if(id!=user_id && !is_application){
				M[id]+=(1+is_comment);
			}
		}
	}

	ifstream myfileprofile("profilepics.txt");
	is_application = 0,is_comment = 0;
	int is_like = 0;
	int is_profile = 0;
	is_data = 0;

	while(getline(myfileprofile,temp)){
		if(temp.find("\"Profile Pictures\"") != string::npos) is_profile = 1;
		if(temp.find("\"application\":") != string::npos) is_application = 1;
		if(is_application && temp.find("},")!=string::npos) is_application = 0; 
		if(temp.find("\"likees\":") != string::npos) is_like = 1;
		if(is_like && temp.find("},")!=string::npos && !is_data) is_like = 0;
		if(temp.find("\"comments\":")!=string::npos) is_comment = 3;
		if((is_like || is_comment) && temp.find("\"data\":")!=string::npos) is_data = 1;
		if(is_data && temp.find("],")!=string::npos) is_data = 0;
		if(is_comment && temp.find("},")!=string::npos && !is_data) is_comment = 0;
		if(is_data && temp.find("\"id\": \"") != string::npos){
			temp = filter(temp);
			//if(DEBUG) cout<<temp<<endl;
			int len = temp.length();
			if(temp[len - 1] == ',') temp = temp.substr(0,len - 1);
			len = temp.length();

			temp = temp.substr(0,len - 1);

			id = temp.substr(7);

			if(M.find(id) == M.end() && id!=user_id && !is_application) M.insert(pair<string,int>(id,1+is_comment));

			else if(id!=user_id && !is_application){
				M[id]+=(1+is_comment);
			}
		}
	}

	map<string,int>::iterator it;
	int size = 0;

	for(it = M.begin(); it != M.end(); it++){
		//cout<<(*it).first<<endl;
		M2.insert(pair<int,string>((*it).second,(*it).first));
		size++;	
	} 

	size-=10;
	M.clear();
	vector<string> v;
	map<int,string>::iterator it2 = M2.begin();

	while(size--) it2++;

	while(it2 != M2.end()){
		//cout<<(*it2).second<<endl;
		v.push_back((*it2).second);
		it2++;
	}

	M2.clear();
	vector<string> v2;

	for(int i = v.size() - 1; i >= 0; i--){
		v2.push_back(v[i].substr(0,v[i].length() - 1));
	}

	v.clear();
	// End of likes and comments
	
	// Start of integration 1
	vector<string>::iterator vec_it;

	for(int i = 0;i<v1.size();i++){
		if((vec_it = find(v2.begin(),v2.end(),v1[i])) != v2.end()) v2.erase(vec_it);
	}

	for(int i = 0;i<v2.size();i++){
		v1.push_back(v2[i]);
	}

	v2.clear();
	// End of intergration 1
	//for(int i = 0;i<v1.size();i++) cout<<v1[i]<<endl;

	ifstream myfilegenre("genrecodes.txt");
	
	vector<string> genres;
	//vector<string> tokens;
	//map<string,string> M4;

	while(getline(myfilegenre,temp)){
		//tokens = mytokenize(temp,' ');
		temp = filter(temp);
		genres.push_back(temp);
	}

	//DEBUG
	//map<string,string>::iterator it7 = M4.begin();
	/*while(it7!=M4.end()){
		cout<<(*it7).first<<" "<<(*it7).second<<endl;
		it7++;
	}*/
	//DEBUG

	ifstream myfilemap("friends.txt");
	id = "";
	map<string,string> M3;
	string name = "";

	while(getline(myfilemap,temp)){
		if(temp.find("\"id\": \"")!=string::npos){
			temp = filter(temp);
			temp = temp.substr(0,temp.length() - 3);
			id = temp.substr(7);
		}
		if(temp.find("\"name\": \"") != string::npos){
			temp = filter(temp);
			temp = temp.substr(0,temp.length() - 2);
			name = temp.substr(9);
		}
		M3.insert(pair<string,string>(id,name));
	}

	ifstream myfilemovgen("movie_genreCode.txt");
	map<string,vector<string> > M5;
	while(getline(myfilemovgen,temp)){
		temp = filter(temp);
		temp = temp.substr(1);
		vector<string> v3;
		int i = 0;
		for(i = 0;i<temp.length();i++){
			if(temp[i] == '$') break;
		}
		string genre;
		name = temp.substr(0,i);
		genre = temp.substr(i+1);
		//cout<<name<<" "<<genre<<endl;
		v3 = mytokenize(genre,',');
		/*cout<<v3.size()<<endl;
		vector<string>::iterator it4;
		it7 = M4.begin();
		for(it4 = v3.begin();it4!=v3.end();it4++){
			string str = (*it4);
			str = filter(str); 
			//cout<<str<<endl;
			it7 = M4.find(str);
			if(it7!=M4.end()) v3.push_back((*it7).second);
			if(it7!=M4.end()) cout<<(*it7).second<<endl;
		}
		int size = v3.size();
		//cout<<size<<endl;
		size/=2;
		//cout<<"here"<<endl;
		v3.erase(v3.begin(),v3.begin()+size);*/
		M5.insert(pair<string,vector<string> >(name,v3));
		//v3.clear();
	}

	map<string,int> M6;
	map<string,int>::iterator it8;

	ifstream myfilefrmov("MoviesFriendsRaw.txt");
	map<string,string>::iterator it3;
	while(getline(myfilefrmov,temp)){
		if(temp.find("\"name\": \"")!=string::npos){
			temp = filter(temp);
			temp = temp.substr(0,temp.length() - 2);
			name = temp.substr(9);
		}

		if(temp.find("\"movies\": \"") != string::npos){
			for(it3 = M3.begin(); it3!=M3.end(); it3++){
				if((*it3).second == name){
					if(find(v1.begin(), v1.end(), (*it3).first) != v1.end()){
						temp = filter(temp);
						temp = temp.substr(0,temp.length() - 2);
						vector<string> mov_list = mytokenize(temp,',');
						for(int i = 0;i<mov_list.size();i++){
							vector<string> mov_gen = M5[mov_list[i]];
							for(int j = 0;j<mov_gen.size();j++){
								if((it8 = M6.find(mov_gen[j]))!= M6.end()) (*it8).second++;
								else M6.insert(pair<string,int>(mov_gen[j],1));
							}
						}
					}
				}
			}
		}
	}

	ifstream myfilemymov("fbdatamohit");
	cout<<genres.size()<<endl;
	int flag = 0;
	while(getline(myfilemymov,temp)){
		if(temp.find("\"genre\"")!=string::npos){
			temp = filter(temp);
			for(int i = 0;i<genres.size();i++){
				if(!i && !flag){
					cout<<temp<<endl;
					cout<<genres[i]<<endl;
					flag = 1;
				}
				if(temp.find(genres[i])!=string::npos){
					cout<<"here: "<<genres[i]<<endl;
					if((it8 = M6.find(genres[i])) != M6.end()) (*it8).second++;
					else M6.insert(pair<string,int>(genres[i],1));
				}
			}
		}
	}
	cout<<M6.size()<<endl;
	ifstream myfilemywmov("videoswatched.txt");

	while(getline(myfilemywmov,temp)){
		if(temp.find("\"title\": \"")){
			temp = filter(temp);
			temp = temp.substr(0,temp.length() - 2);
			vector<string> mov_gen_2 = M5[temp];
			for(int i = 0;i<mov_gen_2.size();i++){
				if((it8 = M6.find(mov_gen_2[i]))!=M6.end()) (*it8).second++;
				else M6.insert(pair<string,int>(mov_gen_2[i],1));
			}
		}
	}

	multimap<int,string> M7;
	map<string,int>::iterator it5;
	size = 0;

	for(it5 = M6.begin();it5!=M6.end();it5++){
		M7.insert(pair<int,string>((*it5).second,(*it5).first));
		size++;
	}

	flag = 0;
	if(size>5){
		flag = 1;
		size-=5;
	}
	multimap<int,string>::iterator it6 = M7.begin();
	vector<string> v4;
	while(flag && size--) it6++;
	//cout<<"here"<<endl;
	while(it6!=M7.end()){
		v4.push_back((*it6).second);
		it6++;
	}

	for(int i = 0;i<v4.size();i++) cout<<v4[i]<<endl;

	return 0;
}
