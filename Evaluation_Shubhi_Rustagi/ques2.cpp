#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, result = "";
    int x;
    cin >> s;
    for(int i = 0;i<s.length();i++)
    {
        x = min((int)s[i]-48, 9 - (int)(s[i])+48);
        result+=to_string(x);
    }
    cout << result << "\n";
    return 0;
}