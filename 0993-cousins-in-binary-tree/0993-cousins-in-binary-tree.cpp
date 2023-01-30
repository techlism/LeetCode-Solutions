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
    bool isCousins(TreeNode* root, int x, int y) {
        multimap<int,int> leveltoNode;
        int level=0;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
          int size=q.size();
         for(int i=0;i<size;i++){
          TreeNode* front= q.front();
          q.pop();
           //checking if nodes (x & y) have same parent
          if(front->left && front->right){
           if((front->left->val==x && front->right->val==y)|| (front->left->val==y && front->right->val==x)){
            return false;              
           }              
          }
          leveltoNode.insert(pair<int,int>(front->val,level));
          if(front->left){
            q.push(front->left);
           }
          if(front->right){
            q.push(front->right);
          }
         }
         level++;
        }
        //if both x and y are at same level
        return (leveltoNode.find(x)->second==leveltoNode.find(y)->second);        
    }
};