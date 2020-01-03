#include<bits/stdc++.h>
using namespace std;

template<class T>
void swap(T* a, T* b)
{
    T t = *a;
    *a = *b;
    *b = t;
}

template <class T>
void printArray(T arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


template <class T>
int Partition(T arr[],int low,int high)
{
    int left,right;
    T key = arr[low];
    left = low;
    right= high;

    while(left<right)
    {
        while(arr[left]<=key)
            left++;
        while(arr[right]>key)
            right--;
        if(left<right)
        {
            swap(&arr[left],&arr[right]);
        }
    }
    arr[low] = arr[right];
    arr[right] = key;
    return right;
}

template <class T>
void quickSort(T arr[],int low,int high)
{
    int pivot;
    //Base case
    if(high>low)
    {
        pivot = Partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}

int main()
{
    int n = 5;
    char arr[n] = {'b','e','z','a','f'};
    quickSort<char>(arr,0,n-1);
    printArray<char>(arr,n);
}

