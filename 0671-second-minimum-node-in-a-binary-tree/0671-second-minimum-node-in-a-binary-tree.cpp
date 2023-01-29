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
    void inorder(TreeNode* root,set<int> & ans){
        if(root==nullptr){
            return;
        }
        inorder(root->left,ans);
        ans.insert(root->val);
        inorder(root->right,ans);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        set<int> ans;
        inorder(root,ans);
        if(ans.size()<=1){
            return -1;
        }
        auto itr = ans.begin();
        itr++;
        return *itr;
    }
};