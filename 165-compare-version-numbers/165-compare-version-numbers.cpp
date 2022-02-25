class Solution {
public:
    // brute force
    // tc - o(N)
    // sc - o(n)
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        
        v1 = version(version1);
        v2 = version(version2);
        
        while(v1.size()>v2.size()) v2.push_back(0);
        while(v2.size()>v1.size()) v1.push_back(0);
        
        for(int i=0; i<min(v1.size(), v2.size()); i++) {
            if(v1[i]>v2[i]) {
                return 1;
            }else if(v2[i] > v1[i]) {
                return -1;
            }
        }
        
        return 0;
    }
    
    vector<int> version(string v) {
        vector<int> r;
        string s="";
        v+='.';
        
        for(char i: v) {
            if(i=='.') {
                r.push_back(stoi(s));
                s = "";
                continue;
            }
            s+=i;
        }
        
        return r;
    }
};