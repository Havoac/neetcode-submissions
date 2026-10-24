class MinStack {
public:
    stack<int> st;
    stack<int> minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if(minStack.empty() || val <= minStack.top())
            minStack.push(val);    
    }
    
    void pop() {
        if(st.top() == minStack.top())
        minStack.pop();

        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
