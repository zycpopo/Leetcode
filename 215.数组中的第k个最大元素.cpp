/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> a;
        for (auto e : nums)
        {
            a.push(e);
        }
        int result = -1;
        for (int i = 0; i < k; i++)
        {
            result = a.top();
            a.pop();
        }

        return result;
    }
};
// @lc code=end
