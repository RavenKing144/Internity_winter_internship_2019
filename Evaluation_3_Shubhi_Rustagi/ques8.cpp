#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; // size of array
    cin >> n;
    
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    
    int sum;
    cin >> sum;
    
    vector<pair<int, int>> ans;
    unordered_set<int> s; 
    for(int i=0;i<n;i++)
    {
        int temp = sum - arr[i];
        if(s.find(temp) != s.end())
        {
            ans.push_back(make_pair(arr[i], sum-arr[i]));
        }
        s.insert(arr[i]);
    }
    
    cout << "Pairs with the given sum are as follows: \n";
    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
    return 0;
}