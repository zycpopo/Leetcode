/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left=0,right=arr.size()-1;
        
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(arr[mid]<arr[mid+1]) left=mid+1;
            else right=mid;
        }
        return right;
    }
};
// @lc code=end

