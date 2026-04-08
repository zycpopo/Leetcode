/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start

class Solution {
public:
    //T(n),S(1)
    int minCostClimbingStairs(vector<int>& cost) {
        int dp0=0;
        int dp1=0;
        int n=cost.size();
        for(int i=2;i<=n;i++)
        {
            int dpi=min(dp1 + cost[i-1],dp0+cost[i-2]);
            dp0=dp1;
            dp1=dpi;
        }
        return dp1;
    }
};
// @lc code=end

