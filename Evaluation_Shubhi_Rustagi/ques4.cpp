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
    
    for(i=0;i<n-1;i++)
    {
        int l=i+1;
        int r=n-1;
        while(l<r)
        {
            if(t-a[l]-a[r]==a[i])
            {
                printf("%d, %d and %d\n", a[i], a[l], a[r]);
                l++;
                r--;
            }
            else if(t-a[l]-a[r]>a[i])
            {
                l++;
            }
            else{
                r--;
            }
        }
    }
    return 0;
}