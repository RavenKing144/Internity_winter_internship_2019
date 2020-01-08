#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void findTriplet(int arr[],int n,int t)
{
    int i,j,k;

    sort(arr,arr+n);

    for(i =0;i<n;i++)
    {
        j = i+1;
        k = n-1;
        while(j<k)
        {
            if(arr[i]+arr[j]+arr[k] == t)
            {
                cout << arr[i] <<", " <<arr[j] <<" and "<<arr[k]<<endl;
                j++;
                k--;
            }
            else if(arr[i]+arr[j]+arr[k]<t)
                j++;
            else if(arr[i]+arr[j]+arr[k]>t)
                k--;
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

    findTriplet(arr,n,target);
}
