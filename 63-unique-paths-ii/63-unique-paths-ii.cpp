class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& obstacleGrid, int i, int j, int n, int m) {
        if(dp[i][j]) return dp[i][j];
        
        if(i<0 || j<0 || i>=n || j>=m || obstacleGrid[i][j]) {
            return 0; 
        }
        
        if(i == n-1 && j == m-1) {
            return 1;
        }
        
        return dp[i][j] = dfs(obstacleGrid, i, j+1, n, m) + dfs(obstacleGrid, i+1, j, n, m);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        dp.resize(n+1,vector<int>(m+1,0));
        
        return dfs(obstacleGrid, 0, 0, n, m);
    }
};