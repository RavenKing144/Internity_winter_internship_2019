#include <bits/stdc++.h>
using namespace std;

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
        
        int left[n] = {0};
        int right[n] = {0};
        
        left[0]=a[0];
        for(i=1;i<n;i++)
        {
            left[i] = max(left[i-1],a[i]);
        }
        
        right[n-1] = a[n-1];
        for(i=n-2;i>=0;i--)
        {
            right[i]=max(right[i+1], a[i]);
        }
        
        int water = 0;
        for(i=0;i<n;i++)
        {
            water+= min(left[i], right[i]) - a[i];
        }
        
        cout << water << "\n";
    }
    return 0;
}