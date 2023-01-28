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
//Logic - I have just used a post order traversal and swapped the nodes (apparently I was not sure that node swapping is also possible).
//Why postorder?
//Because in postorder you will have both the left and right nodes before swapping.
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        invertTree(root->left);
        invertTree(root->right);
        TreeNode * curr =root;
        swap(curr->left,curr->right);
        return root;
    }
};
