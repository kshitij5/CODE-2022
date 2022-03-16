class Solution {
public:
    // initial solution
//     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//         stack<int> st;
//         st.push(INT_MIN);
//         int i = 0;
        
//         for(int last_popped: popped) {
//             if(st.top()!=last_popped) {
//                 while(i<pushed.size() && pushed[i]!=last_popped) {
//                     st.push(pushed[i++]);
//                 }
//                 i++;
//                 continue;
//             }
//             st.pop();
//         }
        
//         return st.size()==1;
//     }
    
    // intution method using stack
    // tc - o(n)
    // sc - o(n)
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        
        for(auto val : pushed){
            st.push(val);
            while(st.size() > 0 && st.top() == popped[j]){
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};

