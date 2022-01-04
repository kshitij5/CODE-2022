class Solution {
public:
    // dp based on matrix chain multiplication concept
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int gap = 0; gap < n; gap++) { // window size for each condition
            for(int i = 0, j = gap; j < n; i++, j++) {   // interval of each window acc. to gap
                int max = INT_MIN;      
                for(int k = i; k <= j; k++) {   // iteration over interval to find max
                    int left  = k == i ? 0 : dp[i][k - 1];
                    int right = k == j ? 0 : dp[k + 1][j];
                    
                    int val = (i == 0 ? 1 : nums[i-1]) * nums[k] * (j == n - 1 ? 1 : nums[j + 1]);
                    
                    int total = right + val + left;
                    
                    if(total > max ) max = total;
                }
                dp[i][j] = max;
            }
        }
        return dp[0][n - 1];
    }
};
// Refer this  video
// https://www.youtube.com/watch?v=YzvF8CqPafI&ab_channel=Pepcoding