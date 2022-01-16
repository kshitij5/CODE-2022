class Solution {
public:
    // using two pointers
    // tc - o(n)
    // sc - o(1)
    int maxDistToClosest(vector<int>& seats) {
        // there can be three condition
        /// 1. max empty is at left
        /// 2. max empty is at right
        /// 3. max empty is at middle anywhere
        int lastfilled = -1;
        int pos = 0;
        
        int n = seats.size();
        for(int i=0; i<n; i++) {
            if(seats[i]) {
                // handling 1st case
                if(lastfilled == -1) {
                    pos = i;
                }
                // else 3rd case
                pos = max((i-lastfilled)/2, pos);
                lastfilled = i;
            }
        }
        
        // handling 2nd case
        if(lastfilled < n-1) {
            pos = max(pos, n - lastfilled - 1);
        }
        
        return pos;
    }
};