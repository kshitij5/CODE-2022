class Solution {
public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size();
        
//         for(int i=0; i<n; i++) {
//             int idx = nums[i]-1;
//             if(nums[idx] < 0) return nums[i];
            
//             nums[idx] *= -1;
//         }
        
//         return -1;
//     }
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int last = -1;
        for(int i: nums) {
            if(i==last) return i;
            last = i;
        } 
        return -1;
    }
};