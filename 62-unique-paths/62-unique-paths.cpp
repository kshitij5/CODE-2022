class Solution {
public:
//     int f(int i, int j, vector<vector<int>>&dp) {
//         //base case
//         if(i<0 || j<0) return 0;
//         if(i==0 && j==0) return 1;
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int up = f(i-1, j, dp);
//         int left = f(i, j-1, dp);
        
//         return dp[i][j] = up + left;
//     }
    
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m+1, vector<int>(n+1, 1));
        
//         for(int i=1;i<m;i++) {
//             for(int j=1;j<n;j++) {
//                 dp[i][j] = dp[i-1][j] + dp[i][j-1];
//             }
//         }
        
//         return dp[m-1][n-1];
//     }
    
    
    int uniquePaths(int m, int n) {
        vector<int> dp(vector<int>(n+1, 1));
        
        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                dp[j] = dp[j] + dp[j-1];
            }
        }
        
        return dp[n-1];
    }
};