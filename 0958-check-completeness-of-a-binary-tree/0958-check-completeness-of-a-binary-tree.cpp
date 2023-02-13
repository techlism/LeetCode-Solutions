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
  int countNodes(TreeNode* root){
      if(root==NULL){
          return 0;
      }
      return 1 + countNodes(root->left) + countNodes(root->right);
  }
  bool isCBT(TreeNode* root,int count, int i){
      if(root==NULL){
          return true;
      }
      if(i>=count){
          return false;
      }
      bool l=isCBT(root->left,count,2*i+1);
      bool r=isCBT(root->right,count,2*i+2);
      return l&&r;
  }    
public:
    bool isCompleteTree(TreeNode* root) {
        int count = countNodes(root);
        return isCBT(root,count,0);
    }
};