class Solution {
public:
    
// 	int f(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>&dp) {
// 	    // base case
// 	    if(i==n-1 && j==m-1) return grid[i][j];
	    
// 	    if(i<0 || j<0 || i>=n || j>=m) return 1e9;
	    
	    
// 	    if(dp[i][j]!=-1) return dp[i][j];
	    
// 	    int right = f(i, j+1, n, m, grid, dp);
// 	    int down = f(i+1, j, n, m, grid, dp);
	    
	    
// 	    return dp[i][j] = grid[i][j]+min(down, right);
	    
// 	}
//     int minPathSum(vector<vector<int>>& grid) {
        
//         int n = grid.size(), m = grid[0].size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
//         return f(0, 0, n, m, grid, dp);
//     }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<int> dp(m+1,0);
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i==0 && j==0) {
                    dp[j] = grid[i][j];
                    continue;
                }
                
                int left = INT_MAX, up = INT_MAX;
                if(i>0) up = dp[j];
                if(j>0) left = dp[j-1];
                
                dp[j] = grid[i][j] + min(up, left);
            }
        }
        
        return dp[m-1];
    }
};