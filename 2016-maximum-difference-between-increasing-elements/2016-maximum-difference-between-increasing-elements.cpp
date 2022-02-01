class Solution {
public:
    // using two pointers
    int maximumDifference(vector<int>& nums) {
        int i = 0, j = 0, mx = INT_MIN;
        
        for(j=0; j<nums.size(); j++) {
            if(nums[j] < nums[i]) {
                i = j;
            }
            
            mx = max(mx, nums[j] - nums[i]);
        }
        
        return mx>0?mx:-1;
    }
};