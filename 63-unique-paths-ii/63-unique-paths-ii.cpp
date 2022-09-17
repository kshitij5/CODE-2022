class Solution {
public:
    // recursion
//     int f(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
//         // base case
//         if(i==0 && j==0) return obstacleGrid[i][j]==0;
//         if( i<0 || j<0 )return 0;
//         if(obstacleGrid[i][j]) return 0;
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int up = f(i-1, j, obstacleGrid, dp);
//         int left = f(i, j-1, obstacleGrid, dp);
        
//         return dp[i][j] = up+left;
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int n = obstacleGrid.size(), m = obstacleGrid[0].size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         return f(n-1, m-1, obstacleGrid, dp);
//     }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        // dp[0][0] = obstacleGrid[i][j]==0;
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) { //base conditions
              if(obstacleGrid[i][j]==1){
                dp[i][j]=0;
                continue;
              }
              if(i==0 && j==0){
                  dp[i][j]=obstacleGrid[i][j]==0;
                  continue;
              }

              int up=0;
              int left = 0;

              if(i>0) 
                up = dp[i-1][j];
              if(j>0)
                left = dp[i][j-1];

              dp[i][j] = up+left;
            }
        }
        
        return dp[n-1][m-1];
    }
};