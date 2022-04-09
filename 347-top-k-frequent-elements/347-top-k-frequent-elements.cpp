class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
//     // brute force
//     // tc - o(nlogn)
//     // sc - o(n)
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> freq;
//         for(int i: nums) freq[i]++;
        
//         vector<pair<int, int>> srt;
//         for(auto it: freq)srt.push_back({it.first, it.second});
        
//         sort(srt.begin(), srt.end(), cmp);
        
//         vector<int> ans;
//         for(auto it: srt) {
//             ans.push_back(it.first);
//             k--;
//             if(k<=0) break;
//         }
        
//         return ans;
//     }
    
    
//     // using priority queue
//     // tc - o(nlogn)
//     // sc - o(n)
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> freq;
//         for(int i: nums) freq[i]++;
        
//         priority_queue<pair<int, int>> pq;
//         for(auto it: freq) pq.push({it.second, it.first});
        
//         vector<int> res;
//         while(k--) {
//             pair<int, int> i = pq.top();
//             res.push_back(i.second);
//             pq.pop();
//         }
        
//         return res;
//     }
    
    // using bucket sort
    // tc - o(n)
    // sc - o(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int i: nums) freq[i]++;
        
        vector<vector<int>> buckets(n+1);
        for(auto it: freq) {
            buckets[it.second].push_back(it.first);
        }
        
        vector<int> res;
        while(k>0) {
            auto bucket = buckets.back();
            
            for(int i: bucket)
                res.push_back(i), k--;
            buckets.pop_back();
        }
        
        return res;
    }
};