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
    void zigzag(int &ans, TreeNode * root, int left, int right){
        if(root==nullptr){
            return;
        }
        ans=max(left,ans);
        ans=max(right,ans);
        zigzag(ans,root->left,0,left+1);
        zigzag(ans,root->right,right+1,0);
    }
public:
    int longestZigZag(TreeNode* root) {
        int ans=0;
        zigzag(ans,root,0,0);
        return ans;
    }
};