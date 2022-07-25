class Solution {
public:
    // binary search
    // Time complexity: O(nLog m)
    // Space complexity: O(1)
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n = matrix.size(), m = matrix[0].size();
        
//         for(int i=0;i<n;i++) {
//             int lower = 0, higher = m-1;
            
//             if(target>=matrix[i][0] && target<=matrix[i][m-1]) {
//                 while(lower<=higher) {
//                     int mid = lower + (higher - lower)/2;

//                     int val = matrix[i][mid];

//                     if(val > target) {
//                         higher = mid-1;
//                     } else if(val < target) {
//                         lower = mid+1;
//                     } else {
//                         return true;
//                     }
//                 }
//             }
//         }
        
//         return false;
//     }
    
    // better optimised approach, based on given condition
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size()-1, m = matrix[0].size()-1;
        int row = 0, col = m;
        
        while(row <= n && col >= 0) {
            if(matrix[row][col] == target) {
                return true;
            } else if(target > matrix[row][col]) {
                row++;
            } else {
                col--;
            }
        }
        
        return false;
    }
};