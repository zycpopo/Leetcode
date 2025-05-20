/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
    public:
        void reverseString(vector<char>& s) {
            if(s.empty()) return;
            size_t begin=0,end=s.size()-1;
            while(begin < end)
            {
                swap(s[begin++],s[end--]);
            }
        }
    };
// @lc code=end

