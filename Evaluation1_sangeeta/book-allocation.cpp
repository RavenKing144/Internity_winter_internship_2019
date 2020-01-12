#include<iostream>
using namespace std;

int sum(int arr[],int n)
{
    int sum =0;
    for(int i =0;i<n;i++)
        sum+=arr[i];
    return sum;
}

bool students(int arr[],int n,int m,int curr)
{
    int s = 1;
    int curr_sum = 0;
    for(int i =0;i<n;i++)
    {
        if(arr[i]>curr)
            return false;
        if(curr_sum+arr[i]>curr)
        {
            s++;
            curr_sum = arr[i];
            if(s>m)
            return false;
        }
        else
            curr_sum+=arr[i];
    }
    return true;
}

int findPages(int arr[],int n,int m)
{
    if(n<m)
        return -1;

    int start = 0;
    int res=INT_MAX;
    int end = sum(arr,n);

    while(start<=end)
    {
        int mid = (start+end)/2;
        if(students(arr,n,m,mid))
        {
            res= min(res,mid);
            end = mid-1;
        }
        else
            start = mid+1;
    }
    return res;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int arr[n];
        for(int i =0;i<n;i++)
        {
            cin>>arr[i];
        }

        cout<<findPages(arr,n,m)<<endl;
    }
}
