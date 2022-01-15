#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // BRUTE FORCE - GREEDILY
    // TC - O(n) SC - O(1)

    // bool canJump(vector<int>& nums) {
    //     int n = nums.size() - 1;
    //     int max_reachable = nums[0];
    //     int last_max = 0;

    //     for (int i = 0; i < n; i++) {
    //         cout << i << endl;
    //         last_max = nums[i];
    //         for (int j = i + 1; j <= nums[i] + i && j < nums.size(); j++) {
    //             if (nums[j] >= last_max) {
    //                 max_reachable = nums[j] + j;
    //             }
    //         }
    //         i = max(max_reachable, i);
    //     }
    //     cout << max_reachable << endl;
    //     return max_reachable >= n;
    // }

    // ITERATIVE SOLUTION
    // TC - O(n) SC - O(1)
    bool canJump(vector<int>& nums) {
        int max_reachable = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (max_reachable < i)
                return false;

            max_reachable = max(max_reachable, nums[i] + i);
        }
        return true;
    }
};