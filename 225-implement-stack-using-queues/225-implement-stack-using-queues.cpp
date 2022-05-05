class MyStack {
public:
    queue<int> stack, temp;
    MyStack() {
        
    }
    
    void push(int x) {
        stack.push(x);
    }
    
    int pop() {
        while(stack.size()>1) {
            temp.push(stack.front());
            stack.pop();
        }
        
        int res = stack.front();
        stack.pop();
        
        while(!temp.empty()) {
            stack.push(temp.front());
            temp.pop();
        }
        
        return res;
    }
    
    int top() {
        while(stack.size()>1) {
            temp.push(stack.front());
            stack.pop();
        }
        
        int res = stack.front();
        temp.push(stack.front());
        stack.pop();
        
        while(!temp.empty()) {
            stack.push(temp.front());
            temp.pop();
        }
        
        return res;
    }
    
    bool empty() {
        return stack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */