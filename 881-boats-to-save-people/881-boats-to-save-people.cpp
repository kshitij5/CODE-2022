class Solution {
public:
    // using two pointers approach
    // tc - o(nlogn)
    // sc - o(1)
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int res = 0;
        
        // sorting people according to their weights
        sort(people.begin(), people.end());
        int left = 0, right = n-1;
        
        //  we will try to make pairs of people having
        // lightest and heaviest weight such that its under limit
        // or else they'll go alone
        while(left <= right) {
            
            // if sum is over the limit,
            // heaviest will go alone.
            if(people[left] + people[right] > limit) {
                right--;
            } else {
            // if sum is under the limit,
            // both heaviest and lightest will go together.
                left++, right--;
            }
            res++;
        }
        
        return res;
    }
};