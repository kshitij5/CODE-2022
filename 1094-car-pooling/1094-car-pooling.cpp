class Solution {
public:
    // using map stl
    // tc - o(n)
    // sc - o(n)
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int mp[1001] = {0};
        
        for(auto it: trips){
            int person = it[0];
            mp[it[1]] += person;     
            mp[it[2]] -= person;  
        }
        
        int person = 0;
        
        for(auto x : mp){
            person += x;
            if(person > capacity) {     // checking if person exceed the required capacity 
                return false;
            } 
        }
        
        return true;
    }
};