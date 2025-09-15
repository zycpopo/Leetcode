/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */

// @lc code=start

//优解
/*class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int s[2]{}, max_s1 = 0;
        for (int i = 0; i < customers.size(); i++) {
            s[grumpy[i]] += customers[i];
            if (i < minutes - 1) { // 窗口长度不足 minutes
                continue;
            }
            max_s1 = max(max_s1, s[1]);
            // 窗口最左边元素离开窗口
            s[1] -= grumpy[i - minutes + 1] ? customers[i - minutes + 1] : 0;
        }
        return s[0] + max_s1;
    }
};*/

//自己的解法
/*class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        vector<int> nums(n);
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==1)
            {
                nums[i]=customers[i];
            }
        }

        int sum=0,ret=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(i-minutes+1<0) continue;

            ret=max(ret,sum);
            sum-=nums[i-minutes+1];
        }

        int sum2=0;
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==0)
            {
                sum2+=customers[i];
            }
        }

        return ret+sum2;
    }
};*/
// @lc code=end

