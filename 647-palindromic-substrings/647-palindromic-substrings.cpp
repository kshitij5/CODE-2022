class Solution {
public:
    int isPalindrome(string S) {
        for (int i = 0; i < S.length() / 2; i++) {
            if (S[i] != S[S.length() - i - 1]) {
                return 0;
            }
        }
        return 1;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        
        for(int gap=1; gap<=n; gap++) {
            for(int i=0; i<=n-gap; i++) {
                if(isPalindrome(s.substr(i, gap))) count++;
            }
        }
        
        return count;
    }
};