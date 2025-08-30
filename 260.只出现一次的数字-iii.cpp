/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorh = 0;

        for(int num:nums)
        {
            xorh^=num;
        }

        long diff=xorh & (-static_cast<long>(xorh));

        int a=0,b=0;
        for(int num:nums)
        {
            if(num&diff) a^=num;
            else  b^=num;
        }

        return {a,b};
    }
};
// @lc code=end

