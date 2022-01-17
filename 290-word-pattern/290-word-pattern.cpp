#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;

        int lastIndex = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ' ') {
                words.push_back(str.substr(lastIndex, i - lastIndex));
                lastIndex = i + 1;
            }
        }
        words.push_back(str.substr(lastIndex));

        if(words.size()!=pattern.size()) {
            return false;
        }

        unordered_map<char, string> h1;
        unordered_map<string, char> h2;

        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern[i];
            string k = words[i];

            auto ik = h1.find(c);
            if (ik != h1.end()) {
                if(h1[c]!=k) {
                    return false;
                }
            }

            auto it = h2.find(k);
            if (it != h2.end()) {
                if (h2[k] !=c) {
                    return false;
                }
            }

            // if(h[c] != h2[k]) {
            //     return false;
            // }

            h1.insert({ c, k });
            h2.insert({ k, c });
        }
        return true;
    }
};