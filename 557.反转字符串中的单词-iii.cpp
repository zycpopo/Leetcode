/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;

        while(i<n)
        {
            int start=i;
            while(i<n&&s[i]!=' ')
            {
                i++;
            }
            reverse(s.begin() + start, s.begin() + i);

            while(i<n&&s[i]==' ')
            {
                i++;
            }
        }
    return s;
    
    }
};
// @lc code=end

