/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
   
        if(n<=1) return n;
        int dp[3];
        int result=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            result=dp[1]+dp[2];
            dp[1]=dp[2];
            dp[2]=result;
        }
        return dp[2];
    }
};
// @lc code=end

