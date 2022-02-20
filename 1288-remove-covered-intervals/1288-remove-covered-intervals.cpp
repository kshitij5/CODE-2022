class Solution {
public:
    static bool sortcol(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] <= v2[0];
    }
    
    // using brute force
    // tc - o(nlog n)
    // sc - o(n)
//     int removeCoveredIntervals(vector<vector<int>>& intervals) {
//         // the first and foremost step is to sort the array
//         sort(intervals.begin(), intervals.end(), sortcol);
        
//         int count = 0;
//         // for(auto it: intervals) {
//         //     cout << it[0] << " "<< it[1] << endl;
//         // }
//         int n = intervals.size();
//         stack<vector<int>> st;
//         st.push(intervals[0]);
        
//         for(int i=1; i<n; i++) {
//             vector<int> last = st.top();
//             if(last[0] == intervals[i][0]) {
//                 if(last[1] < intervals[i][1]) {
//                     st.pop();
//                     st.push(intervals[i]);
//                 }
//             } else {
//                 if(intervals[i][1] > last[1]) {
//                     st.push(intervals[i]);
//                 }
//             }
//         }
        
//         return st.size();
//     }
    
    // slight better solution using o(1) sc
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // sorting the intervals(vector)
        sort(intervals.begin(), intervals.end());        
           
        int x1 = intervals[0][0];
        int x2 = intervals[0][1];
        
		 int res = 1;  //one for x1 and x2;
		
		// if a[i][0] && a[i][1] both greater than a[i-1][0] && a[i-1][1]
		// increase the cnt.
        for(int i= 1; i<intervals.size(); ++i) {
            if(intervals[i][0] > x1 && intervals[i][1] > x2)
                ++res;
            
			// updating x1 & x2 with next intervals
			// as we are comparing from upcoming ones.
            if(intervals[i][1] > x2) {
                x1 = intervals[i][0];
                x2 = intervals [i][1];
            }
        }
        
        return res;       // return cnt
    }
};