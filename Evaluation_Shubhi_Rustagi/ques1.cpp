#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int start, int end) 
{ 
	int total = 0; 
	for (int i = start; i <= end; i++) 
		total += arr[i]; 
	return total; 
} 

int minTime(int a[], int n, int k)
{
    int dp[k+1][n+1] = {0};
    int i, j;
    
    for(i=0;i<n+1;i++)
    {
        dp[1][i] = sum(a, 0, i-1);
    }
    
    for(j=0;j<k+1;j++)
    {
        dp[j][1] = a[0];
    }
    
    for(j=2;j<k+1;j++)
    {
        for(i=2;i<n+1;i++)
        {
            int best = INT_MAX;
            
            for(int p = 0; p <= j;p++)
            {
                best = min(best, max(dp[j-1][p], sum(a, p, i-1)));
            }
            dp[j][i] = best;
        }
    }
    return dp[k][n];
}

int main()
{
    int k, n, i;
    cin >> k >> n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cout << minTime(a, n, k) << "\n";
}