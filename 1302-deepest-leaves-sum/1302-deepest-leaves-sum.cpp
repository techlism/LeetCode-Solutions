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
    int deepestLeavesSum(TreeNode* root) {
      vector<vector<int>> leaves;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            vector<int>level;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode * front = q.front();
                q.pop();
                if(front->left==nullptr && front->right==nullptr){
                    level.push_back(front->val);
                }
                    if(front->left){
                        q.push(front->left);
                    }
                    if(front->right){
                        q.push(front->right);
                    }
                }
            leaves.push_back(level);
            }
        int ans=0;
        int size=leaves.size();
        for(int i=0;i<leaves[size-1].size();i++){
            ans=ans+leaves[size-1][i];
        }
        return ans;
        
    }
};