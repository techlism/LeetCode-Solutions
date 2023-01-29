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
    void preOrder(TreeNode * root, int targetSum , bool &ans,int sum){
        if(root==nullptr){
            return;
        }
        sum=sum+root->val;
        if(root->left==nullptr && root->right==nullptr){
            if(sum==targetSum){
                ans=true;
                return;
            }
            else{
                sum=sum-root->val;
            }
        }
        preOrder(root->left,targetSum,ans,sum);
        preOrder(root->right,targetSum,ans,sum);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        bool ans=false;
        preOrder(root,targetSum,ans,sum);
        return ans;
    }
};