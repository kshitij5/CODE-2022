class Solution {
public:
    // couldn't work
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         if(n==0) return;
        
//         int i=0, j=0;
//         while(i<m && j<n) {
//             if(nums1[i]<=nums2[j]) {
//                 i++;
//             }else{
//                 swap(nums1[i], nums2[j]);
//                 j++;i++;
//             }
//         }
//         sort(nums2.begin(), nums2.end());
//         j=0;
//         while(j<n) {
//             nums1[i+j+1] = nums2[j];
//             j++;
//         }
        
//     }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0&&j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[k]=nums1[i];
                i--;
                k--;
            }
            else
            {
                nums1[k]=nums2[j];
                j--;
                k--;
            }
        }
        while(i>=0)
            nums1[k--]=nums1[i--];
        while(j>=0)
            nums1[k--]=nums2[j--];
    }
};