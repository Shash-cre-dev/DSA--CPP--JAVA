#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to create the BST
Node *createBST(Node *root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = createBST(root->right, d);
    }
    else
    {
        root->left = createBST(root->left, d);
    }

    return root;
}

// Function to perform level-order traversal (similar to pre-order but level-wise)
void preOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << temp->data << " ";
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
    cout << endl; // For better output formatting
}

// Function to take input and create the BST
void giveInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = createBST(root, data);
        cin >> data;
    }
}

Node *minVal(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node *deleteFromBST(Node *root, int val)
{
    // base case
    if (root == NULL)
    {
        return root;
    }

    if (root->data == val)
    {
        // O child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        // left child
        if (root->left != NULL and root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if (root->left == NULL and root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }

    else if (root->data > val)
    {
        // left part
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else
    {
        // right part
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}
int main()
{
    Node *root = NULL;

    cout << "Enter the input to create BST (-1 to stop): ";
    giveInput(root);

    cout << "Preorder Traversal of the BST: ";
    preOrderTraversal(root);

    return 0;
}
