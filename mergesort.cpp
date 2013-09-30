#include <iostream>

using namespace std;

void merge(int* a, int* b, int low, int mid, int high){
	int a1,b1,c,d;
	a1 = low;
	b1 = low;
	c = mid + 1;

	while(a1<=mid && c<=high){
		
		if(a[a1] <= a[c]){
			b[b1] = a[a1];
			a1++;
		}
		
		else{
			b[b1] = a[c];
			c++;
		}

		b1++;
	}

	if(a1>mid){
		
		for(int i = c;i<=high;i++){
			b[b1] = a[i];
			b1++;
		}
	}

	else{
		
		for(int i = a1;i<=mid;i++){
			b[b1] = a[i];
			b1++;
		}
	}
	
	for(int i = low;i<=high;i++) a[i] = b[i];
}

void mergesort(int* a,int* b,int low,int high){
	int mid = (low+high)/2;

	if(low<high){
		mergesort(a,b,low,mid);
		mergesort(a,b,mid+1,high);
		merge(a,b,low,mid,high);
	}
}

int main(){
	int a[10];

	for(int i = 0;i<10;i++) cin>>a[i];

	int b[10];

	mergesort(a,b,0,9);

	for(int i = 0;i<10;i++) cout<<a[i]<<endl;

	return 0;
}