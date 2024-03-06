#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "The Memory freed is: " << value << endl;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *head, Node *tail, int position, int d)
{

    // insert at start
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // creating a new node
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

    // insert at end
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    // deleting first node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any node
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        // If the node to be deleted is the last node
        if (curr->next == NULL)
        {
            prev->next = NULL;
            tail = prev;
        }
        else
        {
            prev->next = curr->next;
        }
        // freeing memory
        curr->next = NULL;
        delete curr;
    }
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
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertAtHead(head, 15);
    insertAtHead(head, 22);
    insertAtTail(tail, 70);
    insertAtTail(tail, 55);
    insertAtPosition(head, tail, 4, 99);
    insertAtPosition(head, tail, 1, 45);
    printLL(head);

    cout << head->data << " " << endl;
    cout << tail->data << " " << endl;
    deleteNode(head, tail, 4);
    printLL(head);
    cout << head->data << endl;
    cout << tail->data << endl;

    deleteNode(head, tail, 5);
    printLL(head);
    cout << head->data << endl;
    cout << tail->data << endl;

    deleteNode(head, tail, 4);
    printLL(head);
    cout << head->data << endl;
    cout << tail->data << endl;
    return 0;
}
