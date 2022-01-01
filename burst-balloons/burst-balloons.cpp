class Solution {
   public:
    // dp based on matrix chain multiplication concept
      int maxCoins(vector<int>& nums) {
         int n = nums.size();
          
         vector<vector<int>> dp(n, vector<int>(n));

         for (int g = 0; g < n; g++) {
            for (int i = 0, j = g; j < n; i++, j++) {
               int max = INT_MIN;
                
               for (int k = i; k <= j; k++) {
                  int left = (k == i ? 0 : dp[i][k - 1]);
                  int right = (k == j ? 0 : dp[k + 1][j]);
                   
                  int val = (i == 0 ? 1 : nums[i - 1]) * nums[k] * (j == n-1 ? 1 : nums[j + 1]);

                  int total = left + right + val;

                  if(total > max) max = total;
               }

               dp[i][j] = max;
            }
         }

         return dp[0][n - 1];
      }
};

int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()));
    
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                cout<<i<<" "<<j<<endl;
                int mx=0;
                for(int k=i;k<=j;k++){
                    int lr= k==i ? 0 : dp[i][k-1];
                    int rr= k==j ? 0 : dp[k+1][j];
                    int curr= (i==0?1:nums[i-1]) *(nums[k]) *(j==n-1?1:nums[j+1]);
                    mx=max(mx,lr+rr+curr);
                }
                dp[i][j]=mx;
            }
        }
        return dp[0][n-1];
    }
	// Refer this  video
	// https://www.youtube.com/watch?v=YzvF8CqPafI&ab_channel=Pepcoding