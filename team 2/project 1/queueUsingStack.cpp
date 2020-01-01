#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Queue {
	stack<int> s1, s2;

public:
	
	void enqueue(int data)
	{
		s1.push(data);
	}

	
   int dequeue()
	{
		
		if (s1.empty() && s2.empty()) 
		{
			cout << "No element present!";
			exit(0);
		}

		
		if (s2.empty()) 
        {
			while (!s1.empty()) 
			{
				s2.push(s1.top());
				s1.pop();
			}
			
		}
        int top = s2.top();
		s2.pop();
		return top;
	}
};

int main()
{
	int keys[] = { 2, 4, 6, 8, 10 };
	Queue q;

	for (int i=0;i<5;i++) 
    {
		q.enqueue(keys[i]);
	}

	cout << q.dequeue() << '\n';	
	cout << q.dequeue() << '\n';   
	cout << q.dequeue() << '\n';
	cout << q.dequeue() << '\n';
	cout << q.dequeue() << '\n';

	return 0;
}
