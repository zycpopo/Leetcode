/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start

// @lc code=end

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        unordered_map<string, int> hash1;
        for (auto& word : words) {
            hash1[word]++;
        }

        int len = words[0].size();
        int m = words.size();
        int totalLen = len * m;

        for (int i = 0; i < len; i++) {
            unordered_map<string, int> hash2;
            int left = i, count = 0;

            // 修正：使用 <=
            for (int right = i; right <= (int)s.size() - len; right += len) {
                string in = s.substr(right, len);
                hash2[in]++;

                // 进窗口：只有在 hash1 中且未超标才 count++
                if (hash1.count(in) && hash2[in] <= hash1[in]) {
                    count++;
                }

                // 收缩窗口：使用 if 足够
                if (right - left + 1 > totalLen) {
                    string out = s.substr(left, len);
                    if (hash1.count(out) && hash2[out] <= hash1[out]) {
                        count--;
                    }
                    hash2[out]--;
                    left += len;
                }

                // 检查是否完全匹配
                if (count == m) {
                    ret.push_back(left);
                }
            }
        }

        return ret;
    }
};