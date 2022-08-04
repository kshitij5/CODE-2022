class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> val;
        
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            if(nums[i]>0) val.insert(nums[i]);
        }
        
        return val.size();
    }
};