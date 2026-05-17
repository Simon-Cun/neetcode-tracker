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
    int diameter = 0;
    int helper(TreeNode* node) {
        if (!node) return 0;
        int left = helper(node->left);
        int right = helper(node->right);
        diameter = max(diameter, left + right);
        return max(left + 1, right + 1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        helper(root);
        return diameter;
    }
};
