/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return  dfs(root,0);
    }
    int dfs(TreeNode* root,int presum){
        presum=presum*10+root->val;
        if(root->left==nullptr&&root->right==nullptr)
        {
            return presum;
        }
        int ret=0;
        if(root->left) ret+=dfs(root->left,presum);
        if(root->right) ret+=dfs(root->right,presum);

        return ret;
    }
};
// @lc code=end

