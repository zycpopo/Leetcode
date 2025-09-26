/*
 * @lc app=leetcode.cn id=1833 lang=cpp
 *
 * [1833] 雪糕的最大数量
 */

// @lc code=start
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ret=0;
        sort(costs.begin(),costs.end());

        for (int cost : costs) 
        {
            if (coins >= cost) 
            { 
                coins -= cost;
                ret++;
            } else {break;}
    }
        return ret;
    }
};
// @lc code=end

