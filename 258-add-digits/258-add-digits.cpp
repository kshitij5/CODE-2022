class Solution {
public:
    // brute force
    string sumOfDigits(string s) {
        int sum = 0;
        for(char c: s) {
            sum += c - '0';
        }
        cout << sum << endl;
        return to_string(sum);
    }
    int addDigits(int num) {
        string str = to_string(num);
        while(str.size()>1) {
            str = sumOfDigits(str);
        }
        
        return str[0] - '0';
    }
};