class Solution {
public:
    // the brute force
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int found = 0;
        for(auto i: matrix) {
            for(auto j: i) {
                if(j==target) {
                    found = 1; break;
                }
            }
        }
        
        return found;
    }
};