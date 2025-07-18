/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[128]={0};
        int left=0,right=0,n=s.size();
        int ret=0;
        while(right<n)
        {
            hash[s[right]]++;
            while(hash[s[right]]>1)
                 hash[s[left++]]--;
            ret=max(ret,right-left+1);
            right++;
        }
        return ret;
    }
};
// @lc code=end

