class Solution {
public:
    string newStr(string s) {
        string res="";
        stack<char> st;
        for(char c:s) {
            if(c=='#') {
                if(!st.empty()) st.pop();
                continue;
            }
            st.push(c);
        }
        
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        
        return res;
    }
    bool backspaceCompare(string s, string t) {
        s = newStr(s);
        t = newStr(t);
        return s==t;
    }
};