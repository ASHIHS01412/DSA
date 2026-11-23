class MyStack {
public:

    queue<int>Q1;
    queue<int>Q2;
    MyStack() {
        
    }
    
    void push(int x) {
        while(!Q1.empty()){
            Q2.push(Q1.front());
            Q1.pop();
        }
        Q1.push(x);
        while(!Q2.empty()){
            Q1.push(Q2.front());
            Q2.pop();
        }
    }
    
    int pop() {
        int ans = Q1.front();
        Q1.pop();
        return ans;
    }
    
    int top() {
        return Q1.front();
    }
    
    bool empty() {
        return Q1.empty();
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