/*
 * @lc app=leetcode.cn id=2529 lang=cpp
 *
 * [2529] 正整数和负整数的最大计数
 */

// @lc code=start
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        // 1. 二分查找第一个 >= 0 的位置（即负数的结束位置）
        int left = 0, right = n - 1;
        int neg = 0;  // 负数个数

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < 0) {
                // mid 可能是负数，往右找更大的
                left = mid + 1;
            } else {
                // nums[mid] >= 0，可能在0或正数区域，往左找更小的满足 >=0 的
                right = mid - 1;
            }
        }
        neg = left;  // left 最终指向第一个 >=0 的位置，也就是负数个数

        // 2. 二分查找第一个 > 0 的位置（即正数的开始位置）
        left = 0, right = n - 1;
        int pos = 0;  // 正数个数

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= 0) {
                // 小于等于0，往右找
                left = mid + 1;
            } else {
                // 大于0，可能为答案，往左找更小的
                right = mid - 1;
            }
        }
        pos = n - left;  // 从 left 到末尾都是正数

        return max(neg, pos);
    }
};
//优解版
/*class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = ranges::lower_bound(nums, 0) - nums.begin();
        int pos = nums.end() - ranges::upper_bound(nums, 0);
        return max(neg, pos);
    }
};
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto [left, right] = ranges::equal_range(nums, 0);
        int neg = left - nums.begin();
        int pos = nums.end() - right;
        return max(neg, pos);
    }
};*/
// @lc code=end

