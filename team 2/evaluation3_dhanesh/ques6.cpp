class Solution {
public:
    void dfs(vector<int> &candidates, int target, vector<vector<int> > &res, vector<int> &r, int i){
        if (target<0){
            return;
        }else{
            if (target==0){
                res.push_back(r);
            }else{
                while (i<candidates.size() && target-candidates[i]>=0){
                    r.push_back(candidates[i]);
                    dfs(candidates,target-candidates[i],res,r,i);
                    i++;
                    r.pop_back();
                }
            }
        }
         
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        if (candidates.size()==0){return res;}
        sort(candidates.begin(),candidates.end());
        vector<int> r;
        dfs(candidates,target,res,r,0);
        return res;
    }
};