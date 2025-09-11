/*
 * @lc app=leetcode.cn id=2461 lang=cpp
 *
 * [2461] 长度为 K 子数组中的最大和
 */

// @lc code=start
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ret=LLONG_MIN,sum=0;
        int n=nums.size();
        unordered_map<int,int>cnt;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            cnt[nums[i]]++;
            
            int left=i-k+1;
            if(left>=0)
            {
                if(cnt.size()==k)
                {
                    ret=max(ret,sum);
                }

                sum-=nums[left];
                cnt[nums[left]]--;
                if(cnt[nums[left]]==0)
                {
                    cnt.erase(nums[left]);
                }
            }
        }
        return ret==LLONG_MIN?0:ret;
    }
};
// @lc code=end

