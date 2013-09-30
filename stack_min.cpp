#include <stack>
#include <cstdlib>
#include <iostream>

using namespace std;

class new_stack{
	stack<int> main;
	stack<int> min;
	stack<int> count;

	public:
	
	void push(int a){
		main.push(a);
		
		if(min.empty() || a<min.top()){
			min.push(a);
			count.push(1);
		}

		else if(a == min.top()){
			int top = count.top();
			count.pop();
			count.push(top++);
		}
		
		cout<<min.top()<<endl;
	}

	int find_min(stack<int> main){
		stack<int> buff;
		buff = main;
		int mins = 1000000;
		
		while(!buff.empty()){;
			int curr = buff.top();
			buff.pop();
			
			if(curr<mins) mins = curr;
		}
		
		return mins;
	}

	int getmin(){return min.top();}

	void pop(){

		if(!main.empty()){
		int retval = main.top();
		main.pop();

		
		if(retval == min.top()){

			if(count.top() == 1){
				min.pop();
				count.pop();
				int new_min = find_min(main);
				
				if(!min.empty() && new_min < min.top()){
					min.push(new_min);
					count.push(1);
				}
			}
			
			else{
				int top = count.top();
				count.pop();
				count.push(top--);
			}

		}
	}

	}

	int top(){return main.top();}
};

int main(){
	new_stack s;
	
	for(int i = 10;i>0;i--) s.push(i);

	for(int i = 0;i<10;i++){
		cout<<s.getmin()<<endl;
		cout<<s.top()<<endl;
		s.pop();
	}

	return 0;
}
