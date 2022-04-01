class Solution {
public:
    // // brute force, iterative
    // bool isPowerOfTwo(int n) {
    //     if (n <= 0) return false;
    //     while (n%2 == 0) n/=2;
    //     return n == 1;
    // }
    
    // recursive
    // bool isPowerOfTwo(int n) {
    //     if(n<=0) return false;
    //     return ((n==1) || (n%2==0 && isPowerOfTwo(n/2)));
    // }
    
    // using log
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return ceil(log2(n)) == floor(log2(n));
    }
};