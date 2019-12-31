#include<iostream>
#include<queue>
using namespace std;
class stack{
    queue<int> q1;
    queue<int> q2;
public:
    //function to check whether the stack is empty
    bool isEmpty(){
        return q1.empty() && q2.empty();
    }
    //function to check the size of stack
    int size(){
        return q1.size() | q2.size();
    }
    // function to push data in stack
    void push(int data){
       // firstly checking which queue is empty
        // then pushing the element into the queue
        //then pushing the elemnts of the first non empty queue into the other queue
        // thus making one queue empty and the other having the elements in stack style
        if(!q1.empty()){
            q2.push(data);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        }else{
            q1.push(data);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }

    }
    //function to pop elements
    void pop(){
        if(!q1.empty()){
            q1.pop();
        }else{
            q2.pop();
        }
    }
    // function to find the top element
    int top(){
        if(!q1.empty()){
           return q1.front();
        }else{
            return q2.front();
        }
    }
};
// in this code push function has time complexity O(n) and every other function is in O(1).
// also the space complexity is O(1).
// in this code the the push function is costly implemented.
// there is another method of this by implementing the pop function costly but in that method the top function is also having a time complexibilty
// of O(n). thats why i have implemented this code.

int main(){
    stack s;
    cout<<s.isEmpty()<<endl;
    s.push(1);
    s.push(12);s.push(15);s.push(2);
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.push(20);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
}