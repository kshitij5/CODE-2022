class Solution {
public:
    // the brute force
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int found = 0;
//         for(auto i: matrix) {
//             for(auto j: i) {
//                 if(j==target) {
//                     found = 1; break;
//                 }
//             }
//         }
        
//         return found;
//     }
    
    // better optimised, binary search
    // Time complexity: O(Log m + Log n)
    // Space complexity: O(1)

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int lower = 0, higher = n*m-1;
        
        while(lower<=higher) {
            int mid = lower + (higher - lower)/2;
            
            int val = matrix[mid/m][mid%m];
            
            if(val > target) {
                higher = mid-1;
            } else if(val < target) {
                lower = mid+1;
            } else {
                return true;
            }
        }
        
        return false;
    }
};