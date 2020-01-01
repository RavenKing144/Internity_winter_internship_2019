#include<bits/stdc++.h>
using namespace std;

class Stack
{
    queue<int>q1,q2;
    int size;

public:
    Stack()
    {
        size=0;
    }
    void push(int data)
    {
        size++;
        if(q1.empty())
        {
            q2.push(data);
        }
        else
        {
            q1.push(data);
        }

    }

    int pop()
    {
        if(size==0)
        {
            cout<<"Underflow";
            return 0;
        }
        int i,temp;
        size--;
        if(q2.empty())
        {
            i=0;
            temp=q1.size();
            while(i<temp-1)
            {
                q2.push(q1.front());
                q1.pop();
                i++;
            }
            temp =q1.front();
            q1.pop();
            return temp;
        }
        else
        {
            i=0;
            temp = q2.size();
            while(i<temp-1)
            {
                q1.push(q2.front());
                q2.pop();
                i++;
            }
            temp =q2.front();
            q2.pop();
            return temp;
        }
    }

    bool isEmpty()
    {
        return(size==0);
    }

    int get_size()
    {
        return size;
    }
};
