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
    int count = 0;
private:
    void countgood(TreeNode * root , int pathMax){
        if(!root) return;
        if(root->val >= pathMax){
            pathMax = root->val;
            count++;
        }
        countgood(root->left,pathMax);
        countgood(root->right,pathMax);
    }
public:
    int goodNodes(TreeNode* root) {
        countgood(root,root->val);
        return count;
    }
};