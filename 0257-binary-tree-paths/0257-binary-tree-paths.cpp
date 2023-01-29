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
    void preOrder(TreeNode * root, vector<string> &ans,string s,string buff){
        if(root==nullptr){
            return;
        }
        if(root->left==nullptr && root->right==nullptr){
            ans.push_back(s+to_string(root->val));
        }
        else{
        buff=to_string(root->val)+"->";
        s=s+buff;
        }
        preOrder(root->left,ans,s,buff);
        preOrder(root->right,ans,s,buff);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(root==nullptr){
            return ans;
        }
        string s="";
        string buff="";
        preOrder(root,ans,s,buff);
        return ans;
    }
};