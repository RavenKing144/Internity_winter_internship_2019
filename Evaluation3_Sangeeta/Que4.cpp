#include<bits/stdc++.h>
using namespace std;

string plusMinusrec(string s,int sum)
{

    if(s.size()==1)
    {
        if(sum+s[0]==0)
            return "+";
        else if(sum-s[0] == 0)
            return "-";
        else
            return "not possible";
    }
    string s2 = plusMinusrec(s.substr(1), sum - s[0]);
  if(s2 != "not possible"){
    return "-" + s2;
  }

  string s1 = plusMinusrec(s.substr(1), sum + s[0]);
  if(s1 != "not possible"){
    return "+" + s1;
  }

}

void plusMinus(string s)
{
    if(s.size()<=1)
    {
        cout<<"not possible"<<endl;
        return;
    }
    string res;
    res = plusMinusrec(s.substr(1),s[0]);
    cout<<res<<endl;

}

int main()
{
    string s;
    cin>>s;
    plusMinus(s);
}
