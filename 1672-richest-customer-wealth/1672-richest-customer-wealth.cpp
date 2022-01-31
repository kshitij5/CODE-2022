#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int richest = 0;

        for (int i = 0; i < accounts.size(); i++){
            int currentWealth = 0;
            for (int j = 0; j < accounts[0].size(); j++){
                currentWealth += accounts[i][j];
            }
            richest = max(richest, currentWealth);
        }

        return richest;
    }
};