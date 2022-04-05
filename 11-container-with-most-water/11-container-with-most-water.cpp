class Solution {
public:
    // two pointers
    int maxArea(vector<int>& h) {
        int left = 0, mx = 0, right = h.size()-1;
        
        while(left<=right) {
            mx = max(mx, min(h[left], h[right]) * (right - left));
            
            if(h[right] >= h[left]) {
                left++;
            } else {
                right--;
            }
        }
        
        return mx;
    }
};