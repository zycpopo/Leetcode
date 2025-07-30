/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        for(int e:nums) sum+=e;
        int n=nums.size();
        int ret=-1;
        int target=sum-x;
        if(target<0) return -1;

        for(int left=0,right=0,tmp=0;right<n;right++)
        {
            tmp+=nums[right];//进窗口
            while(tmp>target)//判断
            {
                tmp-=nums[left++];//出窗口
            }
            if(tmp==target)
            {
                ret=max(ret,right-left+1);
            }
            
        }

        if(ret==-1) return -1;
        else return n-ret;
     }
};
// @lc code=end

