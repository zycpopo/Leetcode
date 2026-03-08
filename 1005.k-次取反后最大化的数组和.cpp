/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
public:
    /*int largestSumAfterKNegations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num: nums) {
            freq[num] += 1;
        }
        int ans = accumulate(nums.begin(), nums.end(), 0);
        for (int i = -100; i < 0; ++i) 
        {
            if (freq[i]) 
            {
                int ops = min(k, freq[i]);
                ans += (-i) * ops * 2;
                freq[i] -= ops;
                freq[-i] += ops;
                k -= ops;
                if (k == 0) 
                {
                    break;
                }
            }
        }
        if (k > 0 && k % 2 == 1 && !freq[0]) 
        {
            for (int i = 1; i <= 100; ++i)
            {
                if (freq[i]) 
                {
                    ans -= i * 2;
                    break;
                }
            }
        }
        return ans;
    }*/
    int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    
    // 尽量把负数变正（从最小的负数开始）
    for (int& x : nums) {
        if (x < 0 && k > 0) {
            x = -x;
            k--;
        } else {
            break;
        }
    }

    // 计算当前总和
    int sum = accumulate(nums.begin(), nums.end(), 0);

    // 如果还有剩余 k，且为奇数，翻转最小的绝对值元素一次
    if (k % 2 == 1) {
        int minAbs = *min_element(nums.begin(), nums.end());
        sum -= 2 * minAbs;  // 因为之前加的是 +minAbs，现在要变成 -minAbs，差值是 -2*minAbs
    }

    return sum;
}
};
// @lc code=end

