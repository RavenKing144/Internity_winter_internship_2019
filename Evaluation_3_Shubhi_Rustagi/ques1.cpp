#include <bits/stdc++.h>
using namespace std;

string findLongestPallindrome(string s)
{
	string ans="";
	int n = s.length();
	int start;
	bool table[n][n];
	memset(table, false, sizeof(table));

	int maxLength = 1;
	for(int i=0;i<n;i++)
	{
		table[i][i] = true;
	}

	// for maxLength = 2
	for(int i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])
		{
			table[i][i+1] = true;
			start = i;
			maxLength=2;
		}
	}

	for(int i=3;i<=n;i++)
	{
		for(int j=0;j<n-i+1;j++)
		{
			int k = i + j -1;
			if(table[i+1][j-1] && s[i]==s[j])
			{
				table[i][j] = true;

				if(k > maxLength)
				{
					start = i;
					maxLength = k;
				}
			}
		}
	}

	while(maxLength--)
	{
		ans += string(1, s[start]);
		start++;
	}
	return ans;
}

int main()
{
	string s;
	cin >> s;
	cout << findLongestPallindrome(s) << "\n";
	return 0;
}