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
    int dfs(TreeNode* curr, int& ret) {
        if (!curr) return -1;
        int left = dfs(curr->left, ret) + 1;
        int right = dfs(curr->right, ret) + 1;
        ret = max(ret, left + right);
        return max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ret = 0;
        dfs(root, ret);
        return ret;
    }
};
