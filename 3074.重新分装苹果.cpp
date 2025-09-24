/*
 * @lc app=leetcode.cn id=3074 lang=cpp
 *
 * [3074] 重新分装苹果
 */

// @lc code=start
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=0;
        int n=capacity.size();

        for(int x:apple)
        {
            sum+=x;
        }

        sort(capacity.begin(),capacity.end(),greater<int>());

        int ret=0,sum2=0;
        for(int i=0;sum2<sum;i++)
        {
            sum2+=capacity[i];
            ret++;
        }
        return ret;
    }
};
// @lc code=end

