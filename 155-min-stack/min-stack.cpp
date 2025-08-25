class MinStack {
public:
    stack<long long> st; // main stack to store values (may store encoded values)
    long long min;       // current minimum in the stack

    MinStack() {
        // initialize min with a very large value
        min = LLONG_MAX;
    }
    
    void push(long long val) {
        if(st.empty()) {
            // First element → push normally and set min
            st.push(val);
            min = val;
        }
        else if(val >= min) {
            // If val is greater or equal to current min
            // push it as it is (normal case)
            st.push(val);
        }
        else {
            // If val is smaller than current min
            // push an encoded value instead of actual val
            // encoding = 2*val - min
            // this allows us to retrieve old min later
            st.push(2*val - min);
            // update min to new smaller value
            min = val;
        }
    }
    
    void pop() {
        if(st.top() <= min) {
            // If top is an encoded value (<= current min)
            // retrieve the previous min before this element was pushed
            long long oldMin = 2*min - st.top();
            min = oldMin;
        }
        // pop element (either real value or encoded value)
        st.pop();
    }
    
    long long top() {
        if(st.top() <= min) {
            // If top is encoded, actual value is the current min
            return min;
        }
        else {
            // Otherwise it's a normal value
            return st.top();
        }
    }

    long long getMin() {
        // Always return current min in O(1)
        return min;
    }
};
