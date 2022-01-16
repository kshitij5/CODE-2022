class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        // there can be three condition
        ///max empty is at left
        /// max empty is at right
        ///max empty is at middle anywhere
        int lastfilled = -1;
        int pos = 0;
        
        int n = seats.size();
        for(int i=0; i<n; i++) {
            if(seats[i]) {
                if(lastfilled == -1) {
                    pos = i;
                }
                pos = max((i-lastfilled)/2, pos);
                lastfilled = i;
            }
        }
        
        if(lastfilled < n-1) {
            pos = max(pos, n - lastfilled - 1);
        }
        
        return pos;
    }
};