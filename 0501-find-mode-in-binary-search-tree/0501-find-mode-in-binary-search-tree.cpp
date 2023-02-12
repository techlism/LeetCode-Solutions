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
    void inorder(TreeNode * root,vector<int>& ans,int &curr,int & prev_Val,int &currmax){
        if(root==nullptr){
            return;
        }
        inorder(root->left,ans,curr,prev_Val,currmax);
        if(root->val==prev_Val){
            curr++;
        }
        else if(root->val!=prev_Val){
            curr=1;
        }
        if(curr>currmax){
            ans.clear();
            ans.push_back(root->val);
            currmax=curr;
        }
        else if(curr==currmax){
            ans.push_back(root->val);
        }
        prev_Val=root->val;
        inorder(root->right,ans,curr,prev_Val,currmax);
    }
public:
    vector<int> findMode(TreeNode* root) {
       vector<int>ans;
        int curr=0;
        int currmax=0;
        int prev_Val=INT_MIN;
        inorder(root,ans,curr,prev_Val,currmax);
        return ans;
    }
};