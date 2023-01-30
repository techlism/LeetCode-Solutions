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
    void findSum(TreeNode* root,int buffer,size_t &ans){
        if(root==nullptr){
            return;
        }
        buffer=buffer*10 + root->val;
        if(root->left==nullptr && root->right==nullptr){
            ans=ans+buffer;
            buffer=buffer-root->val;
        }
        findSum(root->left,buffer,ans);
        findSum(root->right,buffer,ans);
    }
public:
    int sumNumbers(TreeNode* root) {
        size_t ans= 0;
        int buffer=0;
        findSum(root,buffer,ans);
        return ans;
    }
};