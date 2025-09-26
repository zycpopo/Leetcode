/*
 * @lc app=leetcode.cn id=2279 lang=cpp
 *
 * [2279] 装满石头的背包的最大数量
 */

// @lc code=start
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    int n = capacity.size();
    vector<int> diff(n); 

    for (int i = 0; i < n; i++) {
        diff[i] = capacity[i] - rocks[i];
    }
  
    sort(diff.begin(), diff.end());
    
    int ret = 0;
    for (int i = 0; i < n && additionalRocks >= diff[i]; i++) {
        additionalRocks -= diff[i];  
        ret++;                        
    }
    
    return ret;
}
};
// @lc code=end

