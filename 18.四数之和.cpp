/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;

        sort(nums.begin(),nums.end());

        int n=nums.size();
        if(n<4) return ret;
        for(int i=0;i<n-3; ){
            long long sum1=(long long)nums[i]+nums[i+1]+nums[i+2]+nums[i+3];
            if(sum1 >(long long)target) break;

            long long sum2=(long long)nums[i]+nums[n-3]+nums[n-2]+nums[n-1];
            if(sum2 < (long long)target){
                i++;
                continue;
            }

            for(int j=i+1;j<n-2;)
            {
                long long sum3=(long long)nums[i]+nums[j]+nums[j+1]+nums[j+2];
                long long sum4=(long long)nums[i]+nums[j]+nums[n-1]+nums[n-2];
                if(sum3 > target) break;
                if(sum4 < target){
                    j++;
                    continue;
                }
            
            int left=j+1,right=n-1;
            long long currentTarget = (long long)target -nums[i]-nums[j];

            while(left < right){
                long long sum=nums[left] + nums[right];

                if(sum > currentTarget){
                    right--;
                }else if(sum < currentTarget){
                    left++;
                }else{
                    ret.push_back({nums[i],nums[j],nums[left],nums[right]});
                    left++,right--;

                    while(left<right && nums[left]==nums[left-1]) left++;
                    while(left<right && nums[right]==nums[right+1]) right--;
                }
            }
            j++;
            while(j<n-2&&nums[j]==nums[j-1]) j++;
            }
        i++;
        while(i<n-2&&nums[i]==nums[i-1]) i++;
        }
        return ret;
    }
};
// @lc code=end

