class Solution {
public:
    // brute force
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), start = -1, end = -1;
        
        for(int i=0;i<n;i++) {
            if(nums[i]==target && start == -1) {
                start = i;
            }
            
            if(nums[n-i-1] == target && end == -1) {
                end = n-i-1;
            }
            
            if(start!=-1 && end!=-1) break;
        }
        
        return {start, end};
    }
};