#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int Compare(string a, string b)
{
    string ab = a.append(b);
    string ba = b.append(a);

    if(ab>ba)
        return 1;
    else
        return 0;
}

void formBig(string arr[],int n)
{
    sort(arr, arr+n, Compare);
    for(int i=0;i<n;i++)
        cout<<arr[i];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        formBig(arr,n);
    }
}
