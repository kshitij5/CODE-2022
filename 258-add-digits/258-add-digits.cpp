class Solution {
public:
    // brute force
    // tc - o(n)
    // sc - o(1)
//     string sumOfDigits(string s) {
//         int sum = 0;
//         for(char c: s) {
//             sum += c - '0';
//         }
//         cout << sum << endl;
//         return to_string(sum);
//     }
//     int addDigits(int num) {
//         string str = to_string(num);
//         while(str.size()>1) {
//             str = sumOfDigits(str);
//         }
        
//         return str[0] - '0';
//     }
    
    // using digital root
    // tc - o(1)
    // sc - o(1)
    int addDigits(int num) {
       if(num==0)
           return 0;
        else if(num % 9 == 0)
            return 9;
     return num % 9;
    }
};