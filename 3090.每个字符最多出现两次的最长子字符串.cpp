/*
 * @lc app=leetcode.cn id=3090 lang=cpp
 *
 * [3090] 每个字符最多出现两次的最长子字符串
 */

// @lc code=start
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int hash[26]={0};
        int n=s.size();
        int left,right=0;
        int ret=0;

        for(int i=0;i<n;i++)
        {
            hash[s[i]-'a']++;
            while(hash[s[i]-'a']>2)
            {
                hash[s[left]-'a']--;
                left++;
            }
            ret=max(ret,i-left+1);
        }

        return ret;
    }
};
// @lc code=end

