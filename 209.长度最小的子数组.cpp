/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(),sum=0,len=INT_MAX;
        for(int left=0,right=0;right<n;right++)
        {
            sum+=nums[right];
            while(sum>=target)
            {
                len=min(len,right-left+1);
                sum-=nums[left++];
            }
        }
        return len==INT_MAX?0:len;
    }
};
// @lc code=end

