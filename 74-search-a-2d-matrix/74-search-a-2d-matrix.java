class Solution {
    // using binary search
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length, m = matrix[0].length;
        
        for(int i=0; i<n; i++) {
            int left = 0, right = m-1;
            
            if(target >= matrix[i][left] && target <= matrix[i][right]) {
                while(left<=right) {
                    int mid = left + (right-left) / 2;
                    
                    if(matrix[i][mid] == target) {
                        return true;
                    }else if(target > matrix[i][mid]) {
                        left = mid+1;
                    }else {
                        right = mid-1;
                    }
                }
                break;
            }
        }
        
        return false;
    }
}