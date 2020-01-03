#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) 
{ 
    int root = i;
    int left = 2*i + 1;
    int right = 2*i + 2;  
  
    // If left child is larger than root 
    if (left < n && arr[left] > arr[root]) 
        root = left; 
  
    // If right child is larger than root so far 
    if (right < n && arr[right] > arr[root]) 
        root = right; 
  
    // If root is changed
    if (root != i) 
    { 
        swap(arr[i], arr[root]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, root); 
    } 
} 

int main()
{
    int n, temp;
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
    
    //heap sort
    
    //build heap - rearrange the array
    for(int i = n/2 - 1;i>=0;i--)
    {
        heapify(arr, n, i);
    }
    
    //build heap for each element one by one
    for(int i = n-1;i>=0;i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        heapify(arr, i, 0);
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