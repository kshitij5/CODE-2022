class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int freq[7] = {0};
        int n = tops.size();
        int res = INT_MAX;
        
        for(int i=0; i<n; i++) {
            freq[tops[i]]++, freq[bottoms[i]]++;
        }
        
        for(int i=1; i<=6; i++) {
            if(freq[i]>=n) {
                cout << freq[i] << endl;
                res = min(res, isPossible(i, tops, bottoms));
                cout << res << endl;
            }
        }
        
        return res != INT_MAX ? res : -1;
    }
    
    int isPossible(int val, vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int top = 0, bottom = 0;
        
        for(int k=0; k<n; k++) {
            if(tops[k]==val && bottoms[k]==val) continue;
            else if(bottoms[k]==val)  top++;
            else if(tops[k]==val) bottom++;
            else return -1;
        }
        
        return min(top, bottom);
    }
};