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
    void postOrder(TreeNode * &root,int target){
        if(root==nullptr){
            return;
        }
        postOrder(root->left,target);
        postOrder(root->right,target);
        if(root->left){
            if(root->left->left==nullptr && root->left->right==nullptr && root->left->val==target){
                root->left=nullptr;
            }
        }
        if(root->right){
            if(root->right->left==nullptr && root->right->right==nullptr && root->right->val==target){
                root->right=nullptr;
            }
        }
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        postOrder(root,target);
        if(root->left==nullptr && root->right==nullptr && root->val==target){
            return nullptr;
        }
        return root;
    }
};