#include<iostream>
#include<string>
#include<stack>
using namespace std;

void prefix(string s)
{
    int len = s.size();
    stack<string>st;

    for(int i = 0;i<len;i++)
    {
        if(s[i]=='+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
            {
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();

                string final = s[i] + s2 + s1;
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
    cout<<"Enter postfix expression: ";
    cin>>s;

    prefix(s);
}
