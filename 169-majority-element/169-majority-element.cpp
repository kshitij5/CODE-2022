class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,  int> mp;
        
        for(int i: nums) mp[i]++;
        
        int mx = INT_MIN, res = 0;
        for(auto it: mp) {
            if(it.second > mx) {
                mx = it.second;
                res = it.first;
            }
        }
        
        return res;
    }
};