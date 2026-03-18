/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int right=0,left=0,maxpos=0,ret=0,n=nums.size();
        while(left<=right)
        {
            if(maxpos>=n-1)
            {
                return ret;
            }
            for(int i=left;i<=right;i++)
            {
                maxpos=max(maxpos,nums[i]+i);
            }
            left=right+1;
            right=maxpos;
            ret++;
        }
        return -1;
    }
};
// @lc code=end

