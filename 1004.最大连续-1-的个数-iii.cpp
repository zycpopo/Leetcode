/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ret=0;
        int zero=0;
        for(int left=0,right=0;right<nums.size();right++)
        {
            if(nums[right]==0) zero++;
            while(zero > k)
                if(nums[left++]==0) zero--;
            ret=max(ret,right-left+1);
        }
        return ret;
    }
};
// @lc code=end

