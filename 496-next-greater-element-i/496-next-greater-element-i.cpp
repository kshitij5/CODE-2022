class Solution {
public: 
    // using stack and map
    // TC - O(num1.size() + nums2.size())
    // sc - O(num1.size())
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums) {
            while (s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> ans;
        for (int n : findNums) 
            ans.push_back(m.count(n) ? m[n] : -1);
        return ans;
    }
    
    // TC - O(num1.size() + nums2.size())
    // sc - O(num1.size())
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         unordered_map<int, int> map;
//         for(int i=0;i<nums2.size();i++) {
//             map[nums2[i]] = nextGreaterHelper(nums2, nums2[i], i+1);
//         }
        
//         vector<int> res;
//         for(int n: nums1) {
//             res.push_back(map[n]);
//         }
//         return res;
//     }
//     int nextGreaterHelper(vector<int>& nums2, int n, int i) {
//         int next = -1;
//         while(i<nums2.size()) {
//             if(nums2[i] > n){
//                 return nums2[i];
//             }
//             i++;
//         }
//         return next;
//     }
    
    
    // TC - O(num1.size()*nums2.size())
    // sc - O(num1.size())
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> res;
//         for(int n: nums1) {
//             res.push_back(nextGreaterHelper(nums2, n));
//         }
//         return res;
//     }
    
//     int nextGreaterHelper(vector<int>& nums2, int n) {
//         int next = -1;
//         for(int i=0;i<nums2.size();i++) {
//             if(nums2[i] == n) {
//                 while(i<nums2.size()) {
//                     if(nums2[i] > n){
//                         return nums2[i];
//                     }
//                     i++;
//                 }
//             }
//         }
//         return next;
//     }
};