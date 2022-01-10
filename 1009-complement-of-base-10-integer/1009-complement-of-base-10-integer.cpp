class Solution {
public:
    // brute force
    // tc - o(1) // since at most 32 iteration will be done
    // sc - o(1)
    
    // what we are doing is basically, converting bin to dec 
    // but instead, multiplying when digit is 0 and not 1
    // (obviously since we are finding complement)
    // eg - >>> 1       0       1       0   = 10
    //          2*0 +  2*1  +  2*0  +  2*3  = 5
    int bitwiseComplement(int n) {
	//only one case is exception because we can't handle  0 in while loop
        if(n == 0) return 1;
		
        int ans = 0, i = 0;
        while(n){
            if(n%2 == 0)
                ans += pow(2, i);   // all are we doing is right shifting a bit
            i++;  //i will increase every time because of shifting of bits
            n/=2;
        }
        return ans;
    }
};