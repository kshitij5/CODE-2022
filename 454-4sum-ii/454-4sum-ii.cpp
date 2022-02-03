class Solution {
public:
//     //brute force
//     // tc - o(n4)
//     // sc - o(1)
//     // tle
//     int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
//         int n = nums1.size(), count = 0;
//         for(int i=0; i<n; i++) {
//             for(int j=0; j<n; j++) {
//                 for(int k=0; k<n; k++) {
//                     for(int l=0; l<n; l++) {
//                         if(nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0) {
//                             count++;
//                         }
//                     }
//                 }
//             }
//         }
        
//         return count;
//     }
    
//     //brute force with optimization
//     // tc - o(n3)
//     // sc - o(n)
//     // tle
//     int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
//         int n = nums1.size(), count = 0;
//         unordered_map<int, int> mp;
        
//         for(int i=0; i<n; i++) {
//             mp[nums4[i]]++;    
//         }
        
//         for(int i=0; i<n; i++) {
//             for(int j=0; j<n; j++) {
//                 for(int k=0; k<n; k++) {
//                     int sum = nums1[i] + nums2[j] + nums3[k];
                    
//                     if(mp.find(-sum)!=mp.end()) {
//                         count++;
//                     }
//                 }
//             }
//         }
        
//         return count;
//     }
    
    //brute force with optimization
    // tc - o(n2)
    // sc - o(n)
    // tle
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size(), count = 0;
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int sum = nums3[i] + nums4[j];
                
                mp[sum]++;
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int sum = nums1[i] + nums2[j];

                if(mp.find(-sum)!=mp.end()) {
                    count += mp[-sum];
                }
            }
        }
        
        return count;
    }

};