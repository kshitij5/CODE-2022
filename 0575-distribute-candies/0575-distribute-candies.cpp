class Solution {
public:
    int distributeCandies(vector<int>& a) {
        set<int> s(a.begin(), a.end());
        return min(a.size()/2, s.size());
    }
};