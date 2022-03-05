class Solution {
public:
    // https://www.youtube.com/watch?v=qVfjmkL1naw
    int deleteAndEarn(vector<int>& nums) {
        int inc = 0, exc = 0;
        vector<int> v(10001); // since n <= 10000
        
        for(int i: nums) v[i]++;    
        
        for(int i=0; i<=10000; i++) {
            int temp1 = exc + v[i] * i; // if we include
            int temp2 = max(inc, exc);  // if we exclude
            
            inc = temp1;
            exc = temp2;
        }
        
        return max(inc, exc);
    }
};