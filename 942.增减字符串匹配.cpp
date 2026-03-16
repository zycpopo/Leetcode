/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 增减字符串匹配
 */

// @lc code=start
class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ret;
        int right=s.size();
        int left=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='I')
            {
                ret.push_back(left);
                left++;
            }
            else
            {
                ret.push_back(right);
                right--;
            }
        }
        ret.push_back(right);
        return ret;
    }
};
// @lc code=end

