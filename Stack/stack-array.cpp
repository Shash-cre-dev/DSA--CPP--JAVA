#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
        int size;
        int *arr;
        int top;
    
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    //methods
    void push(int ele){
        // checking if empty space present in stack
        if(size - top > 1){
            top++;
            arr[top] = ele;
        }
        else{
            cout<< "Stack Overflow" <<endl;
        }
    }

    void pop(){
        // checking if there are elements in the stack
        if(top >= 0){
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peek(){
        // checking if there are elements in the stack
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"Stack is Empty"<< endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    Stack st(5);

    st.push(22);
    st.push(27);
    st.push(88);
    st.push(58);
    st.push(37);
    st.push(65);

    cout<< st.peek() <<endl;
    st.pop();

    if(st.isEmpty()){
        cout <<"Stack is Empty";
    }
    else{
        cout <<"Stack is Not Empty"; 
    }
}
