/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int k = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[k]) {
            k++;
            nums[k] = nums[i];
        }
    }
    return k + 1;
}
};
// @lc code=end

