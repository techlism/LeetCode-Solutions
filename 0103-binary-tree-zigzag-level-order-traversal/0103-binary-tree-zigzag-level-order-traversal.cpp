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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
    int levelcount=0;
    queue<TreeNode * > q;
    q.push(root);
    while(!q.empty()){
        vector<int>level;
        int size=q.size();
        for(int i=0;i<size;i++){
         TreeNode * nd = q.front();
         q.pop();            
         if(nd->left){
            q.push(nd->left);
         }
         if(nd->right){
            q.push(nd->right);
         }
         level.push_back(nd->val);
        }
        levelcount++;
        if(levelcount%2!=0){
          ans.push_back(level);       
        }
        else{
            reverse(level.begin(),level.end());
            ans.push_back(level);
        } 
    }
    return ans;        
    }
};