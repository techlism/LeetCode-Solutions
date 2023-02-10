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
    void inorderTraverse(TreeNode * root , vector<int>& inorder){
        if(root==nullptr){
            return;
        }
        inorderTraverse(root->left,inorder);
        inorder.push_back(root->val);
        inorderTraverse(root->right,inorder);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int>inorder;
        inorderTraverse(root,inorder);
        int ans=INT_MAX;
        for(int i=0;i<inorder.size()-1;i++){
            int diff=abs(inorder[i]-inorder[i+1]);
            ans=min(ans,diff);
        }
        return ans;
    }
};