/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());

        int right=arr[0][1];
        int ret=1;
        for(int i=1;i < arr.size();i++)
        {
            int a = arr[i][0],b = arr[i][1];
            if(a <= right)
            {
                right = min(right,b);
            }
            else{
                ret++;
                right = b;
            }
        }
        return ret;
    }
};
// @lc code=end

