class Solution {
public:
    static bool comp(vector<int>&a, vector<int>& b) {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        
        int count = 0;
        
        for(auto &it: boxTypes) {
            int numberOfBoxesi = it[0];
            int numberOfUnitsPerBoxi = it[1];
            if(truckSize <= numberOfBoxesi) {
                count += (truckSize*numberOfUnitsPerBoxi);
                break;
            } else {
                count += (numberOfBoxesi*numberOfUnitsPerBoxi);
            }
            truckSize -= numberOfBoxesi;
        }
        
        return count;
    }
};