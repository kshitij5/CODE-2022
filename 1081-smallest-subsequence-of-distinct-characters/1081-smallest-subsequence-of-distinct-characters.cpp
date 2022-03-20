class Solution {
public:
    // using stack and map
    // https://www.youtube.com/watch?v=luCn7p2CIbI&t=796s
    // tc - o(n)
    // sc - o(n)
    string smallestSubsequence(string s) {
        unordered_map<char, int> freq;
        vector<int> exist(26);
        stack<char> st;
        
        for(char c:  s) freq[c]++;
        
        int n = s.size();
        
        for(int i=0; i<n; i++) {
            freq[s[i]]--;
            
            if(exist[s[i] - 'a']) continue;
            
            while(!st.empty() && st.top() > s[i] && freq[st.top()] > 0) {
                exist[st.top() - 'a'] = 0;
                st.pop();
            }
            st.push(s[i]);
            exist[st.top() - 'a'] = 1;
        }
        
        string res = "";
        while(!st.empty()) 
            res = st.top()+res, st.pop();
        
        return res;
    }
};