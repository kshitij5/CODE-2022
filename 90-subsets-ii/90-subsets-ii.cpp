class Solution {
public:
    // using set
    // tc - : O( 2^n *(k log (x) ))
//     void f(int n, vector<int> &arr, vector<int>& temp, set<vector<int>>& res, int i) {
//         // base case
//         if(i==n) {
//             res.insert(temp);
//             return;
//         }

//         temp.push_back(arr[i]);
//         f(n, arr, temp, res, i+1);
//         temp.pop_back();
//         f(n, arr, temp, res, i+1);

//         return;
//     }
    void f(int n, vector<int> &arr, vector<int>& temp, vector<vector<int>>& res, int idx) {
        res.push_back(temp);
        
        for(int i = idx; i<n; i++) {
            if (i != idx && arr[i] == arr[i - 1]) continue; 
            temp.push_back(arr[i]);
            f(n, arr, temp, res, i+1);
            temp.pop_back();
        }

        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> t;
        sort(nums.begin(), nums.end());
        f(n, nums, t, res, 0);
        // vector<vector<int>> ans(res.begin(), res.end());
        return res;
    }
};