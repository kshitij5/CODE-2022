class Solution {
public:
    // simple base 10 to base 26 conversion
    // tc - o(log n)
    // sc - o(1)
    string convertToTitle(int n) {
        string res = "";
        
        while(n) {
            n--;
            // why n--? visit ----> https://leetcode.com/problems/excel-sheet-column-title/discuss/441430/Detailed-Explanation-Here's-why-we-need-n-at-first-of-every-loop-(JavaPythonC%2B%2B)
            char c = (n % 26) + 'A';
            res = c + res;
            n /= 26;
        }
        return res;
    }
};