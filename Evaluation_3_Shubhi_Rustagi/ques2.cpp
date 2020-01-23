#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

void find(vector<char> reference[], vector<int> &input, string res, int index, unordered_map<int, char> mp)
{
    // if we have processed every digit of key, print result
    if (index == -1)
    {
        ans.push_back(res);
        return;
    }
 
    // stores current digit
    int digit = input[index];
 
    // size of the list corresponding to current digit
    int len = reference[digit].size();
 
    // if digit is seen for the first time
    if (mp.find(digit) == mp.end())
    {
        // one by one replace it with each character in the corresponding
        // list and recur for next digit
        for (int i = 0; i < len; i++)
        {
            // store character that maps to the current digit in a map
            mp[digit] = reference[digit][i];
 
            // recur for next digit
            find(reference, input, reference[digit][i] + res, index - 1, mp);
        }
        return;
    }
 
    // if digit is seen before, replace it with same character
    // used in the previous occurrence
    find(reference, input, mp[digit] + res, index - 1, mp);
}
 

int main()
{
    vector<char> reference[] = 
    {
        {'0'},
        {'0'},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };
    
    string s;
    cin >> s;
    int n = s.length();
    vector<int> input;
    
    for(int i=0;i<n;i++)
    {
        input.push_back(int(s[i])-48);
    }
    
    unordered_map<int, char> mp;
    
    find(reference, input, "", n-1, mp);
    
    for(vector<string>::iterator it = ans.begin(); it!=ans.end();it++)
    {
        cout << (*it) << " ";
    }
    cout << "\n";
    
    return 0;
}