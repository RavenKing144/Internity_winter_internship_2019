#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    cin>>str;
    for(int i =0;i<str.length();i++)
    {
        int j = str[i] - 48;

        if(j==9&&i==0)
            continue;

        if(j>4)
        {
            j = 9-j;
        }

        str[i] = j + '0';
    }
    cout<<str<<endl;
}
