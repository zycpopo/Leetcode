/*
 * @lc app=leetcode.cn id=3545 lang=cpp
 *
 * [3545] 不同字符数量最多为 K 时的最少删除数
 */

// @lc code=start
class Solution {
public:
    int minDeletion(string s, int k) {
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }
    vector<int> counts;
    for (int f : freq) {
        if (f > 0) {
            counts.push_back(f);
        }
    }
    
    int unique = counts.size();

    if (unique <= k) {
        return 0;
    }
    
    sort(counts.begin(), counts.end());
    
    int deleteCount = 0;
    for (int i = 0; i < unique - k; i++) {
        deleteCount += counts[i]; 
    }
    
    return deleteCount;
}
};
// @lc code=end

