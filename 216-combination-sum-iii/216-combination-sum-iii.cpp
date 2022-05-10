class Solution {
public:
    // using take not take approach
    // tc - o(2^n*k)
    void helper(int i, int k, int target, vector<int>& ds, vector<vector<int>>& res) {
        if(ds.size() >= k) {
            if(target==0) {
                res.push_back(ds);
            }
            return;
        }
        
        if(i>9) return;
        
        if(i <= target) {
            ds.push_back(i);
            helper(i+1,  k, target-i, ds, res);
            ds.pop_back();
        }
        helper(i+1, k, target, ds, res);
        return;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> ds;
        helper(1, k, n, ds, res);
        
        return res;
    }
};