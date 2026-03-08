/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev=INT_MAX;
        int result=0;
        for(int i=0;i<prices.size();i++)
        {
            int right=prices[i];
            
            prev=min(prev,right);
            
            result=max(result,right-prev);
            
        }
        return result;
    }
};
// @lc code=end

