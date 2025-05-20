/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {}
    
    void push(int x) {
        q2.push(x);
        
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
 
        swap(q1, q2);
    }
    
    int pop() {
        int top_element = q1.front();
        q1.pop();
        return top_element;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
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
// @lc code=end

