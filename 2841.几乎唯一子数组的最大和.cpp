/*
 * @lc app=leetcode.cn id=2841 lang=cpp
 *
 * [2841] 几乎唯一子数组的最大和
 */

// @lc code=start
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n=nums.size();
        long long s=0,ret=0;
        unordered_map<int,int>cnt;

        for(int i=0;i<n;i++)
        {
            s+=nums[i];
            cnt[nums[i]]++;
            int left=i-k+1;
            if(left<0)
            {
                continue;
            }

            if(cnt.size()>=m)
            {
                ret=max(ret,s);
            }

            s-=nums[left];
            if(--cnt[nums[left]]==0)
            {
                cnt.erase(nums[left]);
            }
        }
        return ret;
    }
};
// @lc code=end

