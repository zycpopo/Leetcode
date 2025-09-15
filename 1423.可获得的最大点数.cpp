/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */

// @lc code=start
//反向思维最优解
/*class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int m = n - k;  // 中间连续的未被取走的元素个数
        int s = reduce(cardPoints.begin(), cardPoints.begin() + m);
        int min_s = s;
        for (int i = m; i < n; ++i) {
            s += cardPoints[i] - cardPoints[i - m];
            min_s = min(min_s, s);
        }
        return reduce(cardPoints.begin(), cardPoints.end()) - min_s;
    }
};*/

//最优解
/*class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int s = reduce(cardPoints.begin(), cardPoints.begin() + k);
        int ans = s;
        for (int i = 1; i <= k; i++) {
            s += cardPoints[cardPoints.size() - i] - cardPoints[k - i];
            ans = max(ans, s);
        }
        return ans;
    }
};*/

//前缀和解法
/*class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        
        // 前缀和数组
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int maxSum = 0;

        // 枚举从前边取 i 个（i 从 0 到 k）
        for (int i = 0; i <= k; ++i) {
            int frontSum = prefix[i];                    // 前 i 个
            int backSum = prefix[n] - prefix[n - (k - i)]; // 后 k-i 个
            maxSum = max(maxSum, frontSum + backSum);
        }

        return maxSum;
    }
};*/

//构造新数组解法
/*class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        
        // 构造一个数组：后k个 + 前k个
        vector<int> num2(2 * k);
        int idx = 0;

        // 后k个
        for (int i = n - k; i < n; ++i) {
            num2[idx++] = nums[i];
        }
        // 前k个
        for (int i = 0; i < k; ++i) {
            num2[idx++] = nums[i];
        }

        // 在 num2 上找长度为 k 的最大子数组和
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += num2[i];
        }
        int maxSum = sum;

        // 滑动窗口
        for (int i = k; i < 2 * k; ++i) {
            sum = sum + num2[i] - num2[i - k];
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};*/

// @lc code=end

