#include<iostream>
#include<string>
using namespace std;

void longestpal(string s)
{
    int n = s.size();
    bool palCheck[n][n];

    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
           palCheck[i][j]=false;

    int maxLength = 1;
    for(int i = 0;i<n;i++)
        palCheck[i][i] = true;

    int start = 0;
    for(int i = 0;i<n;i++)
    {
        if(s[i]==s[i+1])
        {
            palCheck[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for(int k = 3;k<=n;k++)
    {
        for(int i = 0;i<n-k+1;i++)
        {
            int j = i+k-1;
            if (palCheck[i+1][j-1] && s[i] == s[j])
            {
            palCheck[i][j] = true;
            if (k > maxLength) {
               start = i;
               maxLength = k;
              }
            }
        }
    }

    cout<<s.substr(start,maxLength);
    return;

}

int main()
{
    string s;
    cin>>s;
    longestpal(s);
}
