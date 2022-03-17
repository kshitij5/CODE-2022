class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                st.push(-1);
                continue;
            } 
            int c = 0;
            
            while(st.top()!=-1){
                c+=st.top();
                st.pop();
            }
            
            st.pop();
            c = c > 0 ? c*=2 : 1;
            st.push(c);
        }
        
        int res = 0;
        while(!st.empty())
            res+=st.top(), st.pop();
        
        return res;
    }
};