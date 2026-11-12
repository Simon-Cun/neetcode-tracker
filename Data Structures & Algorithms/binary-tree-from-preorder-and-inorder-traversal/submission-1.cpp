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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() or inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder.at(0));
        int mid = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            if (inorder.at(i) == preorder.at(0)) {
                mid = i;
                break;
            }
        }
        vector<int> preorderSlice1;
        for (int i = 1; i < mid + 1; ++i) {
            preorderSlice1.push_back(preorder.at(i));
        }
        vector<int> inorderSlice1;
        for (int i = 0; i < mid; ++i) {
            inorderSlice1.push_back(inorder.at(i));
        }
        root->left = buildTree(preorderSlice1, inorderSlice1);

        vector<int> preorderSlice2;
        for (int i = mid + 1; i < preorder.size(); ++i) {
            preorderSlice2.push_back(preorder.at(i));
        }
        vector<int> inorderSlice2;
        for (int i = mid + 1; i < inorder.size(); ++i) {
            inorderSlice2.push_back(inorder.at(i));
        }
        root->right = buildTree(preorderSlice2, inorderSlice2);
        return root;
    }
};
