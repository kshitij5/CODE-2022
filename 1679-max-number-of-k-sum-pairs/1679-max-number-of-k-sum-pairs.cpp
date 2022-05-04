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
    
    int maxOperations(vector<int>& nums, int k) {
        int count = 0, n = nums.size();
        
        sort(nums.begin(), nums.end());
        int left=0, right = n-1;
        
        while(left < right) {
            int sum = nums[left] + nums[right];
            
            if(sum > k) {
                right--;
            } else if( sum < k) {
                left++;
            } else {
                left++, right--;
                count++;
            }
        }
        
        return count;
    }
};