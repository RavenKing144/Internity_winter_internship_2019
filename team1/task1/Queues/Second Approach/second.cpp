class MyQueue {
    stack<int> s;
    stack<int> ts;

    bool fs = true; 
    
public:
    MyQueue() {
        
    }
   
    void push(int x) {
        while(s.empty() != true)
        {
            ts.push(s.top());
            s.pop();
        }
        s.push(x);
        while(ts.empty() != true)
        {
            s.push(ts.top());
            ts.pop();
        }
    }
   
    int pop() {
        int r = s.top();
        s.pop();
        return r;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }


};
