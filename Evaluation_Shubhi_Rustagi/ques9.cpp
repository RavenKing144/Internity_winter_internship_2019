#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t, i;
    cin >> n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cin >> t;
    
    sort(a, a+n);
    
    int l=0;
    int r=n-1;
    while(l<r)
    {
        if(a[l]+a[r]==t)
        {
            printf("%d and %d\n", a[l], a[r]);
            l++;
            r--;
        }
        else if(a[l]+a[r]>t)
        {
            r--;
        }
        else{
            l++;
        }
    }
    return 0;
}