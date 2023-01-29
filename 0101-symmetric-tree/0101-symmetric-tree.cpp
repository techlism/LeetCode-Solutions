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
private:
    bool symmleftRight(TreeNode *root1, TreeNode* root2) {
        if(!root1) 
            return !root2;
        if(!root2) 
            return !root1;
        bool left=symmleftRight(root1->left, root2->right);
        bool right=symmleftRight(root1->right, root2->left);
        return (root1->val == root2->val) && left && right;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr){
            return 1;
        }
        return symmleftRight(root->left,root->right);
    }
};