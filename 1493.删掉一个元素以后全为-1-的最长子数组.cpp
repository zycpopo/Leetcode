/*
 * @lc app=leetcode.cn id=1493 lang=cpp
 *
 * [1493] 删掉一个元素以后全为 1 的最长子数组
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=0;
        int flag=-1;
        int ret=0;

        while(right<n)
        {
            if(nums[right]==0) 
            {
                if(flag!=-1)
                {
                    ret=max(ret,right-left-1);
                    left=flag+1;
                }
                flag=right;
            }
            ret=max(ret,right-left);
            right++;
        }

        return ret;
    }
};
// @lc code=end

