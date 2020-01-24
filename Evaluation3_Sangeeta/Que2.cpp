#include<iostream>
#include<vector>
#include<string>
using namespace std;

void getComb(string charMap[10],vector<string>&result,string&sol,int index,string&s)
{
    if(index == s.size())
        result.push_back(sol);
    else
    {
        for(int i = 0;i<charMap[s[index]-'0'].size();i++)
        {
            sol.push_back(charMap[s[index]-'0'][i]);
            getComb(charMap,result,sol,index+1,s);
            sol.pop_back();
        }
    }
}

vector<string>findComb(string s)
{
    string charMap[10] = {"0","1","abc","def","ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string sol;
    vector<string> result;
    getComb(charMap,result,sol,0,s);
    return result;
}

int main()
{
    string s;
    cin>>s;
    vector<string>result = findComb(s);
    cout<<"[ ";
    for(int i =0;i<result.size();i++)
        cout<<result[i]<<" ";
    cout<<"]"<<endl;
}
