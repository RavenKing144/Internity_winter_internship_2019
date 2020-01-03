

#include<iostream>
using namespace std;

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

int
main ()
{
  char arr[] = { 's', 'a', 'v', 'n', 'p', 'w', 'd', 'q', 'o', 'x' };
  int n = sizeof (arr) / sizeof (arr[0]);
  radixsort (arr, n);
  print (arr, n);
  return 0;
}
