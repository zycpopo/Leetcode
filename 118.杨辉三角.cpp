/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        for(int i=0;i<numRows;i++)
        {
            vector<int> row(i+1,1);

            for(int j=1;j<i;j++)
            {
                row[j]=result[i-1][j-1]+result[i-1][j];
            }

            result.push_back(row);
        }
        
        return result;
    }
};
// @lc code=end

