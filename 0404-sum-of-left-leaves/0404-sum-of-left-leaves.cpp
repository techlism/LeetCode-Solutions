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
    void sumleft(TreeNode * root,int &ans){
        if(root==NULL){
            return;
        }
        sumleft(root->left,ans);
        sumleft(root->right,ans);
        if(root->left){
            TreeNode* curr = root->left;
            if(curr->left==NULL && curr->right==NULL){
                ans=ans+curr->val;
            }
        }
    }
public:
    //Logic- Wherever you are currently just check if the left node from it is a leaf node or not.
    //Or simply we can use inorder traversal.
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans=0;
        sumleft(root,ans);
        return ans;
        
    }
};
