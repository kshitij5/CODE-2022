class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() <= k) return false;
        set<string> codes;
        
        for(int i=0; i<=s.size()-k; i++) {
            string str = s.substr(i, k);
            codes.insert(str);
            // cout << str << endl;
        }
        
        return codes.size() == pow(2, k);
    }
};