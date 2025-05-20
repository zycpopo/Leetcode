/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
    public:
        bool isLetterOrNumber(char ch) {
            return (ch >= '0' && ch <= '9') 
                   || (ch >= 'a' && ch <= 'z') 
                   || (ch >= 'A' && ch <= 'Z');
        }
        
        bool isPalindrome(string s) {
            int begin = 0, end = s.size() - 1;
            while (begin < end) {
                // 跳过非字母数字字符
                while (begin < end && !isLetterOrNumber(s[begin])) 
                    ++begin;
                while (begin < end && !isLetterOrNumber(s[end])) 
                    --end;
                
                // 转换为小写比较（更通用）
                if (tolower(s[begin]) != tolower(s[end])) 
                    return false;
                
                ++begin;
                --end;
            }
            return true;
        }
    };
// @lc code=end

