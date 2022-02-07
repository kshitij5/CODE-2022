class Solution {
public:
    // brute force
    // tc - 0(nlog n)
    // sc - o(1)
//     char findTheDifference(string s, string t) {
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
        
//         for(int i=0; i<t.size(); i++) {
//             if(s[i] != t[i]) {
//                 return t[i];
//             }
//         }
        
//         return t[t.size()-1];
//     }
    
    // optimized
    // tc - 0(n)
    // sc - o(1)
    char findTheDifference(string s, string t) {
        int count = 0;
        for(auto i: t){
            count += (i-'a');
        }
		
        for(auto i: s) count -= (i-'a');
        
        return 'a' + count;
    }
};