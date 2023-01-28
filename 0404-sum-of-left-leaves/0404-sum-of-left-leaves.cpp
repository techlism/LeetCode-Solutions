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
            if(root->left->left==NULL && root->left->right==NULL){
                ans=ans+root->left->val;
            }
        }
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans=0;
        sumleft(root,ans);
        return ans;
        
    }
};