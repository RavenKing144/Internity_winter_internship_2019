#include <bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> q1;
    queue<int> q2;
    public:
        void push(int x);
        void pop();
        int top();
        bool isEmpty();
};

void Stack::push(int x)
{
    q2.push(x);
    while(!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;
    cout << x << " is pushed to the stack.\n";
    return;
}

void Stack::pop()
{
    if(q1.empty())
    {
        cout << "Error! Stack is already empty.\n";
        return;
    }
    cout << q1.front() << " is popped out of the stack.\n";
    q1.pop();
    return;
}

int Stack::top()
{
    return q1.front();
}

bool Stack::isEmpty()
{
    return q1.empty();
}

int main()
{
    Stack s;
    int i, x;
    do
    {
        cout << "Press one of the stack operations from below:\n\t1 - Push a value to stack.\n\t2 - Pop value from stack.\n\t3 - Output the topmost element.\n\t4 - Check if stack is empty.\n\t-1 - Exit\n";
        cin >> i;
        switch(i)
        {
            case 1:
                cout << "Enter a number.\n";
                cin >> x;
                s.push(x);
                break;
            
            case 2:
                s.pop();
                break;
            
            case 3:
                cout << "The topmost element is: " << s.top() << "\n";
                break;
            
            case 4:
                if(s.isEmpty())
                    cout << "The stack is empty.\n";
                else
                    cout << "The stack is not empty.\n";
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