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
    int ret = INT_MIN;
    int helper(TreeNode* curr) {
        if (!curr) return 0;
        int left = max(0, helper(curr->left));
        int right = max(0, helper(curr->right));
        ret = max(ret, curr->val + left + right);
        return curr->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ret;
    }
};
