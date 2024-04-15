#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    cout<<"Enter the data: "<<endl;
    int val;
    cin>>val;
    root = new Node(val);
    if(val == -1){
        return NULL;
    }

    cout<<"Enter the Data for left side"<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter the Data for right side"<<endl;
    root->right = buildTree(root->right);
}

void preOrderTraversal(Node* root){
    //base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){
    //base case
    if(root==NULL){
        return;
    }

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    //base case
    if(root==NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root = NULL;
    root = buildTree(root);

    //Preorder Traversal
    preOrderTraversal(root);
    cout<<endl;
    

    //Inorder Traversal
    inOrderTraversal(root);
    cout<<endl;

    //Postorder Traversal
    postOrderTraversal(root);
    cout<<endl;
}