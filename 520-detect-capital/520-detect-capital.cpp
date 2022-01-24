class Solution {
public:
    //brute force
    // tc - o(n)
    // sc- o(n)
    bool detectCapitalUse(string word) {
        int uc = 0, lc = 0, n = word.size();
        
        for(char c: word) {
            if(islower(c)) lc++;
            else uc++;
        }
        
        // when all are upper or lower
        if(uc == n || lc == n) {
            return true;
        }
        
        // when only first letter is cap
        if(isupper(word[0]) && lc == n-1) {
            return true;
        }
        
        return false;
    }
};