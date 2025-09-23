/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<string> strs;
        for(int x:nums) 
        {
            strs.push_back(to_string(x));
        }

        sort(strs.begin(),strs.end(),[](const string& s1,const string& s2)
        {
            return s1+s2>s2+s1;
        });
        
        string ret;
        for(string & s:strs) ret+=s;

        if(ret[0]=='0') return '0';
        return ret;
        }
};
// @lc code=end

