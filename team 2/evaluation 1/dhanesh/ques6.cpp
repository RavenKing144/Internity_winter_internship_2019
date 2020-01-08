#include <bits/stdc++.h>  
using namespace std; 
int myCompare(string X, string Y) 
{ 
	string XY = X.append(Y); 
	string YX = Y.append(X);  
	return XY.compare(YX) > 0 ? 1: 0; 
}

void printLargest(vector<string> arr) 
{ 
	sort(arr.begin(), arr.end(), myCompare); 

	for (int i=0; i < arr.size() ; i++ ) 
		cout << arr[i]; 
} 

int main() 
{ 
	vector<string> arr;
    int t,n;
    string num;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>num;
            arr.push_back(num); 
        }
        printLargest(arr);
    } 

return 0; 
} 

