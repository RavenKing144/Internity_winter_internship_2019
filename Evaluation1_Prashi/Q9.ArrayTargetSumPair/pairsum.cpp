#include<bits/stdc++.h>
using namespace std;
void print(int arr[], int n, int sum){
    unordered_map<int, int> m; 
    for (int i = 0; i < n; i++){ 
        int rem = sum - arr[i]; 
        if (m.find(rem) != m.end()){ 
            int count = m[rem]; 
            for (int j = 0; j < count; j++) 
                cout<< rem <<" "<< "and" <<" "<< arr[i]<<'\n'; 
        }
        m[arr[i]]++;
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
    print(arr, n, target);
	return 0;
}
