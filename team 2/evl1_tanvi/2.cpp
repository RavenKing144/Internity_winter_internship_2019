#include<iostream>
using namespace std;
int power10(int);
int main()
{
    char a[100];
    cin>>a;
    int i=0,digit;
    if(a[0]=='9')
    {
        i++;
    }
    for(;a[i]!='\0';i++)
    {
        digit=a[i]-'0';
        if(digit>=5)
        {
            digit=9-digit;
            a[i]=digit+'0';
        }
    }
    cout<<a;
   return 0;
}
