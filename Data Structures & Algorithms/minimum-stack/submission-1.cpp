class MinStack {
    private:
        stack<int> minStack;
        stack<int> st;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            minStack.push(val);
            st.push(val);
        }
        else{
            if(val<=minStack.top()){
                st.push(val);
                minStack.push(val);
            }
            else{
                st.push(val);
            }
        }
    }
    
    void pop() {if (st.top() == minStack.top()) {
    minStack.pop();
}
            st.pop();
    }
    
    int top() {
        if(st.empty()){
            return 0;
        }
        int x=st.top();
        return x;
    }
    
    int getMin() {
        int x=minStack.top();
        return x;
    }
};
