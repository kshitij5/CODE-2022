class Solution {
public:
    void func(int idx, vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& res) {
        if(idx >= candidates.size()) return;
        if(target == 0) {
            res.push_back(curr);
            return;
        }
        
        if(candidates[idx] <= target) {
            curr.push_back(candidates[idx]);
            func(idx, candidates, target-candidates[idx], curr, res);
            curr.pop_back();
        }
        
        func(idx+1, candidates, target, curr, res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> res;
        
        func(0, candidates, target, curr, res);
        
        return res;
    }
};