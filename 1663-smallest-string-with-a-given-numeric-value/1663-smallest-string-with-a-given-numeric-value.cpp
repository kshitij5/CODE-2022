class Solution {
public:
    string getSmallestString(int n, int k) {
        string res;
        int i=n-1, sum = n;
        
        while(n--)res+='a';
        // n=3, res = aaa
        
        while(sum < k) {
            if((sum+25) <= k) {
                sum += 25;
                res[i--] = 'z';
                continue;
            }
            res[i--] = ((k-sum)+'a');
            sum += (k-sum);
        }
        
        return res;
    }
    
//     string getSmallestString(int n, int k) {
//         string res;
//         int i = n-1, sum = n;
//         while(n--)  res+='a';
        
//         while(sum < k) {
//             int min = std::min(25, (k-sum));
//             res[i--] = (min + 'a');
//             sum +=  min;
//         }
        
//         return res;
//     }
};