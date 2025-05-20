/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start

class Solution {
    public:
        int firstUniqChar(string s) {
            int count[256]={0};
            int size=s.size();
            for(int i=0;i<size;++i)
                count[s[i]]++;
    
            for(int i=0;i<size;i++)
                if(1==count[s[i]])
                  return i;
                
            return -1;
        }
    };
// @lc code=end

