#include<iostream>
using namespace std;

class Stack {
    
  private:
        int *arr;
        int top;
        int size;
   public:

    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push( int element) {
        if(size - top > 1) {
            top++;
            arr[top] = element;
        }
        else{
            cout << "Stack OverFlow" << endl;
        }
    }

   int pop (){
   	if (top==-1)
   	{
   		cout<<" stack is empty"<<endl;
	   }
	   else {
	   	top--;
	   }
 return top;
 
   }
    int peek() {
        if(top >=0 )
            return arr[top];
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        if( top == -1) {
            return true;
        }
        else{
            return false;
        }
    }

};

int main() {


    Stack st(6);

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(22);
    st.push(21);
    st.push(24);

    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    if(st.isEmpty()) {
        cout << "Stack is Empty  " << endl;
    }
    else{
        cout << "Stack is not Empty  " << endl;
    }
    
    return 0;
}