#include<bits/stdc++.h>
using namespace std;

bool isGreater(int a, int b)
{
    string x = to_string(a);
    string y = to_string(b);
    
    return (x+y)>y+x?true:false;
}

int main()
{
    int t, n, i;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int a[n];
        for(i=0;i<n;i++)
        {
            cin >> a[i];
        }
        
        sort(a, a+n, isGreater);
        
        for(i=0;i<n;i++)
        {
            cout << a[i];
        }
        cout << "\n";
    }
    return 0;
}