#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findFourElements(int arr[], int n, int x)
{
    vector<vector<int>> ans;
    // int k = 0;
    unordered_map<int, pair<int, int>> mp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            mp[arr[i] + arr[j]] = {i, j};
        }
    }
    
    vector<int> temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sum = arr[i] + arr[j];
            if(mp.find(x-sum) != mp.end())
            {
                pair<int, int> p = mp[x-sum];
                if(p.first!=i && p.second!=j && p.first!=j && p.second!=i)
                {
                    temp = {arr[i], arr[j], arr[p.first], arr[p.second]};
                    sort(temp.begin(), temp.end());
                    if(find(ans.begin(), ans.end(), temp) == ans.end())
                    {
                        ans.push_back(temp);
                        // k++;
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    int n; // size of array
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    
    int target;
    cin >> target;
    
    vector<vector<int>> ans = findFourElements(arr, n, target);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}