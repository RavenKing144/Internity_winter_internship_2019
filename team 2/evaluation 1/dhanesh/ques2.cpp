#include <bits/stdc++.h>
using namespace std;
int main()
{
    char num[32];
    cin >> num;
    if(num[0]!='9' && num[0]>='5')
        num[0] =  '0' + 9 - num[0] + '0';
    for(int i = 1; i < strlen(num); ++i)
        if(num[i]>='5')
            num[i] =  '0' + 9 - num[i] + '0';
    cout << num << endl;
    return 0;
}