class Solution {
public:
    // brute force 
    // tc - o(n)
    // sc - o(1)
    vector<int> countBits(int n) {
        if(n==0) return {0};
        if(n==1) return {0, 1};
        
        vector<int> res;
        res.push_back(0);
        res.push_back(1);
        
        int indx = 0, next = 2;
        for(int i=2; i<=n; i++) {
            res.push_back(1+res[indx++]);
            
            if(indx == next) {
                indx = 0;
                next *= 2;
            }
        }
        return res;
    }
};