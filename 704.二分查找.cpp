/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        
        while(left<=right)
        {
            int mid = left + (right - left) / 2; 
            if(target>nums[mid])
            {
                left=mid+1;
            }
            else if(target<nums[mid])
            {
                right=mid-1;
            }
            else return mid;
        }
        return -1;
    }
};
// @lc code=end

