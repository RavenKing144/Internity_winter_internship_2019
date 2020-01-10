#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    string result = "";
    map<char, int> m;
    cin >> s;
    
    result += s[0];
    int count = 1;
    for(int i = 1; i<s.length();i++)
    {
        if(s[i-1] == s[i])
        {
            count++;
        }
        else{
            if(count > 1)result += to_string(count) + string(1, s[i]);
            else result += string(1, s[i]);
            count = 1;
        }
    }
    
    if(count > 1)result += to_string(count) + string(1, s[i]);
    else result += string(1, s[i]);
    
    cout << result << "\n";
    return 0;
}