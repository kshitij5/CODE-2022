#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // // BRUTE FORCE SOLUTION BUT GETS TLE
    // string removeDuplicates(string s, int k) {
    //     string result = "";

    //     for(char c: s) {
    //         if(result.empty()) {
    //             result.push_back(c);
    //         }else if(c == result.back()) {
    //             string temp = "";
    //             while(c == result.back()) {
    //                 temp += result.back();
    //                 result.pop_back();
    //             }

    //             if(temp.size() != k-1) {
    //                 result += temp+c;
    //             cout << result << endl;
    //             }
    //         }else{
    //             result.push_back(c);
    //         }
    //     }

    //     return result;
    // }

    // using stack
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> st;
        for(char c : s) {
            if(st.empty() || st.back().first != c) {
                st.push_back({c,1});
            }
            else if(++st.back().second == k ) 
                st.pop_back();
        }
        string result="";
        for(auto t : st) {
            result.append(t.second,t.first);
        }
        return result;
    }
//     string removeDuplicates(string s, int k) {
//         stack<pair<char, int>> st;
//         int n = s.size();
//         st.push({s[0], 1});
        
//         for(int i=1; i<n; i++) {
//             auto it = st.top();
            
//             if(it.second >= k) {
//                 int  temp =  k;
//                 while(temp-- && !st.empty()) {
//                     cout << st.top().first << " popped" << endl;
//                     st.pop();
//                 }
//                 cout << endl;
                
//                 if(!st.empty())
//                     it = st.top();
//                 // else {
//                 //     st.push({s[i], 1});
//                 //     continue;
//                 // }
//             }
            
//             if(it.first == s[i]) {
//                 st.push({s[i], it.second+1});
//             }
//             else st.push({s[i], 1});
//         }

//         string res;
//         while(!st.empty()) {
//             res = st.top().first + res;
//             st.pop();
//         }
//         return res;
//     }
};