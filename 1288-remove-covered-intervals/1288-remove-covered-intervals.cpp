class Solution {
public:
    static bool sortcol(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] <= v2[0];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // the first and foremost step is to sort the array
        sort(intervals.begin(), intervals.end(), sortcol);
        
        int count = 0;
        // for(auto it: intervals) {
        //     cout << it[0] << " "<< it[1] << endl;
        // }
        int n = intervals.size();
        stack<vector<int>> st;
        st.push(intervals[0]);
        
        for(int i=1; i<n; i++) {
            vector<int> last = st.top();
            if(last[0] == intervals[i][0]) {
                if(last[1] < intervals[i][1]) {
                    st.pop();
                    st.push(intervals[i]);
                }
            } else {
                if(intervals[i][1] > last[1]) {
                    st.push(intervals[i]);
                }
            }
        }
        
        return st.size();
    }
};