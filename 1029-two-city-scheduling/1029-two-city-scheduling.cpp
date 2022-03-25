class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<vector<int>> impact;
        int n = costs.size();
        
        // 1. first we need to calculate the impacts
        // -ve means its better to fly to city a
        // +ve means its better to fly to city b
        for(int i=0; i<n; i++) {
            int impct = costs[i][0] - costs[i][1];
            impact.push_back({impct, i});
        }
        
        // 2. sort the impacts according to their values
        sort(impact.begin(), impact.end());
        
        int sum = 0, k = n/2;
        
        // 3. since already sorted, we can assume that
        // choosing first n/2 people to go to city a
        // and next n/2 people to go to city b will give us
        // the most optimised result
        for(auto it: impact) {
            // cout << it[0] << " " << it[1] << endl;
            if(k>0) sum += costs[it[1]][0], k--;
            else sum += costs[it[1]][1];
        }
        
        return sum;
    }
};