class Solution {
public:
//     string minRemoveToMakeValid(string s) {
//         string res;
//         int count = 0;
        
//         for(char c: s) {
//             if(c=='(') count++;
//             else if(c==')') count--;
//             else {
//                 res.push_back(c);
//                 continue;
//             }
            
//             if(count>=0) res.push_back(c);
//         }
        
//         return res;
//     }
    
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        
        // Iterate over string and mark bad closing parentheses as defect using '*'
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                if(st.size()) st.pop();
                else s[i]='*';
            }
        }
        
        // Iterate over stack to mark bad opening parentheses as defect using '*'
        while(!st.empty()){
            s[st.top()] = '*';
            st.pop();
        }
        
        // Remove defected parentheses from string
        string res;
        // for(char c: s) if(c!='*')res += c;
        
        s.erase(remove(s.begin(), s.end(), '*'),s.end());
        
        return s;
    }
};