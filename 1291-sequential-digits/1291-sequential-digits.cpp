class Solution {
public:
    // brute forced
    // tc - o(no. of sequential digits)
    // sc - o(1)
    vector<int> sequentialDigits(int low, int high) {
        int first[] = {0, 1, 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789};
        int factors[] = {0, 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};
        int mn = to_string(low).length(), mx = to_string(high).length();
        
        vector<int> res;
        for(int k=mn; k<=min(mx+1, 9); k++) {
            int factor = factors[k];
            int turns = 9-k+1;
            int next = first[k];
            while(turns-- && next <= high) {
                if(next >= low)
                    res.push_back(next);
                next += factor;
            }
            
            if(next > high) break;
        }
        return res;
    }
};