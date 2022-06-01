class Solution {
public:
    // brute force
    // Time Complexity : O(N*k), where N is the size of string and k is length of binary code.
    // Space Complexity : O(N*k)
    bool hasAllCodes(string s, int k) {
        if(s.size() <= k) return false;
        set<string> codes;
        
        for(int i=0; i<=s.size()-k; i++) {
            string str = s.substr(i, k);
            codes.insert(str);
            // cout << str << endl;
        }
        
        return codes.size() == (1 << k);
    }
    
    
};