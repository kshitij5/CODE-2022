class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        vector<int> res(n);
        
        for(int i=0; i<n; i++) {
            if(nums[i]&1) {
                res[right--] = nums[i];
            }else{
                res[left++] = nums[i];
            }
        }
        
        return res;
    }
};