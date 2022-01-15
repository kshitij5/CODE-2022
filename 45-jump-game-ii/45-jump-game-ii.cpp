class Solution {
public:
    // using dp
    // tc - o(n2)
    // sc - o(n)
    int jump(vector<int>& nums) {
        int n = size(nums);
        vector<int> dp(n, INT_MAX - 1);
        dp[n - 1] = 0;  // start from last index. No jumps required to reach end if we are already here
        // same as above. For each index, explore all jump sizes and use the one requiring minimum jumps to reach end
        for(int i = n - 2; i >= 0; i--) 
            for(int jumpLen = 1; jumpLen <= nums[i]; jumpLen++) 
                dp[i] = min(dp[i], 1 + dp[min(n - 1, i + jumpLen)]);  // min(n-1, i + jumpLen) for bounds handling
        return dp[0];
    }
};