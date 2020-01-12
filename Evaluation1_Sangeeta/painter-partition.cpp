#include<iostream>
using namespace std;

int painters(int arr[],int n,int maxl)
{
    int total = 0;
    int num = 1;
    for(int i =0;i<n;i++)
    {
        total+=arr[i];
        if(total>maxl)
        {
            total = arr[i];
            num++;
        }
    }
    return num;
}

int Max(int arr[],int n)
{
    int max = arr[0];
    for(int i =1;i<n;i++)
    {
        if(max<arr[i])
            max = arr[i];
    }
    return max;
}

int Sum(int arr[],int n)
{
    int sum=0;
    for(int i =0;i<n;i++)
        sum+=arr[i];
    return sum;
}

int partition(int arr[],int n,int k)
{
    int low = Max(arr,n);
    int high = Sum(arr,n);

    while(low<high)
    {
        int mid = (low+high)/2;
        int requiredpainters = painters(arr,n,mid);
        if(requiredpainters <=k)
        {
            high = mid;
        }
        else
            low = mid+1;
    }
    return low;
}

int main()
{
    int k,n;
    cin>>k;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<partition(arr,n,k)<<endl;
}
