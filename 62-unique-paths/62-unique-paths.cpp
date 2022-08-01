class Solution {
public:
    // using 2d tabular dp - intuitive solution
    // tc-O(m*n)
    // sc-O(m*n)
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n, 1));
    //     for (int i = 1; i < m; i++) {
    //         for (int j = 1; j < n; j++) {
    //             dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    //         }
    //     }
    //     return dp[m - 1][n - 1];
    // }
    
    // using 1d tabular dp
    // tc-O(m*n)
    // sc-O(n)
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[n - 1];
    }
    
    // is also possible in o(1) sc
};