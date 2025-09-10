/*
 * @lc app=leetcode.cn id=1343 lang=cpp
 *
 * [1343] 大小为 K 且平均值大于等于阈值的子数组数目
 */

// @lc code=start
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum=0;
        int ret=0;

        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(i<k-1)
            {
                continue;
            }
            
            if(sum>=k*threshold)
            {
                ret++;
            }

            sum-=arr[i-k+1];
        }
        return ret;
    }
};
// @lc code=end

