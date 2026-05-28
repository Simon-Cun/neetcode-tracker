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
    int good = 0;
    void helper(TreeNode* node, int value) {
        if (!node) return;
        if (node->val >= value) ++good;
        helper(node->left, max(node->val, value));
        helper(node->right, max(node->val, value));
    }
    int goodNodes(TreeNode* root) {
        helper(root, INT_MIN);
        return good;
    }
};
