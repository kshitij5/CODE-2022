class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>&res, vector<int>&ans, int idx) {
        if(idx >= candidates.size()) return;
        if(target == 0) {
            res.push_back(ans);
            return;
        }
        
        if(candidates[idx] <= target) {
            ans.push_back(candidates[idx]);
            dfs(candidates, target-candidates[idx], res, ans, idx);
            ans.pop_back();
        }
        dfs(candidates, target, res, ans, idx+1);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        dfs(candidates, target, res, ans, 0);
        return res;
    }
};