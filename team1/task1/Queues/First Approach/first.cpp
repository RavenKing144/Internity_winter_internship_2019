#include<bits/stdc++.h>
using namespace std;

class Queue
{
    stack<int>s1,s2;
    int Size;
public:
    Queue()
    {
        Size=0;
    }
    void enqueue(int data)
    {
        s1.push(data);
        Size++;
        return;
    }

    int dequeue()
    {
        if(Size==0)
        {
            cout<<"Underflow";
            return 0;
        }
        if(!s2.empty())
        {
            int temp = s2.top();
            s2.pop();
            return temp;
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            int temp = s2.top();
            s2.pop();
            Size--;
            return temp;
        }
    }

    int get_size()
    {
        return Size;
    }

    bool isEmpty()
    {
        return(Size==0);
    }
};
