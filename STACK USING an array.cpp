#include<iostream>
using namespace std;

class Stack{
	public:
		int *arr;
	    int top;
	    int size;
	
	Stack(int value){
		this->size=value;
		arr=new int [size];
		top=-1;
	}

	void push( int value){
		if(size>top){
			arr[++top]=value;
		}
		else{
			cout<<" stack  full "<<endl;
		}
	}
	void pop(){
		 if(top>=0){
		 	top--;
		 }
		 else{
		 	cout<<" Nothing to pop stack is empty  "<<endl;
		 }
	}
	bool Is_empty()
	{
		if(top==-1){
			return true;
		}
		else{
			return false;
		}
	}
	int peek(){
		if(top>=0){
			return arr[top];
		}
		else{
			cout<<"Stack is Empty"<<endl;
			return -1;
		}
	}
};


int main(){
	Stack st(7);
	st.push(12);
	st.push(17);
	st.push(24); 
	 st.push(9);
	 
	 	cout<<"Top element in stack   "<<st.peek()<<endl;
	     st.pop();
	      // st.pop();
	      //st.pop();
	     //st.pop();
	     //st.pop();
	cout<<"After poping out "<<endl;
}