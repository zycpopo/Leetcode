/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int max_s = INT_MIN;
        int ret=0;

        for(int i=0;i<n;i++)
        {
            ret+=nums[i];
            if(i<k-1)
            {
                continue;
            }

            max_s=max(ret,max_s);

            ret-=nums[i-k+1];
        }

        return (double)max_s/k;
    }
};
// @lc code=end

