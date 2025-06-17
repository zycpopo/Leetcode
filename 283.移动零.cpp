
/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur=0;
        int des=-1;
        int n=nums.size();
        while(cur<n)
        {
            if(nums[cur]==0)
            {
                cur++;
            }
            else if(nums[cur]!=0)
            {
                swap(nums[des+1],nums[cur]);
                cur++;
                des++;
            }
        }
    }
};
// @lc code=end

