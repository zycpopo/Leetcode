/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        _st.push(val);
        if(_minst.empty() || val <= _minst.top())
        {
            _minst.push(val);
        }

    }
    
    void pop() {
        if(_minst.top() == _st.top())
           _minst.pop();

        _st.pop();
    }
    
    int top() {
        return _st.top();
    }
    
    int getMin() {
        return _minst.top();
    }
private:
    stack<int> _st;
    stack<int> _minst;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

