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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>avg;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            double levelAvg=0;
            double count=0;
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                levelAvg=levelAvg+front->val;
                count++;
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            avg.push_back(levelAvg/count);
        }
        return avg;
    }
};