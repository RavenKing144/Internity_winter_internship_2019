#include <bits/stdc++.h>
using namespace std;

//Quick Sort
template<class T>
void swap(T* a, T* b)
{
    T t = *a;
    *a = *b;
    *b = t;
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

//Insertion Sort
template <class T>
void insertionSort(T arr[],int n)
{
    int i,j;
    T v;
    for(i = 1;i<n;i++)
    {
        v=arr[i];
        j = i;
        while(j>=1&&arr[j-1]>v)
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = v;
    }
}


template <class T>
void printArray(T arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//Radix Sort
template < class T > int
getMax (T arr[], int n)
{
  T mx = arr[0];
  for (int i = 1; i < n; i++)
    if (arr[i] > mx)
      mx = arr[i];
  return mx;
}

template < class T > void
countSort (T arr[], int n, int exp)
{
  T output[n];
  T i, count[10] = { 0 };

  for (i = 0; i < n; i++)
    count[(arr[i] / exp) % 10]++;

  for (i = 1; i < 10; i++)
    count[i] += count[i - 1];

  for (i = n - 1; i >= 0; i--)
    {
      output[count[(arr[i] / exp) % 10] - 1] = arr[i];
      count[(arr[i] / exp) % 10]--;
    }

  for (i = 0; i < n; i++)
    arr[i] = output[i];
}

template < class T > void
radixsort (T arr[], int n)
{
  int m = getMax (arr, n);

  for (int exp = 1; m / exp > 0; exp *= 10)
    countSort (arr, n, exp);
}

template < class T > void
print (T arr[], int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}

//Count Sort
template < class T >
void
countSort (T array[], int size)
{

T output[10];

T count[10];

T max = array[0];

for (int i = 1; i < size; i++)

    {

if (array[i] > max)

max = array[i];

}

for (int i = 0; i <= max; ++i)

    {

count[i] = 0;

}
for (int i = 0; i < size; i++)

    {

count[array[i]]++;

}
for (int i = 1; i <= max; i++)

    {

count[i] += count[i - 1];

}
for (int i = size - 1; i >= 0; i--)

    {

output[count[array[i]] - 1] = array[i];

count[array[i]]--;

}
for (int i = 0; i < size; i++)

    {

array[i] = output[i];

}
}


int main() {

    clock_t start,end;

    int arr1[] = { 4, 2, 2, 8, 3, 3, 1 };
    int n = sizeof (arr1) / sizeof (arr1[0]);
    start = clock();
    countSort (arr1, n);
    end=clock();
    double tt = double(end- start) / double(CLOCKS_PER_SEC);
    cout<<"Count Sort took "<< fixed << tt << setprecision(8) <<"seconds."<<endl;
    printArray (arr1, n);

    char arr2[] = { 's', 'a', 'v', 'n', 'p', 'w', 'd', 'q', 'o', 'x' };
    n = sizeof (arr2) / sizeof (arr2[0]);
    start = clock();
    radixsort (arr2, n);
    end=clock();
    tt = double(end- start) / double(CLOCKS_PER_SEC);
    cout<<"Radix Sort took "<< fixed << tt << setprecision(8) <<"seconds."<<endl;
    printArray (arr2, n);


    n = 5;
    char arr3[n] = {'b','e','z','a','f'};
    start = clock();
    insertionSort<char>(arr3,n);
    end=clock();
    tt = double(end- start) / double(CLOCKS_PER_SEC);
    cout<<"Insertion Sort took "<< fixed << tt << setprecision(8) <<"seconds."<<endl;
    printArray<char>(arr3,n);

    n = 5;
    char arr4[n] = {'b','e','z','a','f'};
    start = clock();
    quickSort<char>(arr4,0,n-1);
    end=clock();
    tt = double(end- start) / double(CLOCKS_PER_SEC);
    cout<<"Quick Sort took "<< fixed << tt << setprecision(8) <<"seconds."<<endl;
    printArray<char>(arr4,n);



	return 0;
}
