/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 *
 * [2300] 咒语和药水的成功对数
 */

// @lc code=start
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        sort(potions.begin(), potions.end());
        vector<int> ret(n);

        for (int i = 0; i < n; i++) {
            long long spell = spells[i];
            
            long long minPotion = (success + spell - 1) / spell; 
            
            int left = 0, right = m - 1;
            int idx = m;  
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (potions[mid] >= minPotion) {
                    idx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            ret[i] = m - idx;
        }
        
        return ret;
    }
};
// @lc code=end

