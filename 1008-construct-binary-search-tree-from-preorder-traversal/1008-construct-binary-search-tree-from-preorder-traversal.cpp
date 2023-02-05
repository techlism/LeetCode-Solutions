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
    TreeNode* buildtree(int min, int max, vector<int>&preorder,int &i){
        if(i>=preorder.size()){
            return nullptr;
        }
        if(preorder[i] < min || preorder[i] > max){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left=buildtree(min,root->val,preorder,i);
        root->right=buildtree(root->val,max,preorder,i);
        return root;
    } 
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int min=INT_MIN;
        int max=INT_MAX;
        int i=0;
        return buildtree(min,max,preorder,i);
    }
};