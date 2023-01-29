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
    void preOrder(TreeNode * root,int targetSum,int sum,vector<int>path,vector<vector<int>>&ans){
        if(root==nullptr){
            return;
        }
        sum=sum+root->val;
        path.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            if(sum==targetSum){
                ans.push_back(path);
            }
            else{
                path.pop_back();
                sum=sum-root->val;
            }
        }
        if(root->left)
         preOrder(root->left,targetSum,sum,path,ans);
        if(root->right)
         preOrder(root->right,targetSum,sum,path,ans);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int>path;
        vector<vector<int>> ans;
        preOrder(root,targetSum,sum,path,ans);
        return ans;
    }
};