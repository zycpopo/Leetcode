/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int right=0,left=0,maxpos=0,ret=0,n=nums.size();
        while(left<=right)
        {
            if(maxpos>=n-1)
            {
                return true;
            }
            for(int i=left;i<=right;i++)
            {
                maxpos=max(maxpos,nums[i]+i);
            }
            left=right+1;
            right=maxpos;
            
        }
        return false;
    }
};
// @lc code=end

