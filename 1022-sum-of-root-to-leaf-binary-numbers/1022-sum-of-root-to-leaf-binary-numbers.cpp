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
    void preorder(TreeNode* root, int buff, int & ans){
        buff=buff*2 + root->val;
        if(root->left==nullptr &&  root->right==nullptr){
            //leaf node
            ans=ans+buff;
            return;
        }
        if(root->left)
         preorder(root->left,buff,ans);
        if(root->right)
         preorder(root->right,buff,ans);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int buff=0;
        int ans=0;
        preorder(root,buff,ans);
        return ans;
    }
};