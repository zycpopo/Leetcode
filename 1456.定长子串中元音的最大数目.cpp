/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 *
 * [1456] 定长子串中元音的最大数目
 */

// @lc code=start
class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        int count=0;
        int len=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            {
                count++;
            } 
            if(i<k-1)
                continue;
            
            len=max(len,count);

            char out=s[i-k+1];
            if(out=='a'||out=='e'||out=='i'||out=='u'||out=='o')
            {
                count--;
            }
        }

        return len;
    }
};
// @lc code=end

