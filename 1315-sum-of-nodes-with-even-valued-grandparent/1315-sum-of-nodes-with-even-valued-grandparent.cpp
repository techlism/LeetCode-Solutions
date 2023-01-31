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
    int sum=0;
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        if(root){
         if((root->left)){
            if(root->left->left && (root->val % 2 ==0))
             sum=sum+root->left->left->val;
         }
         if((root->left)){
            if(root->left->right && (root->val % 2 ==0))
             sum=sum+root->left->right->val;
         }
         if((root->right)){
            if(root->right->left  && (root->val % 2 ==0))
             sum=sum+root->right->left->val;
         }
         if((root->right)){
            if(root->right->right && (root->val % 2 ==0))
             sum=sum+root->right->right->val;
         }            
        }
        sumEvenGrandparent(root->left);
        sumEvenGrandparent(root->right);
        return sum ;
    }
};