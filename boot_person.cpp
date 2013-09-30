#include <iostream>

using namespace std;

int left1[10],left2[10],right1[10],right2[10],pivoted[10],start1,end1;

class Boot{

public:
	
	int size;
};

class Person{

public:
	
	int size;

	int fit(Boot b){
		if(size == b.size) return 0;
		
		else if(size < b.size) return -1;
		
		else return 1;
	}
};

void init(){
	
	for(int i = 0;i<10;i++){
		left1[i] = -1;
		right1[i] = -1;
		left2[i] = -1;
		right2[i] = -1;
		pivoted[i] = 0;
	}
}

void swap(Boot boot[],int i,int j){
	Boot temp = boot[i];
	boot[i] = boot[j];
	boot[j] = temp;
}

int quicksort(Boot boot[],Person person[],int start,int end,int curr,int max){
	if(curr > max) return 0; 

	if(pivoted[start]){
		
		if(person[curr].fit(boot[start]) < 0) return quicksort(boot,person,left1[start],left2[start],curr,max);
		
		else if(person[curr].fit(boot[start]) > 0) return quicksort(boot,person,right1[start],right2[start],curr,max);

		else return quicksort(boot,person,start1,end1,curr+1,max);
	}

	int ind = 0;

	for(int i = start;i<=end;i++){
		
		if(!person[curr].fit(boot[i])){
			pivoted[i] = 1;
			ind = i;
			break;
		}
	}

	if(ind) swap(boot,curr,ind);

	int j = curr + 1,flag = 0,flag2 = 0;
	left1[curr] = j,right2[curr] = end;

	for(int i = curr + 1;i<=end;i++){
		
		if(!flag && person[curr].fit(boot[i]) < 0){
			swap(boot,j,i);
			j++;
		}
		
		else if(flag && person[curr].fit(boot[i]) > 0){
			swap(boot,j,i);
			j++;
		}
		
		if(flag && !flag2){
			left2[curr] = i;
			right1[curr] = i+1;
			flag2 = 1;
			j = curr + 1;
			i = curr;
			continue;
		}
	}

	return quicksort(boot,person,start1,end1,curr+1,max);
}

int main(){
	Boot boot[10];
	Person person[10];
	start1 = 0;
	end1 = 9;
	init();

	for(int i = 0;i<10;i++){
		boot[i].size = i;
		person[i].size = 9 - i;
	}

	cout<<"Start:"<<endl;

	for(int i = 0;i<10;i++) cout<<boot[i].size<<" ";

	cout<<endl;

	for(int i = 0;i<10;i++) cout<<person[i].size<<" ";

	cout<<endl;

	quicksort(boot,person,0,9,0,9);

	cout<<"End:"<<endl;

	for(int i = 0;i<10;i++) cout<<boot[i].size<<" ";

	cout<<endl;

	for(int i = 0;i<10;i++) cout<<person[i].size<<" ";

	cout<<endl;

	return 0;
}
