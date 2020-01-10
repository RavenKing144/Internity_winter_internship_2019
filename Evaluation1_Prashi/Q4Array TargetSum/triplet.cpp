#include<bits/stdc++.h>
using namespace std;
void triplet(int arr[], int n, int target)
{
	sort (arr, arr + n);
	for (int i = 0; i <= n - 3; i++)
	{
		int k = target - arr[i];
		int low = i + 1, high = n - 1;
		while (low < high)
		{
			if (arr[low] + arr[high] < k)
				low++;
			else if (arr[low] + arr[high] > k)
				high--;
			else
			{
				cout <<arr[i]<<","<< arr[low]<<"and"<<
						arr[high] <<"\n";
				low++, high--;
			}
		}
	}
}

int main() {
    int n;
    cout<<"enter no of elements\n";
    cin>>n;
    int arr[1000];
    for(int i =0;i <n;i++){
        cout<< "enter elements of array\n";
        cin>>arr[i];
    }
    for(int i=0; i<n;i++){
        cout<<arr[i]<<'\n';
    }
    int target;
    cout<<"enter target\n";
    cin>>target;
    triplet(arr, n, target);
	return 0;
}
