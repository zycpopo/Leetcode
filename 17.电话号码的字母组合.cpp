/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        
        // 特殊情况：空输入
        if (digits.empty()) {
            return result;
        }

        // 数字到字母的映射（索引0和1不用）
        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        string current; // 当前组合
        backtrack(digits, 0, current, mapping, result);

        return result;
    }

private:
    void backtrack(const string& digits, int index, string& current,
                   const vector<string>& mapping, vector<string>& result) {
        
        // 递归终止：已经处理完所有数字
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // 当前数字对应的字母
        char digit = digits[index];
        string letters = mapping[digit - '0'];

        // 遍历当前数字对应的每一个字母
        for (char c : letters) {
            current.push_back(c);           // 做选择
            backtrack(digits, index + 1, current, mapping, result); // 递归
            current.pop_back();             // 撤销选择（回溯）
        }
    }
};
// @lc code=end

