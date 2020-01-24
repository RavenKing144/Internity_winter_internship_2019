#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    char character;
    int freq;

    node(char s,int k)
    {
        this->character = s;
        freq = k;
    }
};

string remove(string s,int k)
{
    stack<node>st;
    for(int i = 0;i<s.size();i++)
    {
        char ch = s[i];
        if(st.size()>0 && st.top().freq == k)
        {
            char curr = st.top().character;
                while (st.size() > 0 && st.top().character == curr)
                    st.pop();
        }
        if (st.size() > 0 && st.top().character == ch)
        {
            node new_top(ch, st.top().freq + 1);
            st.push(new_top);
        }
        else
        {
            node new_top(ch, 1);
            st.push(new_top);
        }
    }
    if (st.size() > 0 && st.top().freq == k)
    {
        char curr = st.top().character;
        while (st.size() > 0 && st.top().character == curr)
                st.pop();
    }
        string res = "";
        while (st.size() > 0)
        {
           res += st.top().character;
           st.pop();
        }

        string reduced_string = "";
        for (int i = res.length() - 1; i >= 0; i--)
            reduced_string += res[i];

        return reduced_string;
}

int main()
{
    string s = "deeedbbcccbdaa";
    int k = 3;
    cout<<remove(s,k)<<endl;
}
