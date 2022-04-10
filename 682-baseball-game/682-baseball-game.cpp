class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        
        for(string s: ops) {
            if(s=="+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                
                st.push(a+b);
            } else if(s=="D") {
                st.push(st.top()*2);
            } else if(s=="C") {
                st.pop();
            } else{
                st.push(stoi(s));
            }
        }
        
        int sum = 0;
        while(!st.empty()) {
            sum+=st.top();
            st.pop();
        }
        
        return sum;
    }
};