#include<iostream>
#include<stack>
#include<string>
using namespace std;

void postfix(string s)
{
    stack<string>st;
    int len = s.size();

    for(int i = len-1;i>=0;i--)
    {
        if(s[i]=='+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
            {
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();

                string final = s1 + s2 + s[i];
                st.push(final);
            }
        else
        {
            st.push(string(1,s[i]));
        }
    }
    cout<<st.top()<<endl;
}

int main()
{
    string s;
    cout<<"Enter prefix expression: ";
    cin>>s;
    postfix(s);
}
