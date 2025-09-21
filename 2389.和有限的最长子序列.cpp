/*
 * @lc app=leetcode.cn id=2389 lang=cpp
 *
 * [2389] 和有限的最长子序列
 */

// @lc code=start
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        ranges::sort(nums);
        partial_sum(nums.begin(), nums.end(), nums.begin()); // 原地求前缀和
        for (int& q : queries) { // 用 queries 保存答案
            q = ranges::upper_bound(nums, q) - nums.begin();
        }
        return queries;
    }
};
// @lc code=end

