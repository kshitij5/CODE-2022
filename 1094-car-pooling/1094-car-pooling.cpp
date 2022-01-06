class Solution {
public:
    // This makes the sort be according to column 2 and ascending
    static bool sortFunc( const vector<int>& p1, const vector<int>& p2 ) {
        return p1[1] < p2[1];
    }
    
    // brute force
    // tc - o(n)
    // sc - o(1)
    // note: doesn't work for all the cases
//     bool carPooling(vector<vector<int>>& trips, int capacity) {
//       // Do the sorting according to column 2
//         sort(trips.begin(), trips.end(), sortFunc);
        
//         int lastto = 0, lastfrom = 0, lastcap = 0;
//         for(auto it: trips) {
//             int cap = it[0];
//             int from = it[1];
//             int to = it[2];
            
//             // if the curr trip starts before the end of last trip
//             if(from < lastto) {
//                 int total = lastcap + cap;
//                 if(total > capacity) return false;
//             }
            
//             // if the curr trip is just a sub trip of last trip
//             // in that case last capacity would be some of total passenger
//             if(lastto < to)
//                 lastcap = cap;
//             else    lastcap += cap;
            
            
//             lastto = to;
//             lastfrom = from;
            
//         }
        
//         return true;
//     }
    
    // using map
    // tc - o(n)
    // sc - o(n)
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> mp;
        mp.clear();
        for(int i=0; i<trips.size(); i++){
            int person = trips[i][0];
            mp[trips[i][1]] += person;     // no. of person that will enter the car at the 'from' position
			                               // {start, persons}
            mp[trips[i][2]] -= person;     // no. of person that will leave the car at that 'to' position
			                               // {end, -persons}
        }
        
        int person = 0;
        
        for(auto x : mp){
            person += x.second;
            if(person > capacity){     // checking if person exceed the required capacity 
                return false;
            }
            else if(person < 0){
                person = 0;
            }
        }
        
        return true;
    }
};