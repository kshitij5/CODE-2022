class Solution {
public:
    char closingType(char c) {
    if(c == ')')    return '(';
    if(c == '}')    return '{';
    if(c == ']')    return '[';
    return c;
    }
    
    bool isValid(string s) {
    stack<char> checker;
    
    for(int i=0; i<s.length(); i++){
        char bracket = s[i];
        if(bracket == '(' || bracket == '[' || bracket == '{'){
            checker.push(bracket);
            continue;
        }else{
            if(checker.size() == 0 ) return false;
        }
        
        if(closingType(bracket) == checker.top())
            checker.pop();
        else    break;
    }
    return checker.empty();
}
};