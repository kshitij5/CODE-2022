class Solution {
public:
    // using two pointers inplace approach
    string reverseWords(string str) {
        int startIndex = 0;
        for(int i=0;i<=str.size();i++) {
            if(str[i]==' ' || i==str.size()){
                reverse(&str[startIndex], &str[i]);
                startIndex = i+1;
            }
        }
        return str;
    }
    
    // using string stream method
    // string reverseWords(string str) {
    //     stringstream s(str); // Used for breaking words
    //     string word; // to store individual words
    //     string res;
    //     while (s >> word) {
    //         reverse(word.begin(), word.end());
    //         res += word+" ";
    //     }
    //     res.pop_back();
    //     return res;
    // }
};