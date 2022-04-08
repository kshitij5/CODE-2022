class KthLargest {
public:
//     // brute force gives tle
//     vector<int> dict;
//     int idx;
//     KthLargest(int k, vector<int>& nums) {
//         dict = nums;
//         idx = k;
//     }
    
//     int add(int val) {
//         dict.push_back(val);
//         sort(dict.begin(), dict.end(), greater<int>());
        
//         return dict[idx-1];
//     }
    
    // using priority queue
    priority_queue<int, vector<int>, greater<int>>pq;
    int idx;
    KthLargest(int k, vector<int>& nums) {
        idx = k;
        for(int i: nums) {
            pq.push(i);
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > idx) {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */