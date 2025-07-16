/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;

        sort(nums.begin(),nums.end());

        int n=nums.size();
        if (n < 3) return ret;

        for(int i=0;i<n;)
        {
            if(nums[i]>0) break;
            int left=i+1,right=n-1,target=-nums[i];
            while(left<right)
            {
                int sum=nums[left]+nums[right];
                if(sum>target) right--;
                else if(sum<target) left++;
                else{
                    ret.push_back({nums[i],nums[left],nums[right]});
                    left++,right--;

                    while(left<right&&nums[left]==nums[left-1]) left++;
                    while(left<right&&nums[right]==nums[right+1]) right--;
                }
            }
            i++;
            while(i<n-2&&nums[i]==nums[i-1]) i++;
        }
        return ret;
    }
};
// @lc code=end

