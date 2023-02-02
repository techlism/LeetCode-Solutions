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
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (!root){
        //if root is null then create a new Node and return and then recursion will manage
            return new TreeNode(val);
        }
        if (val > root->val){
            // root will be left child of new node
            return new TreeNode(val, root, NULL);            
        }
        else{
            //Insert into the right of the root
            root->right = insertIntoMaxTree(root->right, val);
        }
        return root;
    }
};