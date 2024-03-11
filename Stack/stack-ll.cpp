#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    Node(int data, Node* next1){
        this->data = data;
        this->next = next1;
    }
};

class Stack{
    public:
        Node* top;
        int size;
    
    Stack(){
        top = NULL;
        size=0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return (top==NULL);
    }

    void push(int data){
        Node* temp = new Node(data);
        temp->next = top;
        top = temp;
        size++;
    }

    void pop(){
        if(isEmpty()){
            return;
        }
        Node* temp = top;
        top=top->next;
        delete(temp);
        size--;
    }

    int getTop(){
        if(isEmpty()){
            return -1;
        }
        return top->data;
    }
};

int main() {
    Stack s;

    // Check if stack is empty
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);

    // Check size of stack
    cout << "Size of stack: " << s.getSize() << endl;

    // Get top element
    cout << "Top element: " << s.getTop() << endl;

    // Pop elements
    s.pop();
    s.pop();

    // Check size of stack
    cout << "Size of stack: " << s.getSize() << endl;

    // Get top element
    cout << "Top element: " << s.getTop() << endl;

    return 0;
}
