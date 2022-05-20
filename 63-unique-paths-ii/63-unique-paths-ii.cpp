class Solution {
public:
    // dfs + dp solution
    // tc-O(m*n)
    // sc-O(m*n)
//     vector<vector<int>> dp;
//     int dfs(vector<vector<int>>& obstacleGrid, int i, int j, int n, int m) {
//         if(dp[i][j]) return dp[i][j];
        
//         if(i<0 || j<0 || i>=n || j>=m || obstacleGrid[i][j]) {
//             return 0; 
//         }
        
//         if(i == n-1 && j == m-1) {
//             return 1;
//         }
        
//         return dp[i][j] = dfs(obstacleGrid, i, j+1, n, m) + dfs(obstacleGrid, i+1, j, n, m);
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int n = obstacleGrid.size(), m = obstacleGrid[0].size();
//         dp.resize(n+1,vector<int>(m+1,0));
        
//         return dfs(obstacleGrid, 0, 0, n, m);
//     }
    
    
    // using 2d tabular dp - intuitive solution
    // tc-O(m*n)
    // sc-O(m*n)
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int m = obstacleGrid.size() , n = obstacleGrid[0].size();
    //     vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    //     dp[0][1] = 1;
    //     for(int i = 1 ; i <= m ; ++i)
    //         for(int j = 1 ; j <= n ; ++j)
    //             if(!obstacleGrid[i-1][j-1])
    //                 dp[i][j] = dp[i-1][j]+dp[i][j-1];
    //     return dp[m][n];
    // }  
    
    // dp iterative
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = size(grid), n = size(grid[0]);
        vector<vector<int> > dp (m + 1, vector<int>(n + 1));
        if(!grid[0][0])
            dp[0][0] = 1;
        
        for(int i = 1; i < n; i++) {
            if(!grid[0][i]) dp[0][i] = dp[0][i-1];
        }
        
        for(int i = 1; i < m; i++) {
            if(!grid[i][0]) dp[i][0] = dp[i-1][0];
        }
        
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                if(!grid[i][j])
                    dp[i][j] =  dp[i - 1][j] + dp[i][j - 1];
        
        return dp[m-1][n-1];
    }
};