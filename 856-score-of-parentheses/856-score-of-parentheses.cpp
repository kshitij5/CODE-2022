class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                st.push(-1);
                continue;
            } 
            
            if(st.top() == -1) {
                st.pop(), st.push(1);
            } else {
                int c = 0;

                while(st.top()!=-1){
                    c+=st.top();
                    st.pop();
                }

                st.pop();
                st.push(c*2);
            }
        }
        
        int res = 0;
        while(!st.empty()) {
            res+=st.top();
            st.pop();
        }
        
        return res;
    }
};