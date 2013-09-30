#include <iostream>

using namespace std;

int bin_search(int* A,int size,int ele){
	if(size == 1 && A[0] != ele) return 0;
	if(A[size - 1] < ele) return 0;
	if(A[0] > ele) return 0;
	int mid = size/2;
	if(A[mid] == ele) return 1;
	else if(A[mid] > ele) return bin_search(A, mid, ele);
	else return bin_search(A + mid + 1,size - mid - 1,ele);
}

int main(){
	int N;
	cin>>N;
	int A[N];
	int curr = -10000000,flag = 0;
	
	for(int i = 0;i<N;i++){
		cin>>A[i];
		if(A[i] < curr) flag = i;
		curr = A[i];
	}

	int B[flag], C[N - flag];

	for(int i = 0;i<flag;i++) B[i] = A[i];

	for(int i = flag;i<N;i++) C[i - flag] = A[i];

	int ele;
	cin>>ele;

	if(bin_search(B,flag,ele) || bin_search(C,N-flag,ele)) cout<<"found"<<endl;

	else cout<<"not found"<<endl;
}
