class Solution {
public:
    // using map and two pointer
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> res;
        vector<int> lastloc(26);
        
        for(int i=0; i<n; i++) {
            lastloc[s[i]-'a'] = i;
        }
        
        int left = 0;
        int maxlength = lastloc[s[0]-'a'];
        
        for(int i=1; i<n; i++) {
            if(i>maxlength) {
                // cout<<s[i] << maxlength << endl;
                res.push_back(maxlength-left+1);
                left = i;
            }
            maxlength = max(maxlength, lastloc[s[i]-'a']);
        }
        res.push_back(maxlength-left+1);
        
        return res;
    }
};