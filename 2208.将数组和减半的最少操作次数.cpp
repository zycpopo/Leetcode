/*
 * @lc app=leetcode.cn id=2208 lang=cpp
 *
 * [2208] 将数组和减半的最少操作次数
 */

// @lc code=start
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> heap;
        double sum=0.0;
        for(int x:nums)
        {
            sum+=x;
            heap.push(x);
        }
        sum/=2.0;

        int count=0;
        while(sum>0)
        {
            double t=heap.top()/2.0;
            heap.pop();
            sum-=t;
            count++;
            heap.push(t);
        }

        return count;
    }
};
// @lc code=end

