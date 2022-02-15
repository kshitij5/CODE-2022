class Solution {
public:
    // brute force
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        
        unordered_map<int, int> mp;
        for(int i: nums) mp[i]++;
        
        for(auto it: mp) {
            if(it.second == 1) return it.first;
        }
        return nums[0];
    }
};