#include <bits/stdc++.h>
using namespace std;

void findNumbers(vector<int> &arr, int target, vector<vector<int>> &res, vector<int>& r, int i) 
{ 
    // If  current sum becomes negative 
    if (target < 0) 
        return; 
  
    // if we get exact answer 
    if (target == 0) 
    { 
        res.push_back(r); 
        return; 
    } 
  
    // Recur for all remaining elements that 
    // have value smaller than sum. 
    while (i < arr.size() && target - arr[i] >= 0) 
    { 
  
        // Till every element in the array starting 
        // from i which can contribute to the sum 
        r.push_back(arr[i]); // add them to list 
  
        // recur for next numbers 
        findNumbers(arr, target - arr[i], res, r, i); 
        i++; 
  
        // remove number from list (backtracking) 
        r.pop_back(); 
    } 
} 

int main()
{
    int n, x; // size of array
    cin >> n;
    
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        cin >>  x;
        arr.push_back(x);
    }
    // n = arr.size();
    
    int target; // the target sum
    cin >>  target;
    
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end()); 
  
    vector<int> r; 
    vector<vector<int> > res; 
    findNumbers(arr, target, res, r, 0);
    
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}