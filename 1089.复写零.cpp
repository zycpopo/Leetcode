/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 */

// @lc code=start
class Solution {
public:
    void duplicateZeros(vector<int>& nums) {
        int cur=0;
        int des=-1;
        int n=nums.size();
        while(cur<n)
        {
            if(nums[cur]!=0)
            {
                    des++;
            }
            else{
                des+=2;
            }
            if(des>=n-1) break;
            cur++;
        }

        if(des==n)
        {
            nums[n-1]=0;
            cur--;
            des-=2;
        }
        

        while(cur>=0)
        {
            if(nums[cur]!=0)
            {
               nums[des--]=nums[cur--];
            }
            else
            {
                nums[des--]=0;
                nums[des--]=0;
                cur--;
                
            }
        }
    }
};
// @lc code=end

