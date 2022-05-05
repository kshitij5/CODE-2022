class Solution {
public:
    // brute force
    // tc - o(n2)
    // sc - o(1)
//     int maxOperations(vector<int>& nums, int k) {
//         int count = 0, n = nums.size();
        
//         sort(nums.begin(), nums.end());
        
//         for(int i=0; i<n-1; i++) {
//             if(nums[i]==0)continue;
//             for(int j=i+1; j<n; j++) {
//                 if(nums[i]+nums[j] == k) {
//                     nums[i] = 0;
//                     nums[j] = 0;
//                     count++;
//                     break;
//                 }
//                 if(nums[i]+nums[j] > k) break;
//             }
//         }
//         return count;
//     }
    
//     // two pointers approach
//     // tc - o(nlogn)
//     // sc - o(1)
//     int maxOperations(vector<int>& nums, int k) {
//         int count = 0, n = nums.size();
        
//         sort(nums.begin(), nums.end());
//         int left=0, right = n-1;
        
//         while(left < right) {
//             int sum = nums[left] + nums[right];
            
//             if(sum > k) {
//                 right--;
//             } else if( sum < k) {
//                 left++;
//             } else {
//                 left++, right--;
//                 count++;
//             }
//         }
        
//         return count;
//     }
    
    // using map and disjoint sum pair formula
    // tc - o(n)
    // sc - o(n)
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int count = 0;
        
        for(int i: nums) {
            map[i]++;
        }
        
        for(auto i: map) {
            int x = i.first;
            if(map.find(k-x) != map.end()) {
                if(k-x != x) {
                    count += min(i.second, map[k-x]);
                    map[x] = 0;
                    map[k-x] = 0;
                } else {
                    count += floor(i.second/2);
                    map[x] = 0;
                }
            }
        }
        
        return count;
    }
    
};