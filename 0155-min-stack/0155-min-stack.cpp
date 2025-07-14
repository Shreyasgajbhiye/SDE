class MinStack {
public:
    stack<pair<int, int>> stk;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()){
            stk.push({val, val});
        }
        else{
            if(val < stk.top().second){
                stk.push({val, val});
            }
            else{
                stk.push({val, stk.top().second});
            }
        }
    }
    
    void pop() {
        if(!stk.empty()){
            stk.pop();
        }
    }
    
    int top() {
        int ans = stk.top().first;
        return ans;
    }
    
    int getMin() {
        int ans = stk.top().second;
        return ans;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */