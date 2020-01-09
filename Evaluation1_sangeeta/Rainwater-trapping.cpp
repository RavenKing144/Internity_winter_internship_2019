#include<iostream>
using namespace std;

int water(int arr[],int n)
{
    int l[n];
    int r[n];
    int water =0;

    l[0] = arr[0];
    for(int i=1;i<n;i++)
    {
        l[i] = max(l[i-1],arr[i]);
    }

    r[n-1] = arr[n-1];
    for(int i = n-2;i>=0;i--)
    {
        r[i] = max(r[i+1],arr[i]);
    }

    for(int i =0;i<n;i++)
    {
        water += min(l[i],r[i]) - arr[i];

    }
    return water;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        cout<<water(arr,n)<<endl<<endl;
    }
}
