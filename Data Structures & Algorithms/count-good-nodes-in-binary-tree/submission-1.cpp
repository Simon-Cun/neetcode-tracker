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
    int ret = 0;
    void helper(TreeNode* curr, int val) {
        if (!curr) return;
        if (curr->val >= val) {
            helper(curr->left, curr->val);
            helper(curr->right, curr->val);
            ++ret;
        } else {
            helper(curr->left, val);
            helper(curr->right, val);
        }
    }
    int goodNodes(TreeNode* root) {
        helper(root, INT_MIN);
        return ret;
    }
};
