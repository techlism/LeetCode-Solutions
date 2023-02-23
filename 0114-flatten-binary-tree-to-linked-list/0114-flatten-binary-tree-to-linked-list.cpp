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
    void preorder(TreeNode * root,vector<TreeNode*>&nodes){
        if(root==nullptr){
            return;
        }
        nodes.emplace_back(root);
        preorder(root->left,nodes);
        preorder(root->right,nodes);
    }
    //For O(1) space use Morris Traversal
public:
    void flatten(TreeNode* root) {
        if(root==nullptr){
            return;
        }
        vector<TreeNode*> nodes;
        preorder(root,nodes);
        for(int i=0;i<nodes.size()-1;i++){
            nodes[i]->right=nodes[i+1];
            nodes[i]->left=nullptr;
        }
        nodes[nodes.size()-1]->left=nullptr;
        nodes[nodes.size()-1]->right=nullptr;
        root=nodes[0];
    }
};