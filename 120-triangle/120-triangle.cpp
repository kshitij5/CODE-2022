class Solution {
public:
//     int f(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
//         if(i==n-1) {
//             return triangle[i][j];
//         }
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int down = 1e9, right = 1e9;
//         down = f(i+1, j, n, triangle, dp);
//         if(j<=i) right = f(i+1, j+1, n, triangle, dp);
        
//         return dp[i][j] = triangle[i][j] + min(down, right);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
        
//         return f(0, 0, n, triangle, dp);
//     }
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<=i;j++) {
                if(i==n-1) {
                    dp[i][j] = triangle[i][j];
                    continue;
                }
                
                
                int down = 1e9, right = 1e9;
                down = dp[i+1][j];
                if(j<=i) right = dp[i+1][j+1];

                dp[i][j] = triangle[i][j] + min(down, right);
            }
        }
        
        return dp[0][0];
    }
};