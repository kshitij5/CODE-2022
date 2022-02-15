class Solution {
public:
    // brute force
//     int singleNumber(vector<int>& nums) {
//         if(nums.size()==1) return nums[0];
        
//         unordered_map<int, int> mp;
//         for(int i: nums) mp[i]++;
        
//         for(auto it: mp) {
//             if(it.second == 1) return it.first;
//         }
//         return nums[0];
//     }
    
    // using xor
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        //xor all numbers, the left over number would be the non repeated one
         // since the equl numbers cancel out each others bits
         int num = 0;
         for (int i = 0; i < n; ++i) {
             num ^= nums[i];
         }
        return num;
    }
};