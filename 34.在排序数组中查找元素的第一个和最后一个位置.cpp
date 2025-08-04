/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        
        int begin=0;
        //寻找左边界
        int left=0,right=nums.size()-1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]<target) left=mid+1;
            else right=mid;
        }

        if(nums[left]!=target) return {-1,-1};
        else begin=left;

        left=0,right=nums.size()-1;
        while(left<right)
        {
            int mid=left+(right-left+1)/2;
            if(nums[mid]<=target) left=mid;
            else right=mid-1;
        }
        return {begin,right};
    }
};
// @lc code=end

