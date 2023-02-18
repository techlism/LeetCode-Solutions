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
    void inorder(TreeNode* root,TreeNode * & first , TreeNode * & second , TreeNode * &prev){
        if(root==nullptr){
            return;
        }
        
        inorder(root->left,first,second,prev);
        
        if(!first && prev->val > root->val){
            first=prev;
        }
        if(first && prev->val > root->val ){
            second=root;
        }
        
        prev=root;
        
        inorder(root->right,first,second,prev);
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode * first ;
        TreeNode * second;
        TreeNode * prev= new TreeNode(INT_MIN);
        inorder(root,first,second,prev);
        swap(first->val,second->val);
    }
};