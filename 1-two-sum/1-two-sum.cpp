#include <bits/stdc++.h>
using namespace std;

// The basic idea to solve this problem is to consider,
// a+b = target, and if we make either of a or b constant 
// we can find b using map in constant time.

// The trick is to check in each step if (target - nums[i]), i.e., 
// if we consider nums[i] as a , then from relation, b should be 
// equal to (target - nums[i]), is already stored by us in map as key or not!

// TC - O(N)
// SC - O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) {
                answer.push_back(map[target - nums[i]]);
                answer.push_back(i);
                return answer;
            }
            map[nums[i]] = i;
        }

        return answer;
    }
};