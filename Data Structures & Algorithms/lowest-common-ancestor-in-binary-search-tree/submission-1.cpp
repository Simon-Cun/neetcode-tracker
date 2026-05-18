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
    TreeNode* ret;
    void helper(TreeNode* root, int p, int q) {
        if (!root) return;
        if (min(p, q) <= root->val and root->val <= max(p, q)) ret = root;
        if (root->val < p and root->val < q) {
            helper(root->right, p, q);
        } else if (root->val > p and root->val > q) {
            helper(root->left, p, q);
        }
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p->val, q->val);
        return ret;
    }
};
