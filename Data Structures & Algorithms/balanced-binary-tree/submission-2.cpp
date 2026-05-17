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
    int balanceFactor(TreeNode* node) {
        if (!node) return 0;
        return height(node->left) - height(node->right);
    }
    int height(TreeNode* node) {
        if (!node) return -1;
        return max(height(node->left), height(node->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (!isBalanced(root->left)) return false;
        if (!isBalanced(root->right)) return false;
        if (abs(balanceFactor(root)) > 1) return false;
        else return true;
    }
};
