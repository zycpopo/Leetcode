/*
 * @lc app=leetcode.cn id=1695 lang=cpp
 *
 * [1695] 删除子数组的最大得分
 */

// @lc code=start
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int hash[10001]={0};
        int n=nums.size();
        int right=0,left=0;
        int sum=0,ret=0;
        while(right<n)
        {
            sum+=nums[right];
            hash[nums[right]]++;
            while(hash[nums[right]]>1)
            {
                hash[nums[left]]--;
                sum-=nums[left];
                left++;
            }
            right++;
            ret=max(ret,sum);
        }
        return ret;
    }
};
// @lc code=end

