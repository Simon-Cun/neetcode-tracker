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
    TreeNode* lca = nullptr;
    void helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return;
        lca = root;
        if (p->val < root->val && q->val < root->val) helper(root->left, p, q);
        if (p->val > root->val && q->val > root->val) helper(root->right, p, q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        helper(root, p, q);
        return lca;
    }
};
