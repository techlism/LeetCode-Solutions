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
    vector<int> largestValues(TreeNode* root) {
        vector<int>levelmax;
        if(root==nullptr){
            return levelmax;
        }
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            int maxval=INT_MIN;
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                maxval=max(maxval,front->val);
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            levelmax.push_back(maxval);
        }
        return levelmax;
    }
};