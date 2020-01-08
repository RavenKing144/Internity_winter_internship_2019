#include <bits/stdc++.h> 
using namespace std; 
void findTriplets(int arr[], int n, int sum) 
{ 
	sort(arr, arr + n); 

	for (int i = 0; i < n - 1; i++) {  
		int l = i + 1; 
		int r = n - 1; 
		int x = arr[i]; 
		while (l < r) { 
			if (x + arr[l] + arr[r] == sum) { 
				cout<<x<<","<<" "<<arr[l]<<" and "<<arr[r]<<endl; 
				l++; 
				r--; 
			} 
			else if (x + arr[l] + arr[r] < sum) 
				l++; 

			else
				r--; 
		} 
	} 
} 
 
int main() 
{ 
	int n,sum;
    cin>>n;
    int arr[n];
    for( int i=0;i<n;i++)
        cin>>arr[i];
    cin>>sum;  
	findTriplets(arr, n, sum); 
	return 0; 
} 
