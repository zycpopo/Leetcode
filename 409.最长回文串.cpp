/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        int ret=0;
        int num[127]={0};
        for(char a: s)
        {
            num[a]++;
        }
        for(int i: num)
        {
                ret+=i/2*2;   
        }
        if(ret<s.size())
        {
            ret++;
        }
        return ret;
    }
};
// @lc code=end

