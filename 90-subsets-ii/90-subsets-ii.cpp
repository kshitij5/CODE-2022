class Solution {
public:
    void f(int n, vector<int> &arr, vector<int>& temp, set<vector<int>>& res, int i) {
        // base case
        if(i==n) {
            res.insert(temp);
            return;
        }

        temp.push_back(arr[i]);
        f(n, arr, temp, res, i+1);
        temp.pop_back();
        f(n, arr, temp, res, i+1);

        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> res;
        vector<int> t;
        sort(nums.begin(), nums.end());
        f(n, nums, t, res, 0);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};