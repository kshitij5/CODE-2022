class Solution {
public:
    // brute force 
    // tc - o(n)
    
    // the logic here is derived from second point that judge will be trusted by everyone
    // so if anyone is trusted by n-1 people he must be the judge
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> judges (n+1);
        
        for(auto it: trust) { // loop through the 'trust' array
            int truster = it[0];
            int trusted = it[1];
            judges[truster]-- ; // if a given person trust someone then decrement the count of his index
            judges[trusted]++; // increment the count of the index whom he trusts
        }
        
        // In last, check the 'judges' array that if there is any index having count equals to n-1
        for(int i = 1; i <= n; i++){
            if(judges[i] == n - 1) return i; // person doesnt trust anybody but everyone else trust him. Return their index
        }
        return -1;
    }
};