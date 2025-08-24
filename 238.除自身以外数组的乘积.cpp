/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> f(n), g(n);

        f[0] = g[n - 1] = 1;
        for (int i = 1; i < n; i++)
        {
            f[i] = f[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            g[i] = g[i + 1] * nums[i + 1];
        }

        vector<int> ret(n);
        for (int i = 0; i < n; i++)
        {
            ret[i] = g[i] * f[i];
        }

        return ret;
    }
};
// @lc code=end
