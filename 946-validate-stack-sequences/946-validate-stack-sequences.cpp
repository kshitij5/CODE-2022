class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        st.push(INT_MIN);
        int i = 0;
        
        for(int last_popped: popped) {
            if(st.top()!=last_popped) {
                while(i<pushed.size() && pushed[i]!=last_popped) {
                    st.push(pushed[i++]);
                }
                i++;
            }else{
                st.pop();
            }
        }
        
        return st.size()==1;
    }
};