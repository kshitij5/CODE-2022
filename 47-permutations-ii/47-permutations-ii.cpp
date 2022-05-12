class Solution {
public:
    // using recursion
    // tc - O(2^n * n * logn)
    // sc - O(2^n + n + n)
    // auxillary spce - O(n)
    void helper(vector<int>& nums, vector<int>& ds, set<vector<int>>& res, vector<int>& isVisited) {
        // base case
        if(nums.size() == ds.size()) {
            res.insert(ds);
            return;
        }
        
        for(int i=0; i<nums.size(); i++) {
            if(!isVisited[i]) {
                // if already not visited
                isVisited[i] = 1;
                ds.push_back(nums[i]);
                helper(nums, ds, res, isVisited);
                // backtracking basically [removing and unchecking]
                ds.pop_back();
                isVisited[i] = 0;
            }
        }
        
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> isVisited(nums.size(), 0), ds;
        
        helper(nums, ds, res, isVisited);
        
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};