/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

// @lc code=start
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }

        vector<pair<string, int>> vec(freq.begin(), freq.end());

        sort(vec.begin(), vec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second != b.second) {
                return a.second > b.second;  
            return a.first < b.first;        
        });

        vector<string> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(vec[i].first);
        }

        return result;
    }
};
// @lc code=end

