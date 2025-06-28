/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int value=0;
        for(auto e:nums)
        {
            value=value^=e;
        }

        return value;
    }
};
// @lc code=end

