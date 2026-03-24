/*
 * @lc app=leetcode.cn id=991 lang=cpp
 *
 * [991] 坏了的计算器
 */

// @lc code=start
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ret=0;

        while(target > startValue)
        {
            if(target % 2 ==0)
            {
                target /= 2;
            }
            else
            {
                target += 1;
            }
            ret++;
        }

        return ret + startValue - target;
    }
};
// @lc code=end

