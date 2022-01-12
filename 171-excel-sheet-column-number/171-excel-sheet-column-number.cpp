class Solution {
public:
    // the idea is simple
    // if we look closely, the input is in base 26, while output in base 10
    // all we need to do is convert
    // tc- o(1)
    // sc- o(1)
    int titleToNumber(string columnTitle) {
        int res = 0;
        
        for(char c: columnTitle) {
            int val = c - 'A' + 1;
            res = res * 26 + val;
        }
        return res;
    }
};

// A = 1 = 26 * 0
// AA = 26 + 1 = 26 * 1 + 1
// BA = 26 + 26 + 1 = 26 * 2 + 1
// CA = 26 + 26 + 26 + 1 = 26 * 3 + 1