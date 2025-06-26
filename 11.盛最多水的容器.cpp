/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int max=0;
        while(left!=right)
        {
            int low=min(height[left],height[right]);
            
            int v=(right-left)*low;
            if(v>max) max=v;
            if(height[left]<height[right])
            {
                left++;
            }
            else{
                right--;
            }
        }
        return max;
    }
};
// @lc code=end

