class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        set<char> set;
        int i = 0, j = 0;
        int n = s.size();

        while(i<n && j<n) {
            if(set.find(s[j]) != set.end()){
                set.erase(s[i++]);
            }else{
                set.insert(s[j++]);
                longest = max(longest, j-i);
            }
        }
        return longest;
    }
};
