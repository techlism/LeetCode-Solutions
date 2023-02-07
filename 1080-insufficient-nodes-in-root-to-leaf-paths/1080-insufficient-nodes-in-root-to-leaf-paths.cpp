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
    TreeNode* preorder(TreeNode * root, int limit ,int sum){
        if(root==nullptr){
            return nullptr;
        }
        TreeNode * leftAns = preorder(root->left,limit,sum+root->val);
        TreeNode * rightAns = preorder(root->right,limit,sum+root->val);
        if(root->left==nullptr && root->right==nullptr){
            if(sum+root->val < limit){
            return nullptr;
            }
            else{
                return root;
            }
        }
        if(leftAns==nullptr){
            root->left=nullptr;
        }
        if(rightAns==nullptr){
            root->right=nullptr;
        }
        if(root->left==nullptr && root->right==nullptr){
            return nullptr;
        }
        return root;
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return preorder(root,limit,0);
    }
};