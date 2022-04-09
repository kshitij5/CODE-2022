class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
    // brute force
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i: nums) freq[i]++;
        
        vector<pair<int, int>> srt;
        for(auto it: freq)srt.push_back({it.first, it.second});
        
        sort(srt.begin(), srt.end(), cmp);
        
        vector<int> ans;
        for(auto it: srt) {
            ans.push_back(it.first);
            k--;
            if(k<=0) break;
        }
        
        return ans;
    }
};