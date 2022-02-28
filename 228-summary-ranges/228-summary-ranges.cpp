class Solution {
public:
    // brute force
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.empty()) return res;
        if(nums.size()<2) return {to_string(nums[0])};
        
        int start=0, end=0;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == nums[i-1] + 1) {
                end++;
            }else{
                if(start == end) res.push_back(to_string(nums[start]));
                else res.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
                
                start = i;
                end = i;
            }
        }

        if(start == end) res.push_back(to_string(nums[start]));
        else res.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
        
        return res;
    }
};