class Solution {
public:
    // using map
    // tc - o(n)
    // sc - o(1)
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> mp;
        mp.clear();
        
         for(auto it: trips) {
            int person = it[0];
            int from = it[1];
            int to = it[2];
            // no. of person that will enter the car at the 'from' position
            // {start, persons}
            mp[from] += person;     
			                            
            // no. of person that will leave the car at that 'to' position
            // {end, -persons}
            mp[to] -= person;     
			                               
        }
        
        int person = 0;
        for(auto x : mp){
            person += x.second;
            // checking if person exceed the required capacity 
            if(person > capacity){     
                return false;
            }
            else if(person < 0){
                person = 0;
            }
        }
        
        return true;
    }
};