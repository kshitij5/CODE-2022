class Solution {
public:
    // brute force
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int,  int> mp;
        
//         for(int i: nums) mp[i]++;
        
//         int mx = INT_MIN, res = 0;
//         for(auto it: mp) {
//             if(it.second > mx) {
//                 mx = it.second;
//                 res = it.first;
//             }
//         }
        
//         return res;
//     }
    
    // using boyce moore majority voting algo
    int majorityElement(vector<int>& nums) {
        int count=0, res = 0;
        for (int num: nums) {
            if (count == 0)
                res = num;
            if (num != res)
                count--;
            else
                count++;
        }
        return res;
    }
};