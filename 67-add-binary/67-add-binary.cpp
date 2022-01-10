class Solution {
public:
    // extreme bruteforce
    // tc - o(n)
    // sc - o(1)
    
    // all are we doing is converting aa and b into its equivalent decimal
    // then adding both and converting the resultant into into its binary form again
//     int binToDig(string a) {
//         reverse(a.begin(), a.end());
//         unsigned int base = 1, bin = 0;
        
//         for(char c: a) {
//             bin += (c - '0') * base;
//             base *= 2;
//         }
//         return bin;
//     }
    
//     string addBinary(string a, string b) {
//         if(a=="0" && b=="0") return "0";
//         int n = binToDig(a) + binToDig(b);
        
//         string bin="";
//         while (n > 0) {
//             // storing remainder in binary array
//             bin = to_string(n % 2) + bin;
//             n  /= 2;
//         }
        
//         return bin;
//     }
    
    
        string addBinary(string a, string b) {
              int sum = 0;
              int i = a.size()-1;
              int j = b.size() -1;
              string str;

              while(i>=0 || j>=0 || sum ==1){

                  sum += (i>=0)?(a[i]-'0'):0;
                  sum += (j>=0)?(b[j]-'0'):0;

                  // sum can be 0 1 2 3 only
                  str = char(sum%2 + '0') + str; // remainder for binary number 
                  // sum can be 0 1 2 3 only so, quotient can represent carry
                  sum = sum/2; // quotient which is actually a carry, sum == 2 and 3 have carry 1

                  i--; j--;
              }
               return str;
        }
};