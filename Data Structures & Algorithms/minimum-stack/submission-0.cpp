class MinStack {
    stack<int>st;
    stack<int>mnst;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(mnst.size()==0||mnst.top()>=val)
        {
            mnst.push(val);
        }
    }
    
    void pop() {
        if(st.size()==0)return;
        int x=st.top();
        st.pop();
        if(mnst.top()==x)
        {
            mnst.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mnst.top();
    }
};
