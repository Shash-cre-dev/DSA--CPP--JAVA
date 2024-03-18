#include <bits/stdc++.h>
class Deque
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    bool pushFront(int x)
    {
        // queue is full
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
        {
            return false;
        }
        // first element to be inserted
        else if (front == -1)
        {
            front = rear = 0;
        }
        // cyclic nature
        else if (front == 0)
        {
            front = size - 1;
        }
        // normal case
        else
        {
            front = front - 1;
        }
        arr[front] = x;
        return true;
    }

    bool pushRear(int x)
    {
        // queue is full
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
        {
            return false;
        }
        // first element to be inserted
        else if (front == -1)
        {
            front = rear = 0;
        }
        // cyclic nature
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        // normal case
        else
        {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    int popFront()
    {
        // queue is empty
        if (front == -1)
        {
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            front = rear = -1;
        }
        // cyclic nature
        else if (front == size - 1)
        {
            front = 0;
        }
        // normal
        else
        {
            front++;
        }
        return ans;
    }

    int popRear()
    {
        // queue is full
        if (front == -1)
        {
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if (front == rear)
        {
            front = rear = -1;
        }
        // cyclic nature
        else if (rear == 0)
        {
            rear = size - 1;
        }
        // normal case
        else
        {
            rear--;
        }
        return ans;
    }

    int getFront()
    {
        // queue is empty
        if (front == -1)
        {
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        // queue is empty
        if (front == -1)
        {
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    { // queue is full
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
        {
            return true;
        }
        return false;
    }
};
