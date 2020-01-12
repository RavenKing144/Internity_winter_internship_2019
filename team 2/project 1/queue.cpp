#include <bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> s1;
    stack<int> s2;
    int f;
    int b;
    public:
        void enqueue(int x);
        void dequeue();
        int front();
        int back();
};

void Queue::enqueue(int x)
{
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while(!s2.empty())
    {
        f = s2.top();
        s1.push(s2.top());
        s2.pop();
    }
    b = x;
    cout << x << " is pushed to the stack.\n";
    return;
}

void Queue::dequeue()
{
    if(s1.empty())
    {
        cout << "Error! Stack is already empty.\n";
        return;
    }
    cout << s1.top() << " is popped out of the stack.\n";
    s1.pop();
    f = s1.top();
    return;
}

int Queue::front()
{
    return f;
}

int Queue::back()
{
    return b;
}

int main()
{
    Queue q;
    int i, x;
    do
    {
        cout << "Press one of the queue operations from below:\n\t1 - Enqueue a value to queue.\n\t2 - Dequeue value from queue.\n\t3 - Output the frontmost element.\n\t4 - Output the last element.\n\t-1 - Exit\n";
        cin >> i;
        switch(i)
        {
            case 1:
                cout << "Enter a number.\n";
                cin >> x;
                q.enqueue(x);
                break;
            
            case 2:
                q.dequeue();
                break;
            
            case 3:
                cout << "The frontmost element is: " << q.front() << "\n";
                break;
            
            case 4:
                cout << "The last element is: " << q.back() << "\n";
                break;
                
            case -1:
                cout << "Exit!\n";
                break;
            
            default:
                cout << "Invalid Input.\n";
                break;
        }
    }while(i>0);
    return 0;
}