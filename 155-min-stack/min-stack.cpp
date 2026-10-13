class MinStack {
public:
    vector<pair<int, int>> st;
    MinStack() {
    }
    
    void push(int value) {
        int n = st.size();
        if (st.empty()) {
            st.push_back({value, value});
        }
        else {
            int temp = min(value, st[n - 1].second);
            st.push_back({value, temp});
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        int n = st.size();
        return st[n - 1].first;
    }
    
    int getMin() {
        int n = st.size();
        return st[n - 1].second;
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