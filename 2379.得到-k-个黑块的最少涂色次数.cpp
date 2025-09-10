/*
 * @lc app=leetcode.cn id=2379 lang=cpp
 *
 * [2379] 得到 K 个黑块的最少涂色次数
 */

// @lc code=start
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ret=INT_MAX;
        int n=blocks.size();
        int wc=0;
        for(int i=0;i<n;i++)
        {
            if(blocks[i]=='W') wc++;
            if(i<k-1)
            {
                continue;
            }
            ret=min(ret,wc);

            if(blocks[i-k+1]=='W') wc--;
        }

        return ret;
    }
};
// @lc code=end

