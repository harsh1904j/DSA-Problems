class MinStack {
public:
stack<int> values;
stack<int> min_values;

    MinStack() {
        
    }
    
    void push(int value) {
       values.push(value);
       if(min_values.empty()){
        min_values.push(value);
       }
       else {
       min_values.push(min(min_values.top(), value)); }
    }
    
    void pop() {
        values.pop();
        min_values.pop();
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return min_values.top();
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