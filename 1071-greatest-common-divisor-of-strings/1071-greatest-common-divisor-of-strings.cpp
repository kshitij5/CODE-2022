class Solution {
public:
    // brute force
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 != str2+str1) 
            return "";
        // gcd of two number is only possible if a+b = b+a
        
        return (str1.substr(0, gcd(str1.size(), str2.size())));
        // if gcd possible, we find the gcd of length and returns it
    }
};