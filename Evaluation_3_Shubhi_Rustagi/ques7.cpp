#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n;
    
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        arr.push_back(x);
    }
    
    stack<int> s;
    
    int max_area = 0;
    int top;
    int area;
    
    int i=0;
    while(i<n)
    {
        if(s.empty() || arr[s.top()] <= arr[i])
        {
            s.push(i++);
        }
        else{
            top = s.top();
            s.pop();
            
            area = arr[top] * (s.empty()?i:i-s.top()-1);
            
            if(max_area < area)
            {
                max_area = area;
            }
        }
    }
    
    while(s.empty() == false)
    {
        top = s.top();
        s.pop();
        area = arr[top] * (s.empty()?i:i-s.top()-1);
        if(max_area<area)
        {
            max_area=area;
        }
    }
    
    cout << max_area<< "\n";
    
    return 0;
}