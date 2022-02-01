class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = INT_MIN, boughtAt = INT_MAX;
        
        for(int i: prices) {
            if(i<boughtAt) {
                boughtAt = i;
            }
            
            profit = max(profit, i-boughtAt);
        }
        
        return profit;
    }
};