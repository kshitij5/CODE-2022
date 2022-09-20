class Solution {
public:
    int f(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        // base case
        if(i==0){
           return matrix[i][j]; 
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int rd = 1e9, top=1e9, ld = 1e9;
        
        if(j-1>=0)  rd = f(i-1, j-1, n, matrix, dp);
        top = f(i-1, j, n, matrix, dp);
        if(j+1<n) ld = f(i-1, j+1, n, matrix, dp);
        
        return dp[i][j] = matrix[i][j] + min({top, rd, ld});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res = INT_MAX;
        int n = matrix.size(), m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        for(int i=0;i<m;i++) {
            res = min(res, f(n-1, i, n, matrix, dp));
        }
        
        return res;
    }
};