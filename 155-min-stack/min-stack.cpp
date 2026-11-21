class MinStack {
public:
    stack<pair<int , int>> p;
    MinStack() {
        
    }
    
    void push(int val) {
        if(p.empty()){
            p.push({val, val});
        }else{
            int minVal = min(val , p.top().second);
            p.push({val, minVal});
        }
    }
    
    void pop() {
        p.pop();
    }
    
    int top() {
        return p.top().first;
    }
    
    int getMin() {
        return p.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */