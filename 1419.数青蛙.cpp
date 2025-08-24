/*
 * @lc app=leetcode.cn id=1419 lang=cpp
 *
 * [1419] 数青蛙
 */

// @lc code=start
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int n= croakOfFrogs.size();
        if(n%5!=0) return -1;

        int hash[26]={0};
        for(int i=0;i<n;i++)
        {
            hash[croakOfFrogs[i]-'a']++;
        }

        int cCount = hash['c' - 'a'];
        if (hash['r' - 'a'] != cCount || hash['o' - 'a'] != cCount || 
            hash['a' - 'a'] != cCount || hash['k' - 'a'] != cCount) {
            return -1;
        }

      // 用于记录每个状态的青蛙数量（c:0, r:1, o:2, a:3, k:4）
        int state[5] = {0};
        int maxFrogs = 0;  // 最多同时鸣叫的青蛙数
        int currentFrogs = 0;  // 当前正在鸣叫的青蛙数
        
        // 字符到状态的映射
        auto charToState = [](char c) {
            switch(c) {
                case 'c': return 0;
                case 'r': return 1;
                case 'o': return 2;
                case 'a': return 3;
                case 'k': return 4;
                default: return -1;
            }
        };
        
        for (char c : croakOfFrogs) {
            int s = charToState(c);
            if (s == -1) return -1;  // 无效字符
            
            if (s == 0) {
                // 新的鸣叫开始
                state[0]++;
                currentFrogs++;
                maxFrogs = max(maxFrogs, currentFrogs);
            } else {
                // 检查前一个状态是否有青蛙
                if (state[s-1] == 0) {
                    return -1;  // 顺序错误
                }
                // 状态转换：从前一个状态移动到当前状态
                state[s-1]--;
                state[s]++;
                
                // 如果是最后一个状态，完成一次鸣叫
                if (s == 4) {
                    state[4]--;
                    currentFrogs--;
                }
            }
        }
        
        // 最后检查是否所有青蛙都完成了鸣叫
        for (int i = 0; i < 5; i++) {
            if (state[i] != 0) {
                return -1;
            }
        }
        
        return maxFrogs;
    }
    
};
// @lc code=end

