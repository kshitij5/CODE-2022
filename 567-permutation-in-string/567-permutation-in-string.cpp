class Solution {
public:
    // Brute force approach
//     bool checkInclusion(string s1, string s2) {
        
//         int len1 = s1.size();
//         int len2  = s2.size();
        
//         if(len1>len2) return false;
        
//         int i = 0;
        
//         sort(s1.begin(), s1.end());
//         while(i<=len2-len1) {
//             string per = s2.substr(i, len1);
//             sort(per.begin(), per.end());
//             i++;
//             if(per == s1) return true;
//         }
        
//         return false;
//     }
    
    // using sliding window and map
    bool checkInclusion(string s1, string s2) {
        int sz1=s1.size();
        int sz2=s2.size();
        
        if(sz1>sz2)return false;
        
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        
        for(int i=0;i<sz1;i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        
        if(v1==v2)return true;
        
        for(int i=sz1;i<sz2;i++){
            v2[s2[i]-'a']++;
            v2[s2[i-sz1]-'a']--;
            
            if(v1==v2)return true;
        }
        
        return false;
    }
//     bool checkInclusion(string s1, string s2) {
//         int map[26] = {0};
//         // fincing freq of char of s1
//         for(char c : s1) map[c - 'a']++;
        
//         int j = 0, i = 0, count_chars = s1.size();
        
//         // traversing s2
//         while(j < s2.size()){
//             if(map[s2[j++] - 'a']-->0)
//                 count_chars--;
//             if(count_chars == 0) return true;
//             if(j - i == s1.size() && map[s2[i++] - 'a']++ >= 0)
//                 count_chars++;
//         }
//         return false;
//     }
};