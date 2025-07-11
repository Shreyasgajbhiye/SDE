class MyStack {
public:
    // 2 queue
    // queue<int> q1;
    // queue<int> q2;
    // MyStack() {
        
    // }
    
    // void push(int x) {
    //     q2.push(x);
    //     while(!q1.empty()){
    //         q2.push(q1.front());
    //         q1.pop();
    //     }
    //     swap(q1, q2);
    // }
    
    // int pop() {
    //     int result = q1.front();
    //     q1.pop();
    //     return result;
    // }
    
    // int top() {
    //     return q1.front();
    // }
    
    // bool empty() {
    //     return q1.empty();
    // }
    queue<int> q;
    int size;
     MyStack() {
        size = 0;
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int result = q.front();
        q.pop();
        return result;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
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