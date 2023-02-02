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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val > root->val)
            // root will be left child of new node
            return new TreeNode(val, root, NULL);
        root->right = insertIntoMaxTree(root->right, val);
        return root;
// have to Understand it once again        
    }
};