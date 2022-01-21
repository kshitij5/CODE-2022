class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        int totalcost = 0, totalgas = 0;
        for(int i = 0; i<n; i++) {
            totalcost += cost[i];
            totalgas += gas[i];
        }
        
        if(totalcost > totalgas) {
            return -1;
        }
        
        int tank = 0, start = 0;
        
        // we can only start from where diff of gas[i] - cost[i] is +ve
        for(int i = 0; i<n; i++) {
            tank += gas[i] - cost[i];
            
            if(tank < 0) {
                start = i+1;
                tank = 0;
            }
        }
        
        return start;
    }
};