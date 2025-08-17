/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        {
            return "1";
        }
        return change(countAndSay(n-1));
    }
    string change(string n)
    {
        int t=n.size();
        string an;
        int i=0;
        while(i < t)
        {
            int j=i+1;
            int length=1;
        
            while(j < t && n[i] == n[j])
            {
                length++;
                j++;
            }

            stringstream ss;
            ss<<length<<n[i];
            an.append(ss.str());

            i=j;
        }

        return an;
    }
};
// @lc code=end

