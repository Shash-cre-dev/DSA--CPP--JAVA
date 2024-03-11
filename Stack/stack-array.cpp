#include <bits/stdc++.h>
using namespace std;

// Stack class.
class Stack
{

public:
    int size;
    int *arr;
    int tos;

    Stack(int capacity)
    {
        this->size = capacity;
        arr = new int[capacity];
        tos = -1;
    }

    void push(int num)
    {
        // atleast one space is empty
        if (size - tos > 1)
        {
            tos++;
            arr[tos] = num;
        }
    }

    int pop()
    {
        // atleast one element is present
        if (tos >= 0)
        {
            int ans = arr[tos];
            tos--;
            return ans;
        }
        return -1;
    }

    int top()
    {
        // atleast one element is present
        if (tos >= 0)
        {
            return arr[tos];
        }
        return -1;
    }

    int isEmpty()
    {
        if (tos == -1)
        {
            return 1;
        }
        return 0;
    }

    int isFull()
    {
        if (tos == size - 1)
        {
            return 1;
        }
        return 0;
    }
};

int main()
{
    Stack st(5);

    st.push(22);
    st.push(27);
    st.push(88);
    st.push(58);
    st.push(37);
    st.push(65);

    cout << st.peek() << endl;
    st.pop();

    if (st.isEmpty())
    {
        cout << "Stack is Empty";
    }
    else
    {
        cout << "Stack is Not Empty";
    }
}
