class Solution {
public:
//     // dfs
//     // tc - o(m*n * 4^(m*n))
//     // m*n -> double for loop
//     // 4^(m*n) -> for each value we can traverse further in 4directionly each m*n at worst case
//     vector<pair<int, int>> coordinates = {{-1,0},{1,0},{0,-1},{0,1}};
    
//     int dfs(vector<vector<int>>& matrix, int i, int j, int n, int m) {
//         int mx = 1;
//         for(auto it: coordinates) {
//             int x = it.first+i, y = it.second+j;
            
//             if(x>=m || y>=n || x<0 || y<0 || matrix[x][y] <= matrix[i][j]) continue;
//                 mx = max(mx, 1 + dfs(matrix, x, y, m, n));
//         }
        
//         return mx;
        
//     }
//     int longestIncreasingPath(vector<vector<int>>& matrix) {
        // int n = matrix.size(), m = matrix[0].size();
    
//         int len = INT_MIN;
//         for(int i=0; i<n; i++) {
//             for(int j=0; j<m; j++) {
//                 len = max(len, dfs(matrix, i, j, n, m));
//             }
//         }
        
//         return len;
//     }
    
     // dfs + dp
    // tc : O(n*m)
    // sc : O(n*m)
    vector<pair<int, int>> coordinates = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int> > dp; // dp[i][j] will store maximum path length starting from matrix[i][j]
    int maxPath, n, m;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        maxPath = 0, n = size(matrix), m = size(matrix[0]);
        dp.resize(n, vector<int>(m));
        // calculating maximum path from each cell and at last returning the maximum length
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                maxPath = max(maxPath, solve(matrix, i, j));            
        return maxPath;
    }
    // recursive solver for each cell with dp for storing each calculated result
    int solve(vector<vector<int>>& mat, int i, int j){
        if(dp[i][j]) return dp[i][j]; // return if result is already calculated
        dp[i][j] = 1;  // minimum path from each cell is always atleast 1
        // choosing each possible move available to us
        for(auto it: coordinates) { 
            int x = i + it.first, y = j + it.second;
            // bound checking as well as move to next cell only when it is greater in value
            if(x < 0 || y < 0 || x >= n || y >= m || mat[x][y] <= mat[i][j]) continue;
            // max( current optimal, select current + optimal solution after moves[k] from current cell
            dp[i][j] = max(dp[i][j], 1 + solve(mat, x, y));
        }         
        return dp[i][j];
    }
};