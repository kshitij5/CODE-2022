class Solution {
public:
    // using recursion and backtracking
    // tc - O(2^n * n * logn)
    // sc - O(2^n + n + n)
    // auxillary spce - O(n)
//     void helper(vector<int>& nums, vector<int>& ds, set<vector<int>>& res, vector<int>& isVisited) {
//         // base case
//         if(nums.size() == ds.size()) {
//             res.insert(ds);
//             return;
//         }
        
//         for(int i=0; i<nums.size(); i++) {
//             if(!isVisited[i]) {
//                 // if already not visited
//                 isVisited[i] = 1;
//                 ds.push_back(nums[i]);
//                 helper(nums, ds, res, isVisited);
//                 // backtracking basically [removing and unchecking]
//                 ds.pop_back();
//                 isVisited[i] = 0;
//             }
//         }
        
//         return;
//     }
    
    
    // using recursion and backtracking without using extra space
    // tc - O(2^n * n * logn)
    // sc - O(2^n)
    // auxillary spce - O(n)
    void helper(int i, vector<int> nums, vector<vector<int>>& res) {
        // base case
        if(i >= nums.size()) {
            res.push_back(nums);
            return;
        }
        
        for (int j = i; j < nums.size(); j++) {
            if (j == i || nums[j] != nums[i]) {
                swap(nums[i], nums[j]);
                helper(i + 1, nums, res);
            }
        }
        
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        helper(0, nums, res);
        return res;
    }
};