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
    void inorder(TreeNode * root, vector<TreeNode*> & nodes){
        if(root==nullptr){
            return;
        }
        inorder(root->left,nodes);
        nodes.push_back(root);
        inorder(root->right,nodes);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*>nodes;
        inorder(root,nodes);
        for(int i=0;i<nodes.size()-1;i++){
            nodes[i]->right=nodes[i+1];
            nodes[i]->left=nullptr;
        }
        nodes[nodes.size()-1]->right=nullptr;
        nodes[nodes.size()-1]->left=nullptr;
        return nodes[0];
    }
};