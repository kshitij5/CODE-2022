class Solution {
public:
    void update(vector<vector<int>>& temp, vector<vector<int>>& board, int i, int j, int n, int m) {
        vector<pair<int, int>> coordinates = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        
        int sum = 0;
        for(auto it: coordinates) {
            int x = it.first+i, y = it.second+j;
            if((x >= 0 && x < n) && (y >= 0 && y < m)) {
                sum += board[x][y];
            }
        }
        
        if(sum < 2 || sum > 3) {
            temp[i][j] = 0;
        } else if((sum == 2 || sum == 3) && board[i][j] == 1) {
            temp[i][j] = 1;
        } else if(sum == 3 && board[i][j] == 0) {
            temp[i][j] = 1;
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        
        vector<vector<int>> temp = board;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                update(temp, board, i, j, n, m);
            }
        }
        
        board = temp;
        return;
    }
};