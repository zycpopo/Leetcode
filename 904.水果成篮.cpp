/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& f) {
        int hash[100001]={};
        int ret=0;
        for(int left=0,right=0,kinds=0;right<f.size();right++)
        {
            if(hash[f[right]]==0) kinds++;
            hash[f[right]]++;
            
            while(kinds>2)
            {
                hash[f[left]]--;
                if(hash[f[left]]==0) kinds--;
                left++;
            }
            ret=max(ret,right-left+1);
        }
        return ret;
    }
};
// @lc code=end

