#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d; // data=d
        this->next = NULL; // next = NULL
    }

    Node(int d, Node* next1){
        this->data = d; // data+d
        this->next = next1; // next = next1
    }
};

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
    // with the help of second constructor Node(int d, Node* next1)
}

// Node* insertHead(Node* &head, int val){
//     Node* temp = new Node(val);
//     temp->next = head;
//     head = temp;
//     return head;
// }

Node* insertTail(Node* head, int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode = new Node(val);
    temp->next=newNode;
    newNode->next = NULL;
}

Node* insertPosition(Node* head, int el, int k){
    if(head==NULL){
        if(k==1){
            return new Node(el, head);
        }
        else{
            return head;
        }
    }
    if(k==1){
            return new Node(el, head);
    }
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        if(cnt == (k-1)){
            Node* x = new Node(el ,temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* removesHead(Node *head)
{
    // edge case
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *removesTail(Node *head)
{
    // edge case
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;

    return head;
}

Node *removesK(Node *head, int k)
{
    if (head == NULL)
        return head;

    if (k == 1)
    {
        Node *head = removesHead(head);

        // or
        // Node* temp = head;
        // head = head->next;
        // delete temp;
        // return head;
    }

    // deletes kth element and tail also
    int cnt = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *removesValue(Node *head, int val)
{
    if (head == NULL)
        return head;

    if (head->data == val)
    {
        Node *head = removesHead(head);

        // or
        // Node* temp = head;
        // head = head->next;
        // delete temp;
        // return head;
    }

    // deletes element with value and tail also
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

void printLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {2, 3, 5, 6, 7};
    Node *head = convertArr2LL(arr);
    cout << head->data << endl;
    printLL(head);

    head = new Node(225, head);
    printLL(head);

    // insertHead(head, 500);
    // printLL(head);

    insertTail(head, 500);
    printLL(head);

    head=insertPosition(head, 964, 3);
    printLL(head);

    // head = removesHead(head);
    // printLL(head);
    // head = removesTail(head);
    // printLL(head);
    // head = removesK(head, 5);
    // printLL(head);

    // head = removesValue(head, 7);
    // printLL(head);
}