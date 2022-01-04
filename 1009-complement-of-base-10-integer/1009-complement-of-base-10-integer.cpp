class Solution {
public:
    // brute force
    // tc - o(1) // since at most 32 iteration will be done
    // sc - o(1)
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
    
	// // bit manupulation (doesn't work, obviously for even numbers)
	// int bitwiseComplement(int n) {
	// //only one case is exception because we can't handle  0 in while loop
	// if(n == 0) return 1;
	// // when all bits be set, we have to return zeroe
	// if(((n + 1) & n) == 0) return 0;
	// // all are we doing is right shifting a bit of n
	// return n >> 1;
	// }
};