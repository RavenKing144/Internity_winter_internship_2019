#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    string x;
    cin >> s;
    
    vector<string> word;
    while(cin >> x)
    {
        word.push_back(x);
    }
    
    vector<int> ans;
    
    int word_size = word[0].size();
    int word_count = word.size();
    
    int total_char = word_size*word_count;
    
    vector<int> res;
    
    if(total_char>s.size())
    {
        if(res.size() == 0) 
        {
            cout << "No Output.\n";
            return 0;
        }
    
        for(int i=0;i<res.size();i++)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
        return 0;
    }
    
    unordered_map<string, int> hash_map;
    
    for(int i=0;i<word_count;i++)
    {
        hash_map[word[i]]++;
    }
    
    for(int i=0;i<=s.size()-total_char;i++)
    {
        unordered_map<string, int> temp_hash_map(hash_map);
        int j = i, count=word_count;
        while(j<i+total_char)
        {
            string wordl = s.substr(j, word_size);
            
            if(hash_map.find(wordl) == hash_map.end()||temp_hash_map[wordl] == 0)
            {
                break;
            }
            
            else{
                temp_hash_map[wordl]--;
                count--;
            }
            
            j+=word_size;
        }
        
        if(count==0)
        {
            res.push_back(i);
        }
    }
    
    if(res.size() == 0) 
    {
        cout << "No Output.\n";
        return 0;
    }
    
    for(int i=0;i<res.size();i++)
    {
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}