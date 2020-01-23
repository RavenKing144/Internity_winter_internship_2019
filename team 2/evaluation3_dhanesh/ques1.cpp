#include<bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string longestPalindrome(string s) {
    int len = s.size();
    if (len < 2) return s;
    string str("^#");
    for (auto& ch: s) {
      str.push_back(ch);
      str.push_back('#');
    }
    str.push_back('$');
    int dp_start = 0;
    int dp_end = 0;
    int start = 0;
    int max_len = 0;
    int str_len = str.size();
    vector<int> dp(str_len, 0);
    for (int i = 1; i < str_len; ++i) {
      dp[i] = dp_end > i ? min(dp[dp_start * 2 - i], dp_end - i) : 1;
      while (str[i + dp[i]] == str[i - dp[i]]) ++dp[i];
      if (i + dp[i] > dp_end) {
        dp_start = i;
        dp_end = i + dp[i];
      }
      if (dp[i] - 1 > max_len) {
        start = (i - dp[i]) / 2;
        max_len = dp[i] - 1;
      }
    }
    return s.substr(start, max_len);
  }
};
int main(){
    string s;
    cin>>s;
    Solution sol;
    cout<<sol.longestPalindrome(s);
}