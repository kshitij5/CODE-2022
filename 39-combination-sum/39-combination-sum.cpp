class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>&res, vector<int>&ans, int idx, int sum) {
        if(idx >= candidates.size()) return;
        if(target == sum) {
            res.push_back(ans);
            return;
        }
        
        if(sum+candidates[idx] <= target) {
            ans.push_back(candidates[idx]);
            dfs(candidates, target, res, ans, idx, sum+candidates[idx]);
            ans.pop_back();
        }
        dfs(candidates, target, res, ans, idx+1, sum);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        dfs(candidates, target, res, ans, 0, 0);
        return res;
    }
};