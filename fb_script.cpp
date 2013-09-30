#include <iostream>
#include <regex>
#include <fstream>

using namespace std;

// Start of movies
class movie{
	string name, likes, genre, starring, directed_by, id;
};

class movies_cell{
	movie val;
	movie_cell* next;
};

class movies_list{
	movies_cell* head;

	void add_movie(movie m){
		movies_cell* curr = head;
		while(curr!=null) curr = curr->next;
		curr = new movies_cell;
		curr->val = m;
	}
};
// End of movies
// Start of friends
class friends{
	string id;
	movies_list mv;
};

class friends_cell{
	friends val;
	friends_cell* next;
};

class friends_list{
	friends_cell* head;

	void add_friend(friends f){
		friends_cell* curr = head;
		while(curr!=null) curr = curr->next;
		curr = new friends_cell;
		curr->val = f;
	}
};
// End of friends
// Start of comments
class comment{
	string name;
};

class comment_cell{
	comment val;
	comment_cell* next;
};

class comment_list{
	comment_cell* head;

	void add_comments(comment c){
		comment_cell* curr = head;
		while(curr!=null) curr = curr->next;
		curr = new comment_cell;
		curr->val = c;
	}
};
// End of comments
// Start of likes
class like{
	string name;
};

class like_cell{
	like val;
	like_cell* next;
};

class likes_list{
	like_cell* head;

	void add_like(like l){
		like_cell* curr = head;
		while(curr!=null) curr = curr->next;
		curr = new like_cell;
		curr->val = l;
	}
};
// End of likes
// Start of post
class post{
	string id;
	string created_time;
	likes_list* likes;
	comments_list* comments;
};

class post_cell{
	post val;
	post_cell* next;
};

class post_list{
	post_cell* head;

	void add_post(post p){
		post_cell* curr = head;
		while(curr!=null) curr = curr->next;
		curr = new post_cell;
		curr->val = p;
	}
};
// End of post
int main(){
	string arg = "";
	ifstream file("myfile");
	string temp;
	smatch match;

	while(getline(file,temp)) arg = arg+temp;

	regex rgx = (".*\"friends\": {(\\w+)}");

	if(regex_search(arg.begin(), arg.end(), match, rgx)){
		string new1 = match[1];
		rgx = (".*\"data\": [(\\w+)]");
		smatch match1;
		if(regex_search(new1.begin(),new1.end(), match1,rgx)){
			string new2 = match1[1];
		}
	}

	return 0;
}