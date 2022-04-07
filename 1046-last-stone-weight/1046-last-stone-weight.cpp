class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        for(int i: stones) pq.push(i);
        
        while(pq.size()>1) {
            int last = pq.top();pq.pop();
            int secondlast = pq.top();pq.pop();
            
            pq.push(abs(last-secondlast));
        }
        return pq.top();
    }
};