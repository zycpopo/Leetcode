/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int left=0,right=n-1;

        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if((target>=letters[mid]))
            {
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return letters[left % n];
    }
};
// @lc code=end

