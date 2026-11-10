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
    int best = 0;
    int dfs(TreeNode* curr) {
        if (!curr) return -1;
        int left = dfs(curr->left) + 1;
        int right = dfs(curr->right) + 1;
        best = max(best, left + right);
        return max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return best;
    }
};
