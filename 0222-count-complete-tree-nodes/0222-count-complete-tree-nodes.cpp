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
    int countNodes(TreeNode* root) {
        //Just Going with Level Order
        if(root==nullptr){
            return 0;
        }
        int ans=0;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            TreeNode * front = q.front();
            q.pop();
            if(front)
                ans++;
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
            }
        return ans;
    }
};