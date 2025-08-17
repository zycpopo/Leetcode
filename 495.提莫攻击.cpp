/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int sum=0;
        int n=timeSeries.size();
        for(int i=0;i<n-1;i++)
        {
            sum+=min(duration,timeSeries[i+1]-timeSeries[i]);
        }
        return sum+duration;
    }
};
// @lc code=end

