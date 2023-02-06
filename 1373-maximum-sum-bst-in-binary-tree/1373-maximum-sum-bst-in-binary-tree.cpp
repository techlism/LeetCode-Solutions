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
class info{
  public:
  int maxi;
  int mini;
  bool isBST;
  int sum;
};
class Solution {
private:
    info solve(TreeNode * root,int & ans){
        if(root==nullptr){
            return {INT_MIN,INT_MAX,true,0};
        }
        info left = solve(root->left,ans);
        info right= solve(root->right,ans);
        info currNode;
        currNode.sum=left.sum + right.sum + root->val;
        currNode.maxi=max(root->val,right.maxi);
        currNode.mini=min(root->val,left.mini);
        currNode.isBST=left.isBST && right.isBST && root->val > left.maxi && root->val < right.mini;
        if(currNode.isBST){
            ans=max(currNode.sum,ans);
        }
        return currNode;
    }    
public:
    int maxSumBST(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};