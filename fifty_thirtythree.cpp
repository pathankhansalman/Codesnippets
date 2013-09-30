#include <iostream>
#include <stack>

using namespace std;

int return_fifty(int A[],int size){
	stack<int> s1,s2;

	for(int i = 0;i<size;i++){
		
		if(!(s1.empty() || s2.empty())){
			s1.pop();
			s2.pop();
		}

		if(s1.empty() || s1.top() == A[i]) s1.push(A[i]);
		
		else if(s2.empty() || s2.top() == A[i]) s2.push(A[i]);
	}

	if(s1.empty() && s2.empty()) return -1;

	int a = s1.top();
	int b = -1;

	if(!s2.empty()) b = s2.top();

	int count = 0;

	for(int i = 0;i<size;i++) if(A[i] == a) count++;

	if(count > size/2) return a;

	count = 0;

	if(b!=-1) for(int i = 0;i<size;i++) if(A[i] == b) count++;

	if(count > size/2) return b;

	return -1; 
}

int return_thirty(int A[],int size){
	stack<int> s1,s2,s3;

	for(int i = 0;i<size;i++){
		
		if(!(s1.empty() || s2.empty() || s3.empty())){
			s1.pop();
			s2.pop();
			s3.pop();
		}

		if(s1.empty() || s1.top() == A[i]) s1.push(A[i]);
		
		else if(s2.empty() || s2.top() == A[i]) s2.push(A[i]);

		else if(s3.empty() || s3.top() == A[i]) s3.push(A[i]);
	}

	if(s1.empty() && s2.empty() && s3.empty()) return -1;

	int a = s1.top();
	int b = -1;
	int c = -1;

	if(!s2.empty()) b = s2.top();
	if(!s3.empty()) c = s3.top();

	int count = 0;

	for(int i = 0;i<size;i++) if(A[i] == a) count++;

	if(count > size/3) return a;

	count = 0;

	if(b!=-1) for(int i = 0;i<size;i++) if(A[i] == b) count++;

	if(count > size/3) return b;

	count = 0;

	if(c!=-1) for(int i = 0;i<size;i++) if(A[i] == c) count++;

	if(count > size/3) return c;

	return -1;
}

int main(){
	int N;
	cin>>N;
	int A[N];

	for(int i = 0;i<N;i++) cin>>A[i];

	cout<<return_thirty(A,N)<<endl;
	
	cout<<return_fifty(A,N)<<endl;

	return 0;
}
