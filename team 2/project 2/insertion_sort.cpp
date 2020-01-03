#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, j, key;
    cout << "Enter the length of the array: ";
    cin >> n;
    cout << n << "\n";
    
    int arr[n];
    cout << "Input the array elements: ";
    for(int i = 0; i<n;i++)
    {
        cin >> arr[i];
    }
    //output the numbers
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    //insertion sort
    for(int i=0;i<n;i++)
    {
        key = arr[i];
        // cout << key;
        for(j=i-1;j>=0;j--)
        {
            if(arr[j] > key)
            {
                arr[j+1] = arr[j];
            }
        }
        arr[j+1] = key;
    }
    
    //printing the sorted array
    cout << "The resultant array: \n";
    for(int i = 0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    return 0;
}