#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void findPairs(int arr[],int n,int t)
{
    int i,j,k;

    sort(arr,arr+n);

    for(i =0;i<n;i++)
    {
        for(j = i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==t)
            {
                cout<<arr[i] <<" and "<<arr[j]<<endl;
                break;
            }
        }
    }

}

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }

    int target;
    cin>>target;

    findPairs(arr,n,target);
}

