class Solution {
public:
    void rec(vector<int>& candidates, int target, int idx, vector<int>& ans, vector<vector<int>>& res) {
        if(target <= 0) {
            res.push_back(ans);
            return;
        }
        
        for(int i=idx; i<candidates.size(); i++) {
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            
            ans.push_back(candidates[i]);
            rec(candidates, target-candidates[i], i+1, ans, res);
            ans.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> ans;
        
        rec(candidates, target, 0, ans, res);
        return res;
    }
};