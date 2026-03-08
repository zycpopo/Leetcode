/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    //版本一：双指针
    /*int maxProfit(vector<int>& prices) {
        int ret=0;
        for(int i=0;i<prices.size();i++)
        {
            int j=i;
            while(j+1<prices.size()&&prices[j+1]>prices[j]) j++;

            ret+=prices[j]-prices[i];
        }
        return ret;
    }*/
    //版本二：微分法
    int maxProfit(vector<int>& p)
    {
        int ret=0;

        for(int i=1;i<p.size();i++)
        {
            if(p[i]>p[i-1])
            {
                ret+=p[i]-p[i-1];
            }
        }
        return ret;
    }
};
// @lc code=end

