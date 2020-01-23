#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int k;
    cin >>s;
    cin >>k;
    
    stack <int> t;
    int l= s.length();
    int d[l];
    for(int i=0;i<l;i++)
    {
        d[i]=1;
    }
    
    for(int i=0;i<l;i++)
    {
        t.push(s[i]);
        if(s[i+1]==s[i])
        {
            d[i]++;
        }
    }
        if(d[i]==k)
        {
            t.pop();
        }
        
        for(int i=0;i<l;i++)
        {
            cout<<t.top();
            t.pop();
        }
}
   
