class Solution {
public:
    // using map stl
    // tc - o(n)
    // sc - o(n)
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> mp;
        
        for(auto it: trips){
            int person = it[0];
            mp[it[1]] += person;     // no. of person that will enter the car at the 'from' position
			                               // {start, persons}
            mp[it[2]] -= person;     // no. of person that will leave the car at that 'to' position
			                               // {end, -persons}
        }
        
        int person = 0;
        
        for(auto it: mp) {
            cout << it.first << " " << it.second << endl;
        }
        
        for(auto x : mp){
            person += x.second;
            if(person > capacity) {     // checking if person exceed the required capacity 
                return false;
            } 
        }
        
        return true;
    }
};