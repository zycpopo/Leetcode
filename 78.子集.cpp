/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums,0);
        return ret;
    }

    void dfs(vector<int> & nums,int pos)
    {
        ret.push_back(path);
        for(int i=pos;i<nums.size();i++)
        {
            path.push_back(nums[i]);
            dfs(nums,i+1);
            path.pop_back();
        }
    }
};
// @lc code=end

