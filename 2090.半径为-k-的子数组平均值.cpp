/*
 * @lc app=leetcode.cn id=2090 lang=cpp
 *
 * [2090] 半径为 k 的子数组平均值
 */

// @lc code=start
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ret(nums.size(),-1);
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(i<2*k)
            {
                ret[i]=-1;
                continue;
            }
            ret[(i+i-2*k)/2]=sum/(2*k+1);
            sum-=nums[i-2*k];
        }
        return ret;
    }
};
// @lc code=end

