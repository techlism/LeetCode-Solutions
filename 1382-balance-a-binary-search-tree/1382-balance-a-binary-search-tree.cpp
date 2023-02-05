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
    void inorder(TreeNode * root,vector<int>&traversal){
        if(root==nullptr){
            return;
        }
        inorder(root->left,traversal);
        traversal.push_back(root->val);
        inorder(root->right,traversal);
    }
    
    TreeNode* buildtree(int s,int e,vector<int>&traversal){
        if(s>e){
            return nullptr;
        }
        int mid = (s+e)/2;
        TreeNode * newroot = new TreeNode(traversal[mid]);
        newroot->left=buildtree(s,mid-1,traversal);
        newroot->right=buildtree(mid+1,e,traversal);
        return newroot;
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>traversal;
        inorder(root,traversal);
        return buildtree(0,traversal.size()-1,traversal);
    }
};