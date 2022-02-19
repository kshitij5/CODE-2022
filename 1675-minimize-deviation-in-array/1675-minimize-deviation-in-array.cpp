class Solution {
public:
    // don't know
    int minimumDeviation(vector<int>& nums) {
        //convert all the odds to even
        priority_queue<int> pq;
        int mn = INT_MAX;
        for(int i: nums) {
            if(i%2==1) i*=2;
            mn = min(mn, i);
            pq.push(i);
        }
        
        int diff = INT_MAX;
        while(pq.top()%2==0) {
            int mx = pq.top(); pq.pop();
            diff = min(diff, mx-mn);
            mn = min(mx/2, mn);
            pq.push(mx/2);
        }
        
        return min(diff, pq.top() - mn);
    }
};