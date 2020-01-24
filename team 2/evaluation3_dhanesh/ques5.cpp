class Solution {
public:
    string removeDuplicates(string s, int k) {
   string ans;
    stack<pair<char,int>>st;
    for(int i=0; i<s.size(); i++)
    {
            if(st.empty())
            {
                //myMap[s[i]]++;
                st.push(make_pair(s[i],1));
            }
            else
            {
                //cnt=0;
                if(s[i]==st.top().first)
                {
                    if(st.top().second==k-1)
                    {
                            st.pop();

                    }
                    else
                    {
                        st.top().second++;
                    }
                }
                else
                {
                   st.push(make_pair(s[i],1));
                }
            }
    }
    while(!st.empty())
    {
        while(st.top().second>0)
        {
            ans+=st.top().first;
            st.top().second--;
        }
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};